#ifndef __THERMOMETERDEMO_H__
#define __THERMOMETERDEMO_H__

#include "ui_ThermometerDemo.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QTimer>

class CThermometerDemo : public QMainWindow
{
	Q_OBJECT
public:
	CThermometerDemo(QWidget* parent = 0);
	~CThermometerDemo();

private slots:
	void onReadyRead();
	void onError(QNetworkReply::NetworkError error);
	void onFinished();
	void slotTimeOut();

private:
	void download(const QString& url);

private:
	Ui::ThermometerDemo m_ui;
	QNetworkAccessManager* m_nam;
	QNetworkReply* m_reply;
	QTimer* m_pTimer;
};

#endif