#pragma once

#include <string>

using namespace std;

class CategoryData {

	string satCategory[52] = { "Amateur radio", "Beidou Navigation System", "Brightest", "Celestis", "CubeSats", "Disaster monitoring", "Earth resources", "Education", "Engineering" "Experimental", "Flock", "Galileo", "Geodetic", "Geostationary", "Global Positioning System(GPS) Constellation", "Global Positioning System(GPS) Operational", "Globalstar", "Glonass Constellation", "Glonass Operational", "GOES", "Gonets", "Gorizont", "Intelsat", "Iridium", "IRNSS", "ISS", "Lemur", "Military", "Molniya", "Navy Navigation Satellite System", "NOAA", "O3B Networks", "Orbcomm", "Parus", "QZSS", "Radar Calibration", "Raduga", "Russian LEO Navigation", "Satellite - Based Augmentation System", "Search & rescue", "Space & Earth Science", "Starlink", "Strela", "Tracking and Data Relay Satellite System", "Tselina", "Tsikada", "Tsiklon", "TV", "Weather", "Westford Needles", "XM and Sirius", "Yaogan" };
	int satCategoryValue[52] = { 18, 35, 1, 45, 32, 8, 6, 29, 28, 19, 48, 22, 27, 10, 50, 20, 17, 51, 21, 5, 40, 12, 11, 15, 46, 2, 49, 30, 14, 24, 4, 43, 16, 38, 47, 31, 13, 25, 23, 7, 26, 52, 39, 9, 44, 42, 41, 34, 3, 37, 33, 36 };

public:
	int getSatValue(int userChoice) {
		return satCategoryValue[userChoice];
	}

	string getSatCategory(int userChoice) {
		return satCategory[userChoice];
	}

	static int getSatCategorySize() {
		return sizeof(satCategory) / sizeof(satCategory[0]);
	}
};