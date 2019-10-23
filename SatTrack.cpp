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
	bool UoM;

public:
	CurrentLocation() {
		setLongitude(); 
		setLatitude();
		setElevation();
		/*this->longitude = "-83.045753"; // This is for testing purposes; I get sick of typing them.
		this->latitude = "42.331429";
		this->elevation = "200";*/

	}
protected:
	void setLongitude() {
		cout << "Enter your longitude: ";
		cin >> this->longitude;
	}

	void setLatitude() {
		cout << "Enter your latitude: ";
		cin >> this->latitude;
	}

	void setElevation() {
		cout << "Enter your elevation: ";
		cin >> this->elevation;
	}

	void setUnitOfMeasure() {
		cout << "Imperial or Metric: ";
		cin >> this->UoM;
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

private:


};

class SatelliteInformation {
	vector<string> satID;
	vector<string> satOfficialName;
	vector<string> satDesignator;
	vector<string> satLaunchDate;
	vector<string> satLatitude;
	vector<string> satLongitude;
	vector<string> satAltitude;

public:
	SatelliteInformation() {

	}

	void insertSatelliteItem(string passedID, string passedOfficialName, string passedDesignator, string passedLaunchDate, string passedLatitude, string passedLongitude, string passedAltitude) {
		setID(passedID);
		setOfficialName(passedOfficialName);
		setSatelliteDesignator(passedDesignator);
		setLaunchDate(passedLaunchDate);
		setLatitude(passedLatitude);
		setLongitude(passedLongitude);
		setAltitude(passedAltitude);
	}

	void display(int choiceValue) {
		cout << "\n";
		displaySatelliteOfficialName(choiceValue);
		displaySatelliteDesignator(choiceValue);
		displayLaunchDate(choiceValue);
		displayAltitude(choiceValue);
		displayLatitude(choiceValue);
		displayLongitude(choiceValue);
	}

	virtual void showCrafts(vector<string> satOfficialName) {
		for (size_t i = 0; i < satOfficialName.size(); i++) {
			cout << "\n" << i + 1 << ". " << this->satOfficialName.at(i);
		}
	}

	virtual void showSatelliteList() {
		for (size_t i = 0; i < this->satID.size(); i++) {
			cout << "\n" << i + 1 << ". " << getSatelliteOfficialName(i);
		}
	}

	int satChoice() {
		int userInput;
		cout << "\n" << "Your choice: ";
		cin >> userInput;
		return userInput;
	}

	void setID(string passedID) {
		this->satID.push_back(passedID);
	}

	string getID(int choice) {
		return this->satID.at(choice);
	}

	vector<string> getID() {
		return this->satID;
	}

	void setOfficialName(string passedName) {
		this->satOfficialName.push_back(passedName);
	}

	string getSatelliteOfficialName(int choice) {
		return this->satOfficialName.at(choice);
	}

	void displaySatelliteOfficialName(int choice) {
		cout << "Name: " << getSatelliteOfficialName(choice) << "\n";
	}

	vector<string> getSatelliteOfficialName() {
		return this->satOfficialName;
	}

	void setSatelliteDesignator(string passedDesignator) {
		this->satDesignator.push_back(passedDesignator);
	}

	string getSatelliteDesignator(int choice) {
		return this->satDesignator.at(choice);
	}

	void displaySatelliteDesignator(int choice) {
		cout << "Designator: " << getSatelliteDesignator(choice) << "\n";
	}

	vector<string> getSatelliteDesignator() {
		return this->satDesignator;
	}

	void setLaunchDate(string passedLaunchDate) {
		this->satLaunchDate.push_back(passedLaunchDate);
	}

	string getLaunchDate(int choice) {
		return this->satLaunchDate.at(choice);
	}

	void displayLaunchDate(int choice) {
		cout << "Launch Date: " << getLaunchDate(choice) << "\n";
	}

	vector<string> getLaunchDate() {
		return this->satLaunchDate;
	}

	void setLatitude(string passedLatitude) {
		this->satLatitude.push_back(passedLatitude);
	}

