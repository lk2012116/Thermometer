#ifndef __THERMOMETER_H__
#define __THERMOMETER_H__

#include "ThermometerDef.h"
#include <QSvgRenderer>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include "PointItem.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QTimer>

class LIB_THERMOMETER_EXPORT CThermometer : public QGraphicsView
{
	Q_OBJECT
public:
	CThermometer(QWidget* parent = 0);
	~CThermometer();
	void setTemperature(double dAngle);

private:
	QSvgRenderer* m_pSvgRender;
	QGraphicsScene* m_pScene;
	QGraphicsSvgItem* m_pBGItem;
	CPointItem* m_pPointItem;
};

#endif