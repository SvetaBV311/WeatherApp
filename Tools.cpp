#include "Tools.h"
#include<string>

using json = nlohmann::json;


std::string Tools::showFiveDaysForecast(const json& data) {
    try {
        if (data["cod"] == "200" ) {
        std::string res;
            int* index = new int (0); int* counter = new int(); int* index_2 = new int(); int* res1 = new int();
            float* sum = new float(); std:: string* date = new std::string(); std:: string* date2 = new std::string();
            while (*index < data["list"].size()) {
                *date = data["list"][*index]["dt_txt"];
                date->erase(10);
                *index_2 = *index + 1;
                *date2 = data["list"][*index_2]["dt_txt"];
                date2->erase(10);
                *counter = 1; *sum = data["list"][*index]["main"]["temp"];
                while (*date2 == *date) {
                    *counter += 1;
                    *sum += data["list"][*index_2]["main"]["temp"].get<double>();
                    *index_2 += 1;
                    if (*index_2 >= data["list"].size()) { break; }
                    *date2 = data["list"][*index_2]["dt_txt"];
                    date2->erase(10);
                }
                res += *date + " Temp: ";

                if (*sum / *counter - 273.15 > 0) {
                    res += "+";
                }
                *res1 = std::round(*sum / *counter - 273.15);

                res += std::to_string(*res1) + " C\n";
                *index = *index_2;
            }
            delete index, delete counter, delete index_2, delete res1, delete sum, delete date, delete date2;
            return res;
        }

        else {throw 400;}
    }
    catch (int g) {
        return "HttpError: " + to_string(data["cod"]);
    }
}



std::string Tools::showOneDayWeather(const json& data, const std::string& ndate) {
    try {
        if (data["cod"] == "200") {
            std::cout << std::endl;
            int* counter = new int (0); int* index = new int (); int* res1 = new int ();
            float* sum = new float (0); std::string* date = new std::string();
            for (*index = 0; *index < data["list"].size(); *index+=1) {
                *date = data["list"][*index]["dt_txt"];
                date->erase(10);
                if (ndate == *date) {
                    *counter += 1;
                    *sum += data["list"][*index]["main"]["temp"].get<double>();
                }
            }
            std::string res;
            res += " Temp: ";

            if (*counter != 0) {
                if (*sum / *counter - 273.15 > 0) {
                    res +=  "+";
                }

                *res1 = std::round(*sum / *counter - 273.15);

                res += std::to_string(*res1) + " C\n";
            }
            else {
                res = "Incorrect date!";
            }
            delete counter, delete index, delete res1, delete sum, delete date;
            return res;
        }

        else {throw 400;}
    }
    catch (int g) {
        return "HttpError: " + to_string(data["cod"]);
    }
}



std::string Tools::showCurrentWeather(const json& data) {
    try {
        if ( data["cod"] == 200) {
            std::string res; int* res1 = new int ();
            res += "Current weather: ";
            res += data["weather"][0]["main"].get<std::string>();
            res += "\nTemp: ";

            if ( data["main"]["temp"].get<double>() - 273.15 > 0) {
                res += "+";
            }

            *res1 = std::round( data["main"]["temp"].get<double>() - 273.15);

            res += std::to_string(*res1) + " C\nFeels like: ";

            if (data["main"]["feels_like"].get<double>() - 273.15 > 0) {
                res += "+";
            }

            *res1 = std::round(data["main"]["feels_like"].get<double>() - 273.15);

            res += std::to_string(*res1) + " C";

            delete res1;
            return res;
        }

        else {throw 400;}
    }
    catch (int g) {
        return "HttpError: " + to_string(data["cod"]);
    }
}

