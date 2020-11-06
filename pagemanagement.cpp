#include "pagemanagement.h"

PageManagement::PageManagement(QQmlApplicationEngine *engine, QQuickItem *root,
                               QObject *parent) : QObject(parent),
                                                  graph (engine, root,
                                                         "original3x3.tfgarena")

{
//    pageChanged("Hello: HomePage 1");
//    printf("Hello World: HomePage 1 (constructor)\n");
    qDebug() << "PageManagement";
    engine->rootContext()->setContextProperty("cppGraph", &graph);

    // QMetaObject::Connection QObject::connect
    // Creates a connection of the given type from the signal in the sender
    // object to the method in the receiver object. Returns a handle to the
    // connection that can be used to disconnect it later.

    // QObject::connect(const QObject *sender, const char *signal,
    //                  const QObject *receiver, const char *method,
    //                  Qt::ConnectionType type = Qt::AutoConnection)
//    QObject::connect(this, &PageManagement::applicationWindowWidthChanged,
//                         &graph, &Graph::setApplicationWindowWidth);
//    QObject::connect(this, &PageManagement::applicationWindowHeightChanged,
//                         &graph, &Graph::setApplicationWindowHeight);

    team1Pokes.reserve(3);
    team2Pokes.reserve(3);
}

#define FOLDINGSTART {
//int PageManagement::applicationWindowWidth() const
//{   return m_applicationWindowWidth;
//}

//void PageManagement::setApplicationWindowWidth(int width)
//{   // The NOTIFY signal should only be emitted when the property has really
//    // been changed, to avoid bindings being unnecessarily re-evaluated in QML,
//    // for example.
//    if(width == m_applicationWindowWidth)
//    {   return;
//    }
//    m_applicationWindowWidth = width;
//    qDebug() << "PageManagement : setApplicationWindowWidth" << width;
//    emit applicationWindowWidthChanged(width);

////    setApplicationWindowHeight(m_applicationWindowHeight
////        * m_applicationWindowWidth/initialApplicationWindowWidth);

////    if (gameRunning == true)
////    {   graph.displayNodes();
////    }
//}

//int PageManagement::applicationWindowHeight() const
//{   return m_applicationWindowHeight;
//}

//void PageManagement::setApplicationWindowHeight(int height)
//{   // The NOTIFY signal should only be emitted when the property has really
//    // been changed, to avoid bindings being unnecessarily re-evaluated in QML,
//    // for example.
//    if(height == m_applicationWindowHeight)
//    {   return;
//    }
//    m_applicationWindowHeight = height;
//    qDebug() << "PageManagement : setApplicationWindowHeight" << height;
//    emit applicationWindowHeightChanged(height);

////    setApplicationWindowWidth(m_applicationWindowHeight
////        * m_applicationWindowHeight/initialApplicationWindowHeight);

////    if (gameRunning == true)
////    {   graph.displayNodes();
////    }
//}
#define FOLDINGEND }

void PageManagement::showHomePage(const QString &text)
{   qDebug() << "HomePage\n" ;
}

void PageManagement::showGamePage(const QString &text)
{   qDebug() << "GamePage\n";
//    if (gameRunning == false)
//    {   gameRunning = true;
//        graph.displayNodes();
//    }
}

void PageManagement::loadArenaNodesAndAdjacencyList(std::string fileName)
{   qDebug() << "PageManagement: Loading Arena Nodes and edges\n";
    if (gameRunning == false)
    {   gameRunning = true;
        graph.loadGraphFromFile(fileName);
    }
}

QVariantList PageManagement::getVectorNodes()
//std::vector<Node*> PageManagement::getVectorNodes()
{   qDebug() << "PageManagement: Loading Arena Nodes\n";

    QVariantList newList;
    std::vector<Node*> pNode = graph.getVectorNodes();
    int vectorNodeSize = pNode.size();
    for (int i = 0; i < vectorNodeSize; ++i)
        newList.append(QVariant::fromValue((QObject*) pNode[i]));

    return newList;
    //return QVariant::fromValue(graph.getVectorNodes());//newList;

    //std::vector<Node*> pNode = graph.getVectorNodes();//[0];
    //QQmlEngine::setObjectOwnership(pNode, QQmlEngine::CppOwnership);
    //return pNode;//graph.getVectorNodes()[0];
}

QVariantList PageManagement::getAdjacencyList()
//std::vector<Node*> PageManagement::getVectorNodes()
{   qDebug() << "PageManagement: Loading AdjacencyList\n";

    QVariantList newList;
    adjacencyListType pAdjacencyList = graph.getAdjacencyList();
    int adjacencyListSize = pAdjacencyList.size();
    for (int i = 0; i < adjacencyListSize; ++i)
        newList.append(QVariant::fromValue(pAdjacencyList[i]));

    return newList;
}

void PageManagement::loadPokesFromFiles(std::string fileName)
{   qDebug() << "PageManagement: Loading Pokes from file\"";// << fileName << "\"\n";
    std::vector<Poke> vectorPoke;
    loadPokesFromFile(fileName, vectorPoke);

    QPoke *qPoke1T1 = new QPoke(vectorPoke[10], this);
    team1Pokes.push_back(qPoke1T1);

    QPoke *qPoke2T1 = new QPoke(vectorPoke[11], this);
    team1Pokes.push_back(qPoke2T1);

    QPoke *qPoke3T1 = new QPoke(vectorPoke[12], this);
    team1Pokes.push_back(qPoke3T1);

    QPoke *qPoke1T2 = new QPoke(vectorPoke[13], this);
    team1Pokes.push_back(qPoke1T2);

    QPoke *qPoke2T2 = new QPoke(vectorPoke[14], this);
    team1Pokes.push_back(qPoke2T2);

    QPoke *qPoke3T2 = new QPoke(vectorPoke[15], this);
    team1Pokes.push_back(qPoke3T2);

    int team1PokesSize = team1Pokes.size();
    for (int i = 0; i < team1PokesSize; ++i)
    {   QQmlEngine::setObjectOwnership(team1Pokes[i],
                                       QQmlEngine::CppOwnership);
        QQmlEngine::setObjectOwnership(team2Pokes[i],
                                               QQmlEngine::CppOwnership);
    }
}

QVariantList PageManagement::getTeam1Pokes()
{   qDebug() << "PageManagement: getTeam1Pokes\n";

    QVariantList newList;
    int team1PokesSize = team1Pokes.size();
    for (int i = 0; i < team1PokesSize; ++i)
        newList.append(QVariant::fromValue((QObject*) team1Pokes[i]));

    return newList;
}

QVariantList PageManagement::getTeam2Pokes()
{   qDebug() << "PageManagement: getTeam2Pokes\n";

    QVariantList newList;
    int team2PokesSize = team2Pokes.size();
    for (int i = 0; i < team2PokesSize; ++i)
    newList.append(QVariant::fromValue((QObject*) team2Pokes[i]));

    return newList;
}

//https://stackoverflow.com/questions/9265288/casting-a-list-as-qvariant-or-qvariant-list
//template <typename T>
//QVariantList toVariantList( const QList<T> &list )
//{
//    QVariantList newList;
//    foreach( const T &item, list )
//        newList << item;

//    return newList;
//}
