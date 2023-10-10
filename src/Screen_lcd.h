/**
 * @file Screen_lcd.h
 * @author by Szymon Markiewicz (https://github.com/InzynierDomu/)
 * @brief 16x2 lcd Screen
 * @date 2022-08
 */
#pragma once

#include "Config.h"
#include "IScreen.h"
#include "LiquidCrystal_I2C.h"

class Screen_lcd : public IScreen
{
  public:
  Screen_lcd();
  void startup() override;
  void calib_mode() override;
  void range_mode() override;
  void save_data() override;
  void measurements_ph(const float temperature, const float ph, const bool relay_state) override;
  void measurements_ec(const float temperature, const float ec, const bool relay_state) override;
  void calibration_ph(const uint8_t sample, const float temperature) override;
  void calibration_ec(const double sample, uint8_t position, const float temperature) override;
  void change_ph_range(const double value, uint8_t position);
  void change_ec_range(const double value, uint8_t position);
  void fill_ph();
  void fill_ec();

  private:
  LiquidCrystal_I2C m_display; ///< HD44780 via PCF8574
};