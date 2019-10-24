// SatTrack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cpr/cpr.h>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <math.h>
#include <nlohmann/json.hpp>


using namespace std;
using json = nlohmann::json;

//  https://www.n2yo.com/rest/v1/satellite/above/42.331429/-83.045753/656/70/18/&apiKey=DARUHH-CVU8AH-H9U5KE-47PU
// API KEy: DARUHH-CVU8AH-H9U5KE-47PU

// Detroit Longitude: -83.045753	Latitude: 42.331429		Elevation: 200 meters

class CurrentLocation {
	string longitude;
	string latitude;
	string elevation;
	int satelliteCategory;

public:
	CurrentLocation() {
		setLongitude(); 
		setLatitude();
		setElevation();
		displaySatelliteCategories();
		/*this->longitude = "-83.045753"; // This is for testing purposes; I get sick of typing them.
		this->latitude = "42.331429";
		this->elevation = "200";*/

	}
protected:
	void setLongitude() {
		cout << "Enter longitude: ";
		cin >> this->longitude;
	}

	void setLatitude() {
		cout << "Enter latitude: ";
		cin >> this->latitude;
	}

	void setElevation() {
		cout << "Enter elevation from sea level (in meters): ";
		cin >> this->elevation;
	}

	void displaySatelliteCategories() {
		int satelliteChoice;
		for (int i = 0; i < sizeof(satelliteCategories); i++) {
			cout << "\n" << i + 1 << ". " << satelliteCategories[i];
		}
		cout << "\nYour choice: ";
		cin >> satelliteChoice;
		this->satelliteCategory = satelliteValues[satelliteChoice];
	}


public:
	string getLongitude() {
		return this->longitude;
	}

	string getLatitude() {
		return this->latitude;
	}

	string getElevation() {
		return this->elevation;
	}

	int getCategory() {
		return this->satelliteCategory;
	}

private:
	string satelliteCategories[52] = { "Amateur radio", "Beidou Navigation System", "Brightest", "Celestis", "CubeSats", "Disaster monitoring", "Earth resources", "Education", "Engineering" "Experimental", "Flock", "Galileo", "Geodetic", "Geostationary", "Global Positioning System(GPS) Constellation", "Global Positioning System(GPS) Operational", "Globalstar", "Glonass Constellation", "Glonass Operational", "GOES", "Gonets", "Gorizont", "Intelsat", "Iridium", "IRNSS", "ISS", "Lemur", "Military", "Molniya", "Navy Navigation Satellite System", "NOAA", "O3B Networks", "Orbcomm", "Parus", "QZSS", "Radar Calibration", "Raduga", "Russian LEO Navigation", "Satellite - Based Augmentation System", "Search & rescue", "Space & Earth Science", "Starlink", "Strela", "Tracking and Data Relay Satellite System", "Tselina", "Tsikada", "Tsiklon", "TV", "Weather", "Westford Needles", "XM and Sirius", "Yaogan" };
	int satelliteValues[52] = { 18, 35, 1, 45, 32, 8, 6, 29, 28, 19, 48, 22, 27, 10, 50, 20, 17, 51, 21, 5, 40, 12, 11, 15, 46, 2, 49, 30, 14, 24, 4, 43, 16, 38, 47, 31, 13, 25, 23, 7, 26, 52, 39, 9, 44, 42, 41, 34, 3, 37, 33, 36 };
	
};

