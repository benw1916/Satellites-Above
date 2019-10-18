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
#include <nlohmann/json.hpp>


using namespace std;
using json = nlohmann::json;

//  https://www.n2yo.com/rest/v1/satellite/above/42.331429/-83.045753/656/70/18/&apiKey=DARUHH-CVU8AH-H9U5KE-47PU
// API KEy: DARUHH-CVU8AH-H9U5KE-47PU

// Detroit Longitude: -83.045753	Latitude: 42.331429		Elevation: 656

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

	vector<string> getSatelliteOfficialName() {
		return this->satOfficialName;
	}

	void setSatelliteDesignator(string passedDesignator) {
		this->satDesignator.push_back(passedDesignator);
	}

	string getSatelliteDesignator(int choice) {
		return this->satDesignator.at(choice);
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

	vector<string> getLaunchDate() {
		return this->satLaunchDate;
	}

	void setLatitude(string passedLatitude) {
		this->satLatitude.push_back(passedLatitude);
	}

	string getLatitude(int choice) {
		return this->satLatitude.at(choice);
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

	vector<string> getLongitude() {
		return this->satLongitude;
	}

	void setAltitude(string passedAltitude) {
		this->satAltitude.push_back(passedAltitude);

	}

	string getAltitude(int choice) {
		return this->satAltitude.at(choice);
	}

	vector<string>getAltitude() {
		return this->satAltitude;
	}

};


class APIConnection {
/*	vector<string> satID;
	vector<string> satOfficialName;
	vector<string> satDesignator;
	vector<string> satLaunchDate;
	vector<string> satLatitude;
	vector<string> satLongitude;
	vector<string> satAltitude;*/
	SatelliteInformation SI;
	
public:
	void initializeAPI(CurrentLocation userDefinedCurrentLocation) {
		string rawSatelliteOutput = downloadSatelliteList(userDefinedCurrentLocation.getLongitude(), userDefinedCurrentLocation.getLatitude(), userDefinedCurrentLocation.getElevation());
		vector<string> unformattedSatelliteList = convertSatelliteToJSON(rawSatelliteOutput);
		insertSatellitesAboveToVectors(unformattedSatelliteList);
		//cout << unformattedSatelliteList.at(2);
	}

	SatelliteInformation getSIData() {
		return this->SI;
	}

	string getID(int choice) {
		return this->SI.getID(choice);
	}

	/*vector<string> getID() {
		return this->satID;
	}*/

	string getSatelliteOfficialName(int choice) {
		return this->SI.getSatelliteOfficialName(choice);
	}

	/*vector<string> getSatelliteOfficialName() {
		return this->satOfficialName;
	}*/

	string getSatelliteDesignator(int choice) {
		return this->SI.getSatelliteDesignator(choice);
	}

	/*vector<string> getSatelliteDesignator() {
		return this->satDesignator;
	}*/

	string getLaunchDate(int choice) {
		return this->SI.getLaunchDate(choice);
	}

	/*vector<string> getLaunchDate() {
		return this->satLaunchDate;
	}*/

	string getLatitude(int choice) {
		return this->SI.getLatitude(choice);
	}

	/*vector<string> getLatitude() {
		return this->satLatitude;
	}*/

	string getLongitude(int choice) {
		return this->SI.getLongitude(choice);
	}

	/*vector<string> getLongitude() {
		return this->satLongitude;
	}*/

	string getAltitude(int choice) {
		return this->SI.getAltitude(choice);
	}

	/*vector<string>getAltitude() {
		return this->satAltitude;
	}*/


private:
	string downloadSatelliteList(double passedLongitude, double passedLatitude, double passedElevation) {
		return cpr::Get(cpr::Url{ getAPIURL(passedLongitude, passedLatitude, passedElevation) }).text;
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
			SI.setID(to_string(stringToJSON.find("satid").value()));
			//satID.push_back(to_string(stringToJSON.find("satid").value()));
			SI.setOfficialName(to_string(stringToJSON.find("satname").value()));
			//satOfficialName.push_back(to_string(stringToJSON.find("satname").value()));
			SI.setSatelliteDesignator(to_string(stringToJSON.find("intDesignator").value()));
			//satDesignator.push_back(to_string(stringToJSON.find("intDesignator").value()));
			SI.setLaunchDate(to_string(stringToJSON.find("launchDate").value()));
			//satLaunchDate.push_back(to_string(stringToJSON.find("launchDate").value()));
			SI.setLatitude(to_string(stringToJSON.find("satlat").value()));
			//satLatitude.push_back(to_string(stringToJSON.find("satlat").value()));
			SI.setLongitude(to_string(stringToJSON.find("satlng").value()));
			//satLongitude.push_back(to_string(stringToJSON.find("satlng").value()));
			SI.setAltitude(to_string(stringToJSON.find("satalt").value()));
			//satAltitude.push_back(to_string(stringToJSON.find("satalt").value()));
		}
	}

	string getAPIURL(double longitude, double latitude, double elevation) {
		return "https://www.n2yo.com/rest/v1/satellite/above/" + to_string(longitude) + "/" + to_string(latitude) + "/" + to_string(elevation) + "/70/18/&apiKey=DARUHH-CVU8AH-H9U5KE-47PU";
	}

};


