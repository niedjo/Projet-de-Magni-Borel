/***************************************************
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Adafruit_Fingerprint.h>


#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
// For UNO and others without hardware serial, we must use software serial...
// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
// Set up the serial port to use softwareserial..
SoftwareSerial mySerial(2, 3);

#else
// On Leonardo/M0/etc, others with hardware serial, use hardware serial!
// #0 is green wire, #1 is white
#define mySerial Serial1

#endif


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int ledverte=13;//led verte si empreinte OK
int ledrouge=9;//led rouge si mauvaise empreinte
void setup()
{
  Serial.begin(9600);
  pinMode(ledverte,OUTPUT);//declare pin 13 comme sortie
   pinMode(ledrouge,OUTPUT);//declare pin 9 comme sortie
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit Fingerprint sensor enrollment");

  // set the data rate for the sensor serial port
  finger.begin(57600);
delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);
  finger.getTemplateCount();
  if(finger.templateCount==0){
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else{
    Serial.println("waiting for valid finger...");
    Serial.print("Sensor contains"); Serial.print(finger.templateCount); Serial.println("template");
  }
  }
 

void loop()                     // run over and over again
{
  getFingerprintID();
  delay(50);
  }
  uint8_t getFingerprintID() {
   uint8_t p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
    // Serial.println("No finger delected");
      Serial.print(".");
    return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
    }
 
  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p=finger.fingerSearch();
  if(p==FINGERPRINT_OK){
    Serial.println("Found a print match!");

    digitalWrite(ledverte,HIGH);//allume led verte
    tone(10,3000,150);
    delay(2000);
    digitalWrite(ledverte,LOW);//eteind la led verte
  }else if(p==FINGERPRINT_PACKETRECIEVEERR){
    Serial.println("communication error");
    return p;
  }else if(p==FINGERPRINT_NOTFOUND){
    Serial.println("Did not find a match");
    digitalWrite(ledrouge,HIGH);//allume led rouge
    tone(10,100,150);//active buzzer
    delay(2000);
    digitalWrite(ledrouge,LOW);//eteind la led rouge
    return p;
  }else{
    Serial.println("Unknown error");
    return p;
  }
  //found match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print("with confidence of"); Serial.println(finger.confidence);

  return finger.fingerID;
  }
//  returns -1 if failed, otherwise returns ID #
  int getFingerprintIDez(){
    uint8_t p=finger.getImage();
    if(p!=FINGERPRINT_OK) return -1;
    p=finger.image2Tz();
    if(p!=FINGERPRINT_OK) return -1;
    p=finger.fingerFastSearch();
    if(p!=FINGERPRINT_OK) return -1;

    //found a match!
    Serial.print("Found ID #"); Serial.print(finger.fingerID);
    Serial.print("with confidence of"); Serial.println(finger.confidence);
    return finger.fingerID;
  }
