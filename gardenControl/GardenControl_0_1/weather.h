#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include<QLabel>
#include<QUrl>
#include<QtWebSockets/QWebSocket>

class Weather : public QObject
{
  Q_OBJECT
public:
  void Weatherinit(const QUrl &url, QLabel* status, QLabel* relay,QLabel* temp, QLabel* press,QLabel* humid );
  explicit Weather( QObject *parent = nullptr);
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
    QLabel* m_pstatus;
    QLabel* m_prelay;
    QLabel* m_ptemp;
    QLabel* m_ppress;
    QLabel* m_phumid;

};


#endif // WEATHER_H