class CurrentLocation {

	double longitude;
	double latitude;
	double elevation;

public: 
	CurrentLocation() {
		setLongitude();
		setLatitude();
		setElevation();
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

public:
	double getLongitude() {
		return this->longitude;
	}

	double getLatitude() {
		return this->latitude;
	}

	double getElevation() {
		return this->elevation;
	}

};


class SatData {
	vector<string> satID;
	vector<string> satOfficialName;
	vector<string> satDesignator;
	vector<string> satLaunchDate;
	vector<string> satLatitude;
	vector<string> satLongitude;
	vector<string> satAltitude;
	SatelliteInformation createdSI;


public:
	SatData() {
	
	}

	SatData(SatelliteInformation passedSI) {
		this->createdSI = passedSI;
		/*this->satID = passedData.getID;
		this->satOfficialName = passedData.getSatelliteOfficialName();
		this->satDesignator = passedData.getSatelliteDesignator();
		this->satLaunchDate = passedData.getLaunchDate();
		this->satLatitude = passedData.getLatitude();
		this->satLongitude = passedData.getLongitude();
		this->satAltitude = passedData.getAltitude();*/

		showCrafts(createdSI.getSatelliteOfficialName());
	}

	void display(int choiceValue) {
		cout << "\n";
		displaySatelliteName(choiceValue);
		displaySatelliteDesignator(choiceValue);
		displaySatelliteID(choiceValue);
		displaySatelliteAltitude(choiceValue);
		displaySatelliteLatitude(choiceValue);
		displaySatelliteLongitude(choiceValue);
	}

	virtual void showCrafts(vector<string> satOfficialName) {
		for (size_t i = 0; i < satOfficialName.size(); i++) {
			cout << "\n" << i + 1 << ". " << satOfficialName.at(i);
		}
	}

	virtual void showSatelliteList() {
		for (size_t i = 0; i < this->satID.size(); i++) {
			cout << "\n" << i + 1 << ". " << getSatelliteName(i);
		}
	}

	int satChoice() {
		int userInput;
		cout << "\n" << "Your choice: ";
		cin >> userInput;
		return userInput;
	}

	string getSatelliteID(int value) {
		return this->satID.at(value);
	}

	void displaySatelliteID(int value) {
		cout << "ID: " << getSatelliteID(value) << "\n";
	}

	string getSatelliteName(int value) {
		return this->satOfficialName.at(value);
	}

	void displaySatelliteName(int value) {
		cout << "Name: " + getSatelliteName(value) << "\n";
	}

	string getSatelliteDesignator(int value) {
		return this->satDesignator.at(value);
	}

	void displaySatelliteDesignator(int value) {
		cout << "Designation: " + getSatelliteDesignator(value) << "\n";
	}

	string getSatelliteLaunchDate(int value) {
		return this->satLaunchDate.at(value);
	}

	void displaySatelliteLaunchDater(int value) {
		cout << "LaunchDate: " + getSatelliteDesignator(value) << "\n";
	}

	string getSatelliteLongitude(int value) {
		return this->satLongitude.at(value);
	}

	void displaySatelliteLongitude(int value) {
		cout << "Longitude: " << getSatelliteLongitude(value) << "\n";
	}

	string getSatelliteLatitude(int value) {
		return this->satLatitude.at(value);
	}

	void displaySatelliteLatitude(int value) {
		cout << "Latitude: " << getSatelliteLatitude(value) << "\n";
	}

	string getSatelliteAltitude(int value) {
		return this->satAltitude.at(value);
	}

	void displaySatelliteAltitude(int value) {
		cout << "Altitude: " << getSatelliteAltitude(value) << "\n";
	}

};


int main() {
	int userInput;
	cout << "Sat Track\n";
	SatelliteInformation SI;
	APIConnection apc;
	CurrentLocation CL;
	apc.initializeAPI(CL);
	//cout << apc.outputAPIText();
	SI = apc.getSIData();
	SatData SD(SI);
	


	//SD.showCrafts(apc.getSatelliteOfficialName());
	userInput = SD.satChoice();
	SD.display(userInput - 1 );
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
