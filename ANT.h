/**
 * Copyright (c) 2009 Andrew Rapp. All rights reserved.
 * Update by Copyright (c) 2016 Curtis Malainey
 *
 * This file is part of Ant-Arduino.
 *
 * Ant-Arduino is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Ant-Arduino is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRAntY; without even the implied warranty of
 * MERCHAntABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Ant-Arduino.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ANT_h
#define ANT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <inttypes.h>

#define START_BYTE 0xA4

// This value is determined by the largest message size available
#define MAX_FRAME_DATA_SIZE 20

// start/length/msg/checksum bytes
#define PACKET_OVERHEAD_LENGTH 4
// msg is always the third byte in packet
#define MSG_ID_INDEX 3

// not everything is implemented!
/**
 * Msg Id constants
 */
// Config Messages
#define UNASSIGN_CHANNEL                    0x41
#define ASSIGN_CHANNEL                      0x42
#define CHANNEL_ID                          0x51
#define CHANNEL_PERIOD                      0x43
#define SEARCH_TIMEOUT                      0x44
#define CHANNEL_RF_FREQUENCY                0x45
#define SET_NETWORK_KEY                     0x46
#define TRANSMIT_POWER                      0x47
#define SEARCH_WAVEFORM                     0x49
#define ADD_CHANNEL_ID_TO_LIST              0x59
#define ADD_ENCRYPTION_ID_TO_LIST           0x59
#define CONFIG_ID_LIST                      0x5A
#define CONFIG_ENCRYPTION_ID_LIST           0x5A
#define SET_CHANNEL_TRANSMIT_POWER          0x60
#define LOW_PRIORITY_SEARCH_TIMEOUT         0x63
#define SERIAL_NUMBER_SET_CHANNEL_ID        0x65
#define ENABLE_EXT_RX_MESSAGES              0x66
// #define ENABLE_LED                          0x68
// #define CRYSTAL_ENABLE                      0x6D
#define LIB_CONFIG                          0x6E
#define FREQUENCY_AGILITY                   0x70
#define PROXIMITY_SEARCH                    0x71
// #define CONFIGURE_BUFFER_EVENT              0x74
#define CHANNEL_SEARCH_PRIORITY             0x75
// #define SET_128BIT_NETWORK_KEY              0x76
// #define HIGH_DUTY_SEARCH                    0x77
#define CONFIGURE_ADVANCED_BURST            0x78
#define CONFIGURE_EVENT_FILTER              0x79
#define CONFIGURE_SELECTIVE_DATA_UPDATES    0x7A
#define SET_SELECTIVE_DATA_UPDATE_MASK      0x7B
// #define CONFIGURE_USER_NVM                  0x7C
#define ENABLE_SINGLE_CHANNEL_ENCRYPTION    0x7D
#define SET_ENCRYPTION_KEY                  0x7E
#define SET_ENCRYPTION_INFO                 0x7F
#define CHANNEL_SEARCH_SHARING              0x81
// #define LOAD_STORE_ENCRYPTION_KEY           0x83
// #define SET_USB_DESCRIPTOR_STRING           0xC7
// Notification Messages
#define START_UP_MESSAGE                    0x6F
// #define SERIAL_ERROR_MESSAGE                0xAE
// Control Messages
#define RESET_SYSTEM                        0x4A
#define OPEN_CHANNEL                        0x4B
#define CLOSE_CHANNEL                       0x4C
#define REQUEST_MESSAGE                     0x4D
#define OPEN_RX_SCAN_MODE                   0x5B
// #define SLEEP_MESSAGE                       0xC5
// Data Messages
#define BROADCAST_DATA                      0x4E
#define ACKNOWLEDGED_DATA                   0x4F
#define BURST_DATA_TRANSFER                 0x50
#define ADVANCED_BURST_DATA                 0x72
// Channel Messages
#define CHANNEL_EVENT                       0x40
#define CHANNEL_RESPONSE                    0x40
// Requested Response Messages
#define CHANNEL_STATUS                      0x52
#define CHANNEL_ID                          0x51
#define ANT_VERSION                         0x3E
#define CAPABILITIES                        0x54
// #define SERIAL_NUMBER                       0x61
// #define EVENT_BUFFER_CONFIGURATION          0x74
#define ADVANCED_BURST_CAPABILITES          0x78
#define ADVANCED_BURST_CONFIGURATION        0x78
#define EVENT_FILTER                        0x79
#define SELECTIVE_DATA_UPDATE_MASK_SETTING  0x7B
// #define USER_NVM                            0x7C
#define ENCRYPTION_MODE_PARAMETERS          0x7D
// Test Mode Messages
#define CW_INIT                             0x53
#define CW_TEST                             0x48
// Extended Data Messages (Legacy)
#define EXTENDED_BROADCAST_DATA             0x5D
#define EXTENDED_ACKNOWLEDGED_DATA          0x5E
#define EXTENDED_BURST_DATA                 0x5F

