
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLOd-20fhQ"
#define BLYNK_DEVICE_NAME "LED Control"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "p701";
char pass[] = "rhust701";
char auth[] = "LQ9ZEcXKOj1JKjWU4Pwut0Pcpo25hIrR";

#define ledpin 2 
int ledstate; // trang thai den led


void setup_wifi();


BLYNK_WRITE(V0) // Gui du lieu tu Blynk xuong 
{
  ledstate = param.asInt(); // Doc du lieu duoc gui xuong
  if(ledstate == 1) digitalWrite(ledpin,HIGH);
  else digitalWrite(ledpin,LOW);
} 
void setup()
{
  Serial.begin(115200);
  pinMode(ledpin,OUTPUT); // LED o che do output
  delay(100);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

void setup_wifi(){
  Serial.begin(115200);
  Serial.print("Connecting to wifi");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
