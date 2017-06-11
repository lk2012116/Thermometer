#include "ThermometerDemo.h"
#include <iostream>
#include <QPainter>
#include <QGraphicsItem>
#include <QJsonDocument>
#include <QJsonObject>

using namespace std;

CThermometerDemo::CThermometerDemo(QWidget* parent)
	: QMainWindow(parent)
	, m_nam(new QNetworkAccessManager(this))
	, m_reply(NULL)
	, m_pTimer(new QTimer(this))
{
	m_ui.setupUi(this);
	m_pTimer->setInterval(30 * 1000);
	m_pTimer->start();
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
	slotTimeOut();
}

void CThermometerDemo::slotTimeOut()
{
	download(QString("http://api.yeelink.net/v1.0/device/343806/sensor/381801/datapoints"));
}

CThermometerDemo::~CThermometerDemo()
{
	if (m_reply)
	{
		m_reply->deleteLater();
		m_reply = 0;
	}
}

void CThermometerDemo::download(const QString& url)
{
	QUrl httpAddr(url);
	QNetworkRequest req(httpAddr);
	if (m_reply)
	{
		m_reply->deleteLater();
		m_reply = NULL;
	}
	m_reply = m_nam->get(req);
	connect(m_reply, SIGNAL(readyRead())
		, this, SLOT(onReadyRead()));
	connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError))
		, this, SLOT(onError(QNetworkReply::NetworkError)));
	connect(m_reply, SIGNAL(finished()), this, SLOT(onFinished()));
}

void CThermometerDemo::onReadyRead()
{
	QByteArray data = m_reply->readAll();
	QJsonObject obj = QJsonDocument::fromJson(data).object();
	m_ui.label->setText(QString("Update time: ") + obj.value(QString("timestamp")).toString());
	m_ui.widget->setTemperature(obj.value(QString("value")).toDouble());
}

void CThermometerDemo::onError(QNetworkReply::NetworkError error)
{
	qDebug() << error;
}

void CThermometerDemo::onFinished()
{
	m_reply->disconnect(this);
	m_reply->deleteLater();
	m_reply = NULL;
}