/**
 * Channel Response Message Codes
 */
#define	RESPONSE_NO_ERROR               0x00
#define EVENT_RX_SEARCH_TIMEOUT         0x01
#define EVENT_RX_FAIL                   0x02
#define EVENT_TX                        0x03
#define EVENT_TRANSFER_RX_FAILED        0x04
#define EVENT_TRANSFER_TX_COMPLETED     0x05
#define EVENT_TRANSFER_TX_FAILED        0x06
#define EVENT_CHANNEL_CLOSED            0x07
#define EVENT_RX_FAIL_GO_TO_SEARCH      0x08
#define EVENT_CHANNEL_COLLISION         0x09
#define EVENT_TRANSFER_TX_START         0x0A
#define EVENT_TRANSFER_NEXT_DATA_BLOCK  0x11
#define CHANNEL_IN_WRONG_STATE          0x15
#define CHANNEL_NOT_OPENED              0x16
#define CHANNEL_ID_NOT_SET              0x18
#define CLOSE_ALL_CHANNELS              0x19
#define TRANSFER_IN_PROGRESS            0x1F
#define TRANSFER_SEQUENCE_NUMBER_ERROR  0x20
#define TRANSFER_IN_ERROR               0x21
#define MESSAGE_SIZE_EXCEEDS_LIMIT      0x27
#define INVALID_MESSAGE                 0x28
#define INVALID_NETWORK_NUMBER          0x29
#define INVALID_LIST_ID                 0x30
#define INVALID_SCAN_TX_CHANNEL         0x31
#define INVALID_PARAMETER_PROVIDED      0x33
#define EVENT_SERIAL_QUE_OVERFLOW       0x34
#define EVENT_QUE_OVERFLOW              0x35
#define ENCRYPT_NEGOTIATION_SUCCESS     0x38
#define ENCRYPT_NEGOTIATION_FAIL        0x39
#define NVM_FULL_ERROR                  0x40
#define NVM_WRITE_ERROR                 0x41
#define USB_STRING_WRITE_FAIL           0x70
#define MESG_SERIAL_ERROR_ID            0xAE

// Start Up Message Codes
#define POWER_ON_RESET       0x00
#define HARDWARE_RESET_LINE  ( 1 << 0 )
#define WATCH_DOG_RESET      ( 1 << 1 )
#define COMMAND_RESET        ( 1 << 5 )
#define SYNCHRONOUS_RESET    ( 1 << 6 )
#define SUSPEND_RESET        ( 1 << 7 )

#define NO_ERROR                          0
#define CHECKSUM_FAILURE                  1
#define PACKET_EXCEEDS_BYTE_ARRAY_LENGTH  2
#define UNEXPECTED_START_BYTE             3

/**
 * C++11 introduced the constexpr as a hint to the compiler that things
 * can be evaluated at compiletime. This can help to remove
 * startup code for global objects, or otherwise help the compiler to
 * optimize. Since the keyword is introduced in C++11, but supporting
 * older compilers is a matter of removing the keyword, we use a macro
 * for this.
 */
#if __cplusplus >= 201103L
#define CONSTEXPR constexpr
#else
#define CONSTEXPR
#endif

/**
 * The super class of all Ant responses (RX packets)
 * Users should never attempt to create an instance of this class; instead
 * create an instance of a subclass
 * It is recommend to reuse subclasses to conserve memory
 */
