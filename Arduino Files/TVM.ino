#include <SPI.h>
#include <MFRC522.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>
#include "webpageCode.h";
#include "Accepted.h";
#include "Rejected.h";
#include "Service.h";
#define debug

//----------Web Server & Mqtt--------------------
ESP8266WebServer server(80);

const char* ssid = "TVM"; //SSID
const char* password = "password123"; //WiFi password

const char* mqtt_server = "broker.mqtt-dashboard.com";
const char* outTopic = "TVM/out";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char text[MSG_BUFFER_SIZE];

//--------------RFID---------------------
constexpr uint8_t RST_PIN = D3;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;     // Configurable, see typical pin layout above

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;

String tag;
String Service_tag = "55189167180";
//--------------Var---------------------
int coke, pepsi, sprite, refill;
#define c 15
#define p 4
#define s 5
#define r 2
//--------------Functions---------------------
void webpage() {
  server.send(200, "text/html", webpageCode);
}
void accepted() {
  server.send(200, "text/html", Accepted);
}

void rejected() {
  server.send(200, "text/html", Rejected);
}
void service() {
  server.send(200, "text/html", Service);
}

void Coke() {
  pinMode(16, OUTPUT);
  digitalWrite(16, HIGH);
  delay(1000);
  RFid_Check(1);
  delay(1000);
  
  //server.send(200, "text/html", Accepted);
}

void Pepsi() {
  pinMode(16, OUTPUT);
  digitalWrite(16, HIGH);
  delay(1000);
  RFid_Check(2);
  delay(1000);
  //server.send(200, "text/html", webpageCode);
}

void Sprite() {
  pinMode(16, OUTPUT);
  digitalWrite(16, HIGH);
  delay(1000);
  RFid_Check(3);
  delay(1000);
  //server.send(200, "text/html", webpageCode); 
}

void Refill() {
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  delay(1000);
  RFid_Check(0);
  delay(1000);
  //server.send(200, "text/html", webpageCode);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
#ifdef debug
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
#endif
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
#ifdef debug
    Serial.print(".");
#endif
  }

  randomSeed(micros());
#ifdef debug
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
#endif

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
#ifdef debug
    Serial.print("Attempting MQTT connection...");
#endif


    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
#ifdef debug
      Serial.println("connected");
#endif


    } else {
#ifdef debug
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
#endif

      // Wait 5 seconds before retrying
      delay(1000);
    }
  }
}

void mqtt(const char* text) {
  client.setServer(mqtt_server, 1883);
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  client.publish(outTopic, text);
#ifdef debug
  Serial.print("Publish message: ");
  Serial.println(text);
#endif

  delay(2000);
}



void RFid_Check(int bev) {

  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
#ifdef debug
    Serial.print("tag ");
    Serial.println(tag);
#endif


    if (bev == 1) {

      coke -= 1;
      refill = 0;
      snprintf (text, MSG_BUFFER_SIZE, "{\"coke\":%ld, \"sprite\":%ld, \"pepsi\":%ld, \"refill\":%ld}", coke, sprite, pepsi, refill);
      accepted() ;
      mqtt(text);
      //actuators for coke 
      digitalWrite(c, HIGH);
      delay(1000);
      digitalWrite(c, LOW);
    }
    else if (bev == 2) {

      pepsi -= 1;
      refill = 0;
      snprintf (text, MSG_BUFFER_SIZE, "{\"coke\":%ld, \"sprite\":%ld, \"pepsi\":%ld, \"refill\":%ld}", coke, sprite, pepsi, refill);
      accepted() ;
      mqtt(text);
      //actuators for pepsi
      digitalWrite(p, HIGH);
      delay(1000);
      digitalWrite(p, LOW);
    }
    else if (bev == 3) {

      sprite -= 1;
      refill = 0;
      snprintf (text, MSG_BUFFER_SIZE, "{\"coke\":%ld, \"sprite\":%ld, \"pepsi\":%ld, \"refill\":%ld}", coke, sprite, pepsi, refill);
      accepted() ;
      mqtt(text);
      //actuators for sprie
      digitalWrite(s, HIGH);
      delay(1000);
      digitalWrite(s, LOW);
    }
    else if (bev == 0) {
      if (tag == Service_tag) {

        coke = 30;
        pepsi = 30;
        sprite = 30;
        refill = 1;
        snprintf (text, MSG_BUFFER_SIZE, "{\"coke\":%ld, \"sprite\":%ld, \"pepsi\":%ld, \"refill\":%ld}", coke, sprite, pepsi, refill);
        
        //actuators for service purposes
        digitalWrite(r, HIGH);
        delay(1000);
        digitalWrite(r, LOW);

        service() ;
        mqtt(text);
      }
      else {}
      rejected() ;
      delay(1000);
    }



  }
  tag = "";

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  delay(500);
}


//------------------------------------------

void setup() {
  Serial.begin(115200);
  setup_wifi();

  server.on("/", webpage);
  server.on("/0", Refill);
  server.on("/1", Coke);
  server.on("/2", Pepsi);
  server.on("/3", Sprite);
  server.on("/1/#1", webpage);
  server.begin();

  pinMode(c, OUTPUT);
  pinMode(p, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(r, OUTPUT);

  digitalWrite(c, LOW);
  digitalWrite(p, LOW);
  digitalWrite(s, LOW);
  digitalWrite(r, LOW);

  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  pinMode(D8, OUTPUT);

}

//------------------------------------------

void loop()
{
  server.handleClient();
}
