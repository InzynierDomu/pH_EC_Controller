/**
 * @file main.cpp
 * @author by Szymon Markiewicz (https://github.com/InzynierDomu/)
 * @brief pH and EC meter
 * @date 2022-06
 */

#include "Automation.h"
#include "Buttons.h"
#include "Calibration_data_memory.h"
#include "Config.h"
#include "DS18B20.h"
#include "Data_presentation.h"
#include "Linear_function.h"
#include "OneWire.h"
#include "Sd_card.h"

#include <Arduino.h>
#include <EEPROM.h>
#include <math.h>


///< possible device state
enum class Device_state
{
  startup,
  display_measure_ph,
  display_measure_ec,
  calibration_ph,
  calibration_ec,
  change_ph_range,
  change_ec_range,
  fill_ph,
  fill_ec
};

byte m_ds_address[8]; ///< ds18b20 thermometer one wire address
OneWire m_one_wire = OneWire(Config::pin_thermometer); ///< one wire bus
DS18B20 m_ds_sensor = DS18B20(Config::pin_thermometer); ///< ds18b20 thermometer
Data_presentation m_data_presentation; ///< screen and serial handling
Calibration_data_memory m_memory; ///< memory handling
// Sd_card m_sd_card; ///< sd crad handling
Automation m_automation;

Device_state m_device_state = Device_state::startup; ///< actual device state

volatile bool m_up_button_pressed = false; ///< up button pressed flag
volatile bool m_down_button_pressed = false; ///< down button pressed flag
volatile bool m_right_button_pressed = false; ///< right button pressed flag
volatile bool m_left_button_pressed = false; ///< left button pressed flag
volatile bool m_center_button_pressed = false; ///< center button pressed flag
Linear_function ph_probe_characteristic; ///< ph probe linear characteristic
Linear_function ec_probe_characteristic; ///< ec probe linear characteristic

/**
 * @brief find thermometer on one wire
 */
void ds_thermometer_init()
{
  m_one_wire.reset_search();
  while (m_one_wire.search(m_ds_address))
  {
    if (m_ds_address[0] != 0x28)
      continue;

    if (OneWire::crc8(m_ds_address, 7) != m_ds_address[7])
    {
      break;
    }
  }
}

/**
 * @brief state - ph measure
 * @param action: buttons action
 */
void measurements_ph(const Buttons_action action)
{
  auto temperature = m_ds_sensor.getTempC();

  digitalWrite(Config::ph_supply_pin_probe, HIGH);
  digitalWrite(Config::ec_supply_pin_probe, LOW);
  delay(50);
  auto analog_mes = analogRead(Config::ph_pin_probe);
  auto ph = ph_probe_characteristic.find_unit_val(analog_mes);
  m_data_presentation.presentation_measurements_ph(temperature, ph, false);

  digitalWrite(Config::ph_supply_pin_probe, LOW);
  digitalWrite(Config::ec_supply_pin_probe, HIGH);
  delay(50);
  analog_mes = analogRead(Config::ec_pin_probe);
  auto ec = ec_probe_characteristic.find_unit_val(analog_mes);

  if (m_automation.check_ec_value(ec))
  {
    digitalWrite(Config::ph_supply_pin_probe, LOW);
    digitalWrite(Config::ec_supply_pin_probe, HIGH);
    m_automation.turn_on_fill_ec();
    m_device_state = Device_state::fill_ec;
  }
  else if (m_automation.check_ph_value(ph))
  {
    digitalWrite(Config::ph_supply_pin_probe, HIGH);
    digitalWrite(Config::ec_supply_pin_probe, LOW);
    m_automation.turn_on_fill_ph();
    m_device_state = Device_state::fill_ph;
  }
  else
  {
    switch (action)
    {
      case Buttons_action::up_pressed:
        digitalWrite(Config::ph_supply_pin_probe, HIGH);
        digitalWrite(Config::ec_supply_pin_probe, LOW);
        m_data_presentation.display_calib_mode();
        m_device_state = Device_state::calibration_ph;
        break;
      case Buttons_action::down_pressed:
        m_data_presentation.display_range_mode();
        m_device_state = Device_state::change_ph_range;
        break;
      case Buttons_action::left_pressed:
        m_device_state = Device_state::display_measure_ec;
        break;
      case Buttons_action::right_pressed:
        // if (m_sd_card.get_card_status())
        // {
        //   m_sd_card.save_ph_measurement(temperature, ph);
        //   m_data_presentation.display_save_data();
        // }
        break;
      default:
        m_device_state = Device_state::display_measure_ph;
        break;
    }
  }
}

/**
 * @brief state - ec measure
 * @param action: buttons action
 */
