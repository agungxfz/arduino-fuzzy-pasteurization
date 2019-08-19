#include <LiquidCrystal.h>

LiquidCrystal MyLCD(2,3,4,5,6,7);
int LM35Pin = A0, temp_value, statOn = 0, myStatus = 0;
int motor = 9, heater = 8;
int button1 = 10, button2 = 11, button3 = 12, button4 = 13;
double voltage, celcius, referenceVoltage;
int buttonState_btn1 = 0, buttonState_btn2 = 0, buttonState_btn3 = 0, buttonState_btn4 = 0;
int lastButtonState = LOW;

unsigned long seconds = 1000L;
unsigned long minutes = seconds * 60;
unsigned long hours = minutes * 60;

void setup() {
  MyLCD.begin(16,2);
  pinMode(LM35Pin, INPUT);
  analogReference(INTERNAL);
  referenceVoltage = 1.1;
  
  pinMode(motor, OUTPUT);
  pinMode(heater, OUTPUT);
  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  
  MyLCD.setCursor(0,0);
  MyLCD.print(".:: WELCOME ::.");
  MyLCD.setCursor(0,1);
  MyLCD.print("Milk-Pasteurizer");
  delay(1000);
  MyLCD.clear();
  MyLCD.setCursor(0,0);
  MyLCD.print("Main Menu :");
  MyLCD.setCursor(0,1);
  MyLCD.print("1. SetMode: HTST");
  delay(2000);
  MyLCD.clear();
  MyLCD.setCursor(0,0);
  MyLCD.print("2. SetMode: LTLT");
  MyLCD.setCursor(0,1);
  MyLCD.print("3. Motor: 5 mins");
  delay(2000);
  MyLCD.clear();
  MyLCD.setCursor(0,0);
  MyLCD.print("4. Motor:10 mins");
  MyLCD.setCursor(0,1);
  MyLCD.print("Select menu...");
  delay(2000);
  MyLCD.clear();
}

void loop() {
  buttonState_btn1 = digitalRead(button1);
  buttonState_btn2 = digitalRead(button2);
  buttonState_btn3 = digitalRead(button3);
  buttonState_btn4 = digitalRead(button4);
  
  temp_value = analogRead(LM35Pin);
  celcius = (referenceVoltage *temp_value * 100) / 1023;
  
  MyLCD.setCursor(0,0);
  MyLCD.print("Suhu (C) : ");  
  MyLCD.setCursor(11,0);
  MyLCD.print(celcius, 2);
  
  if(buttonState_btn1 == LOW)
  {
    MyLCD.setCursor(0,0);
    MyLCD.print("Suhu (C) : ");  
    MyLCD.setCursor(11,0);
    MyLCD.print(celcius, 2);
    MyLCD.setCursor(0,1);
    MyLCD.print("HTST...");
    digitalWrite(heater, HIGH);
    digitalWrite(motor, HIGH);
    delay(10 * minutes);
    digitalWrite(heater, LOW);
    digitalWrite(motor, LOW);
    MyLCD.setCursor(0,1);
    MyLCD.print("Select menu...");
  }
  if(buttonState_btn2 == LOW)
  {
    MyLCD.setCursor(0,0);
    MyLCD.print("Suhu (C) : ");  
    MyLCD.setCursor(11,0);
    MyLCD.print(celcius, 2);
    MyLCD.setCursor(0,1);
    MyLCD.print("LTLT...");
    digitalWrite(heater, HIGH);
    digitalWrite(motor, HIGH);
    delay(8 * minutes);
    digitalWrite(heater, LOW);
    digitalWrite(motor, LOW);
    delay(5 * minutes);
    digitalWrite(heater, HIGH);
    digitalWrite(motor, HIGH);
    delay(5 * minutes);
    digitalWrite(heater, LOW);
    digitalWrite(motor, LOW);
    delay(5 * minutes);
    digitalWrite(heater, HIGH);
    digitalWrite(motor, HIGH);
    delay(5 * minutes);
    digitalWrite(heater, LOW);
    digitalWrite(motor, LOW);
    delay(5 * minutes);
    digitalWrite(heater, HIGH);
    digitalWrite(motor, HIGH);
    delay(5 * minutes);
    digitalWrite(heater, LOW);
    digitalWrite(motor, LOW);
    MyLCD.setCursor(0,1);
    MyLCD.print("Select menu...");
  }
  if(buttonState_btn3 == LOW)
  {
    MyLCD.setCursor(0,0);
    MyLCD.print("Suhu (C) : ");  
    MyLCD.setCursor(11,0);
    MyLCD.print(celcius, 2);
    MyLCD.setCursor(0,1);
    MyLCD.print("Motor 5...");
    digitalWrite(motor, HIGH);
    delay(5 * minutes);
    digitalWrite(motor, LOW);
    MyLCD.setCursor(0,1);
    MyLCD.print("Select menu...");
  }
  if(buttonState_btn4 == LOW)
  {
    MyLCD.setCursor(0,0);
    MyLCD.print("Suhu (C) : ");  
    MyLCD.setCursor(11,0);
    MyLCD.print(celcius, 2);
    MyLCD.setCursor(0,1);
    MyLCD.print("Motor 10...");
    digitalWrite(motor, HIGH);
    delay(10 * minutes);
    digitalWrite(motor, LOW);
    MyLCD.setCursor(0,1);
    MyLCD.print("Select menu...");
  }
}

void HTST()
{  
  if(celcius <= 71.7)
  {
    digitalWrite(motor, HIGH);
    digitalWrite(heater, HIGH);
  }
  else if(celcius > 71.7 && celcius < 75)
  {
    digitalWrite(motor, LOW);
    digitalWrite(heater, LOW);
  }
  else if(celcius > 75)
  {
    digitalWrite(motor, LOW);
    digitalWrite(heater, LOW);
  }
}

void LTLT()
{
  if(celcius <= 62.8)
  {
    digitalWrite(motor, HIGH);
    digitalWrite(heater, HIGH);
  }
  else if (celcius == 63.9)
  {
    digitalWrite(motor, LOW);
    digitalWrite(heater, LOW);
  }
  else if (celcius > 65)
  {
    digitalWrite(motor, LOW);
    digitalWrite(heater, LOW);
  }
}
