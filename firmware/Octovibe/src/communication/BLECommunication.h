#ifndef BLECOMMUNICATION_H
#define BLECOMMUNICATION_H
#include "ICommunication.h"
#include "..\..\config.h"

#include <NimBLEDevice.h>
#define   CONFIG_BT_NIMBLE_PINNED_TO_CORE   1 //Pins NimBLE to core 1

class BLECommunication : public ICommunication {
private:
    bool m_isOpen;
    NimBLEServer* pServer;
    
public:
    BLECommunication();

    bool isOpen() override;

    void start() override;
	
    void output(char* data) override;

    bool readData(char* input) override;
};

#endif