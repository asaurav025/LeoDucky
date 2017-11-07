//Changes wallpaper in a linux machine by dowloading file form other computer

#include <Keyboard.h>

const int buttonPin = 4;
int previousButtonState = HIGH;
//int counter = 0;
int flag = HIGH;
void setup() {
  delay(2000);
  pinMode(buttonPin, INPUT);
  Keyboard.begin();
}

void loop() {
  // If you add a Switch
//  int buttonState = digitalRead(buttonPin);
//  if ((buttonState != previousButtonState) && (buttonState == HIGH)){
//    
//    
//  }
//
//  previousButtonState = buttonState

// For one time run
  if(flag == HIGH){
  // Opens Terminal
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      delay(500);
      Keyboard.releaseAll();
  // Go to Desktop directory and Download a image file from a server hosted on lan
      Keyboard.print("cd Desktop/");
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      Keyboard.print("wget http://192.168.0.19/tst/img.jpg");
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      delay(500);
  // Opens up image  on Eye of Gnome
      Keyboard.print("eog img.jpg");
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      delay(1000);
  //sets up wallpaper
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_F8);
      delay(500);
      
      Keyboard.releaseAll();
  // move current screen to Desktop
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('d');
      Keyboard.releaseAll();
  // IMPORTANT: set flag to low to avoid infinite loop
      flag = LOW;
      
  }
}
