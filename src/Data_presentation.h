/**
 * @file Data_presentation.h
 * @author by Szymon Markiewicz (https://github.com/InzynierDomu/)
 * @brief send data via serial and present on screen
 * @date 2022-06
 */
#pragma once

#include "Linear_function.h"
#include "Screen_lcd.h"

#include <stdint.h>
class Data_presentation
{
  public:
  Data_presentation();
  void init();
  void display_calib_mode();
  void display_range_mode();
  void display_save_data();
  void presentation_measurements_ph(const float temperature, const float ph, const bool relay_state);
  void presentation_measurements_ec(const float temperature, const float ec, const bool relay_state);
  void display_calibration_ph(const uint8_t sample, const float temperature);
  void display_calibration_ec(const double sample, uint8_t position, const float temperature);
  void display_change_ph_range(const double sample, uint8_t position);
  void print_ph_calibration(Point points[2]);
  void print_ec_calibration(Point points[2]);
  void print_max_ph(const double value);
  void print_max_ec(const double value);

  private:
  void print_points(Point points[2]);

  Screen_lcd m_display; ///< lcd screen
};