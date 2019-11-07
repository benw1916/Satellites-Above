#pragma once

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SatelliteList {
	vector<string> satID;
	vector<string> satOfficialName;
	vector<string> satDesignator;
	vector<string> satLaunchDate;
	vector<double> satLatitude;
	vector<double> satLongitude;
	vector<double> satAltitude;

public:
	void insertSatellite(string passedID, string passedName, string passedDesignator, string passedLaunch, double passedLat, double passedLon, double passedAlt) {
		this->satID.push_back(passedID);
		this->satOfficialName.push_back(passedName);
		this->satDesignator.push_back(passedDesignator);
		this->satLaunchDate.push_back(passedLaunch);
		this->satLatitude.push_back(passedLat);
		this->satLongitude.push_back(passedLon);
		this->satAltitude.push_back(passedAlt);
	}

	void displaySatelliteList() {
		for (int i = 0; i < satOfficialName.size(); i++) {
			cout << "\n" << i + 1 << "." << satOfficialName.at(i);
		}
	}

	vector<string> getSatID() {
		return this->satID;
	}

	vector<string> getOfficialName() {
		return this->satOfficialName;
	}

	vector<string> getDesignator() {
		return this->satDesignator;
	}

	vector<string> getLaunchDate() {
		return this->satLaunchDate;
	}

	vector<double> getLatitude() {
		return this->satLatitude;
	}

	vector<double> getLongitude() {
		return this->satLongitude;
	}

	vector<double> getAltitude() {
		return this->satAltitude;
	}

};