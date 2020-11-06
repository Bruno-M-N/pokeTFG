#ifndef POKEPAWN_H
#define POKEPAWN_H

// https://doc.qt.io/qt-5/qtqml-tutorials-extending-qml-example.html

//#include <QObject>
#include <QtQuick/QQuickItem>

#include "qpoke.h"
#include "statusclass.h"

#include "pokemonfileoperations.h"

#include "movesector.h"

class PokePawn : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY  statusChanged)
    Q_PROPERTY(int currentNodeIdentifier READ currentNodeIdentifier 
               WRITE setCurrentNodeIdentifier)

    Q_PROPERTY(QQmlListProperty<MoveSector> moveSector READ moveSector)

//    //The PokePawn class is registered using the QML_ELEMENT macro, to allow it
//    //to be used from QML
//    QML_ELEMENT
public:
    explicit PokePawn(QQuickItem *parent = nullptr);

    explicit PokePawn(QPoke *poke, QQuickItem *parent = nullptr);
    
    Status status() const;
    void setStatus(const Status &state);
    
    int currentNodeIdentifier() const;
    void setCurrentNodeIdentifier(const int &nodeIdentifier);

    QQmlListProperty<MoveSector> moveSector();

signals:
    void statusChanged();
    void currentNodeIdentifierChanged();

private:
    static void appendMoveSector(QQmlListProperty<MoveSector> *list,
                                 MoveSector *moveSector);

    QPoke *pokeData;
    
    Status statusData;
    int currentNodeIdentifierData;

    QList<MoveSector *> moveSectors;
};

#endif // POKEPAWN_H
