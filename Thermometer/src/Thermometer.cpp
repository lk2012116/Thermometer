#include "Thermometer.h"
#include <iostream>
#include <QPainter>
#include <QGraphicsItem>

using namespace std;

CThermometer::CThermometer(QWidget* parent)
	: QGraphicsView(parent)
	, m_pScene(new QGraphicsScene)
	, m_pSvgRender(new QSvgRenderer(QString(":/images/wenduji.svg")))
{
	// ±³¾°
	m_pBGItem = new QGraphicsSvgItem();
	m_pBGItem->setSharedRenderer(m_pSvgRender);
	m_pBGItem->setElementId(QString("bg"));
	m_pBGItem->setZValue(0);
	m_pScene->addItem(m_pBGItem);
	// Ö¸Õë
	m_pPointItem = new CPointItem();
	m_pPointItem->setSvgRenderer(m_pSvgRender);
	m_pPointItem->addItemID(QString("point"));
	m_pPointItem->setZValue(1);
	m_pScene->addItem(m_pPointItem);
	
	setScene(m_pScene);
}

CThermometer::~CThermometer()
{
	
}

void CThermometer::setTemperature(double dAngle)
{
	m_pPointItem->setTemperature(dAngle);
}