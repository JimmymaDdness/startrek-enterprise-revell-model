/*===================================== USS ENTERPRISE NCC-1701 ARDUINO SKETCH ===========================================================================
 * This sketch was written to control light and sound effects of the USS Enterprise NCC-1701 (Revell - 1:600) model.
 * Please note there are several ways to achieve the same effects or even different ones. This sketch was written as best suited to the author's needs. 
 * Authors: JimmymaDdness edited Guilherme Negrini & Luísa Lucchese
 */


#include <LedFlasher.h>
#include <LedFader.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
 
SoftwareSerial DFPlayerSerial(10, 11); // RX, TX



//Sounds
/*
 * 0001_opening.mp3 > 60s (1min)
 * 0002_bridge.mp3 > 870s (14min30s)
 * 0003_redalert.mp3 > 33s
 * 0004_phasers.mp3 > 30s
 * 0005_torpedoes.mp3 > 4s
 */


//Button's pins
const int button_theme1 = 14;
const int button_theme = 15;
const int button_bridge = 16;
const int button_alert = 17;
const int button_firing = 18;
const int button_mute = 19;
//const int button_mute = 20;


// set up some LEDs
//                        pin  min max  millis
LedFlasher floodLight       (8, 200, 300);
LedFlasher shuttleBayDoors  (9, 300, 600);
LedFlasher impulseEngine    (10, 900, 100);
LedFlasher strobe           (11, 500, 1000);
LedFlasher navigation       (12, 1000, 2000);
LedFlasher torpedoes        (13, 250, 500);


//Button's variables
int button_theme1_state = 0;
int button_theme_state = 0;
int button_bridge_state = 0;
int button_alert_state = 0;
int button_firing_state = 0;
int button_mute_state = 0;



//Functions called when buttons are pressed


void ThemeSound1(){
  button_theme1_state = digitalRead(button_theme1);   //reads button state
  if (button_theme1_state == LOW){                   //if pressed
    mp3_stop();                                     //stops previous sound
    //mp3_set_volume(30);                             //sets volume
    mp3_play(1);                                    //play sound
  }

}
void ThemeSound(){
  button_theme_state = digitalRead(button_theme);   //reads button state
  if (button_theme_state == LOW){                   //if pressed
    mp3_stop();                                     //stops previous sound
    //mp3_set_volume(30);                             //sets volume
    mp3_play(2);                                    //play sound
  }
  
}

void BridgeSound(){
  button_bridge_state = digitalRead(button_bridge);
  if (button_bridge_state == LOW){
    mp3_stop();
    //mp3_set_volume(30);  
    mp3_play(3);
  }
  
}

void AlertSound(){
  button_alert_state = digitalRead(button_alert);
  if (button_alert_state == LOW){
    mp3_stop();
    //mp3_set_volume(30);   
    mp3_play(4);
  }
  
}

void FiringMode(){
  button_firing_state = digitalRead(button_firing);
  if (button_firing_state == LOW){
     mp3_stop();
     //mp3_set_volume(30);
     mp3_play(5);
     
  }
}

void MuteMode()
{
  button_mute_state = digitalRead(button_mute);
  if (button_mute_state == LOW){
    mp3_stop();
  }
}

void setup() {
  // Set button pins as input
  pinMode (button_theme1, INPUT_PULLUP);
  pinMode (button_theme, INPUT_PULLUP);
  pinMode (button_bridge, INPUT_PULLUP);
  pinMode (button_alert, INPUT_PULLUP);
  pinMode (button_firing, INPUT_PULLUP);
  pinMode (button_mute, INPUT_PULLUP);
  floodLight.begin ();
  shuttleBayDoors.begin ();
  impulseEngine.begin ();
  strobe.begin ();
  navigation.begin ();
  torpedoes.begin ();
  
   //Set configuration of DFPlayer mini
  Serial.begin(9600);
  DFPlayerSerial.begin(9600);
  mp3_set_serial(DFPlayerSerial);
  mp3_set_volume (30);
}

void loop() {

  ThemeSound1();
  ThemeSound();
  BridgeSound();
  AlertSound();
  FiringMode();
  MuteMode();
  floodLight.update ();
  shuttleBayDoors.update ();
  impulseEngine.update ();
  strobe.update ();
  navigation.update ();
  torpedoes.update ();
}
