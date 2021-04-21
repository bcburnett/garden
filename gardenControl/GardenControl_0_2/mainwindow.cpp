#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "echoclient.h"
#include<functional>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){ui->setupUi(this);}

MainWindow::~MainWindow(){delete ui;}


void MainWindow::on_btns1Connect_clicked(){
    sensor1.disconnect();
    sensor1.Echoinit(QUrl("ws://192.168.1.105/ws"),[=](QVariantMap json_map){
    ui->lbls1moist->setText( json_map["moisture"].toString());
    ui->lbls1Relay->setText( json_map["relay"].toString());
    });
}

void MainWindow::on_btns2Connect_clicked(){
    sensor2.disconnect();
    sensor2.Echoinit(QUrl("ws://192.168.1.130/ws"),[=](QVariantMap json_map){
    ui->lbls2moist->setText( json_map["moisture"].toString());
    ui->lbls2Relay->setText( json_map["relay"].toString());
    });
}

void MainWindow::on_btns3Connect_clicked(){
    sensor3.disconnect();
    sensor3.Echoinit(QUrl("ws://192.168.1.129/ws"),[=](QVariantMap json_map){
    ui->lbls3moist->setText( json_map["moisture"].toString());
    ui->lbls3Relay->setText( json_map["relay"].toString());
    });
}

void MainWindow::on_btns4Connect_clicked(){
    sensor4.disconnect();
    sensor4.Echoinit(QUrl("ws://192.168.1.128/ws"),[=](QVariantMap json_map){
    ui->lbls4moist->setText( json_map["moisture"].toString());
    ui->lbls4Relay->setText( json_map["relay"].toString());
    });
}

void MainWindow::on_btns3Connect_2_clicked(){
    sensor1.disconnect();
    garden1.Echoinit(QUrl("ws://192.168.1.124/ws"),[=](QVariantMap json_map){
        ui->lblPumpStatus->setText( json_map["status"].toString());
        ui->lblPumpRelay->setText( json_map["relay"].toString());
        ui->lblPumpTemp->setText( json_map["temperature"].toString());
        ui->lblPumpPressure->setText( json_map["pressure"].toString());
        ui->lblPumpHumidity->setText( json_map["humidity"].toString());
  });
}

void MainWindow::on_btns1Relay_clicked(){sensor1.sendMessage("relay");}

void MainWindow::on_btns2Relay_clicked(){sensor2.sendMessage("relay");}

void MainWindow::on_btns3Relay_clicked(){sensor3.sendMessage("relay");}

void MainWindow::on_btns4Relay_clicked(){sensor4.sendMessage("relay");}

void MainWindow::on_btns3Relay_2_clicked(){garden1.sendMessage("relay");}

