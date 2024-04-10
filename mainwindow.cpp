#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include "WeatherApp.h"
#include "Tools.h"


using namespace Tools;

const std::string API = "e566abb4bf71c63f4750ec1a847e21c8";

QString Qcity, Qdate, Qresult; std::string result, city = "null", date;
WeatherApp* app = new WeatherApp("api.openweathermap.org", API, city);

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_currentWeather_clicked()
{
    Qcity = ui->lineEdit->text();
    city = Qcity.toStdString();
    if (city.size() == 0) {
        ui->label->setText("Enter the city!");
    }
    else {
        app = new WeatherApp("api.openweathermap.org", API, city);

        result = showCurrentWeather(app->getCurrentWeather());
        Qresult = QString::fromStdString(result);
        ui->label->setText(Qresult);
    }
}


void MainWindow::on_oneDayForecast_clicked()
{
    Qcity = ui->lineEdit->text();
    Qdate = ui->lineEdit_date->text();
    city = Qcity.toStdString();
    date = Qdate.toStdString();
    if (city.size() == 0 || date.size() == 0) {
        ui->label->setText("Enter the city and the date!");
    }
    else {
        app = new WeatherApp("api.openweathermap.org", API, city);

        result = showOneDayWeather(app->getWeatherForFiveDays(), date);
        Qresult = QString::fromStdString(result);
        ui->label->setText(Qresult);
    }
}


void MainWindow::on_fiveDayForecast_clicked()
{
    Qcity = ui->lineEdit->text();
    city = Qcity.toStdString();
    if (city.size() == 0) {
        ui->label->setText("Enter the city!");
    }
    else {
        app = new WeatherApp("api.openweathermap.org", API, city);

        result = showFiveDaysForecast(app->getWeatherForFiveDays());
        Qresult = QString::fromStdString(result);
        ui->label->setText(Qresult);
    }
}


void MainWindow::on_exit_clicked()
{
   QApplication::quit();
   delete app;
   delete ui;
}

