// SatTrack.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
#include <stdio.h>

#include "CurrentLocation.h"
#include "WebData.h"
#include "SatelliteData.h"

using namespace std;

//  https://www.n2yo.com/rest/v1/satellite/above/42.331429/-83.045753/656/70/18/&apiKey=DARUHH-CVU8AH-H9U5KE-47PU
// API Key: DARUHH-CVU8AH-H9U5KE-47PU

// Detroit Longitude: -83.045753	Latitude: 42.331429		Elevation: 200 meters

int main() {
	int userInput;
	cout << "Sat Track\n";
	SatelliteData SI;
	CurrentLocation CL(-83.045, 42.331, 200.0);
	BatchList SatList;
	WebData apc;

	apc.downloadBroadSatelliteList(CL);
	SatList = apc.getSatelliteList();

	SatList.displaySatelliteList();
	userInput = SI.chooseSpecificSatellite();
	cout << userInput;
	string specificSatelliteData = apc.downloadSpecificSatelliteData(userInput, CL);
	cout << specificSatelliteData;
//	SI.display(userInput - 1);


	/*SatelliteLocation SL;
	apc.pullDownWebData(CL);
	SI = apc.getSatelliteData();

	SI.showSatelliteList();
	userInput = SI.satChoice();
	SI.display(userInput - 1 );*/
//	sl = SI.outputToClass(userInput - 1);
	return 0;
}