	string getLatitude(int choice) {
		return this->satLatitude.at(choice);
	}

	void displayLatitude(int choice) {
		cout << "Latitude: " << getLatitude(choice) << "\n";
	}

	vector<string> getLatitude() {
		return this->satLatitude;
	}

	void setLongitude(string passedLongitude) {
		this->satLongitude.push_back(passedLongitude);

	}

	string getLongitude(int choice) {
		return this->satLongitude.at(choice);
	}

	void displayLongitude(int choice) {
		cout << "Longitude: " << getLongitude(choice) << "\n";
	}

	vector<string> getLongitude() {
		return this->satLongitude;
	}

	void setAltitude(string passedAltitude) {
		this->satAltitude.push_back(passedAltitude);

	}

	string getAltitude(int choice) {
		return this->satAltitude.at(choice);
	}

	void displayAltitude(int choice) {
		cout << "Altitude: " << getAltitude(choice) << "\n";
	}

	vector<string>getAltitude() {
		return this->satAltitude;
	}

};


class Calculations {

/*	void calculateAzimuth(CurrentLocation cl, SatelliteLocation sl) {
		// arctan((x2 –x1)/(y2 –y1))
		atan((stod(cl.getLatitude()) - stod(cl.getLongitude())) / (stod(sl.getLatitude()) - stod(sl.getLongitude())));

	}*/

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

class GetWebData {
	SatelliteInformation SI;
	
public:
	void initializeAPI(CurrentLocation cl) {
		string rawSatelliteOutput = downloadSatelliteList(cl);
		vector<string> unformattedSatelliteList = convertSatelliteToJSON(rawSatelliteOutput);
		insertSatellitesAboveToVectors(unformattedSatelliteList);
	}

	SatelliteInformation getSIData() {
		return this->SI;
	}

	string getID(int choice) {
		return this->SI.getID(choice);
	}

	string getSatelliteOfficialName(int choice) {
		return this->SI.getSatelliteOfficialName(choice);
	}

	string getSatelliteDesignator(int choice) {
		return this->SI.getSatelliteDesignator(choice);
	}

	string getLaunchDate(int choice) {
		return this->SI.getLaunchDate(choice);
	}

	string getLatitude(int choice) {
		return this->SI.getLatitude(choice);
	}

	string getLongitude(int choice) {
		return this->SI.getLongitude(choice);
	}

	string getAltitude(int choice) {
		return this->SI.getAltitude(choice);
	}

private:
	string downloadSatelliteList(CurrentLocation udcl) {
		return cpr::Get(cpr::Url{ getAPIURL(udcl.getLongitude(), udcl.getLatitude(), udcl.getElevation()) }).text;
	}

	string downloadSatelliteList() {
		return cpr::Get(cpr::Url{ getAPIURL("-83.045753", "42.331429", "656") }).text;
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
			SI.insertSatelliteItem(to_string(stringToJSON.find("satid").value()), to_string(stringToJSON.find("satname").value()), to_string(stringToJSON.find("intDesignator").value()), to_string(stringToJSON.find("launchDate").value()), to_string(stringToJSON.find("satlat").value()), to_string(stringToJSON.find("satlng").value()), to_string(stringToJSON.find("satalt").value()));
		}
	}

	string getAPIURL(string longitude, string latitude, string elevation) {
		return "https://www.n2yo.com/rest/v1/satellite/above/" + longitude + "/" + latitude + "/" + elevation + "/70/18/&apiKey=DARUHH-CVU8AH-H9U5KE-47PU";
	}

};



int main() {
	int userInput;
	cout << "Sat Track\n";
	SatelliteInformation SI;
	GetWebData apc;
	CurrentLocation CL;
	SatelliteLocation sl;
	apc.initializeAPI(CL);
	SI = apc.getSIData();

	SI.showSatelliteList();
	userInput = SI.satChoice();
	SI.display(userInput - 1 );
//	sl = SI.outputToClass(userInput - 1);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
