/**
 * @file Buttons.cpp
 * @author by Szymon Markiewicz (https://github.com/InzynierDomu/)
 * @brief buttons handling
 * @date 2022-08
 */

#include "Buttons.h"

#include "Config.h"

/**
 * @brief buttons action reaction
 * @return Buttons_action type of action was done
 */
Buttons_action Buttons::check_buttons(const bool up_button_pressed, const bool down_button_pressed, const bool left_button_pressed,
                                      bool right_button_pressed, const bool center_button_pressed)
{
  static long buttons_start_press;
  long now = millis();

  if (now > (buttons_start_press + 200))
  {
    if (up_button_pressed)
    {
      Serial.println("u");
      return Buttons_action::up_pressed;
    }
    if (down_button_pressed)
    {
      Serial.println("d");
      return Buttons_action::down_pressed;
    }
    if (right_button_pressed)
    {
      Serial.println("r");
      return Buttons_action::right_pressed;
    }
    if (left_button_pressed)
    {
      Serial.println("l");
      return Buttons_action::left_pressed;
    }
    if (center_button_pressed)
    {
      Serial.println("c");
      return Buttons_action::center_pressed;
    }

    buttons_start_press = now;
  }

  return Buttons_action::nothing;
}

bool Buttons::check_two_buttons_long()
{
  long buttons_start_press = millis();
  do
  {
    long loop_time = millis();
    if (loop_time - buttons_start_press > Config::long_press_time)
    {
      return true;
    }
  } while (!digitalRead(Config::pin_up_button) && !digitalRead(Config::pin_down_button));
  return false;
}

bool Buttons::check_up_botton_long()
{
  long buttons_start_press = millis();
  do
  {
    long loop_time = millis();
    if (loop_time - buttons_start_press > Config::long_press_time)
    {
      return true;
    }
  } while (!digitalRead(Config::pin_up_button) && digitalRead(Config::pin_down_button));
  return false;
}