#include <LiquidCrystal.h>

// entities for lcd
int Contrast = 130;
int backLight = 9;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// enteties for button
const int buttonPin = 7;   // The pin that the pushbutton is attached to
int buttonState = 0;        // Current state of the button
int buttonPushCounter = 0;   // counter for the number of button presses
int lastButtonState = 0;     // previous state of the button

// enteties for rgbLED
const int redPin = 10; //this sets the red led pin
const int bluePin = 9; //this sets the green led pin
const int greenPin = 6; //this sets the blue led pin

//enteties for lyrics
int blockCounter = 1; //Increments with each block

void setup() {
  // setup for lcd
  analogWrite(6, Contrast);
  lcd.begin(16, 2);
  analogWrite(backLight, 127);
  // setup for button
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  // setup for rgbLED
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  setColor(0, 0, 0);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, -(red-255));
  analogWrite(greenPin, -(green-255));
  analogWrite(bluePin, -(blue-255));
}

void loop() {
  buttonState = digitalRead(buttonPin);
  lcd.clear();
  lcd.setCursor(0, 0);
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
      blockCounter++;
    }
    // Delay to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  
  //Interlude
  if (buttonPushCounter == 1) {
    lcd.print("...");
  }

  // 1st Verse
  if (buttonPushCounter == 2) {
    lcd.print("Do you hear me");
  }
  if (buttonPushCounter == 3) {
    lcd.print("Do you feel");
    lcd.setCursor(0, 1);
    lcd.print("the way I do");
  }
  if (buttonPushCounter == 4) {
    setColor(255, 0, 0);
    lcd.print("for you");
    delay(500);
  }
  if (buttonPushCounter == 5) {
    lcd.print("Lost in my mind");
  }
  if (buttonPushCounter == 6) {
    lcd.print("with her");
  }
  if (buttonPushCounter == 7) {
    lcd.print("Of you my love");
  }
  if (buttonPushCounter == 8) {
    lcd.print("Words");
  }
  if (buttonPushCounter == 9) {
    lcd.print("Crumbling");
  }
  if (buttonPushCounter == 10) {
    lcd.print("Like");
  }
  if (buttonPushCounter == 11) {
    lcd.print("Cards");
  }
  if (buttonPushCounter == 12) {
    lcd.print("Crumbling like cards");
  }
  if (buttonPushCounter == 13) {
    lcd.print("Like cards");
  }
  if (buttonPushCounter == 14) {
    lcd.print("Crumbling like cards");
  }
  if (buttonPushCounter == 15) {
    lcd.print("GGWP?");
  }

  delay(30);
}

