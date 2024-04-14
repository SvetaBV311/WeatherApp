#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include "WeatherApp.h"
#include "Tools.h"


using namespace Tools;

const std::string API = "e566abb4bf71c63f4750ec1a847e21c8";

QString Qcity, Qdate, Qresult;
std::string* result = new std::string("null"); std::string* city = new std::string ("null");
std::string* date = new std::string("null");
WeatherApp* app = new WeatherApp("api.openweathermap.org", API, *city);

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
    delete city;
    city = new std::string(Qcity.toStdString());
    if (city->size() == 0) {
        ui->label->setText("Enter the city!");
    }
    else {
        delete app;
        app = new WeatherApp("api.openweathermap.org", API, *city);
        delete result;
        result = new std::string(showCurrentWeather(app->getJson("/data/2.5/weather?")));
        Qresult = QString::fromStdString(*result);

        ui->label->setText(Qresult);
    }
}


void MainWindow::on_oneDayForecast_clicked()
{
    Qcity = ui->lineEdit->text();
    Qdate = ui->lineEdit_date->text();
    delete city, delete date;
    city = new std::string(Qcity.toStdString());
    date = new std::string(Qdate.toStdString());
    if (city->size() == 0 || date->size() == 0) {
        ui->label->setText("Enter the city and the date!");
    }
    else {
        delete app;
        app = new WeatherApp("api.openweathermap.org", API, *city);
        delete result;
        result = new std::string (showOneDayWeather(app->getJson("/data/2.5/forecast?"), *date));
        Qresult = QString::fromStdString(*result);

        ui->label->setText(Qresult);
    }
}


void MainWindow::on_fiveDayForecast_clicked()
{
    Qcity = ui->lineEdit->text();
    delete city;
    city = new std::string(Qcity.toStdString());

    if (city->size() == 0) {
        ui->label->setText("Enter the city!");
    }
    else {
        delete app;
        app = new WeatherApp("api.openweathermap.org", API, *city);
        delete result;
        result = new std::string(showFiveDaysForecast(app->getJson("/data/2.5/forecast?")));
        Qresult = QString::fromStdString(*result);

        ui->label->setText(Qresult);
    }
}


void MainWindow::on_exit_clicked()
{
   QApplication::quit();
   delete app;
   delete ui;
}

