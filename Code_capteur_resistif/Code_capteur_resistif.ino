// ========= CODE CAPTEUR RESISTIF ========= //


// *********************************************************//
// *********************************************************//


// ========= Initialisation ecran OLED ========= //

#include <Adafruit_SSD1306.h>

#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);

// ========= Initialisation flex sensor ========= //

const int flexPin = A1;
const float VCC = 5;      // voltage at Arduino 5V line
const float R_DIV = 33000.0;  // resistor used to create a voltage divider
const float flatResistance = 25000.0; // resistance when flat
const float bendResistance = 100000.0; // resistance at 90 deg

// ========= Initialisation encodeur rotatoire ========= //

#define encoder0PinA  2  //CLK Output A Do not use other pin for clock as we are using interrupt
#define encoder0PinB  4  //DT Output B
#define Switch 5 // Switch connection if available

volatile unsigned int encoder0Pos = 0;

void doEncoder() {
  if (digitalRead(encoder0PinA)==HIGH && digitalRead(encoder0PinB)==HIGH) {
    encoder0Pos++;
    delay(500);
  } else if (digitalRead(encoder0PinA)==HIGH && digitalRead(encoder0PinB)==LOW) {
    encoder0Pos--;
    delay(500);
  }
}

// ========= Initialisation potentiometre digital ========= //

#include <SPI.h>

const byte csPin           = 12;      // MCP42100 chip select pin
const int  maxPositions    = 256;     // wiper can move from 0 to 255 = 256 positions
const long rAB             = 46000;   // 46k pot resistance between terminals A and B 
const byte rWiper          = 125;     // 125 ohms pot wiper resistance
const byte pot0            = 0x11;    // pot0 addr // B 0001 0001
const byte pot0Shutdown    = 0x21;    // pot0 shutdown // B 0010 0001

void setPotWiper(int addr, int pos) {
  pos = constrain(pos, 0, 255);            // limit wiper setting to range of 0 to 255
  digitalWrite(csPin, LOW);                // select chip
  SPI.transfer(addr);                      // configure target pot with wiper position
  SPI.transfer(pos);
  digitalWrite(csPin, HIGH);               // de-select chip

  long resistanceWB = ((rAB * pos) / maxPositions ) + rWiper;     // print pot resistance between wiper and B terminal
  Serial.print("Wiper position : ");
  Serial.print(pos);
  Serial.print(" Resistance wiper to B terminal : ");
  Serial.print(resistanceWB);
  Serial.println(" ohms");
}

// ========= Initialisation module bluetooth ========= //

#include <SoftwareSerial.h>
#define rxPin 10     //Broche 10 en tant que RX, a raccorder sur TX du HC05-07
#define txPin 9     //Broche 9 en tant que TX, a raccorder sur RX du HC05-07
#define baudrate 9600
SoftwareSerial mySerial(rxPin ,txPin);     //Definition du software serial


// *********************************************************//
// *********************************************************//


void setup() {
  
  Serial.begin(9600);

  // ========= Setup ecran OLED ========= //

  ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED);
  ecranOLED.setTextSize(1);
  ecranOLED.setTextColor(SSD1306_WHITE);

  // ========= Setup flex sensor ========= //

  pinMode(flexPin, INPUT);

  // ========= Setup encodeur rotatoire ========= //

  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);
  attachInterrupt(0, doEncoder, RISING);
  Serial.println("start");

  // ========= Setup potentiometre digital ========= //

  digitalWrite(csPin, HIGH);        // chip select default to de-selected
  pinMode(csPin, OUTPUT);           // configure chip select as output
  SPI.begin();
  //setPotWiper(pot0, 255);     // réglage de la valeur de resistance de R2
  //delay(500);

  // ========= Setup module bluetooth ========= //

  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
    
  mySerial.begin(baudrate);
  Serial.begin(baudrate);
}


// *********************************************************//
// *********************************************************//


void loop() {

  int sensorValue = analogRead(A0);     // on recupere la valeur de resistance du capteur graphene
  //Serial.print("Resistance_graphene : ");
  Serial.println(sensorValue);
  ecranOLED.clearDisplay();
  ecranOLED.setCursor(0, 10);
  ecranOLED.println("RESISTANCE GRAPHENE");
  ecranOLED.println(sensorValue);
  delay(500);

  int ADCflex = analogRead(flexPin);     // on recupere la valeur brute du flex sensor
  float Vflex = ADCflex * VCC / 1023.0;     // on convertit cette valeur brute en tension reelle
  float Rflex = R_DIV * (VCC / Vflex - 1.0);     // on calcule la resistance correspondante du flex sensor
  //Serial.print("Resistance_flex : ");
  Serial.println(String(Rflex) + " ohms");
  ecranOLED.println("RESISTANCE FLEXSENSOR");
  ecranOLED.println(Rflex);
  ecranOLED.display();
  delay(500);

  //Serial.print("Position : ");
  Serial.println (encoder0Pos, DEC);  //Angle = (360 / Encoder_Resolution) * encoder0Pos
  delay(500);

  mySerial.write(sensorValue/4);     // on envoie vers le module bluetooth la donnee mesuree divisee par 4 car on passe de 10 bits (1024 valeurs) a 8 bits (256 valeurs)
  mySerial.write(ADCflex/4);     // on envoie vers le module bluetooth la donnee mesuree divisee par 4 car on passe de 10 bits (1024 valeurs) a 8 bits (256 valeurs)
}