void measurements_ec(const Buttons_action action)
{
  auto temperature = m_ds_sensor.getTempC();

  digitalWrite(Config::ph_supply_pin_probe, LOW);
  digitalWrite(Config::ec_supply_pin_probe, HIGH);
  delay(50);
  auto analog_mes = analogRead(Config::ec_pin_probe);
  auto ec = ec_probe_characteristic.find_unit_val(analog_mes);

  digitalWrite(Config::ph_supply_pin_probe, HIGH);
  digitalWrite(Config::ec_supply_pin_probe, LOW);
  delay(50);
  analog_mes = analogRead(Config::ph_pin_probe);
  auto ph = ph_probe_characteristic.find_unit_val(analog_mes);

  m_data_presentation.presentation_measurements_ec(temperature, ec, false);

  if (m_automation.check_ec_value(ec))
  {
    digitalWrite(Config::ph_supply_pin_probe, LOW);
    digitalWrite(Config::ec_supply_pin_probe, HIGH);
    m_automation.turn_on_fill_ec();
    m_device_state = Device_state::fill_ec;
  }
  else if (m_automation.check_ph_value(ph))
  {
    digitalWrite(Config::ph_supply_pin_probe, HIGH);
    digitalWrite(Config::ec_supply_pin_probe, LOW);
    m_automation.turn_on_fill_ph();
    m_device_state = Device_state::fill_ph;
  }
  else
  {
    switch (action)
    {
      case Buttons_action::up_pressed:
        digitalWrite(Config::ph_supply_pin_probe, LOW);
        digitalWrite(Config::ec_supply_pin_probe, HIGH);
        m_data_presentation.display_calib_mode();
        m_device_state = Device_state::calibration_ec;
        break;
      case Buttons_action::down_pressed:
        m_data_presentation.display_range_mode();
        m_device_state = Device_state::change_ec_range;
        break;
      case Buttons_action::left_pressed:
        m_device_state = Device_state::display_measure_ph;
        break;
      case Buttons_action::right_pressed:
        // if (m_sd_card.get_card_status())
        // {
        //   m_sd_card.save_ec_measurement(temperature, ec);
        //   m_data_presentation.display_save_data();
        // }
        break;
      default:
        m_device_state = Device_state::display_measure_ec;
        break;
    }
  }
}

/**
 * @brief saving next point in characteristic
 * @param samples points to characteristic
 * @param sample new reference value
 * @return is calibration finished
 */
bool save_sample(Point* samples, double sample)
{
  static int sample_counter = 0;
  samples[sample_counter].unit_val = sample;
  switch (m_device_state)
  {
    case Device_state::calibration_ph:
      samples[sample_counter].analog_val = analogRead(Config::ph_pin_probe);
      break;
    case Device_state::calibration_ec:
      samples[sample_counter].analog_val = analogRead(Config::ec_pin_probe);
      break;
    default:
      break;
  }

  if (++sample_counter == 2)
  {
    sample_counter = 0;
    return true;
  }
  return false;
}

double load_ph_point(uint8_t point)
{
  Point points[2];
  m_memory.load_ph_calibration(points);
  return points[point].unit_val;
}

/**
 * @brief state -calibration ph procedure
 * @param action buttons action
 */
void calibration_ph(const Buttons_action action)
{
  static double sample = load_ph_point(0);

  static Point samples[2] = {};

  auto temperature = m_ds_sensor.getTempC();

  switch (action)
  {
    case Buttons_action::center_pressed:
      m_data_presentation.display_save_data();
      if (save_sample(samples, sample))
      {
        m_memory.save_ph_calibration(samples);
        ph_probe_characteristic.set_points(samples);
        sample = samples[0].unit_val;
        m_device_state = Device_state::display_measure_ph;
      };
      sample = load_ph_point(1);
      break;
    case Buttons_action::down_pressed:
      if (sample > 1)
      {
        sample--;
      }
      break;
    case Buttons_action::up_pressed:
      if (sample < Config::max_ph_to_calib)
      {
        sample++;
      }
      break;
    default:
      m_data_presentation.display_calibration_ph(sample, temperature);
      break;
  }
}

double load_ec_point(uint8_t point)
{
  Point points[2];
  m_memory.load_ec_calibration(points);
  return points[point].unit_val;
}

/**
 * @brief state -calibration ec procedure
 * @param action buttons action
 */
