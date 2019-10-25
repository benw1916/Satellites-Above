#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class SatelliteData {

	string satName;
	string satID;
	string satLat;
	string satLon;
	string satAlt;
	string satAzi;
	string satEle;
	string satRA;
	string satDec;
	string satTime;
	int satelliteChoice;


	/*"satlatitude": -39.86493451,
	  "satlongitude": 158.35261287,
	  "sataltitude": 417.84,
	  "azimuth": 254.33,
	  "elevation": -69.06,
	  "ra": 44.81676119,
	  "dec": -43.98086419,
	  "timestamp": 1521354419

	*/

public:
	SatelliteData(string passedID) {

	}

	void createSatellite(string passedName, string passedID, string passedLatitude, string passedLongitude, string passedAltitude, string passedAzimuth, string passedElevation, string passedRA, string passedDec, string passedTimestamp) {
		setOfficialName(passedName);
		setID(passedID);
		setLatitude(passedLatitude);
		setLongitude(passedLongitude);
		setAltitude(passedAltitude);
		setAzimuth(passedAzimuth);
		setElevation(passedElevation);
		setAscension(passedRA);
		setDeclination(passedDec);
		setTimeStamp(passedTimestamp);
	}

	void display() {
		cout << "\n";
		displaySatelliteOfficialName();
		displayID();
		displayLatitude();
		displayLongitude();
		displayAltitude();
		displayAzimuth();
		displayElevation();
		displayAscension();
		displayAscension();
		displayDeclination();
		displayTimestamp();
	}

	int chooseSpecificSatellite() {
		cout << "Choose a specific satellite: ";
		cin >> this->satelliteChoice;
		return this->satelliteChoice;
	}

	void setOfficialName(string passedName) {
		this->satName = passedName;
	}

	string getSatelliteOfficialName() {
		return this->satName;
	}

	void displaySatelliteOfficialName() {
		cout << "Name: " << getSatelliteOfficialName() << "\n";
	}


	void setID(string passedID) {
		this->satID = passedID;
	}

	string getID() {
		return this->satID;
	}

	void displayID() {
		cout << "ID: " << getID() << "\n";
	}

	void setLatitude(string passedLatitude) {
		this->satLat = passedLatitude;
	}

	string getLatitude() {
		return this->satLat;
	}

	void displayLatitude() {
		cout << "Latitude: " << getLatitude() << "\n";
	}

	void setLongitude(string passedLongitude) {
		this->satLon = passedLongitude;
	}

	string getLongitude() {
		return this->satLon;
	}

	void displayLongitude() {
		cout << "Longitude: " << getLongitude() << "\n";
	}

	void setAltitude(string passedAltitude) {
		this->satAlt = passedAltitude;
	}

	string getAltitude() {
		return this->satAlt;
	}

	void displayAltitude() {
		cout << "Altitude: " << getAltitude() << "\n";
	}

	void setAzimuth(string passedAzi) {
		this->satAzi = passedAzi;
	}

	string getAzimuth() {
		return this->satAzi;
	}

	void displayAzimuth() {
		cout << "Azimuth: " << getAzimuth() << "\n";
	}


	void setElevation(string passedEle) {
		this->satEle = passedEle;
	}

	string getElevation() {
		return this->satEle;
	}

	void displayElevation() {
		cout << "Elevation: " << getElevation() << "\n";
	}

	void setAscension(string passedRA) {
		this->satRA = passedRA;
	}

	string getAscension() {
		return this->satRA;
	}

	void displayAscension() {
		cout << "Ascension: " << getAscension() << "\n";
	}

	void setDeclination(string passedDec) {
		this->satDec = passedDec;
	}

	string getDeclination() {
		return this->satDec;
	}

	void displayDeclination() {
		cout << "Declination: " << getDeclination() << "\n";
	}

	void setTimeStamp(string passedTimestamp) {
		this->satTime = passedTimestamp;
	}

	string getTimestamp() {
		return this->satTime;
	}

	void displayTimestamp() {
		cout << "Time: " << getTimestamp() << "\n";
	}

};