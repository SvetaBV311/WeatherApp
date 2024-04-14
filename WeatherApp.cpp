#include "WeatherApp.h"

using json = nlohmann::json;


WeatherApp::WeatherApp(std::string cli, const std::string& API, const std::string& cityName) {
	this->cli = new httplib::Client(cli);
	this->API = API;
	this->cityName = cityName;
}


json WeatherApp::getJson(std::string request) {

    request += "q=" + this->cityName;
    request += "&appid=" + this->API;

	if (auto res = this->cli->Get(request)) {

            json data = json::parse(res->body);
			return data;
	}
	else {
        std::cout <<  "Query does not complited";
		return 0;
	}
}


