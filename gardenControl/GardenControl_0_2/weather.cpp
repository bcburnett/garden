#include "weather.h"
#include <QtCore/QDebug>
#include <iostream>
#include<QDebug>
#include"mainwindow.h"
#include <QtCore/QDebug>
#include <iostream>
#include<QDebug>
#include<QJsonDocument>
#include<QJsonObject>

QT_USE_NAMESPACE

Weather::Weather(QObject *parent) : QObject(parent)
{

}

void Weather::Weatherinit( const QUrl &url, QLabel* status, QLabel* relay,QLabel* temp, QLabel* press,QLabel* humid) {
  m_webSocket.close(QWebSocketProtocol::CloseCodeNormal);
  m_pstatus = status;
  m_prelay = relay;
  m_ptemp = temp;
  m_ppress = press;
  m_phumid = humid;
  m_url = url;
     connect(&m_webSocket, &QWebSocket::connected, this, &Weather::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &Weather::closed);
    m_webSocket.open(m_url);
    qDebug() << "connecting to: " << m_url;
}

void Weather::onConnected()
{

    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &Weather::onTextMessageReceived);

    qDebug() << "connected to: " << m_url;
    this->connected = true;
}

void Weather::onTextMessageReceived(QString message)
{
auto json_doc=QJsonDocument::fromJson(message.toUtf8());
if(json_doc.isNull()){
    qDebug()<<"Failed to create JSON doc.";
    return;
}
if(!json_doc.isObject()){
    qDebug()<<"JSON is not an object.";
    return;
}
QJsonObject json_obj=json_doc.object();
if(json_obj.isEmpty()){
    qDebug()<<"JSON object is empty.";
    return;
}
QVariantMap json_map = json_obj.toVariantMap();

//  m_pstatus->setText(message.mid(12,4));
  m_prelay->setText(json_map["relay"].toString());
  m_pstatus->setText(json_map["status"].toString());
  m_ptemp->setText(json_map["temperature"].toString());
  m_ppress->setText(json_map["pressure"].toString());
  m_phumid->setText(json_map["humidity"].toString());
  qDebug() << message;
}

void Weather::sendMessage(QString message)
{
  m_webSocket.sendTextMessage(message);
}
