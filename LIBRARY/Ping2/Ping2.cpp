/*
 Ping2.cpp - Library for using Ping2))) Sensors with Arduino - Version 2
 Copyright (c) 2009 Caleb Zulawski.  All right reserved.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "WProgram.h"
#include "Ping2.h"

Ping2::Ping2(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _in = 0;
  _cm = 0;
  _duration = -1;
}
Ping2::Ping2(int pin, double in, double cm)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _in = in;
  _cm = cm;
  _duration = -1;
}

void Ping2::fire()
{
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(_pin, LOW);
  pinMode(_pin, INPUT);
  // Modification to not use the 1 second default
  _duration = pulseIn(_pin, HIGH, 5000);
  
}

int Ping2::microseconds()
{
  return _duration;
}

double Ping2::inches()
{
  if(_duration != -1){
    return _duration / (74+_in) / 2;
  }else{
    return -1;
  }
}

double Ping2::centimeters()
{
  if(_duration != -1){
    return _duration / (29+_cm) / 2;
  }else{
    return -1;
  }
}