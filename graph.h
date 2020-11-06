#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>

//QQmlApplicationEngine provides a convenient way to load an application from a
//single QML file. Inherits QQMLEngine
//The QQmlEngine class provides an environment for instantiating QML components.
#include <QGuiApplication>
#include <QQmlApplicationEngine>

//The QQmlContext class defines a context within a QML engine.
// Needed for PageManagement constructor in????????????????????????????????????
// engine.rootContext()->setContextProperty(...)
#include <QQmlContext>

#include <QQuickItem>

#include <vector>

// Using typedef to Make a Type Synonym -
// https://www2.cs.sfu.ca/CourseCentral/125/tjd/tsp_example.html
typedef std::vector< std::vector< unsigned char > > adjacencyListType;

#include <QDebug>

#include "nodetypeclass.h"
#include "node.h"
#include "nodefileoperations.h"

class Graph : public QObject
{
    Q_OBJECT

//    Q_ENUM(NodeType)

//    Q_ENUM(NodeStatus)
public:
    explicit Graph(QQmlApplicationEngine *engineSetup, QQuickItem *rootSetup,
                   QObject *parent = nullptr);

    explicit Graph(QQmlApplicationEngine *engineSetup, QQuickItem *rootSetup,
                   std::string fileName,
                   QObject *parent = nullptr);

    bool createNode(unsigned char nodeIdentifier,
                    int positionX, int positionY,
                    NodeType nodeTypeValue,
                    NodeStatus nodeStatusValue  = NodeStatus::Free);

    bool createEdge(unsigned char nodeIdentifier1,
                    unsigned char nodeIdentifier2);

    void loadGraphFromFile(std::string fileName);

//    void displayNodes();

    std::vector<Node*> getVectorNodes();
    adjacencyListType getAdjacencyList();
    //adjacencyListType getAdjacencyList();



//    QQuickItem* integrationQMLToDisplayNode(const QUrl url);
//    Node searchNode(unsigned char nodeIdentifier);


// Slots
// https://doc.qt.io/qt-5/signalsandslots.html#slots

// A slot is called when a signal connected to it is emitted. Slots are normal
// C++ functions and can be called normally; their only special feature is that
// signals can be connected to them.

public slots:
//    void setApplicationWindowWidth(int width);
//    void setApplicationWindowHeight(int height);

signals:

private:
    //First identifier: 0 LastIdentifier: VectorNodes.size() - 1
    std::vector<Node*> vectorNodes;
    adjacencyListType adjacencyList;

//    QQmlApplicationEngine *engine;
//    QQuickItem *root;
//    std::vector <QQuickItem*> nodesVisual;

    unsigned char maxNumberOfEntryPointsPlayer1;
    unsigned char maxNumberOfEntryPointsPlayer2;

    // int initialFieldWidth;
    // int initialFieldHeight;

    // From QML code
//    int m_applicationWindowWidth;
//    int m_applicationWindowHeight;

//    int radius;
};

#endif // GRAPH_H
