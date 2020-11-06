#include "movesector.h"

MoveSector::MoveSector(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{

}

ColorType MoveSector::colorType() const
{   return colorTypeData;
}

void MoveSector::setColorType(const ColorType &colorType)
{   colorTypeData = colorType;
}

int MoveSector::fromAngle() const
{   return fromAngleData;
}

void MoveSector::setFromAngle(int angle)
{   fromAngleData = angle;
}

int MoveSector::angleSpan() const
{   return angleSpanData;
}

void MoveSector::setAngleSpan(int angle)
{   angleSpanData = angle;
}

void MoveSector::paint(QPainter *painter)
{   QColor color1 = "#FFFFFF"; //255,255,255
    QColor color2 = "#F0F0F0"; //240,240,240
    if (colorTypeData == ColorType::BLUE)
    {   color1 = "#00A2E8"; //00,162,232
        color2 = "#50BEF0"; //80,190,240
    }else if (colorTypeData == ColorType::PURPLE)
    {   color1 = "#A349A4"; //163,73,164
        color2 = "#B964B9"; //185,100,185
    }else if (colorTypeData == ColorType::WHITE)
    {   color1 = "#FFFFFF"; //255,255,255
        color2 = "#F0F0F0"; //240,240,240
    }else if (colorTypeData == ColorType::RED)
    {   color1 = "#ED1C24"; //237,28,36
        color2 = "#F25860"; //242,88,96
    }else if (colorTypeData == ColorType::GOLD)
    {   color1 = "#E0C010"; //224,192,16
        color2 = "#EACA2E"; //234,202,46
    }


    //The QPen class defines how a QPainter should draw lines and outlines of
    //shapes. https://doc.qt.io/qt-5/qpen.html
    QPen pen1(color1, 1);
    QPen pen2(color2, 1);
    painter->setBrush(Qt::SolidPattern);
    painter->setPen(pen1);

    //void QPainter::setRenderHint(QPainter::RenderHint hint, bool on = true)
    //Sets the given render hint on the painter if on is true; otherwise clears
    //the render hint.
    //https://doc.qt.io/qt-5/qpainter.html#rendering-quality
    //QPainter::Antialiasing indicates that the engine should antialias edges of
    //primitives if possible
    painter->setRenderHints(QPainter::Antialiasing, true);

    //void QPainter::drawPie(const QRectF &rectangle, int startAngle,
    //                       int spanAngle)
    //Draws a pie defined by the given rectangle, startAngle and spanAngle. The
    //pie is filled with the current brush().
    //The startAngle and spanAngle must be specified in 1/16th of a degree,
    //i.e. a full circle equals 5760 (16 * 360). Positive values for the angles
    //mean counter-clockwise while negative values mean the clockwise
    //direction. Zero degrees is at the 3 o'clock position.
    // https://doc.qt.io/qt-5/qpainter.html#drawPie

    int iAngle = 5 * 16;
    int newAngle = fromAngleData * 16 + iAngle;
    int lastAngle = fromAngleData * 16;
    for (int i = 1 ; newAngle < angleSpanData; i++)
    {	newAngle =  fromAngleData * 16 + (i * iAngle);
        if (i % 2 == 1)
        {   painter->setPen(pen2);

        }else
        {   painter->setPen(pen1);
        }
        lastAngle = newAngle;
        painter->drawPie(boundingRect().adjusted(1, 1, -1, -1),
                         lastAngle, newAngle);
    }
}

