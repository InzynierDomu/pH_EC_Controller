/**
 * @file Linear_function.cpp
 * @author by Szymon Markiewicz (https://github.com/InzynierDomu/)
 * @brief saving and loading calibration data from memory
 * @date 2022-06
 */
#include "Calibration_data_memory.h"

enum memory_map
{
  ph_calibration = 0,
  ec_calibration = 4,
  ph_min = 8,
  ec_min = 9
};

/**
 * @brief save ph calibration data
 * @param points calibration data
 */
void Calibration_data_memory::save_ph_calibration(const Point points[2])
{
  save_calibration(points, memory_map::ph_calibration);
}

/**
 * @brief save ec calibration data
 * @param points calibration data
 */
void Calibration_data_memory::save_ec_calibration(const Point points[2])
{
  save_calibration(points, memory_map::ec_calibration);
}

/**
 * @brief save ph min value for automation
 * @param value ph value
 */
void Calibration_data_memory::save_ph_min(const double value)
{
  EEPROM.put<double>(sizeof(double) * memory_map::ph_min, value);
}

/**
 * @brief save ec min value for automation
 * @param value ec value
 */
void Calibration_data_memory::save_ec_min(const double value)
{
  EEPROM.put<double>(sizeof(double) * memory_map::ec_min, value);
}

/**
 * @brief load ph calibration data
 * @param points calibration data to fill
 */
void Calibration_data_memory::load_ph_calibration(Point points[2])
{
  load_calibration(points, memory_map::ph_calibration);
}

/**
 * @brief load ec calibration data
 * @param points calibration data to fill
 */
void Calibration_data_memory::load_ec_calibration(Point points[2])
{
  load_calibration(points, memory_map::ec_calibration);
}

/**
 * @brief load ph min value for automation
 * @return min ph value
 */
double Calibration_data_memory::load_ph_min()
{
  double min_ph;
  EEPROM.get<double>(sizeof(double) * memory_map::ph_min, min_ph);
  return min_ph;
}

/**
 * @brief load ec min value for automation
 * @return min ec value
 */
double Calibration_data_memory::load_ec_min()
{
  double min_ec;
  EEPROM.get<double>(sizeof(double) * memory_map::ec_min, min_ec);
  return min_ec;
}

void Calibration_data_memory::save_calibration(const Point points[2], const uint8_t start)
{
  EEPROM.put<double>(sizeof(double) * start, points[0].analog_val);
  EEPROM.put<double>(sizeof(double) * (start + 1), points[0].unit_val);
  EEPROM.put<double>(sizeof(double) * (start + 2), points[1].analog_val);
  EEPROM.put<double>(sizeof(double) * (start + 3), points[1].unit_val);
}

void Calibration_data_memory::load_calibration(Point points[2], const uint8_t start)
{
  double analog_val;
  double unit_val;
  EEPROM.get<double>(sizeof(double) * start, analog_val);
  EEPROM.get<double>(sizeof(double) * (start + 1), unit_val);
  points[0] = Point(analog_val, unit_val);
  EEPROM.get<double>(sizeof(double) * (start + 2), analog_val);
  EEPROM.get<double>(sizeof(double) * (start + 3), unit_val);
  points[1] = Point(analog_val, unit_val);
}