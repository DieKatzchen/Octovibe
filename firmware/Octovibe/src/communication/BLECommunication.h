#ifndef BLECOMMUNICATION_H
#define BLECOMMUNICATION_H
#include "ICommunication.h"
#include "..\..\config.h"

#include <NimBLEDevice.h>
#define   CONFIG_BT_NIMBLE_PINNED_TO_CORE   1 //Pins NimBLE to core 1

#ifndef BLE_SERVICE_UUID
#define BLE_SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#endif

#ifndef BLE_RX_CHARACTERISTIC_UUID
#define BLE_RX_CHARACTERISTIC_UUID "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#endif

#ifndef BLE_TX_CHARACTERISTIC_UUID
#define BLE_TX_CHARACTERISTIC_UUID "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"
#endif

class BLECommunication : public ICommunication {
private:
    //bool m_isOpen;
    NimBLEServer* pServer;
    
public:
    BLECommunication();

    bool isOpen() override;

    void start() override;
	
    void output(char* data) override;

    bool readData(char* input) override;
};

#endif