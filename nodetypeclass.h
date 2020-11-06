// Enums in Qt QML
// https://qml.guide/enums-in-qt-qml/

#ifndef NODETYPECLASS_H
#define NODETYPECLASS_H

#include <QObject>

//#include "node.h"

class NodeTypeClass
{
    Q_GADGET
public:
    // Enumerated types with enum class
    //http://www.cplusplus.com/doc/tutorial/other_data_types/
    enum class NodeTypeValue //: //char
    {	Player1Goal,
        Player2Goal,
        Player1EntryPoint,
        Player2EntryPoint,
        Normal

        //future
    //	Teleport,
    //	Impulse1,
    //	Impulse2,
    //	Impulse3,
    //	Paralyzing,
    //	Poisoning,
    //	Sleeping,
    //	Confusing,
    //	Burning,
    //	Freezing,
    //	Toxic // noxius
    //	Special1,
    //	Special2,
    //	Special3
    };
    Q_ENUM(NodeTypeValue)

private:
    explicit NodeTypeClass();
};

typedef NodeTypeClass::NodeTypeValue NodeType;

#endif // NODETYPECLASS_H
