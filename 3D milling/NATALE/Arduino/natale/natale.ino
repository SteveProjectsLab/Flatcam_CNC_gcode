/*
  Arduino Christmas Songs
  
  Based on a project and code  by Dipto Pratyaksa, updated on 31/3/13

  Modified for Christmas by Joshi,  on Dec 17th, 2017.
*/

#include "pitches.h"

#define melodyPin  3

// Jingle Bells

int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

int tempo[]  = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8,  8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

// We wish you a merry Christmas

int  wish_melody[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int  wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

//  Santa Claus is coming to town

int santa_melody[] = {
  NOTE_G4,
  NOTE_E4,  NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

int  santa_tempo[] = {
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4,  4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};

int switchOne  = 0;
int switchTwo = 0;
int switchThree = 0;

void setup(void) {
  pinMode(3, OUTPUT); // Buzzer
  pinMode(13, OUTPUT); // Led indicator when  singing a note
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void all_leds_on(){
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
}

void all_leds_off(){
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}
void  loop() {
sing(1);
delay(100);
sing(2);
delay(100);
sing(3);
delay(100);
}

int song = 0;

void sing(int s) {
  // iterate over the  notes of the melody:
  song = s;
  if (song == 3) {
    Serial.println("  'We wish you a Merry Christmas'");
    int size = sizeof(wish_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      
      // to calculate  the note duration, take one second
      // divided by the note type.
      //e.g.  quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration =  1000 / wish_tempo[thisNote];

      buzz(melodyPin, wish_melody[thisNote],  noteDuration);

      // to distinguish the notes, set a minimum time between  them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes  = noteDuration * 1.30;

      delay(pauseBetweenNotes);
      
      // stop the  tone playing:
      buzz(melodyPin, 0, noteDuration);

    }
  } else  if (song == 2) {
    Serial.println(" 'Santa Claus is coming to town'");
    int size = sizeof(santa_melody) / sizeof(int);
    for (int thisNote = 0;  thisNote < size; thisNote++) {

      // to calculate the note duration, take  one second
      // divided by the note type.
      //e.g. quarter note =  1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 900 / santa_tempo[thisNote];

      buzz(melodyPin, santa_melody[thisNote], noteDuration);

      // to  distinguish the notes, set a minimum time between them.
      // the note's duration  + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin,  0, noteDuration);

    }
  } else {

    Serial.println(" 'Jingle  Bells'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote  = 0; thisNote < size; thisNote++) {

      // to calculate the note duration,  take one second
      // divided by the note type.
      //e.g. quarter note  = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

      buzz(melodyPin, melody[thisNote], noteDuration);

      // to distinguish  the notes, set a minimum time between them.
      // the note's duration + 30%  seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    }
  }
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  all_leds_on();
  long delayValue = 1000000 / frequency / 2; // calculate  the delay value between transitions
  //// 1 second's worth of microseconds,  divided by the frequency, then split in half since
  //// there are two phases  to each cycle
  long numCycles = frequency * length / 1000; // calculate the  number of cycles for proper timing
  //// multiply frequency, which is really  cycles per second, by the number of seconds to
  //// get the total number of  cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated  length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin  high to push out the diaphram
    delayMicroseconds(delayValue); // wait for  the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer  pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait  again or the calculated delay value
  }
  digitalWrite(13, LOW);
  all_leds_off();
}
