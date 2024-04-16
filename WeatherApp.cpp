#include "WeatherApp.h"

using json = nlohmann::json;


WeatherApp::WeatherApp(std::string cli, const std::string& API, const std::string& cityName) {
	this->cli = new httplib::Client(cli);
	this->API = API;
	this->cityName = cityName;
}


json WeatherApp::getJson(std::string request) {

    this->request = request;
    this->request += "q=" + this->cityName;
    this->request += "&appid=" + this->API;

    if (auto res = this->cli->Get(this->request)) {

            json data = json::parse(res->body);
			return data;
	}
	else {
        std::cout <<  "Query does not complited";
		return 0;
	}
}