class AntResponse {
	public:
		//static const int MODEM_STATUS = 0x8a;
		/**
		 * Default constructor
		 */
		AntResponse();
		/**
		 * Returns msg Id of the response
		 */
		uint8_t getMsgId();
		void setMsgId(uint8_t msgId);
		/**
		 * Returns the MSB length of the packet
		 */
		uint8_t getLength();
		void setLength(uint8_t length);
		/**
		 * Returns the packet checksum
		 */
		uint8_t getChecksum();
		void setChecksum(uint8_t checksum);
		/**
		 * Returns the length of the frame data: all bytes after the msg id, and prior to the checksum
		 * Note up to release 0.1.2, this was incorrectly including the checksum in the length.
		 */
		uint8_t getFrameDataLength();
		void setFrameData(uint8_t* frameDataPtr);
		/**
		 * Returns the buffer that contains the response.
		 * Starts with byte that follows MSG ID and includes all bytes prior to the checksum
		 * Length is specified by getFrameDataLength()
		 * Note: Unlike Dynasteam's definition of the frame data, this does not start with the MSG ID..
		 * The reason for this is all responses include an MSG ID, whereas my frame data
		 * includes only the MSG specific data.
		 */
		uint8_t* getFrameData();

		void setFrameLength(uint8_t frameLength);
		/**
		 * Returns the length of the packet
		 */
		uint16_t getPacketLength();
		/**
		 * Resets the response to default values
		 */
		void reset();
		/**
		 * Initializes the response
		 */
		void init();
		/**
		 * Call with instance of StartUpMessage class only if getMsgId() == START_UP_MESSAGE
		 * to populate response
		 */
		void getStartUpMessage(AntResponse &response);
		/**
		 * Call with instance of BroadcastData class only if getMsgId() == BROADCAST_DATA
		 * to populate response
		 */
		void getBroadcastData(AntResponse &response);
		/**
		 * Call with instance of AcknowledgedData class only if getMsgId() == ACKNOWLEDGED_DATA
		 * to populate response
		 */
		void getAcknowledgedData(AntResponse &response);
		/**
		 * Call with instance of BurstTransferData class only if getMsgId() == BURST_TRANSFER_DATA
		 * to populate response
		 */
		void getBurstTransferData(AntResponse &response);
		/**
		 * Call with instance of AdvancedBurstData only if getMsgId() == ADVANCED_BURST_DATA
		 */
		void getAdvancedBurstData(AntResponse &responses);
		/**
		 * Call with instance of ChannelEvent only if getMsgId() == CHANNEL_EVENT
		 */
		void getChannelEvent(AntResponse &response);
		/**
		 * Call with instance of ChannelResponse only if getMsgId() == CHANNEL_RESPONSE
		 */
		void getChannelResponse(AntResponse &response);
		/**
		 * Call with instance of ChannelStatus only if getMsgId() == CHANNEL_STATUS
		 */
		void getChannelStatus(AntResponse &response);
		/**
		 * Call with instance of ChannelID only if getMsgId() == CHANNEL_ID
		 */
		void getChannelID(AntResponse &response);
		/**
		 * Call with instance of AntVersion only if getMsgId() == ANT_VERSION
		 */
		void getAntVersion(AntResponse &response);
		/**
		 * Call with instance of SerialNumber only if getMsgId() == SERIAL_NUMBER
		 */
		void getSerialNumber(AntResponse &response);
		/**
		 * Returns true if the response has been successfully parsed and is complete and ready for use
		 */
		bool isAvailable();
		void setAvailable(bool complete);
		/**
		 * Returns true if the response contains errors
		 */
		bool isError();
		/**
		 * Returns an error code, or zero, if successful.
		 * Error codes include: CHECKSUM_FAILURE, PACKET_EXCEEDS_BYTE_ARRAY_LENGTH, UNEXPECTED_START_BYTE
		 */
		uint8_t getErrorCode();
		void setErrorCode(uint8_t errorCode);
	protected:
		// pointer to frameData
		uint8_t* _frameDataPtr;
	private:
		void setCommon(AntResponse &target);
		uint8_t _msgId;
		uint8_t _length;
		uint8_t _checksum;
		uint8_t _frameLength;
		bool _complete;
		uint8_t _errorCode;
};

/**
 * Common functionality for both Series 1 and 2 data RX data packets
 */
