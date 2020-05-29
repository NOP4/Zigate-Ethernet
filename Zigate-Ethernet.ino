/*
 * Zigate-Ethernet (Arduino & ESP8266 Wemos)
 */

//#include <SoftwareSerial.h> // Disabled for Arduino
#include <Ethernet.h>
#if defined(__AVR__)
  #include <avr/wdt.h>
#endif
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  // Set your device MAC Address. Must be unique on your network.
IPAddress ip(192,168,1,177);                          // Set your IP address. Best to pin IP address on your firewall/router.
                                                      // If not possible, choose an IP outside of DHCP range.

EthernetServer server(9999);
EthernetClient client;

#define BAUD_RATE 115200
#define BUFFER_SIZE 128
#define min(a,b) ((a)<(b)?(a):(b))

void setup(void)
{  
  #ifdef USE_WDT
    wdt_enable(1000);
  #endif

  Serial.begin(115200);
//  Serial.swap();  // Disabled for Arduino

  #if defined(ESP8266)
    WiFi.mode(WIFI_OFF);  //Disable WiFi
  #endif

  delay(500); // Give the Ethernet shield a moment to power on
  Ethernet.begin(mac, ip);  // Start Ethernet connection and web server
  delay(1000);  // Give the Ethernet shield a second to initialize
  server.begin();
}

void loop(void)
{
  yield();  //Reset WDT
  #if defined(__AVR__)
    wdt_reset(); //Reset WDT
  #endif

  size_t bytes_read;
  uint8_t net_buf[BUFFER_SIZE];
  uint8_t serial_buf[BUFFER_SIZE];
  
  // Check if a client has connected
  client = server.available();
  if (!client) {
    // No client connected, empty the buffer if necessary
    while(Serial.available()) {
      Serial.read();
    }
    return;
  }
  if(client.connected()) {
    // Check the network for any bytes to send to serial
    int count = client.available();
    if(count > 0) {      
      bytes_read = client.read(net_buf, min(count, BUFFER_SIZE));
      Serial.write(net_buf, bytes_read);
      Serial.flush();
    }
    
    // Read all serial data and send to Ethernet
    bytes_read = 0;
    while(Serial.available() && bytes_read < BUFFER_SIZE) {
      serial_buf[bytes_read] = Serial.read();
      bytes_read++;
    }
    if(bytes_read > 0) {  
      client.write((const uint8_t*)serial_buf, bytes_read);
      client.flush();
    }
  } else {
      // Disconnect
      client.stop();
  }
}
