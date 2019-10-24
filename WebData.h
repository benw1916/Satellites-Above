#pragma once

/*class GetWebData {
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
			SI.insertSatelliteItem(to_string(stringToJSON.find("satid").value()), to_string(stringToJSON.find("satname").value()), to_string(stringToJSON.find("intDesignator").value()), to_string(stringToJSON.find("launchDate").value()), to_string(stringToJSON.find("satlat").value()), to_string(stringToJSON.find("satlng").value()), to_string(stringToJSON.find("satalt").value()));
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

};*/