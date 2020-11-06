#include "node.h"

//initialize static member ("class variable") of Node class
int Node::numberOfObjects = 0;

Node::Node(QObject *parent) : QObject(parent)
{   identifier = numberOfObjects;
    x = 10;
    y = 10;
    nodeType = NodeType::Normal;
    nodeStatus = NodeStatus::Free;
}

Node::Node(unsigned char nodeIdentifier, int positionX, int positionY,
           NodeType nodeTypeValue, NodeStatus nodeStatusValue,
           QObject *parent) : QObject(parent)
{   numberOfObjects++;
    identifier = nodeIdentifier;
    x = positionX;
    y = positionY;
    nodeType = nodeTypeValue;
    nodeStatus = nodeStatusValue;
}

unsigned char Node::getIdentifier()
{   return identifier;
}

int Node::getX()
{   return x;
}

int Node::getY()
{   return y;
}

NodeType Node::getNodeType()
{   return nodeType;
}

NodeStatus Node::getNodeStatus()
{   return nodeStatus;
}

void Node::setIdentifier(unsigned char nodeIdentifier)
{   identifier = nodeIdentifier;
}

void Node::setX(int positionX)
{   x = positionX;
}

void Node::setY(int positionY)
{   y = positionY;
}

void Node::setNodeType(NodeType nodeTypeValue)
{   nodeType = nodeTypeValue;
}

void Node::setNodeStatus(NodeStatus nodeStatusValue)
{   nodeStatus = nodeStatusValue;
}
