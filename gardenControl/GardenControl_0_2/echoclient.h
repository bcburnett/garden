#ifndef ECHOCLIENT_H
#define ECHOCLIENT_H

#include <QObject>
#include <QtWebSockets/QWebSocket>
#include <QJsonDocument>
#include<QLabel>
#include<functional>


class EchoClient : public QObject
{
  Q_OBJECT
public:
  void Echoinit(const QUrl &url, std::function<void(QVariantMap json_map)> callback );
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
    std::function<void(QVariantMap json_map)> m_callback;
    bool m_debug;
    QLabel* m_moist;
    QLabel* m_relay;

};

#endif // ECHOCLIENT_H
