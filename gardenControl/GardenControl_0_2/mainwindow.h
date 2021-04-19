#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"echoclient.h"
#include"weather.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
EchoClient sensor1;
EchoClient sensor2;
EchoClient sensor3;
EchoClient sensor4;
Weather garden1;
private slots:
  void on_btns1Relay_clicked();

  void on_btns1Connect_clicked();

  void on_btns2Connect_clicked();

  void on_btns3Connect_clicked();

  void on_btns4Connect_clicked();

  void on_btns2Relay_clicked();

  void on_btns3Relay_clicked();

  void on_btns4Relay_clicked();

  void on_btns3Connect_2_clicked();

  void on_btns3Relay_2_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
