/*Michele Piccotti 2017

This Sketch is made to run on arduino uno and nano.
It allows to display on the I2C display the opening of the sieves of a harvester via linear actuators equipped with a potentiometer.
*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x3F,16,2); //The display address is given by HHH
//Displays connected to A5 and A4 respectively SCL and SDA of I2C interface
int Val_sup =0;

/*Connections:
pin A0, A1 sensors (respectively sup e inf)
A4 -> SDA
A5 -> SSCL

An external 5v stabilizer supplies power to Arduino
*/
//Variables for internal use
int Val_inf =0;
int Ltt_sup =0;
int Ltt_inf =0;

void setup(){
  lcd.init();
  lcd.backlight();
//initialize the display and the backlight
}

void loop(){
  //Read superior data
  Ltt_sup = analogRead(A0);
  Val_sup = map(Ltt_sup,49,976,0,150);  //To calibrate, change the values
  // The first two values ​​are the ones to be modified to calibrate the sensor depth limit
  // The last two values ​​are the ones that identify the range of values ​​that are printed on video

  //Print superior data
  lcd.setCursor(0,0);
  lcd.print("Superiore ");
  lcd.print(Val_sup);
  delay(100);

  //Read inferior data
  Ltt_inf = analogRead(A1);
  Val_inf = map(Ltt_inf,49,976,0,150);// come sopra

  //Print inferior data
  lcd.setCursor(0,1);
  lcd.print("Inferiore ");
  lcd.print(Val_inf);
  delay(100);
}

