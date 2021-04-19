#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "echoclient.h"


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_btns1Relay_clicked()
{
    sensor1.sendMessage("relay");

}


void MainWindow::on_btns1Connect_clicked()
{
      sensor1.Echoinit(QUrl("ws://192.168.1.105/ws"), ui->lbls1moist, ui->lbls1Relay);
}


void MainWindow::on_btns2Connect_clicked()
{
  sensor2.Echoinit(QUrl("ws://192.168.1.130/ws"), ui->lbls2moist, ui->lbls2Relay);
}


void MainWindow::on_btns3Connect_clicked()
{
  sensor3.Echoinit(QUrl("ws://192.168.1.129/ws"), ui->lbls3moist, ui->lbls3Relay);
}


void MainWindow::on_btns4Connect_clicked()
{
  sensor4.Echoinit(QUrl("ws://192.168.1.128/ws"), ui->lbls4moist, ui->lbls4Relay);
}


void MainWindow::on_btns2Relay_clicked()
{
    sensor2.sendMessage("relay");
}


void MainWindow::on_btns3Relay_clicked()
{
    sensor3.sendMessage("relay");
}


void MainWindow::on_btns4Relay_clicked()
{
    sensor4.sendMessage("relay");
}


void MainWindow::on_btns3Connect_2_clicked()
{
    garden1.Weatherinit(QUrl("ws://192.168.1.124/ws"),
                        ui->lblPumpStatus,
                        ui->lblPumpRelay,
                        ui->lblPumpTemp,
                        ui->lblPumpPressure,
                        ui->lblPumpHumidity);
}


void MainWindow::on_btns3Relay_2_clicked()
{
    garden1.sendMessage("relay");
}

