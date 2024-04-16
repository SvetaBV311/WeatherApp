
#pragma once
#include <string>
#include "httplib.h"
#include <nlohmann/json.hpp>


class WeatherApp {
	std::string API;
	httplib::Client *cli;
    std::string cityName;
    std::string request;

public:

    WeatherApp(std::string cli, const std::string& API, const std::string& cityName);

    nlohmann::json getJson(std::string request);

};
