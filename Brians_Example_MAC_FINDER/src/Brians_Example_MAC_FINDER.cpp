/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/owenschwab/Documents/IoT/CapStoneTesting/Brians_Example_MAC_FINDER/src/Brians_Example_MAC_FINDER.ino"
/*
 * Project BlueInTheFace2
 * Description: BLE Scanner
 * Author: Brian Rashap
 * Date: 27-MAR-2023
 */

// Create BLE Scanner Object
void setup();
void loop();
#line 9 "/Users/owenschwab/Documents/IoT/CapStoneTesting/Brians_Example_MAC_FINDER/src/Brians_Example_MAC_FINDER.ino"
const byte SCAN_RESULT_MAX = 40;
BleScanResult scanResults[SCAN_RESULT_MAX];

// Declare Variables
byte count, i,j;
byte buf[BLE_MAX_ADV_DATA_LEN];
byte mac[SCAN_RESULT_MAX][6];
int8_t rssi[SCAN_RESULT_MAX];

SYSTEM_MODE(MANUAL);

void setup() {
    Serial.begin(9600);
    waitFor(Serial.isConnected,10000);
    BLE.on();
}

void loop() {
    // Only scan for 500 milliseconds
    BLE.setScanTimeout(500);
    count = BLE.scan(scanResults, SCAN_RESULT_MAX);
    Serial.printf("%i devices found\n",count);
    for (int i = 0; i < count; i++) {
        scanResults[i].advertisingData().get(BleAdvertisingDataType::MANUFACTURER_SPECIFIC_DATA, buf, BLE_MAX_ADV_DATA_LEN);
        for(j=0;j<6;j++){
            mac[i][j] = scanResults[i].address()[j];
            rssi[i] = scanResults[i].rssi();

        }
        if(rssi[i]>-50){
        Serial.printf("%02X:%02X:%02X:%02X:%02X:%02X,%i\n",mac[i][0],mac[i][1],mac[i][2],mac[i][3],mac[i][4],mac[i][5],rssi[i]); 
        }
    }

  delay(5000);
}