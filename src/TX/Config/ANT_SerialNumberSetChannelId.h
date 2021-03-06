#ifndef ANT_SERIALNUMBERSETCHANNELID_h
#define ANT_SERIALNUMBERSETCHANNELID_h

#include <TX/ANT_AntRequest.h>

/**
 * Represents a serial number set channel id message
 *
 * used to configure a radio to use a devices serial number
 */
class SerialNumberSetChannelId : public AntRequest {
public:
    SerialNumberSetChannelId();
    SerialNumberSetChannelId(uint8_t channel);
    void setChannel(uint8_t channel);
    void setDeviceType(uint8_t deviceType);
    void setPairingBit(bool paringBit);
    void setTransmissionType(uint8_t transmissionType);
    uint8_t getChannel();
    uint8_t getDeviceType();
    bool getPairingBit();
    uint8_t getTransmissionType();
    uint8_t getData(uint8_t pos);
    uint8_t getDataLength();
#ifdef NATIVE_API_AVAILABLE
    uint8_t execute();
#endif // NATIVE_API_AVAILABLE
private:
    uint8_t _channel;
    uint8_t _deviceType;
    // TODO figure out default for pairing bit, assuming false
    bool _pairingBit = false;
    uint8_t _transmissionType = 0;
};

#endif // ANT_SERIALNUMBERSETCHANNELID_h