#ifndef __POINTITEM_H__
#define __POINTITEM_H__

#include <QGraphicsSvgItem>
#include <QSvgRenderer>

class CPointItem : public QGraphicsSvgItem
{
public:
	CPointItem(QGraphicsSvgItem* parent = NULL);
	~CPointItem();
	void setSvgRenderer(QSvgRenderer* pRenderer);
	void addItemID(QString str);
	void setTemperature(double dAngle);

protected:
	void paint(QPainter* painter
		, const QStyleOptionGraphicsItem* option
		, QWidget* widget = Q_NULLPTR);

	QRectF boundingRect() const;


private:
	QSvgRenderer* m_pSvgRender;
	QRectF m_svgRectF;
	QString m_itemID;
};

#endif