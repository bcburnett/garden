/****************************************************************************
**
** Copyright (C) 2016 Kurt Pattyn <pattyn.kurt@gmail.com>.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWebSockets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "echoclient.h"
#include <QtCore/QDebug>
#include <iostream>
#include<QDebug>
#include"mainwindow.h"
#include<QJsonDocument>
#include<QJsonObject>

QT_USE_NAMESPACE

//! [constructor]
void EchoClient::Echoinit( const QUrl &url, QLabel* moist, QLabel* relay) {
  m_webSocket.close(QWebSocketProtocol::CloseCodeNormal);
  m_moist = moist;
  m_relay = relay;
 m_url = url;
     connect(&m_webSocket, &QWebSocket::connected, this, &EchoClient::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &EchoClient::closed);
    m_webSocket.open(m_url);
    qDebug() << "connecting to: " << m_url;
}



EchoClient::EchoClient(QObject *parent) :
    QObject(parent)
{}
//! [constructor]

//! [onConnected]
void EchoClient::onConnected()
{

    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &EchoClient::onTextMessageReceived);

    qDebug() << "connected to: " << m_url;

}
//! [onConnected]

//! [onTextMessageReceived]
void EchoClient::onTextMessageReceived(QString message)
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
  m_relay->setText(json_map["relay"].toString());
  m_moist->setText(json_map["moisture"].toString());

        qDebug() << message;
}
//! [onTextMessageReceived]

//! [sendMessage]
void EchoClient::sendMessage(QString message)
{
  m_webSocket.sendTextMessage(message);
}
//! [sendMessage]
