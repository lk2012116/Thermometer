#include "ThermometerDemo.h"
#include <iostream>
#include <QPainter>
#include <QGraphicsItem>

using namespace std;

CThermometerDemo::CThermometerDemo(QWidget* parent)
	: QMainWindow(parent)
	, m_nam(new QNetworkAccessManager(this))
	, m_reply(NULL)
	, m_pTimer(new QTimer(this))
{
	m_ui.setupUi(this);
	m_pTimer->setInterval(10 * 1000);
	m_pTimer->start();
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
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
	QString time = QString::fromLocal8Bit(data).mid(14, 10)
		+ QString(" ")
		+ QString::fromLocal8Bit(data).mid(25, 8);
	m_ui.label->setText(tr("Update Time:") + time);
	QString strTemp = QString::fromLocal8Bit(data).mid(43, 3);
	double temp = 0.0;
	if (strTemp.right(1) == QString("}"))
	{
		if (strTemp.count() == 2)
		{
			temp = strTemp.mid(0, 1).toDouble();
		}
		else
		{
			temp = strTemp.mid(0, 2).toDouble();
		}
	}
	else
	{
		temp = strTemp.toDouble();
	}
	m_ui.widget->setTemperature(temp);
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