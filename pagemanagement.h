#ifndef PAGEMANAGEMENT_H
#define PAGEMANAGEMENT_H

#include <QVariant>

#include <QObject>

//QQmlApplicationEngine provides a convenient way to load an application from a
//single QML file. Inherits QQMLEngine
//The QQmlEngine class provides an environment for instantiating QML components.
#include <QGuiApplication>
#include <QQmlApplicationEngine>

//The QQmlContext class defines a context within a QML engine.
// Needed for PageManagement constructor in
// engine.rootContext()->setContextProperty(...)
#include <QQmlContext>

#include <QDebug>

#include "graph.h"


#include "poke.h"
#include "pokemonfileoperations.h"
#include "qpoke.h"

class PageManagement : public QObject
{
    Q_OBJECT
public:
    explicit PageManagement(QQmlApplicationEngine *engine, QQuickItem *root,
                            QObject *parent = nullptr);

    //Communication between QML and C++

    // A property behaves like a class data member, but it has additional
    // features accessible through the Meta-Object System.
    // https://doc.qt.io/qt-5/properties.html

    // A READ accessor function is required if no MEMBER variable was specified.
    // It is for reading the property value. Ideally, a const function is used
    // for this purpose, and it must return either the property's type or a
    // const reference to that type.

    // A WRITE accessor function is optional. It is for setting the property
    // value. It must return void and must take exactly one argument, either of
    // the property's type or a pointer or reference to that type.
    // Read-only properties do not need WRITE functions.

    // A NOTIFY signal is optional. If defined, it should specify one existing
    // signal in that class that is emitted whenever the value of the property
    // changes.
    // The NOTIFY signal should only be emitted when the property has really
    // been changed, to avoid bindings being unnecessarily re-evaluated in QML,
    // for example.

//    Q_PROPERTY(int applicationWindowWidth
//               READ applicationWindowWidth
//               WRITE setApplicationWindowWidth
//               NOTIFY applicationWindowWidthChanged)
//    Q_PROPERTY(int applicationWindowHeight
//               READ applicationWindowHeight
//               WRITE setApplicationWindowHeight
//               NOTIFY applicationWindowHeightChanged)

//    int applicationWindowWidth() const;
//    Q_INVOKABLE void setApplicationWindowWidth(int width);
//    int applicationWindowHeight() const;
//    Q_INVOKABLE void setApplicationWindowHeight(int height);

    Q_INVOKABLE void showHomePage(const QString &text);
    Q_INVOKABLE void showGamePage(const QString &text);

    Q_INVOKABLE void loadArenaNodesAndAdjacencyList(std::string fileName =
                                                    "original3x3.tfgarena");

    Q_INVOKABLE QVariantList getVectorNodes();
    //Q_INVOKABLE std::vector<Node*> getVectorNodes();
    Q_INVOKABLE QVariantList getAdjacencyList();

    Q_INVOKABLE void loadPokesFromFiles(std::string fileName);
    Q_INVOKABLE QVariantList getTeam1Pokes();
    Q_INVOKABLE QVariantList getTeam2Pokes();

signals:
    //Ce signal doit être généré dès lors que le compteur change : il faut en
    //informer l’interface graphique pour qu’elle lise la nouvelle valeur du
    //compteur et l’affiche dans l’élément graphique « Text » que nous avons
    //créé précédemment.
    //void pageChanged(const QString &text);
//    void applicationWindowWidthChanged(int newWidth);
//    void applicationWindowHeightChanged(int newHeight);

private:
//    int m_applicationWindowWidth;
//    int m_applicationWindowHeight;

//    int initialApplicationWindowWidth;
//    int initialApplicationWindowHeight;

    bool gameRunning;
    Graph graph;

    std::vector<QPoke*> team1Pokes;
    std::vector<QPoke*> team2Pokes;
};

//Q_DECLARE_METATYPE(std::vector<Node*>);


#endif // PAGEMANAGEMENT_H