void calibration_ec(const Buttons_action action)
{
  static double sample = load_ec_point(0);

  static uint8_t position = 0;

  static Point samples[2] = {};

  auto temperature = m_ds_sensor.getTempC();

  switch (action)
  {
    case Buttons_action::center_pressed:
      m_data_presentation.display_save_data();
      if (save_sample(samples, sample))
      {
        m_memory.save_ec_calibration(samples);
        ec_probe_characteristic.set_points(samples);
        sample = samples[0].unit_val;
        m_device_state = Device_state::display_measure_ec;
      }
      sample = load_ec_point(1);
      break;
    case Buttons_action::down_pressed:
      // FIXME: min value
      sample = sample - pow(10.0, position * (-1.0));
      break;
    case Buttons_action::up_pressed:
      if (sample < Config::max_ec_to_calib)
      {
        sample = sample + pow(10.0, position * (-1.0));
      }
      break;
    case Buttons_action::right_pressed:
      // TODO: remove magic number
      if (position < 3)
      {
        position++;
      }
      else
      {
        position = 0;
      }
    case Buttons_action::left_pressed:
      if (position > 0)
      {
        position--;
      }
      else
      {
        position = 2;
      }
      break;
    default:
      m_data_presentation.display_calibration_ec(sample, position, temperature);
      break;
  }
}

/**
 * @brief state -change ph range for automation
 * @param action buttons action
 */
void change_ph_range(const Buttons_action action)
{
  static double sample = m_memory.load_ph_min();
  static uint8_t position = 0;

  float temperature = m_ds_sensor.getTempC();

  switch (action)
  {
    case Buttons_action::center_pressed:
      m_data_presentation.display_save_data();
      m_memory.save_ph_min(sample);
      m_automation.set_min_ph(sample);
      m_device_state = Device_state::display_measure_ph;
      break;
    case Buttons_action::up_pressed:
      sample++;
      break;
    case Buttons_action::down_pressed:
      sample--;
      break;
    case Buttons_action::right_pressed:
      if (position < 3)
      {
        position++;
      }
      else
      {
        position = 0;
      }
    case Buttons_action::left_pressed:
      if (position > 0)
      {
        position--;
      }
      else
      {
        position = 2;
      }
      break;
    default:
      m_data_presentation.display_change_ph_range(sample, position);
      break;
  }
}

/**
 * @brief state - change ec range for automation
 * @param action buttons action
 */
void change_ec_range(const Buttons_action action)
{
  static double sample = m_memory.load_ec_min();
  static uint8_t position = 0;

  float temperature = m_ds_sensor.getTempC();

  switch (action)
  {
    case Buttons_action::center_pressed:
      m_data_presentation.display_save_data();
      m_memory.save_ec_min(sample);
      m_automation.set_min_ec(sample);
      m_device_state = Device_state::display_measure_ec;
      break;
    case Buttons_action::down_pressed:
      // FIXME: min value
      sample = sample - pow(10.0, position * (-1.0));
      break;
    case Buttons_action::up_pressed:
      if (sample < Config::max_ec_to_calib)
      {
        sample = sample + pow(10.0, position * (-1.0));
      }
      break;
    case Buttons_action::right_pressed:
      // TODO: remove magic number
      if (position < 3)
      {
        position++;
      }
      else
      {
        position = 0;
      }
    case Buttons_action::left_pressed:
      if (position > 0)
      {
        position--;
      }
      else
      {
        position = 2;
      }
      break;
    default:
      m_data_presentation.display_calibration_ec(sample, position, temperature);
      break;
  }
}

/**
 * @brief turn on increasing ph until the expected value is obtained state
 */
void fill_ph()
{
  auto temperature = m_ds_sensor.getTempC();
  auto analog_mes = analogRead(Config::ph_pin_probe);
  auto ph = ph_probe_characteristic.find_unit_val(analog_mes);
  m_data_presentation.presentation_measurements_ph(temperature, ph, true);

  if (!m_automation.check_ph_value(ph))
  {
    m_automation.turn_off_fill_ph();
    m_device_state = Device_state::display_measure_ph;
  }
}

/**
 * @brief turn on increasing ec until the expected value is obtained state
 */
void fill_ec()
{
  auto temperature = m_ds_sensor.getTempC();
  auto analog_mes = analogRead(Config::ec_pin_probe);
  auto ec = ec_probe_characteristic.find_unit_val(analog_mes);
  m_data_presentation.presentation_measurements_ec(temperature, ec, true);

  if (!m_automation.check_ec_value(ec))
  {
    m_automation.turn_off_fill_ec();
    m_device_state = Device_state::display_measure_ec;
  }
}


/**
 * @brief setup on startup
 */
