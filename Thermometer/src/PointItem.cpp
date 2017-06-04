#include "PointItem.h"

CPointItem::CPointItem(QGraphicsSvgItem* parent)
: QGraphicsSvgItem(parent)
, m_pSvgRender(NULL)
{
	setAcceptDrops(true);
}

CPointItem::~CPointItem()
{
}

void CPointItem::setSvgRenderer(QSvgRenderer* pRenderer)
{
	m_pSvgRender = pRenderer;
	setSharedRenderer(m_pSvgRender);
}

void CPointItem::addItemID(QString str)
{
	m_itemID = str;
	m_svgRectF = m_pSvgRender->boundsOnElement(str);
	moveBy(m_svgRectF.x() + 696.988888, m_svgRectF.y() - 504.3567890);
}

void CPointItem::paint(QPainter* painter
	, const QStyleOptionGraphicsItem* option
	, QWidget* widget)
{
	m_pSvgRender->render(painter, m_itemID, m_svgRectF);
}

QRectF CPointItem::boundingRect() const
{
	return m_svgRectF;
}

void CPointItem::setTemperature(double temp)
{
	resetTransform();
	setTransformOriginPoint(m_svgRectF.x() + m_svgRectF.width() - 23.5
		, m_svgRectF.y() + m_svgRectF.height() - 23.5);
	double dAngle = temp * 3.0;
	setRotation(dAngle);
}