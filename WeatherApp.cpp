#include "WeatherApp.h"

using json = nlohmann::json;


WeatherApp::WeatherApp(std::string cli, const std::string& API, const std::string& cityName) {
	this->cli = new httplib::Client(cli);
	this->API = API;
	this->cityName = cityName;
}


json WeatherApp::getWeatherForFiveDays() {
	this->request = "/data/2.5/forecast?";
	this->request += "q=" + this->cityName;
	this->request += "&appid=" + this->API;

	if (auto res = this->cli->Get(request)) {

            json data = json::parse(res->body);
			return data;
	}
	else {
        std::cout <<  "Query does not complited";
		return 0;
	}
}


json WeatherApp::getCurrentWeather() {
        this->request = "/data/2.5/weather?";
        this->request += "q=" + this->cityName;
        this->request += "&appid=" + this->API;

        if (auto res = this->cli->Get(request)) {
                json data = json::parse(res->body);
                return data;
        }
        else {
            std::cout << "Query does not complited";
            return 0;
        }
    }

