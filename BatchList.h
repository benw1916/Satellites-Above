#pragma once

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BatchList {
	vector<string> satID;
	vector<string> satOfficialName;
	vector<string> satDesignator;
	vector<string> satLaunchDate;
	vector<string> satLatitude;
	vector<string> satLongitude;
	vector<string> satAltitude;

public:
	void insertSatelliteItem(string passedID, string passedName, string passedDesignator, string passedLaunch, string passedLat, string passedLon, string passedAlt) {
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

	vector<string> getLatitude() {
		return this->satLatitude;
	}

	vector<string> getLongitude() {
		return this->satLongitude;
	}

	vector<string> getAltitude() {
		return this->satAltitude;
	}

};