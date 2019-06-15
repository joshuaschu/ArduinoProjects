#include <LiquidCrystal.h>

int ledPin = 13;                // choose the pin for the LED
int inputPin = 24;              // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //In dieser Zeile wird festgelegt, welche Pins des Mikrocontrollerboards für das LCD verwendet wird (Am besten erstmal nicht verändern).

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);
  lcd.begin(16, 2);

   lcd.setCursor(0,0);
   lcd.print("Init");
   while( digitalRead(inputPin) == HIGH){
    Serial.println("Init");
    lcd.setCursor(0,0);
    lcd.print("Init");
    delay(1000);
  }
  lcd.clear();
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {  // check if the input is HIGH            
    digitalWrite(ledPin, HIGH);  // turn LED ON
  
    if (pirState == LOW) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Motion detected!");
      Serial.println("Motion detected!"); // print on output change
      pirState = HIGH;
    }
  } 
  else {
    digitalWrite(ledPin, LOW); // turn LED OFF
  
    if (pirState == HIGH) {
      lcd.clear();   
      lcd.setCursor(0,0);
      lcd.print("Motion ended!");
      Serial.println("Motion ended!");  // print on output change
      pirState = LOW;
    }
  }
}
