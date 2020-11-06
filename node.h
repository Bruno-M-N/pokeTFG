#ifndef NODE_H
#define NODE_H

#include <QObject>

#include "nodetypeclass.h"

#define FOLDINGSTART {
//// Enumerated types with enum class
////http://www.cplusplus.com/doc/tutorial/other_data_types/
//enum class NodeType : char
//{	Player1Goal,
//    Player2Goal,
//    Player1EntryPoint,
//    Player2EntryPoint,
//    Normal

//    //future
////	teleport,
////	impulse1,
////	impulse2,
////	impulse3,
////	paralyzing,
////	poisoning,
////	sleeping,
////	confusing,
////	burning,
////	freezing,
////	toxic // noxius
////	special1,
////	special2,
////	special3
//};
#define FOLDINGEND }

enum class NodeStatus : char
{	Free,
    OccupiedAndBlocking,
    OccupiedAndNotBlocking
};



class Node : public QObject
{   Q_OBJECT
public:
    explicit Node(QObject *parent = nullptr);

    explicit Node(unsigned char nodeIdentifier, int positionX, int positionY,
         NodeType nodeTypeValue, NodeStatus nodeStatusValue = NodeStatus::Free,
         QObject *parent = nullptr);
    unsigned char getIdentifier();
    Q_INVOKABLE int getX();
    Q_INVOKABLE int getY();
    Q_INVOKABLE NodeType getNodeType();
    NodeStatus getNodeStatus();
    void setIdentifier(unsigned char nodeIdentifier);
    void setX(int positionX);
    void setY(int positionY);
    void setNodeType(NodeType nodeTypeValue);
    void setNodeStatus(NodeStatus nodeStatusValue);



private:
    static int numberOfObjects; //"class variable"

    unsigned char identifier;
    int x;
    int y;
    NodeType nodeType;
    NodeStatus nodeStatus;
};


#endif // NODE_H
