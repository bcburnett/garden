#ifndef ECHOCLIENT_H
#define ECHOCLIENT_H

#include <QObject>
#include <QtWebSockets/QWebSocket>
#include <QJsonDocument>
#include<QLabel>

class EchoClient : public QObject
{
  Q_OBJECT
public:
  void Echoinit(const QUrl &url, QLabel* moist, QLabel* relay );
  explicit EchoClient( QObject *parent = nullptr);
  QJsonDocument qjd();
  bool connected = false;


  void sendMessage(QString message);

signals:
    void closed();

private slots:
    void onConnected();
    void onTextMessageReceived(QString message);
private:
    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;
    QLabel* m_moist;
    QLabel* m_relay;

};

#endif // ECHOCLIENT_H