void setup()
{
  pinMode(Config::pin_ph_relay, OUTPUT);
  digitalWrite(Config::pin_ph_relay, LOW);
  pinMode(Config::pin_ec_relay, OUTPUT);
  digitalWrite(Config::pin_ec_relay, LOW);
  pinMode(Config::ph_supply_pin_probe, OUTPUT);
  digitalWrite(Config::ph_supply_pin_probe, HIGH);
  pinMode(Config::ec_supply_pin_probe, OUTPUT);
  digitalWrite(Config::ec_supply_pin_probe, LOW);

  m_data_presentation.init();
  ds_thermometer_init();

  Point points[2];
  m_memory.load_ph_calibration(points);
  m_data_presentation.print_ph_calibration(points);
  ph_probe_characteristic.set_points(points);

  m_memory.load_ec_calibration(points);
  m_data_presentation.print_ec_calibration(points);
  ec_probe_characteristic.set_points(points);

  m_up_button_pressed = false;
  m_down_button_pressed = false;
  m_right_button_pressed = false;
  m_left_button_pressed = false;
  m_up_button_pressed = false;

  pinMode(Config::pin_up_button, INPUT_PULLUP);
  pinMode(Config::pin_down_button, INPUT_PULLUP);
  pinMode(Config::pin_right_button, INPUT_PULLUP);
  pinMode(Config::pin_left_button, INPUT_PULLUP);
  pinMode(Config::pin_center_button, INPUT_PULLUP);
  pinMode(Config::pin_disable_ec_automation, INPUT_PULLUP);
  pinMode(Config::pin_disable_ph_automation, INPUT_PULLUP);
  PCICR |= Config::ports_with_interrupt;
  PCMSK2 |= Config::pins_interrupt_D;

  m_device_state = Device_state::display_measure_ph;

  // if (m_sd_card.is_card_available())
  // {
  //   Serial.println("SD card is present");
  // }

  auto min_val = m_memory.load_ph_min();
  m_automation.set_min_ph(min_val);
  m_data_presentation.print_min_ph(min_val);

  min_val = m_memory.load_ec_min();
  m_automation.set_min_ec(min_val);
  m_data_presentation.print_min_ec(min_val);
}

/**
 * @brief check pin for enable/disable automation
 */
void check_automation_disable()
{
  if (digitalRead(Config::pin_disable_ph_automation) == LOW && !m_automation.get_disable_ph_status())
  {
    m_data_presentation.print_change_disable_ph_automation(true);
    m_automation.change_disable_ph(true);
  }
  else if (digitalRead(Config::pin_disable_ph_automation) == HIGH && m_automation.get_disable_ph_status())
  {
    m_data_presentation.print_change_disable_ph_automation(false);
    m_automation.change_disable_ph(false);
  }

  if (digitalRead(Config::pin_disable_ec_automation) == LOW && !m_automation.get_disable_ec_status())
  {
    m_data_presentation.print_change_disable_ec_automation(true);
    m_automation.change_disable_ec(true);
  }
  else if (digitalRead(Config::pin_disable_ec_automation) == HIGH && m_automation.get_disable_ec_status())
  {
    m_data_presentation.print_change_disable_ec_automation(false);
    m_automation.change_disable_ec(false);
  }
}

/**
 * @brief main loop with state machine
 */
void loop()
{
  Buttons_action action = Buttons::check_buttons(
      m_up_button_pressed, m_down_button_pressed, m_right_button_pressed, m_left_button_pressed, m_center_button_pressed);
  if (action != Buttons_action::nothing)
  {
    // TODO: struct?
    m_up_button_pressed = false;
    m_down_button_pressed = false;
    m_right_button_pressed = false;
    m_left_button_pressed = false;
    m_center_button_pressed = false;
    delay(100);
  }

  check_automation_disable();

  switch (m_device_state)
  {
    case Device_state::display_measure_ph:
      measurements_ph(action);
      break;
    case Device_state::display_measure_ec:
      measurements_ec(action);
      break;
    case Device_state::calibration_ph:
      calibration_ph(action);
      break;
    case Device_state::calibration_ec:
      calibration_ec(action);
      break;
    case Device_state::change_ph_range:
      change_ph_range(action);
      break;
    case Device_state::change_ec_range:
      change_ec_range(action);
      break;
    case Device_state::fill_ph:
      fill_ph();
      break;
    case Device_state::fill_ec:
      fill_ec();
      break;
    default:
      break;
  }
}

/**
 * @brief port D Interrupts
 */
ISR(PCINT2_vect)
{
  if (digitalRead(Config::pin_up_button) == LOW)
  {
    m_up_button_pressed = true;
  }
  if (digitalRead(Config::pin_down_button) == LOW)
  {
    m_down_button_pressed = true;
  }
  if (digitalRead(Config::pin_right_button) == LOW)
  {
    m_right_button_pressed = true;
  }
  if (digitalRead(Config::pin_left_button) == LOW)
  {
    m_left_button_pressed = true;
  }
  if (digitalRead(Config::pin_center_button) == LOW)
  {
    m_center_button_pressed = true;
  }
}