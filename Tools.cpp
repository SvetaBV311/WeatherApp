#include "Tools.h"
#include<string>

using json = nlohmann::json;


std::string Tools::showFiveDaysForecast(const json& data) {
    try {
        if (data["cod"] == "200" ) {
        std::string res;
        int index = 0, counter, index_2; float sum; std:: string date, date2;
            while (index < data["list"].size()) {
                date = data["list"][index]["dt_txt"];
                date.erase(10);
                index_2 = index + 1;
                date2 = data["list"][index_2]["dt_txt"];
                date2.erase(10);
                counter = 1; sum = data["list"][index]["main"]["temp"];
                while (date2 == date) {
                    counter += 1;
                    sum += data["list"][index_2]["main"]["temp"].get<double>();
                    index_2 += 1;
                    if (index_2 >= data["list"].size()) { break; }
                    date2 = data["list"][index_2]["dt_txt"];
                    date2.erase(10);
                }
                res += date + " Temp: ";

                if (sum / counter - 273.15 > 0) {
                    res += "+";
                }
                int res1 = std::round(sum / counter - 273.15);

                std::string res_str = std::to_string(res1);

                res += res_str + " C\n";
                index = index_2;
                }
            return res;
        }

        else {throw 1;}
    }
    catch (int g) {
        return "HttpError: " + to_string(data["cod"]);
    }
}



std::string Tools::showOneDayWeather(const json& data, const std::string& ndate) {
    try {
        if (data["cod"] == "200") {
        std::cout << std::endl;
        int counter = 0; float sum = 0; std::string date;
        for (int index = 0; index < data["list"].size(); index++) {
            date = data["list"][index]["dt_txt"];
            date.erase(10);
            if (ndate == date) {
                counter += 1;
                 sum += data["list"][index]["main"]["temp"].get<double>();  // указываем, какой тип данных получаем
            }
        }
        std::string res;
        res += " Temp: ";

        if (counter != 0) {
            if (sum / counter - 273.15 > 0) {
                res +=  "+";
            }

            int res1 = std::round(sum / counter - 273.15);
            std::string res_str = std::to_string(res1);

            res += res_str + " C\n";
        }
        else {
            res = "Incorrect date!";
        }
        return res;
        }

        else {throw 1;}
    }
    catch (int g) {
        return "HttpError: " + to_string(data["cod"]);
    }
}



std::string Tools::showCurrentWeather(const json& data) {
    std::string res, weather;
    res += "Current weather: ";
    try {
        if ( data["cod"] == 200) {
            auto resd = data["main"]["temp"].get<double>();
            weather = data["weather"][0]["main"].get<std::string>();
            weather += "\nTemp: ";

            if (resd - 273.15 > 0) {
                res += "+";
            }

            int res1 = std::round(resd - 273.15);

            std::string res_str = std::to_string(res1);

            res += res_str + " C\nFeels like: ";

            if (data["main"]["feels_like"].get<double>() - 273.15 > 0) {
                res += "+";
            }

            res1 = std::round(data["main"]["feels_like"].get<double>() - 273.15);
            res_str = std::to_string(res1);

            res += res_str + " C";
            return res;
        }

        else {throw 1;}
    }
    catch (int g) {
        return "HttpError: " + to_string(data["cod"]);
    }
}

