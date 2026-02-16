//There are libraries?!?
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Okay I guess

//Of course I need to define the size of the screen for it
LiquidCrystal_I2C lcd(0x27, 16, 2); 

//I still be defining those pins
const int countPin = 2;
const int clearPin = 3;
const int startPin = 4;

//States and intial values
bool state = 0;

bool countState = 0;

int temp = 0;

void setup() {
  //Wakey wakey Arduino
  lcd.init();
  lcd.noBacklight();

  pinMode(countPin, INPUT_PULLUP);
  pinMode(startPin, INPUT_PULLUP);
  pinMode(clearPin, INPUT_PULLUP);
}

void loop() {
  //Flips the state to increase temp
  if(digitalRead(startPin) == LOW){
    state = !state;
    lcd.clear();
    if(state){
      lcd.backlight(); //On
    } else {
      lcd.noBacklight(); //Or off!
    }
    
    delay(300); //Bouncy Bouncy :D
  }

  if(state == true) { //Reset/Clear Pin
    if(digitalRead(clearPin) == LOW) {
      temp = 0;
      delay(100);
  }
    
  if(digitalRead(countPin) == LOW) { //Adds to the current temp
      delay(100);
      temp++;
  }


  //Makes it display :D
  lcd.setCursor(0,0);
  lcd.print("Current Temp:");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("F");
  lcd.print("    ");
  }
}
