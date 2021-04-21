/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_8;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *lbls3moist;
    QLabel *label_16;
    QLabel *lbls3Relay;
    QPushButton *btns3Connect;
    QPushButton *btns3Relay;
    QFormLayout *formLayout_9;
    QLabel *label_9;
    QLabel *lbls4moist;
    QLabel *label_17;
    QLabel *lbls4Relay;
    QPushButton *btns4Relay;
    QPushButton *btns4Connect;
    QLabel *label_4;
    QFormLayout *formLayout_6;
    QLabel *label;
    QLabel *label_6;
    QLabel *lbls1moist;
    QLabel *label_14;
    QLabel *lbls1Relay;
    QPushButton *btns1Relay;
    QPushButton *btns1Connect;
    QPushButton *btns3Relay_2;
    QFormLayout *formLayout_7;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *lbls2moist;
    QLabel *label_15;
    QLabel *lbls2Relay;
    QPushButton *btns2Relay;
    QPushButton *btns2Connect;
    QWidget *formWidget_5;
    QFormLayout *formLayout_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *lblPumpTemp;
    QLabel *label_12;
    QLabel *lblPumpHumidity;
    QLabel *label_13;
    QLabel *lblPumpPressure;
    QLabel *lblPumpStatus;
    QLabel *label_5;
    QLabel *lblPumpRelay;
    QLabel *label_18;
    QPushButton *btns3Connect_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(484, 559);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 10, 431, 498));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        formLayout_8->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        label_3->setAlignment(Qt::AlignCenter);

        formLayout_8->setWidget(0, QFormLayout::SpanningRole, label_3);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8(""));

        formLayout_8->setWidget(1, QFormLayout::LabelRole, label_8);

        lbls3moist = new QLabel(gridLayoutWidget);
        lbls3moist->setObjectName(QString::fromUtf8("lbls3moist"));
        lbls3moist->setStyleSheet(QString::fromUtf8(""));

        formLayout_8->setWidget(1, QFormLayout::FieldRole, lbls3moist);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("width: 100%;\n"
"height: 100%"));

        formLayout_8->setWidget(2, QFormLayout::LabelRole, label_16);

        lbls3Relay = new QLabel(gridLayoutWidget);
        lbls3Relay->setObjectName(QString::fromUtf8("lbls3Relay"));
        lbls3Relay->setStyleSheet(QString::fromUtf8(""));

        formLayout_8->setWidget(2, QFormLayout::FieldRole, lbls3Relay);

        btns3Connect = new QPushButton(gridLayoutWidget);
        btns3Connect->setObjectName(QString::fromUtf8("btns3Connect"));
        btns3Connect->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        formLayout_8->setWidget(4, QFormLayout::SpanningRole, btns3Connect);

        btns3Relay = new QPushButton(gridLayoutWidget);
        btns3Relay->setObjectName(QString::fromUtf8("btns3Relay"));
        btns3Relay->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        formLayout_8->setWidget(3, QFormLayout::SpanningRole, btns3Relay);


        gridLayout->addLayout(formLayout_8, 1, 0, 1, 1);

        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_9->setWidget(1, QFormLayout::LabelRole, label_9);

        lbls4moist = new QLabel(gridLayoutWidget);
        lbls4moist->setObjectName(QString::fromUtf8("lbls4moist"));

        formLayout_9->setWidget(1, QFormLayout::FieldRole, lbls4moist);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_9->setWidget(2, QFormLayout::LabelRole, label_17);

        lbls4Relay = new QLabel(gridLayoutWidget);
        lbls4Relay->setObjectName(QString::fromUtf8("lbls4Relay"));

        formLayout_9->setWidget(2, QFormLayout::FieldRole, lbls4Relay);

        btns4Relay = new QPushButton(gridLayoutWidget);
        btns4Relay->setObjectName(QString::fromUtf8("btns4Relay"));
        btns4Relay->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        formLayout_9->setWidget(3, QFormLayout::SpanningRole, btns4Relay);

        btns4Connect = new QPushButton(gridLayoutWidget);
        btns4Connect->setObjectName(QString::fromUtf8("btns4Connect"));
        btns4Connect->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        formLayout_9->setWidget(4, QFormLayout::SpanningRole, btns4Connect);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        label_4->setAlignment(Qt::AlignCenter);

        formLayout_9->setWidget(0, QFormLayout::SpanningRole, label_4);


        gridLayout->addLayout(formLayout_9, 1, 1, 1, 1);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        label->setAlignment(Qt::AlignCenter);

        formLayout_6->setWidget(0, QFormLayout::SpanningRole, label);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_6);

        lbls1moist = new QLabel(gridLayoutWidget);
        lbls1moist->setObjectName(QString::fromUtf8("lbls1moist"));

        formLayout_6->setWidget(1, QFormLayout::FieldRole, lbls1moist);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, label_14);

        lbls1Relay = new QLabel(gridLayoutWidget);
        lbls1Relay->setObjectName(QString::fromUtf8("lbls1Relay"));

        formLayout_6->setWidget(2, QFormLayout::FieldRole, lbls1Relay);

        btns1Relay = new QPushButton(gridLayoutWidget);
        btns1Relay->setObjectName(QString::fromUtf8("btns1Relay"));
        btns1Relay->setAutoFillBackground(false);
        btns1Relay->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        formLayout_6->setWidget(3, QFormLayout::SpanningRole, btns1Relay);

        btns1Connect = new QPushButton(gridLayoutWidget);
        btns1Connect->setObjectName(QString::fromUtf8("btns1Connect"));
        btns1Connect->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        formLayout_6->setWidget(4, QFormLayout::SpanningRole, btns1Connect);


        gridLayout->addLayout(formLayout_6, 0, 0, 1, 1);

        btns3Relay_2 = new QPushButton(gridLayoutWidget);
        btns3Relay_2->setObjectName(QString::fromUtf8("btns3Relay_2"));
        btns3Relay_2->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        gridLayout->addWidget(btns3Relay_2, 3, 0, 1, 2);

        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        label_2->setAlignment(Qt::AlignCenter);

        formLayout_7->setWidget(0, QFormLayout::SpanningRole, label_2);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_7);

        lbls2moist = new QLabel(gridLayoutWidget);
        lbls2moist->setObjectName(QString::fromUtf8("lbls2moist"));

        formLayout_7->setWidget(1, QFormLayout::FieldRole, lbls2moist);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_7->setWidget(2, QFormLayout::LabelRole, label_15);

        lbls2Relay = new QLabel(gridLayoutWidget);
        lbls2Relay->setObjectName(QString::fromUtf8("lbls2Relay"));

        formLayout_7->setWidget(2, QFormLayout::FieldRole, lbls2Relay);

        btns2Relay = new QPushButton(gridLayoutWidget);
        btns2Relay->setObjectName(QString::fromUtf8("btns2Relay"));
        btns2Relay->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        formLayout_7->setWidget(3, QFormLayout::SpanningRole, btns2Relay);

        btns2Connect = new QPushButton(gridLayoutWidget);
        btns2Connect->setObjectName(QString::fromUtf8("btns2Connect"));
        btns2Connect->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        formLayout_7->setWidget(4, QFormLayout::SpanningRole, btns2Connect);


        gridLayout->addLayout(formLayout_7, 0, 1, 1, 1);

        formWidget_5 = new QWidget(gridLayoutWidget);
        formWidget_5->setObjectName(QString::fromUtf8("formWidget_5"));
        formWidget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));
        formLayout_5 = new QFormLayout(formWidget_5);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_10 = new QLabel(formWidget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formWidget_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_11);

        lblPumpTemp = new QLabel(formWidget_5);
        lblPumpTemp->setObjectName(QString::fromUtf8("lblPumpTemp"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, lblPumpTemp);

        label_12 = new QLabel(formWidget_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_12);

        lblPumpHumidity = new QLabel(formWidget_5);
        lblPumpHumidity->setObjectName(QString::fromUtf8("lblPumpHumidity"));

        formLayout_5->setWidget(3, QFormLayout::FieldRole, lblPumpHumidity);

        label_13 = new QLabel(formWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_13);

        lblPumpPressure = new QLabel(formWidget_5);
        lblPumpPressure->setObjectName(QString::fromUtf8("lblPumpPressure"));

        formLayout_5->setWidget(4, QFormLayout::FieldRole, lblPumpPressure);

        lblPumpStatus = new QLabel(formWidget_5);
        lblPumpStatus->setObjectName(QString::fromUtf8("lblPumpStatus"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lblPumpStatus);

        label_5 = new QLabel(formWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_5->setWidget(5, QFormLayout::LabelRole, label_5);

        lblPumpRelay = new QLabel(formWidget_5);
        lblPumpRelay->setObjectName(QString::fromUtf8("lblPumpRelay"));

        formLayout_5->setWidget(5, QFormLayout::FieldRole, lblPumpRelay);

        label_18 = new QLabel(formWidget_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 160, 0);"));
        label_18->setAlignment(Qt::AlignCenter);

        formLayout_5->setWidget(0, QFormLayout::SpanningRole, label_18);


        gridLayout->addWidget(formWidget_5, 2, 0, 1, 2);

        btns3Connect_2 = new QPushButton(gridLayoutWidget);
        btns3Connect_2->setObjectName(QString::fromUtf8("btns3Connect_2"));
        btns3Connect_2->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        gridLayout->addWidget(btns3Connect_2, 4, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 484, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Garden Control Panel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Sensor: 3", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Moisture:", nullptr));
        lbls3moist->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        lbls3Relay->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        btns3Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        btns3Relay->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Moisture:", nullptr));
        lbls4moist->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        lbls4Relay->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        btns4Relay->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        btns4Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Sensor: 4", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sensor: 1", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Moisture:", nullptr));
        lbls1moist->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        lbls1Relay->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        btns1Relay->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        btns1Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        btns3Relay_2->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Sensor: 2", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Moisture:", nullptr));
        lbls2moist->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        lbls2Relay->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        btns2Relay->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        btns2Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Temp", nullptr));
        lblPumpTemp->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        lblPumpHumidity->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Pressure", nullptr));
        lblPumpPressure->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lblPumpStatus->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        lblPumpRelay->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Pump Control", nullptr));
        btns3Connect_2->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
