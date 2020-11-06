// Enums in Qt QML
// https://qml.guide/enums-in-qt-qml/

#ifndef COLORTYPECLASS_H
#define COLORTYPECLASS_H

#include <QObject>

//#include "poke.h"

class ColorTypeClass
{
    Q_GADGET
public:
    // Enumerated types with enum class
    //http://www.cplusplus.com/doc/tutorial/other_data_types/
    enum class ColorTypeValue //: char
    {	BLUE = 1,
        PURPLE,
        WHITE,
        RED,
        GOLD
    };
    Q_ENUM(ColorTypeValue)

private:
    explicit ColorTypeClass();
};

typedef ColorTypeClass::ColorTypeValue ColorType;

#endif // COLORTYPECLASS_H
