#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class ExpandedData {

	string satName;
	string satID;
	double satLat;
	double satLon;
	double satAlt;
	string satAzi;
	double satEle;
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
	ExpandedData() {

	}

	ExpandedData(string passedID) {

	}

	void createSatellite(string passedName, string passedID, double passedLatitude, double passedLongitude, double passedAltitude, string passedAzimuth, double passedElevation, string passedRA, string passedDec, string passedTimestamp) {
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
		cout << "\nChoose a specific satellite: ";
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

	void setLatitude(double passedLatitude) {
		this->satLat = passedLatitude;
	}

	double getLatitude() {
		return this->satLat;
	}

	void displayLatitude() {
		cout << "Latitude: " << getLatitude() << "\n";
	}

	void setLongitude(double passedLongitude) {
		this->satLon = passedLongitude;
	}

	double getLongitude() {
		return this->satLon;
	}

	void displayLongitude() {
		cout << "Longitude: " << getLongitude() << "\n";
	}

	void setAltitude(double passedAltitude) {
		this->satAlt = passedAltitude;
	}

	double getAltitude() {
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


	void setElevation(double passedEle) {
		this->satEle = passedEle;
	};

	double getElevation() {
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