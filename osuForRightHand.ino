
//The used librairies
#include <Keyboard.h>

//les pins des switchs
int ButtonPin1 = 4;
int ButtonPin2 = 3;
int ButtonPin3 = 2;

//états des switchs
unsigned long ButtonState1 = 0;
unsigned long ButtonState2 = 0;
unsigned long ButtonState3 = 0;
unsigned long TimeDelay = 50000;

void setup() 
{
  pinMode(ButtonPin1, INPUT_PULLUP);
  pinMode(ButtonPin2, INPUT_PULLUP);
  pinMode(ButtonPin3, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() 
{
  ButtonState1 = !digitalRead(ButtonPin1);
  ButtonState2 = !digitalRead(ButtonPin2); 
  ButtonState3 = !digitalRead(ButtonPin3); 
  Serial.println(ButtonState2);
  Serial.println(ButtonState1);
  
  if (ButtonState1 == 1){
    Keyboard.press('i');
    ButtonState1 = micros();
  } else if (micros()-ButtonState1 >= TimeDelay ) {
    Keyboard.release('i');
  }
    
  if (ButtonState2 == 1){
    Keyboard.press('o');
    ButtonState2 = micros();
  } else if (micros()-ButtonState2 >= TimeDelay ) {
    Keyboard.release('o');
  }
  
    if (ButtonState3 == 1){
    Keyboard.press('p');
    ButtonState3 = micros();
  } else if (micros()-ButtonState3 >= TimeDelay ) {
    Keyboard.release('p');
  }
}