class RxDataResponse : public AntResponse {
public:
	RxDataResponse();
	/**
	 * Returns the specified index of the payload.  The index may be 0 to getDataLength() - 1
	 * This method is deprecated; use uint8_t* getData()
	 */
	uint8_t getData(int index);
	/**
	 * Returns the payload array.  This may be accessed from index 0 to getDataLength() - 1
	 */
	uint8_t* getData();
	/**
	 * Returns the length of the payload
	 */
	virtual uint8_t getDataLength() = 0;
	/**
	 * Returns the position in the frame data where the data begins
	 */
	virtual uint8_t getDataOffset() = 0;
};

// getResponse to return the proper subclass:
// we maintain a pointer to each type of response, when a response is parsed, it is allocated only if NULL
// can we allocate an object in a function?

/**
 * Represents a Series 2 TX status packet
 */
class ZBTxStatusResponse : public FrameIdResponse {
	public:
		ZBTxStatusResponse();
		uint16_t getRemoteAddress();
		uint8_t getTxRetryCount();
		uint8_t getDeliveryStatus();
		uint8_t getDiscoveryStatus();
		bool isSuccess();

	static const uint8_t MSG_ID = ZB_TX_STATUS_RESPONSE;
};

/**
 * Represents a Series 2 RX packet
 */
class ZBRxResponse : public RxDataResponse {
	public:
		ZBRxResponse();
		uint16_t getRemoteAddress16();
		uint8_t getOption();
		uint8_t getDataLength();
		// frame position where data starts
		uint8_t getDataOffset();

		static const uint8_t MSG_ID = ZB_RX_RESPONSE;
};

/**
 * Represents a Series 2 Explicit RX packet
 *
 * Note: The receive these responses, set AO=1. With the default AO=0,
 * you will receive ZBRxResponses, not knowing exact details.
 */
class ZBExplicitRxResponse : public ZBRxResponse {
	public:
		ZBExplicitRxResponse();
		uint8_t getSrcEndpoint();
		uint8_t getDstEndpoint();
		uint16_t getClusterId();
		uint16_t getProfileId();
		uint8_t getOption();
		uint8_t getDataLength();
		// frame position where data starts
		uint8_t getDataOffset();

		static const uint8_t MSG_ID = ZB_EXPLICIT_RX_RESPONSE;
};

/**
 * Represents a Series 2 RX I/O Sample packet
 */
class ZBRxIoSampleResponse : public ZBRxResponse {
	public:
		ZBRxIoSampleResponse();
		bool containsAnalog();
		bool containsDigital();
		/**
		 * Returns true if the pin is enabled
		 */
		bool isAnalogEnabled(uint8_t pin);
		/**
		 * Returns true if the pin is enabled
		 */
		bool isDigitalEnabled(uint8_t pin);
		/**
		 * Returns the 10-bit analog reading of the specified pin.
		 * Valid pins include ADC:xxx.
		 */
		uint16_t getAnalog(uint8_t pin);
		/**
		 * Returns true if the specified pin is high/on.
		 * Valid pins include DIO:xxx.
		 */
		bool isDigitalOn(uint8_t pin);
		uint8_t getDigitalMaskMsb();
		uint8_t getDigitalMaskLsb();
		uint8_t getAnalogMask();

		static const uint8_t MSG_ID = ZB_IO_SAMPLE_RESPONSE;
};

#ifdef SERIES_1
/**
 * Represents a Series 1 TX Status packet
 */
class TxStatusResponse : public FrameIdResponse {
	public:
		TxStatusResponse();
		uint8_t getStatus();
		bool isSuccess();

		static const uint8_t MSG_ID = TX_STATUS_RESPONSE;
};

/**
 * Represents a Series 1 RX packet
 */
class RxResponse : public RxDataResponse {
	public:
		RxResponse();
		// remember rssi is negative but this is unsigned byte so it's up to you to convert
		uint8_t getRssi();
		uint8_t getOption();
		bool isAddressBroadcast();
		bool isPanBroadcast();
		uint8_t getDataLength();
		uint8_t getDataOffset();
		virtual uint8_t getRssiOffset() = 0;
};

/**
 * Represents a Series 1 16-bit address RX packet
 */
class Rx16Response : public RxResponse {
	public:
		Rx16Response();
		uint8_t getRssiOffset();
		uint16_t getRemoteAddress16();

