//Matrix btn midi usb - morning conversation with oai
#include <MIDIUSB.h>

int rangee[] = {9, 8, 7, 6};
int colonne[] = {10, 11, 12, 13};
int col_scan;

void setup() {
  // Initialize MIDI communication
  MIDI.begin();
  // Set baud rate to 9600
  Serial.begin(9600);

  // Initialize pins
  for (int i = 0; i <= 3; i++) {
    pinMode(rangee[i], OUTPUT);
    pinMode(colonne[i], INPUT);
    digitalWrite(colonne[i], HIGH);
  }
  Serial.println(" Make & Play Controller its ready ");
}

void loop() {
  // Check if a button is pressed
  for (int i = 0; i <= 3; i++) {
    digitalWrite(rangee[0], HIGH);
    digitalWrite(rangee[1], HIGH);
    digitalWrite(rangee[2], HIGH);
    digitalWrite(rangee[3], HIGH);
    digitalWrite(rangee[i], LOW);
    for (int j = 0; j <= 3; j++) {
      col_scan = digitalRead(colonne[j]);
      if (col_scan == LOW) {
        // When a button is pressed, send a MIDI note on message
        MIDI.sendNoteOn(60 + (i * 4) + j, 100, 1);
        delay(300);
        // Send a MIDI note off message
        MIDI.sendNoteOff(60 + (i * 4) + j, 0, 1);
      }
    }
  }
}
"""
Ce code utilise la bibliothèque MIDIUSB pour envoyer des messages MIDI lorsque les boutons du clavier matriciel sont enfoncés. Il inclut d'abord la bibliothèque MIDIUSB en utilisant l'instruction #include <MIDIUSB.h>. Dans la fonction setup(), il initialise la communication MIDI à l'aide de la fonction MIDI.begin() et configure les broches du clavier matriciel comme dans le précédent exemple.

Dans la fonction loop(), il parcourt chaque rangée et colonne pour vérifier si un bouton est enfoncé en utilisant des boucles for. S'il y a un bouton enfoncé, il envoie un message MIDI de type Note On en utilisant la fonction MIDI.sendNoteOn(note, velocity, channel) ou MIDI.sendControlChange(control, value, channel) pour envoyer des messages de type control change, la note MIDI est calculée en utilisant l'expression 60 + (i * 4) + j, cela permet de donner une note différente pour chaque bouton. Il y a un délai de 300 ms entre chaque lecture pour éviter les rebonds.

"""