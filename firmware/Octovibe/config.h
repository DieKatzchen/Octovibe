#ifndef CONFIG_H
#define CONFIG_H

#define DEBUG_LED LED_BUILTIN
#define BTSERIAL_DEVICE_NAME "Octovibe"
#define WIFI_SSID "Octovibe OTA Update"
//#define NEOPIXEL //Is the debug LED a NeoPixel?
//#define BT_ECHO //Should the bluetooth data be echoed over serial for debugging?
#define BLE_SERVICE_UUID "F0DAC9F0-06B0-4725-A80A-FF083A09A857"
#define BLE_RX_CHARACTERISTIC_UUID "F0DAC9F2-06B0-4725-A80A-FF083A09A857"
#define BLE_TX_CHARACTERISTIC_UUID "F0DAC9F1-06B0-4725-A80A-FF083A09A857"
#define SERIAL_BAUD_RATE 115200
#define V0_PIN D10
#define V1_PIN D9
#define V2_PIN D8
#define V3_PIN D7
#define V4_PIN D6
#define V5_PIN D5
#define V6_PIN D4
#define V7_PIN D3

#endif
