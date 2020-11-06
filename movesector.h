#ifndef MOVESECTOR_H
#define MOVESECTOR_H

// https://doc.qt.io/qt-5/qtqml-tutorials-extending-qml-example.html

//#include <QObject>
#include <QtQuick/QQuickPaintedItem>
#include <QPainter>

#include "colortypeclass.h"

class MoveSector : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(ColorType colorType READ colorType WRITE setColorType)
    Q_PROPERTY(int fromAngle READ fromAngle WRITE setFromAngle)
    Q_PROPERTY(int angleSpan READ angleSpan WRITE setAngleSpan)
public:
    explicit MoveSector(QQuickItem *parent = nullptr);

    ColorType colorType() const;
    void setColorType(const ColorType &colorType);

    int fromAngle() const;
    void setFromAngle(int angle);

    int angleSpan() const;
    void setAngleSpan(int span);

    void paint(QPainter *painter);

signals:

private:
    ColorType colorTypeData;
    int fromAngleData;
    int angleSpanData;
};

#endif // MOVESECTOR_H
