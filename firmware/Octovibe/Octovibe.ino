#include <Arduino.h>

#include "config.h"
#include "src/tcode/tcode.h"
#include "src/communication/ICommunication.h"
#include "src/communication/BLECommunication.h"
//#include "src/esp32-softap-ota/softap_ota.h"

static ICommunication* comm;

void tcode_D0() {
    comm->output("Octovibe version 0.5");
}

void tcode_D1() {
    comm->output("TCode version 0.3");
}

void tcode_D2() {
    comm->output("8 vibration axes");
}

void tcode_DSTOP() {
    digitalWrite(V0_PIN, LOW);
		digitalWrite(V1_PIN, LOW);
		digitalWrite(V2_PIN, LOW);
		digitalWrite(V3_PIN, LOW);
		digitalWrite(V4_PIN, LOW);
		digitalWrite(V5_PIN, LOW);
		digitalWrite(V6_PIN, LOW);
		digitalWrite(V7_PIN, LOW);
}

//void tcode_DUPDATE() {
//	activate_ota();
//}

struct
{
    TCodeAxis V0{"V0", 0, 0, 255};
    TCodeAxis V1{"V1", 0, 0, 255};
    TCodeAxis V2{"V2", 0, 0, 255};
    TCodeAxis V3{"V3", 0, 0, 255};
    TCodeAxis V4{"V4", 0, 0, 255};
    TCodeAxis V5{"V5", 0, 0, 255};
    TCodeAxis V6{"V6", 0, 0, 255};
    TCodeAxis V7{"V7", 0, 0, 255};
} axes;

struct {
    TCodeDeviceCommand d0{"0", &tcode_D0};
    TCodeDeviceCommand d1{"1", &tcode_D1};
		TCodeDeviceCommand d2{"2", &tcode_D2};
    TCodeDeviceCommand d_stop{"STOP", &tcode_DSTOP};
		//TCodeDeviceCommand d_update{"UPDATE", &tcode_DUPDATE};
} tcode_device_commands;

TCode tcode(reinterpret_cast<TCodeAxis *>(&axes), sizeof(axes) / sizeof(TCodeAxis),
            reinterpret_cast<TCodeDeviceCommand *>(&tcode_device_commands), sizeof(tcode_device_commands) / sizeof(TCodeDeviceCommand));


void setup()
{
	  //validate_ota();
		pinMode(DEBUG_LED, OUTPUT);
		pinMode(V0_PIN, OUTPUT);
		pinMode(V1_PIN, OUTPUT);
		pinMode(V2_PIN, OUTPUT);
		pinMode(V3_PIN, OUTPUT);
		pinMode(V4_PIN, OUTPUT);
		pinMode(V5_PIN, OUTPUT);
		pinMode(V6_PIN, OUTPUT);
		pinMode(V7_PIN, OUTPUT);
    digitalWrite(DEBUG_LED, HIGH);
    comm = new BLECommunication();
		comm->start();
}

void loop()
{
    if (comm->isOpen()){
      digitalWrite(DEBUG_LED, HIGH);
			char buffer[100];
	    if(comm->readData(buffer)){
  			uint32_t t0 = micros();
	  		tcode.parse_single_line(buffer, strlen(buffer));
				#ifdef BT_ECHO
        Serial.println(axes.V0.get_remap(t0));
				Serial.println(axes.V1.get_remap(t0));
				Serial.println(axes.V2.get_remap(t0));
				Serial.println(axes.V3.get_remap(t0));
				Serial.println(axes.V4.get_remap(t0));
				Serial.println(axes.V5.get_remap(t0));
				Serial.println(axes.V6.get_remap(t0));
				Serial.println(axes.V7.get_remap(t0));
				#endif
		  	analogWrite(V0_PIN, axes.V0.get_remap(t0));
			 	analogWrite(V1_PIN, axes.V1.get_remap(t0));
			  analogWrite(V2_PIN, axes.V2.get_remap(t0));
  			analogWrite(V3_PIN, axes.V3.get_remap(t0));
  			analogWrite(V4_PIN, axes.V4.get_remap(t0));
  			analogWrite(V5_PIN, axes.V5.get_remap(t0));
	  		analogWrite(V6_PIN, axes.V6.get_remap(t0));
		  	analogWrite(V7_PIN, axes.V7.get_remap(t0));
			}
		}
   else{
    digitalWrite(DEBUG_LED,HIGH);
    delay(1000);
    digitalWrite(DEBUG_LED,LOW);
    delay(1000);
   }
}
