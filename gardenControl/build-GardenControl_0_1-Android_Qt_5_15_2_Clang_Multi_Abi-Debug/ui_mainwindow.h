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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_4;
    QWidget *formWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_9;
    QLabel *lbls4moist;
    QLabel *label_17;
    QLabel *lbls4Relay;
    QPushButton *btns4Relay;
    QPushButton *btns4Connect;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *formWidget;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLabel *lbls1moist;
    QLabel *label_14;
    QLabel *lbls1Relay;
    QPushButton *btns1Relay;
    QPushButton *btns1Connect;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QWidget *formWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QLabel *lbls2moist;
    QLabel *label_15;
    QLabel *lbls2Relay;
    QPushButton *btns2Relay;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btns2Connect;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_5;
    QWidget *formWidget_5;
    QFormLayout *formLayout_5;
    QLabel *label_10;
    QLabel *lblPumpStatus;
    QLabel *label_11;
    QLabel *lblPumpTemp;
    QLabel *label_12;
    QLabel *lblPumpHumidity;
    QLabel *label_13;
    QLabel *lblPumpPressure;
    QSpacerItem *verticalSpacer;
    QWidget *verticalWidget_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QWidget *formWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_8;
    QLabel *lbls3moist;
    QLabel *lbls3Relay;
    QLabel *label_16;
    QPushButton *btns3Relay;
    QPushButton *btns3Connect;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(120, 15, 571, 454));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));

        verticalLayout_9->addWidget(label_4);

        formWidget_4 = new QWidget(gridLayoutWidget);
        formWidget_4->setObjectName(QString::fromUtf8("formWidget_4"));
        formWidget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));
        formLayout_4 = new QFormLayout(formWidget_4);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_9 = new QLabel(formWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_9);

        lbls4moist = new QLabel(formWidget_4);
        lbls4moist->setObjectName(QString::fromUtf8("lbls4moist"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lbls4moist);

        label_17 = new QLabel(formWidget_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_17);

        lbls4Relay = new QLabel(formWidget_4);
        lbls4Relay->setObjectName(QString::fromUtf8("lbls4Relay"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lbls4Relay);


        verticalLayout_9->addWidget(formWidget_4);

        btns4Relay = new QPushButton(gridLayoutWidget);
        btns4Relay->setObjectName(QString::fromUtf8("btns4Relay"));
        btns4Relay->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        verticalLayout_9->addWidget(btns4Relay);

        btns4Connect = new QPushButton(gridLayoutWidget);
        btns4Connect->setObjectName(QString::fromUtf8("btns4Connect"));
        btns4Connect->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        verticalLayout_9->addWidget(btns4Connect);


        gridLayout->addLayout(verticalLayout_9, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));

        verticalLayout->addWidget(label);

        formWidget = new QWidget(gridLayoutWidget);
        formWidget->setObjectName(QString::fromUtf8("formWidget"));
        formWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));
        formLayout = new QFormLayout(formWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_6 = new QLabel(formWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        lbls1moist = new QLabel(formWidget);
        lbls1moist->setObjectName(QString::fromUtf8("lbls1moist"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lbls1moist);

        label_14 = new QLabel(formWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_14);

        lbls1Relay = new QLabel(formWidget);
        lbls1Relay->setObjectName(QString::fromUtf8("lbls1Relay"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lbls1Relay);


        verticalLayout->addWidget(formWidget);

        btns1Relay = new QPushButton(gridLayoutWidget);
        btns1Relay->setObjectName(QString::fromUtf8("btns1Relay"));
        btns1Relay->setAutoFillBackground(false);
        btns1Relay->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        verticalLayout->addWidget(btns1Relay);

        btns1Connect = new QPushButton(gridLayoutWidget);
        btns1Connect->setObjectName(QString::fromUtf8("btns1Connect"));
        btns1Connect->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        verticalLayout->addWidget(btns1Connect);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));

        verticalLayout_3->addWidget(label_2);

        formWidget_2 = new QWidget(gridLayoutWidget);
        formWidget_2->setObjectName(QString::fromUtf8("formWidget_2"));
        formWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));
        formLayout_2 = new QFormLayout(formWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_7 = new QLabel(formWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        lbls2moist = new QLabel(formWidget_2);
        lbls2moist->setObjectName(QString::fromUtf8("lbls2moist"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lbls2moist);

        label_15 = new QLabel(formWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_15);

        lbls2Relay = new QLabel(formWidget_2);
        lbls2Relay->setObjectName(QString::fromUtf8("lbls2Relay"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lbls2Relay);


        verticalLayout_3->addWidget(formWidget_2);

        btns2Relay = new QPushButton(gridLayoutWidget);
        btns2Relay->setObjectName(QString::fromUtf8("btns2Relay"));
        btns2Relay->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        verticalLayout_3->addWidget(btns2Relay);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        btns2Connect = new QPushButton(gridLayoutWidget);
        btns2Connect->setObjectName(QString::fromUtf8("btns2Connect"));
        btns2Connect->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        verticalLayout_5->addWidget(btns2Connect);


        verticalLayout_3->addLayout(verticalLayout_5);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 1, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));

        verticalLayout_11->addWidget(label_5);

        formWidget_5 = new QWidget(gridLayoutWidget);
        formWidget_5->setObjectName(QString::fromUtf8("formWidget_5"));
        formWidget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));
        formLayout_5 = new QFormLayout(formWidget_5);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_10 = new QLabel(formWidget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_10);

        lblPumpStatus = new QLabel(formWidget_5);
        lblPumpStatus->setObjectName(QString::fromUtf8("lblPumpStatus"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lblPumpStatus);

        label_11 = new QLabel(formWidget_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_11);

        lblPumpTemp = new QLabel(formWidget_5);
        lblPumpTemp->setObjectName(QString::fromUtf8("lblPumpTemp"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lblPumpTemp);

        label_12 = new QLabel(formWidget_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_12);

        lblPumpHumidity = new QLabel(formWidget_5);
        lblPumpHumidity->setObjectName(QString::fromUtf8("lblPumpHumidity"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, lblPumpHumidity);

        label_13 = new QLabel(formWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_13);

        lblPumpPressure = new QLabel(formWidget_5);
        lblPumpPressure->setObjectName(QString::fromUtf8("lblPumpPressure"));

        formLayout_5->setWidget(3, QFormLayout::FieldRole, lblPumpPressure);


        verticalLayout_11->addWidget(formWidget_5);


        gridLayout->addLayout(verticalLayout_11, 4, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        verticalWidget_5 = new QWidget(gridLayoutWidget);
        verticalWidget_5->setObjectName(QString::fromUtf8("verticalWidget_5"));
        verticalWidget_5->setAutoFillBackground(false);
        verticalLayout_6 = new QVBoxLayout(verticalWidget_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_3 = new QLabel(verticalWidget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));

        verticalLayout_6->addWidget(label_3);

        formWidget_3 = new QWidget(verticalWidget_5);
        formWidget_3->setObjectName(QString::fromUtf8("formWidget_3"));
        formWidget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));
        formLayout_3 = new QFormLayout(formWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_8 = new QLabel(formWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_8);

        lbls3moist = new QLabel(formWidget_3);
        lbls3moist->setObjectName(QString::fromUtf8("lbls3moist"));
        lbls3moist->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lbls3moist);

        lbls3Relay = new QLabel(formWidget_3);
        lbls3Relay->setObjectName(QString::fromUtf8("lbls3Relay"));
        lbls3Relay->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lbls3Relay);

        label_16 = new QLabel(formWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("width: 100%;\n"
"height: 100%"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_16);


        verticalLayout_6->addWidget(formWidget_3);

        btns3Relay = new QPushButton(verticalWidget_5);
        btns3Relay->setObjectName(QString::fromUtf8("btns3Relay"));
        btns3Relay->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        verticalLayout_6->addWidget(btns3Relay);

        btns3Connect = new QPushButton(verticalWidget_5);
        btns3Connect->setObjectName(QString::fromUtf8("btns3Connect"));
        btns3Connect->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));

        verticalLayout_6->addWidget(btns3Connect);


        gridLayout->addWidget(verticalWidget_5, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
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
        label_4->setText(QCoreApplication::translate("MainWindow", "Sensor: 4", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Moisture:", nullptr));
        lbls4moist->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        lbls4Relay->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        btns4Relay->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        btns4Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sensor: 1", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Moisture:", nullptr));
        lbls1moist->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        lbls1Relay->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        btns1Relay->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        btns1Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Sensor: 2", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Moisture:", nullptr));
        lbls2moist->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        lbls2Relay->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        btns2Relay->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        btns2Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Weather", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        lblPumpStatus->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Temp", nullptr));
        lblPumpTemp->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        lblPumpHumidity->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Pressure", nullptr));
        lblPumpPressure->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Sensor: 3", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Moisture:", nullptr));
        lbls3moist->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lbls3Relay->setText(QCoreApplication::translate("MainWindow", "Off", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        btns3Relay->setText(QCoreApplication::translate("MainWindow", "Relay", nullptr));
        btns3Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