class SatelliteData {
	/*vector<string> satID;
	vector<string> satOfficialName;
	vector<string> satDesignator;
	vector<string> satLaunchDate;
	vector<string> satLatitude;
	vector<string> satLongitude;
	vector<string> satAltitude;*/

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
	SatelliteData() {

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

	void setAzimuth(string passedAzi){
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

class SatelliteLocation {
	string name;
	string longitude;
	string latitude;
	string altitude;

	void setSatelliteInformation(string passedName, string passedLongitude, string passedLatitude, string passedAltitude) {
		this->name = passedName;
		this->longitude = passedLongitude;
		this->latitude = passedLatitude;
		this->altitude = passedAltitude;
	}
public:
	string getName() {
		return this->name;
	}

	string getLongitude() {
		return this->longitude;
	}

	string getLatitude() {
		return this->latitude;
	}

	string getAltitude() {
		return this->altitude;
	}
};

class SatelliteList {



};

class GetWebData {
	SatelliteList SL;
	
public:
	void pullDownWebData(CurrentLocation cl) {
		string rawSatelliteOutput = downloadSatelliteList(cl);
		vector<string> unformattedSatelliteList = convertSatelliteToJSON(rawSatelliteOutput);
		insertSatellitesAboveToVectors(unformattedSatelliteList);
	}

	SatelliteData getSatelliteData() {
		return this->SD;
	}

	string getID() {
		return this->SD.getID();
	}

	string getSatelliteOfficialName() {
		return this->SD.getSatelliteOfficialName();
	}

	string getLatitude() {
		return this->SD.getLatitude();
	}

	string getLongitude() {
		return this->SD.getLongitude();
	}

	string getAltitude() {
		return this->SD.getAltitude();
	}
	
	string getElevation() {
		return this->SD.getElevation();
	}

	string getDeclination() {
		return this->SD.getDeclination();
	}

	string getAzimuth() {
		return this->SD.getAzimuth();
	}

private:
	string downloadSatelliteList(CurrentLocation udcl) {
		return cpr::Get(cpr::Url{ getSatellitesAboveURL(udcl) }).text;
	}

	vector<string> convertSatelliteToJSON(string rawSatelliteOutput) {
		json jsonData = json::parse(rawSatelliteOutput);
		vector<string> satellitesAbove;
		nlohmann::json commands;

		json data = commands["above"];

		for (auto& el : jsonData["above"].items()) {
			//	cout << el.key() << " : " << el.value() << '\n';
			satellitesAbove.push_back(to_string(el.value()));
		}
		return satellitesAbove;
	}

	void insertSatellitesAboveToVectors(vector<string> unformattedSatelliteList) {
		for (size_t p = 0; p < unformattedSatelliteList.size(); p++) {
			json stringToJSON = json::parse(unformattedSatelliteList.at(p));
			SI.createSatellite(to_string(stringToJSON.find("satname").value()), to_string(stringToJSON.find("satid").value()), to_string(stringToJSON.find("satlatitude").value()), to_string(stringToJSON.find("satlongitude").value()), to_string(stringToJSON.find("sataltitude").value()), to_string(stringToJSON.find("azimuth").value()), to_string(stringToJSON.find("elevation").value()), to_string(stringToJSON.find("ra").value()), to_string(stringToJSON.find("dec").value()), to_string(stringToJSON.find("timestamp").value()));
		}
	}

	string getAPIKey() {
		return "DARUHH-CVU8AH-H9U5KE-47PU";
	}

	string getSatellitesAboveURL(CurrentLocation cl) {
		return "https://www.n2yo.com/rest/v1/satellite/above/" + cl.getLatitude() + "/" + cl.getLongitude() + "/" + cl.getElevation() + "/90/" + to_string(cl.getCategory()) + "/&apiKey=" + getAPIKey();
	}

	string getSpecificSatelliteDataURL(string satelliteChoice, CurrentLocation cl) {
		return "http://www.n2yo.com/rest/v1/satellite/visualpasses/" + satelliteChoice + "/" + cl.getLatitude() + "/" + cl.getLongitude() + "/" + cl.getElevation() + "/0/300/&apiKey=" + getAPIKey();
	}

};



int main() {
	int userInput;
	cout << "Sat Track\n";
	SatelliteData SI;
	GetWebData apc;
	CurrentLocation CL;
	SatelliteLocation sl;
	apc.pullDownWebData(CL);
	SI = apc.getSatelliteData();

	SI.showSatelliteList();
	userInput = SI.satChoice();
	SI.display(userInput - 1 );
//	sl = SI.outputToClass(userInput - 1);
	return 0;
}