		static const uint8_t MSG_ID = RX_16_RESPONSE;
	protected:
		uint16_t _remoteAddress;
};

/**
 * Represents a Series 1 64-bit address RX packet
 */
class Rx64Response : public RxResponse {
	public:
		Rx64Response();
		uint8_t getRssiOffset();
		AntAddress64& getRemoteAddress64();

		static const uint8_t MSG_ID = RX_64_RESPONSE;
};

/**
 * Represents a Series 1 RX I/O Sample packet
 */
class RxIoSampleBaseResponse : public RxResponse {
	public:
		RxIoSampleBaseResponse();
		/**
		 * Returns the number of samples in this packet
		 */
		uint8_t getSampleSize();
		bool containsAnalog();
		bool containsDigital();
		/**
		 * Returns true if the specified analog pin is enabled
		 */
		bool isAnalogEnabled(uint8_t pin);
		/**
		 * Returns true if the specified digital pin is enabled
		 */
		bool isDigitalEnabled(uint8_t pin);
		/**
		 * Returns the 10-bit analog reading of the specified pin.
		 * Valid pins include ADC:0-5.  Sample index starts at 0
		 */
		uint16_t getAnalog(uint8_t pin, uint8_t sample);
		/**
		 * Returns true if the specified pin is high/on.
		 * Valid pins include DIO:0-8.  Sample index starts at 0
		 */
		bool isDigitalOn(uint8_t pin, uint8_t sample);
		uint8_t getSampleOffset();

		/**
		 * Gets the offset of the start of the given sample.
		 */
		uint8_t getSampleStart(uint8_t sample);
	private:
};

class Rx16IoSampleResponse : public RxIoSampleBaseResponse {
	public:
		Rx16IoSampleResponse();
		uint16_t getRemoteAddress16();
		uint8_t getRssiOffset();

		static const uint8_t MSG_ID = RX_16_IO_RESPONSE;
};

class Rx64IoSampleResponse : public RxIoSampleBaseResponse {
	public:
		Rx64IoSampleResponse();
		uint8_t getRssiOffset();

		static const uint8_t MSG_ID = RX_64_IO_RESPONSE;
};

#endif

/**
 * Represents a Modem Status RX packet
 */
class ModemStatusResponse : public AntResponse {
public:
	ModemStatusResponse();
	uint8_t getStatus();

	static const uint8_t MSG_ID = MODEM_STATUS_RESPONSE;
};

/**
 * Represents an AT Command RX packet
 */
class AtCommandResponse : public FrameIdResponse {
	public:
		AtCommandResponse();
		/**
		 * Returns an array containing the two character command
		 */
		uint8_t* getCommand();
		/**
		 * Returns the command status code.
		 * Zero represents a successful command
		 */
		uint8_t getStatus();
		/**
		 * Returns an array containing the command value.
		 * This is only applicable to query commands.
		 */
		uint8_t* getValue();
		/**
		 * Returns the length of the command value array.
		 */
		uint8_t getValueLength();
		/**
		 * Returns true if status equals AT_OK
		 */
		bool isOk();

		static const uint8_t MSG_ID = AT_COMMAND_RESPONSE;
};

/**
 * Represents a Remote AT Command RX packet
 */
class RemoteAtCommandResponse : public AtCommandResponse {
	public:
		RemoteAtCommandResponse();
		/**
		 * Returns an array containing the two character command
		 */
		uint8_t* getCommand();
		/**
		 * Returns the command status code.
		 * Zero represents a successful command
		 */
		uint8_t getStatus();
		/**
		 * Returns an array containing the command value.
		 * This is only applicable to query commands.
		 */
		uint8_t* getValue();
		/**
		 * Returns the length of the command value array.
		 */
		uint8_t getValueLength();
		/**
		 * Returns the 16-bit address of the remote radio
		 */
		uint16_t getRemoteAddress16();
		/**
		 * Returns true if command was successful
		 */
		bool isOk();

		static const uint8_t MSG_ID = REMOTE_AT_COMMAND_RESPONSE;
	private:
		AntAddress64 _remoteAddress64;
};


/**
 * Super class of all Ant requests (TX packets)
 * Users should never create an instance of this class; instead use an subclass of this class
 * It is recommended to reuse Subclasses of the class to conserve memory
 * <p/>
 * This class allocates a buffer to
 */
