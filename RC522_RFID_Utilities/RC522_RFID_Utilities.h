#ifndef RC522_RFID_UTILITIES_h
#define RC522_RFID_UTILITIES_h
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>



class RC522_RFID_Utilities 
{
public:
	MFRC522 *mfrc522;
	MFRC522::MIFARE_Key NFCDefaultKeyA;
	MFRC522::MIFARE_Key NFCDefaultKeyB;
	MFRC522::MIFARE_Key NFCKeyA;
	MFRC522::MIFARE_Key NFCKeyB;
	MFRC522::MIFARE_Key MADKeyA;
	MFRC522::MIFARE_Key MADKeyB;

	RC522_RFID_Utilities();
	RC522_RFID_Utilities(MFRC522 *mfrc522);

	/*
	 * Sets the MFRC pointer
	 */
	void setMFRC(MFRC522 *mfrc522);

	/*
	 * Shows the reader details. This method is copied from the MFRC522 library directly.
	 */
	void showReaderDetails();

	/*
	 * Copies a byte array to a Mifare key
	 * Arguments:
	 *  array: the byte array
	 *  key: the Miare key
	 */
	void copyBytesToKey(byte *array,  MFRC522::MIFARE_Key *key);

	/*
	 * Prints a sector using key A
	 * 
	 * Arguments:
	 *  sector: the sector number
	 *  keyA: the authentication key
	 */
	void printSector(byte sector, MFRC522::MIFARE_Key *keyA);

	/*
	 * Prints all the sectors
	 */
	void printAllSectors(MFRC522::MIFARE_Key *MADKeyA, MFRC522::MIFARE_Key *NFCKeyA);

	/**
	 * Helper routine to dump a byte array as hex values to Serial.
	 */
	void dump_byte_array(byte *buffer, byte bufferSize);

	/**
	 * Writes a block of data to the tag
	 * 
	 * Arguments:
	 *  sector: the sector number
	 *  blockAddr: the destination block address
	 *  dataBlock: a pointer to a 16-byte block 
	 *  keyB: a pointer to a keyB
	 */
	void writeBlock(byte sector, byte blockAddr, byte* dataBlock, MFRC522::MIFARE_Key *keyB);

private:
	/* sector 1 block 4 */
	byte dataBlock14[16] ={0x03, 0x11, 
	                      0xD1, 0x01, 0x0D, 0x55, 
	                      0x01, 0x61, 0x64, 0x61, 
	                      0x66, 0x72, 0x75, 0x69, 0x74, 0x2E};       
	/* sector 1 block 5 */
	byte dataBlock15[16] = { 0x63, 0x6F, 
	                      0x6D, 0xFE, 0x00, 0x00, 
	                      0x00, 0x00, 0x00, 0x00, 
	                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00};     
	/* sector 1 block 6 */
	byte dataBlock16[16] = {0x00, 0x00, 0x00, 0x00, 
	                      0x00, 0x00, 0x00, 0x00, 
	                      0x00, 0x00, 0x00, 0x00, 
	                      0x00, 0x00, 0x00, 0x00};   

	/* Rest of the data blocks are null */
	byte dataBlockNull[16] = {0x00, 0x00, 0x00, 0x00, 
	                      0x00, 0x00, 0x00, 0x00, 
	                      0x00, 0x00, 0x00, 0x00, 
	                      0x00, 0x00, 0x00, 0x00};   


	// Those two methods are not used. Set them as private for now.
	void writeDefaultMessage();
	void writePlainText();


};




#endif