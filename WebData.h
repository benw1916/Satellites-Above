#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <nlohmann/json.hpp>
#include "UserLocation.h"
#include "SatelliteList.h"

using namespace std;
using json = nlohmann::json;

class WebData {
	SatelliteList SL;

public:
	void downloadBroadSatelliteList(UserLocation cl) {
		string rawSatelliteOutput = downloadSatelliteList(cl);
		vector<string> unformattedSatelliteList = convertSatelliteToJSON(rawSatelliteOutput);
		insertSatellitesAboveToVectors(unformattedSatelliteList);
	}

	void downloadDetailedSatellite(UserLocation cl, string passedSatelliteChoice) {
		//getSpecificSatelliteDataURL();
	}

	SatelliteList getSatelliteList() {
		return this->SL;
	}

	vector<string> getID() {
		return this->SL.getSatID();
	}

	vector<string> getSatelliteOfficialName() {
		return this->SL.getOfficialName();
	}

	vector<double> getLatitude() {
		return this->SL.getLatitude();
	}

	vector<double> getLongitude() {
		return this->SL.getLongitude();
	}

	vector<double> getAltitude() {
		return this->SL.getAltitude();
	}


private:
	string downloadSatelliteList(UserLocation udcl) {
		return cpr::Get(cpr::Url{ getSatellitesAboveURL(udcl) }).text;
	}

	string downloadSpecificSatelliteData(string passedSatelliteChoice, UserLocation udcl) {
		return cpr::Get(cpr::Url{ getSpecificSatelliteDataURL(passedSatelliteChoice, udcl) }).text;
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
			SL.insertSatellite(to_string(stringToJSON.find("satid").value()), to_string(stringToJSON.find("satname").value()), to_string(stringToJSON.find("intDesignator").value()), to_string(stringToJSON.find("launchDate").value()), stringToJSON.find("satlat").value(), stringToJSON.find("satlng").value(), stringToJSON.find("satalt").value());
		}
	}

	/*void insertSpecificSatelliteData() {
		json stringToJSON = json::parse(unformattedSatelliteList.at(p));

	}*/


	static string getAPIKey() {
		return "DARUHH-CVU8AH-H9U5KE-47PU";
	}

	static string getSatellitesAboveURL(UserLocation cl) {
		return "https://www.n2yo.com/rest/v1/satellite/above/" +  to_string(cl.getLatitude()) + "/" + to_string(cl.getLongitude()) + "/" + to_string(cl.getElevation()) + "/90/" + to_string(cl.getCategory()) + "/&apiKey=" + getAPIKey();
	}

	static string getSpecificSatelliteDataURL(string satelliteChoice, UserLocation cl) {
		return "http://www.n2yo.com/rest/v1/satellite/visualpasses/" + satelliteChoice + "/" + to_string(cl.getLatitude()) + "/" + to_string(cl.getLongitude()) + "/" + to_string(cl.getElevation()) + "/0/300/&apiKey=" + getAPIKey();
	}

};