class AntRequest {
	public:
		/**
		 * Constructor
		 * TODO make protected
		 */
		AntRequest(uint8_t msgId, uint8_t frameId);
		/**
		 * Returns the Msg id
		 */
		uint8_t getMsgId();
		// setting = 0 makes this a pure virtual function, meaning the subclass must implement, like abstract in java
		/**
		 * Starting after the frame id (pos = 0) and up to but not including the checksum
		 * Note: Unlike Dynastream's definition of the frame data, this does not start with the MSG ID.
		 * The reason for this is the MSG ID and Frame ID are common to all requests, whereas my definition of
		 * frame data is only the MSG specific data.
		 */
		virtual uint8_t getFrameData(uint8_t pos) = 0;
		/**
		 * Returns the size of the msg frame (not including frame id or msg id or checksum).
		 */
		virtual uint8_t getFrameDataLength() = 0;
		//void reset();
	protected:
		void setMsgId(uint8_t msgId);
	private:
		uint8_t _msgId;
};

// TODO add reset/clear method since responses are often reused
/**
 * Primary interface for communicating with an Ant Radio.
 * This class provides methods for sending and receiving packets with an Ant radio via the serial port.
 * The Ant radio must be configured with the network stack
 * in order to use this software.
 * <p/>
 * Since this code is designed to run on a microcontroller, with only one thread, you are responsible for reading the
 * data off the serial buffer in a timely manner.  This involves a call to a variant of readPacket(...).
 * If your serial port is receiving data faster than you are reading, you can expect to lose packets.
 * Arduino only has a 128 byte serial buffer so it can easily overflow if two or more packets arrive
 * without a call to readPacket(...)
 * <p/>
 * In order to conserve resources, this class only supports storing one response packet in memory at a time.
 * This means that you must fully consume the packet prior to calling readPacket(...), because calling
 * readPacket(...) overwrites the previous response.
 * <p/>
 * This class creates an array of size MAX_FRAME_DATA_SIZE for storing the response packet.  You may want
 * to adjust this value to conserve memory.
 *
 * \author Andrew Rapp
 */
class Ant {
	public:
		Ant();
		/**
		 * Reads all available serial bytes until a packet is parsed, an error occurs, or the buffer is empty.
		 * You may call <i>xbee</i>.getResponse().isAvailable() after calling this method to determine if
		 * a packet is ready, or <i>xbee</i>.getResponse().isError() to determine if
		 * a error occurred.
		 * <p/>
		 * This method should always return quickly since it does not wait for serial data to arrive.
		 * You will want to use this method if you are doing other timely stuff in your loop, where
		 * a delay would cause problems.
		 * NOTE: calling this method resets the current response, so make sure you first consume the
		 * current response
		 */
		void readPacket();
		/**
		 * Waits a maximum of <i>timeout</i> milliseconds for a response packet before timing out; returns true if packet is read.
		 * Returns false if timeout or error occurs.
		 */
		bool readPacket(int timeout);
		/**
		 * Reads until a packet is received or an error occurs.
		 * Caution: use this carefully since if you don't get a response, your Arduino code will hang on this
		 * call forever!! often it's better to use a timeout: readPacket(int)
		 */
		void readPacketUntilAvailable();
		/**
		 * Starts the serial connection on the specified serial port
		 */
		void begin(Stream &serial);
		void getResponse(AntResponse &response);
		/**
		 * Returns a reference to the current response
		 * Note: once readPacket is called again this response will be overwritten!
		 */
		AntResponse& getResponse();
		/**
		 * Sends a AntRequest (TX packet) out the serial port
		 */
		void send(AntRequest &request);
		//uint8_t sendAndWaitForResponse(AntRequest &request, int timeout);
		/**
		 * Returns a sequential frame id between 1 and 255
		 */
		uint8_t getNextFrameId();
		/**
		 * Specify the serial port.  Only relevant for Arduinos that support multiple serial ports (e.g. Mega)
		 */
		void setSerial(Stream &serial);
	private:
		bool available();
		uint8_t read();
		void flush();
		void write(uint8_t val);
		void sendByte(uint8_t b, bool escape);
		void resetResponse();
		AntResponse _response;
		bool _escape;
		// current packet position for response.  just a state variable for packet parsing and has no relevance for the response otherwise
		uint8_t _pos;
		// last byte read
		uint8_t b;
		uint8_t _checksumTotal;
		uint8_t _nextFrameId;
		// buffer for incoming RX packets.  holds only the msg specific frame data, starting after the msg id byte and prior to checksum
		uint8_t _responseFrameData[MAX_FRAME_DATA_SIZE];
		Stream* _serial;
};

