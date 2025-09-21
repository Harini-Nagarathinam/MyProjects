#include <TM1637Display.h>
#include <Blynk.h>

char auth[] = "AUTH";
char ssid[] = "SSID";
char pass[] = "PASSWORD";

#define CLK 22
#define DIO 21

TM1637Display display(CLK, DIO);
uint8_t blank[] = { 0x0, 0x0, 0x0, 0x0 };
int c[2];

volatile bool nopen_flag = false;  // moved heavy ISR work to loop via this flag

void IRAM_ATTR Nopen_ISR() {
  nopen_flag = true;  // set flag only; do long work in loop()
}

void setup() {
  // configure the output pins
  Serial.begin(115200);

  pinMode(34, INPUT);
  attachInterrupt(digitalPinToInterrupt(34), Nopen_ISR, RISING);

  pinMode(4, OUTPUT);   // NR
  pinMode(0, OUTPUT);   // Ny
  pinMode(2, OUTPUT);   // Ng
  pinMode(19, OUTPUT);  // sr
  pinMode(18, OUTPUT);  // sy
  pinMode(5, OUTPUT);   // Sg
  pinMode(14, OUTPUT);  // er
  pinMode(12, OUTPUT);  // ey
  pinMode(13, OUTPUT);  // eg
  pinMode(25, OUTPUT);  // wr
  pinMode(26, OUTPUT);  // wy
  pinMode(27, OUTPUT);  // wg

  display.setBrightness(0x0f);  // set brightness of display
  uint8_t data8888[] = { 0xff, 0xff, 0xff, 0xff };  // all segments show
  display.setSegments(data8888);                    // display 8888 for test
  delay(3000);                                      // time to read the display
  display.setSegments(blank);                       // clear
  display.showNumberDec(0);
}

void loop() {
  // handle what used to be inside the ISR (long/timed work) safely here
  if (nopen_flag) {
    nopen_flag = false;

    if (c[0] == 13 || c[0] == 0) {
      digitalWrite(4, 0);  // enables the 2nd set of signals
      digitalWrite(19, 0);
      digitalWrite(13, 0);
      digitalWrite(27, 0);
      digitalWrite(0, 0);
      digitalWrite(18, 0);
      digitalWrite(12, 0);
      digitalWrite(26, 0);
      digitalWrite(0, 1);
      digitalWrite(12, 1);
      digitalWrite(26, 1);
      for (int i = 5; i >= 0; i--) {
        display.setSegments(blank);  // clear the screen from previous values
        display.showNumberDec(i * 100 + i);
        delay(987);
      }
      digitalWrite(2, 1);
      digitalWrite(0, 0);
      digitalWrite(12, 0);
      digitalWrite(26, 0);
      for (int i = 30; i >= 0; i--) {
        display.setSegments(blank);  // clear the screen from previous values
        display.showNumberDec(i * 100);
        delay(993);
      }
    }
  }

  // your original loop body (unchanged except printf fixes)
  // Serial.printf(digitalRead(34));  // (commented in your code)

  digitalWrite(4, 1);  // enables the 1st set of signals
  digitalWrite(19, 1);
  digitalWrite(13, 1);
  digitalWrite(27, 1);
  digitalWrite(0, 0);
  digitalWrite(18, 0);
  digitalWrite(12, 0);
  digitalWrite(26, 0);
  c[0] = 13;
  for (int i = 45; i >= 0; i--) {
    display.setSegments(blank);
    display.showNumberDec(i * 100 + i);
    delay(993);
  }

  Serial.printf("2. %d\n", digitalRead(34));

  digitalWrite(4, 0);  // enables the 2nd set of signals
  digitalWrite(19, 0);
  digitalWrite(13, 0);
  digitalWrite(27, 0);
  digitalWrite(0, 1);
  digitalWrite(18, 1);
  digitalWrite(12, 1);
  digitalWrite(26, 1);
  c[0] = 0;
  for (int i = 5; i >= 0; i--) {
    display.setSegments(blank);
    display.showNumberDec(i * 100 + i);
    delay(993);
  }

  Serial.printf("3. %d\n", digitalRead(34));

  digitalWrite(2, 1);  // enables the 3rs set of signals
  digitalWrite(5, 1);
  digitalWrite(14, 1);
  digitalWrite(25, 1);
  digitalWrite(0, 0);
  digitalWrite(18, 0);
  digitalWrite(12, 0);
  digitalWrite(26, 0);
  c[0] = 2;
  for (int i = 45; i >= 0; i--) {
    display.setSegments(blank);
    display.showNumberDec(i * 100 + i);
    delay(993);
  }

  Serial.printf("4. %d\n", digitalRead(34));

  digitalWrite(2, 0);  // enables the 4th set of signals
  digitalWrite(5, 0);
  digitalWrite(14, 0);
  digitalWrite(25, 0);
  digitalWrite(0, 1);
  digitalWrite(18, 1);
  digitalWrite(12, 1);
  digitalWrite(26, 1);
  c[0] = 0;
  for (int i = 5; i >= 0; i--) {
    display.setSegments(blank);
    display.showNumberDec(i * 100 + i);
    delay(993);
  }

  Serial.printf("5'. %d\n", digitalRead(34));
}
