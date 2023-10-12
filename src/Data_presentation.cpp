/**
 * @file Data_presentation.cpp
 * @author by Szymon Markiewicz (https://github.com/InzynierDomu/)
 * @brief send data via serial and present on screen
 * @date 2022-06
 */
#include "Data_presentation.h"

#include "Config.h"

#include <Arduino.h>
#include <math.h>

/**
 * @brief Construct a new Data_presentation::Data_presentation object
 */
Data_presentation::Data_presentation()
: m_display()
{}

/**
 * @brief startup screen
 */
void Data_presentation::init()
{
  Serial.begin(9600);

  m_display.startup();
  delay(1000);
}

/**
 * @brief calibration mode info screen
 */
void Data_presentation::display_calib_mode()
{
  m_display.calib_mode();
  delay(500);
}

/**
 * @brief change range mode info screen
 */
void Data_presentation::display_range_mode()
{
  m_display.range_mode();
  delay(500);
}

/**
 * @brief save point info screen
 */
void Data_presentation::display_save_data()
{
  m_display.save_data();
  delay(500);
}

/**
 * @brief send ph and temperature and print on screen
 * @param temperature: temperature value to send and print
 * @param ph: ph value to send and print
 */
void Data_presentation::presentation_measurements_ph(const float temperature, const float ph, const bool relay_state)
{
  Serial.print("temperature:");
  Serial.print(temperature);
  Serial.print("'C ;pH:");
  Serial.print(ph);
  Serial.print("; relay:");
  Serial.println(relay_state);

  m_display.measurements_ph(temperature, ph, relay_state);
}

/**
 * @brief send ec and temperature and print on screen
 * @param temperature: temperature value to send and print
 * @param ph: ec value to send and print
 */
void Data_presentation::presentation_measurements_ec(const float temperature, const float ec, const bool relay_state)
{
  Serial.print("temperature:");
  Serial.print(temperature);
  Serial.print("'C ;EC:");
  Serial.print(ec);
  Serial.print("; relay:");
  Serial.println(relay_state);

  m_display.measurements_ec(temperature, ec, relay_state);
}

/**
 * @brief ph calibration screen
 * @param sample: ph value current calibrating
 * @param temperature: current temperature
 */
void Data_presentation::display_calibration_ph(const uint8_t sample, const float temperature)
{
  m_display.calibration_ph(sample, temperature);
}

/**
 * @brief ec calibration screen
 * @param sample: ec value current calibrating
 * @param position: toggling digit position
 * @param temperature: current temperature
 */
void Data_presentation::display_calibration_ec(const double sample, uint8_t position, const float temperature)
{
  m_display.calibration_ec(sample, position, temperature);
}

/**
 * @brief ph calibration screen
 * @param sample: ph value current calibrating
 * @param position: toggling digit position
 */
void Data_presentation::display_change_ph_range(const double sample, uint8_t position)
{
  m_display.change_ph_range(sample, position);
}

/**
 * @brief print on serial port ph calibration points
 * @param points calibration points
 */
void Data_presentation::print_ph_calibration(Point points[2])
{
  Serial.print("pH :");
  print_points(points);
}

/**
 * @brief print on serial port ec calibration points
 * @param points calibration points
 */
void Data_presentation::print_ec_calibration(Point points[2])
{
  Serial.print("EC :");
  print_points(points);
}

/**
 * @brief print max ph value for automation
 * @param value max ph value
 */
void Data_presentation::print_max_ph(const double value)
{
  Serial.print("max ph:");
  Serial.println(value);
}

/**
 * @brief print max ec value for automation
 * @param value max ec value
 */
void Data_presentation::print_max_ec(const double value)
{
  Serial.print("max ec:");
  Serial.println(value);
}

void Data_presentation::print_points(Point points[2])
{
  Serial.print("analog_val 1:");
  Serial.print(points[0].analog_val);
  Serial.print(" unit_val 1:");
  Serial.print(points[0].unit_val);
  Serial.print(" analog_val 2:");
  Serial.print(points[1].analog_val);
  Serial.print(" unit_val 2:");
  Serial.println(points[1].unit_val);
}
