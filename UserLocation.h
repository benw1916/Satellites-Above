#pragma once
#include "pch.h"
#include <iostream>
#include <string>

#include "CategoryData.h"

using namespace std;

class UserLocation {
	double longitude;
	double latitude;
	double elevation;
	int satelliteCategory;
	string satelliteCategories[52] = { "Amateur radio", "Beidou Navigation System", "Brightest", "Celestis", "CubeSats", "Disaster monitoring", "Earth resources", "Education", "Engineering" "Experimental", "Flock", "Galileo", "Geodetic", "Geostationary", "Global Positioning System(GPS) Constellation", "Global Positioning System(GPS) Operational", "Globalstar", "Glonass Constellation", "Glonass Operational", "GOES", "Gonets", "Gorizont", "Intelsat", "Iridium", "IRNSS", "ISS", "Lemur", "Military", "Molniya", "Navy Navigation Satellite System", "NOAA", "O3B Networks", "Orbcomm", "Parus", "QZSS", "Radar Calibration", "Raduga", "Russian LEO Navigation", "Satellite - Based Augmentation System", "Search & rescue", "Space & Earth Science", "Starlink", "Strela", "Tracking and Data Relay Satellite System", "Tselina", "Tsikada", "Tsiklon", "TV", "Weather", "Westford Needles", "XM and Sirius", "Yaogan" };
	int satelliteValues[52] = { 18, 35, 1, 45, 32, 8, 6, 29, 28, 19, 48, 22, 27, 10, 50, 20, 17, 51, 21, 5, 40, 12, 11, 15, 46, 2, 49, 30, 14, 24, 4, 43, 16, 38, 47, 31, 13, 25, 23, 7, 26, 52, 39, 9, 44, 42, 41, 34, 3, 37, 33, 36 };

public:
	UserLocation() {
		setLongitude();
		setLatitude();
		setElevation();
		displaySatelliteCategories();
		/*this->longitude = "-83.045753"; // This is for testing purposes; I get sick of typing them.
		this->latitude = "42.331429";
		this->elevation = "200";*/
	}

	UserLocation(double passedLong, double passedLat, double passedEle) {
		this->longitude = passedLong;
		this->latitude = passedLat;
		this->elevation = passedEle;
		displaySatelliteCategories();
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
		for (int i = 0; i <= (sizeof(satelliteCategories) / sizeof(satelliteCategories[0])); i++) {
			cout << "\n" << i + 1 << ". " << CategoryData().getSatCategory(i);
		}
		cout << "\nYour choice: ";
		cin >> satelliteChoice;
		this->satelliteCategory = satelliteValues[satelliteChoice];
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

	int getCategory() {
		return this->satelliteCategory;
	}
};