class PayloadRequest : public AntRequest {
	public:
		PayloadRequest(uint8_t msgId, uint8_t frameId, uint8_t *payload, uint8_t payloadLength);
		/**
		 * Returns the payload of the packet, if not null
		 */
		uint8_t* getPayload();
		/**
		 * Sets the payload array
		 */
		void setPayload(uint8_t* payloadPtr);

		/*
		 * Set the payload and its length in one call.
		 */
		void setPayload(uint8_t* payloadPtr, uint8_t payloadLength) {
			setPayload(payloadPtr);
			setPayloadLength(payloadLength);
		}

		/**
		 * Returns the length of the payload array, as specified by the user.
		 */
		uint8_t getPayloadLength();
		/**
		 * Sets the length of the payload to include in the request.  For example if the payload array
		 * is 50 bytes and you only want the first 10 to be included in the packet, set the length to 10.
		 * Length must be <= to the array length.
		 */
		void setPayloadLength(uint8_t payloadLength);
	private:
		uint8_t* _payloadPtr;
		uint8_t _payloadLength;
};

/**
 * Represents a Series 2 TX packet that corresponds to Msg Id: ZB_TX_REQUEST
 *
 * Be careful not to send a data array larger than the max packet size of your radio.
 * This class does not perform any validation of packet size and there will be no indication
 * if the packet is too large, other than you will not get a TX Status response.
 * The datasheet says 72 bytes is the maximum for ZNet firmware and ZB Pro firmware provides
 * the ATNP command to get the max supported payload size.  This command is useful since the
 * maximum payload size varies according to certain settings, such as encryption.
 * ZB Pro firmware provides a PAYLOAD_TOO_LARGE that is returned if payload size
 * exceeds the maximum.
 */
class ZBTxRequest : public PayloadRequest {
	public:
		/**
		 * Creates a unicast ZBTxRequest with the ACK option and DEFAULT_FRAME_ID
		 */
		ZBTxRequest(const AntAddress64 &addr64, uint8_t *payload, uint8_t payloadLength);
		ZBTxRequest(const AntAddress64 &addr64, uint16_t addr16, uint8_t broadcastRadius, uint8_t option, uint8_t *payload, uint8_t payloadLength, uint8_t frameId);
		/**
		 * Creates a default instance of this class.  At a minimum you must specify
		 * a payload, payload length and a 64-bit destination address before sending
		 * this request.
		 */
		ZBTxRequest();
		AntAddress64& getAddress64();
		uint16_t getAddress16();
		uint8_t getBroadcastRadius();
		uint8_t getOption();
		void setAddress64(const AntAddress64& addr64);
		void setAddress16(uint16_t addr16);
		void setBroadcastRadius(uint8_t broadcastRadius);
		void setOption(uint8_t option);
	protected:
		// declare virtual functions
		uint8_t getFrameData(uint8_t pos);
		uint8_t getFrameDataLength();
		AntAddress64 _addr64;
		uint16_t _addr16;
		uint8_t _broadcastRadius;
		uint8_t _option;
};

/**
 * Represents a Series 2 TX packet that corresponds to Msg Id: ZB_EXPLICIT_TX_REQUEST
 *
 * See the warning about maximum packet size for ZBTxRequest above,
 * which probably also applies here as well.
 *
 * Note that to distinguish reply packets from non-Ant devices, set
 * AO=1 to enable reception of ZBExplicitRxResponse packets.
 */
