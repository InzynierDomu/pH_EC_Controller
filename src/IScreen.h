/**
 * @file IScreen.h
 * @author by Szymon Markiewicz (https://github.com/InzynierDomu/)
 * @brief Screens interface
 * @date 2022-08
 */
#pragma once

#include <Wire.h>

class IScreen
{
  public:
  ~IScreen() {}
  virtual void startup() = 0;
  virtual void calib_mode() = 0;
  virtual void range_mode() = 0;
  virtual void save_data() = 0;
  virtual void measurements_ph(const float temperature, const float ph, const bool relay_state) = 0;
  virtual void measurements_ec(const float temperature, const float ec, const bool relay_state) = 0;
  virtual void calibration_ph(const uint8_t sample, const float temperature) = 0;
  virtual void calibration_ec(const double sample, uint8_t position, const float temperature) = 0;
};
