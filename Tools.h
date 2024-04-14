#pragma once
#include <iostream>
#include <nlohmann/json.hpp>

#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Tools {
    std::string showFiveDaysForecast(const nlohmann::json& data);
    std::string showCurrentWeather(const nlohmann::json& data);
    std::string showOneDayWeather(const nlohmann::json& data, const std::string& ndate);
    //void showMenu();
}