class ZBExplicitTxRequest : public ZBTxRequest {
	public:
		/**
		 * Creates a unicast ZBExplicitTxRequest with the ACK option and
		 * DEFAULT_FRAME_ID.
		 *
		 * It uses the Maxstream profile (0xc105), both endpoints 232
		 * and cluster 0x0011, resulting in the same packet as sent by a
		 * normal ZBTxRequest.
		 */
		ZBExplicitTxRequest(AntAddress64 &addr64, uint8_t *payload, uint8_t payloadLength);
		/**
		 * Create a ZBExplicitTxRequest, specifying all fields.
		 */
		ZBExplicitTxRequest(AntAddress64 &addr64, uint16_t addr16, uint8_t broadcastRadius, uint8_t option, uint8_t *payload, uint8_t payloadLength, uint8_t frameId, uint8_t srcEndpoint, uint8_t dstEndpoint, uint16_t clusterId, uint16_t profileId);
		/**
		 * Creates a default instance of this class.  At a minimum you
		 * must specify a payload, payload length and a destination
		 * address before sending this request.
		 *
		 * Furthermore, it uses the Maxstream profile (0xc105), both
		 * endpoints 232 and cluster 0x0011, resulting in the same
		 * packet as sent by a normal ZBExplicitTxRequest.
		 */
		ZBExplicitTxRequest();
		uint8_t getSrcEndpoint();
		uint8_t getDstEndpoint();
		uint16_t getClusterId();
		uint16_t getProfileId();
		void setSrcEndpoint(uint8_t endpoint);
		void setDstEndpoint(uint8_t endpoint);
		void setClusterId(uint16_t clusterId);
		void setProfileId(uint16_t profileId);
	protected:
		// declare virtual functions
		uint8_t getFrameData(uint8_t pos);
		uint8_t getFrameDataLength();
	private:
		uint8_t _srcEndpoint;
		uint8_t _dstEndpoint;
		uint16_t _profileId;
		uint16_t _clusterId;
};

/**
 * Represents an AT Command TX packet
 * The command is used to configure the serially connected Ant radio
 */
class AtCommandRequest : public AntRequest {
	public:
		AtCommandRequest();
		AtCommandRequest(uint8_t *command);
		AtCommandRequest(uint8_t *command, uint8_t *commandValue, uint8_t commandValueLength);
		uint8_t getFrameData(uint8_t pos);
		uint8_t getFrameDataLength();
		uint8_t* getCommand();
		void setCommand(uint8_t* command);
		uint8_t* getCommandValue();
		void setCommandValue(uint8_t* command);
		uint8_t getCommandValueLength();
		void setCommandValueLength(uint8_t length);
		/**
		 * Clears the optional commandValue and commandValueLength so that a query may be sent
		 */
		void clearCommandValue();
		//void reset();
	private:
		uint8_t *_command;
		uint8_t *_commandValue;
		uint8_t _commandValueLength;
};

/**
 * Represents an Remote AT Command TX packet
 * The command is used to configure a remote Ant radio
 */
class RemoteAtCommandRequest : public AtCommandRequest {
	public:
		RemoteAtCommandRequest();
		/**
		 * Creates a RemoteAtCommandRequest with 16-bit address to set a command.
		 * 64-bit address defaults to broadcast and applyChanges is true.
		 */
		RemoteAtCommandRequest(uint16_t remoteAddress16, uint8_t *command, uint8_t *commandValue, uint8_t commandValueLength);
		/**
		 * Creates a RemoteAtCommandRequest with 16-bit address to query a command.
		 * 64-bit address defaults to broadcast and applyChanges is true.
		 */
		RemoteAtCommandRequest(uint16_t remoteAddress16, uint8_t *command);
		/**
		 * Creates a RemoteAtCommandRequest with 64-bit address to set a command.
		 * 16-bit address defaults to broadcast and applyChanges is true.
		 */
		RemoteAtCommandRequest(AntAddress64 &remoteAddress64, uint8_t *command, uint8_t *commandValue, uint8_t commandValueLength);
		/**
		 * Creates a RemoteAtCommandRequest with 16-bit address to query a command.
		 * 16-bit address defaults to broadcast and applyChanges is true.
		 */
		RemoteAtCommandRequest(AntAddress64 &remoteAddress64, uint8_t *command);
		uint16_t getRemoteAddress16();
		void setRemoteAddress16(uint16_t remoteAddress16);
		bool getApplyChanges();
		void setApplyChanges(bool applyChanges);
		uint8_t getFrameData(uint8_t pos);
		uint8_t getFrameDataLength();
	//	static uint16_t broadcast16Address;
	private:
		uint16_t _remoteAddress16;
		bool _applyChanges;
};



#endif //ANT_h
