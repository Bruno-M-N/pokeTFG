#include "pokepawn.h"

PokePawn::PokePawn(QQuickItem *parent) : QQuickItem(parent)
{   pokeData = nullptr;
    statusData = Status::Normal;
    currentNodeIdentifierData = 255;
}


PokePawn::PokePawn(QPoke *poke, QQuickItem *parent) : QQuickItem(parent)
{   pokeData = poke;
    statusData = Status::Normal;
    currentNodeIdentifierData = 255;
}

Status PokePawn::status() const
{   return statusData;
}


void PokePawn::setStatus(const Status &state)
{   // check that the status value has actually changed before emitting    
    // statusChanged(). This ensures the signal is not emitted unnecessarily and
    // also prevents loops when other types respond to the value change.
    if(state != statusData)
    {   statusData = state;
        emit statusChanged();
    }
}

int PokePawn::currentNodeIdentifier() const
{   return currentNodeIdentifierData;
}

void PokePawn::setCurrentNodeIdentifier(const int &nodeIdentifier)
{   if(nodeIdentifier != currentNodeIdentifierData)
    {   currentNodeIdentifierData = nodeIdentifier;
        emit currentNodeIdentifierChanged();
    }
}


QQmlListProperty<MoveSector> PokePawn::moveSector()
{
    return QQmlListProperty<MoveSector>(this, nullptr, &PokePawn::appendMoveSector, nullptr, nullptr, nullptr);
}

void PokePawn::appendMoveSector(QQmlListProperty<MoveSector> *list, MoveSector *moveSector)
{
    PokePawn *pawn = qobject_cast<PokePawn *>(list->object);
    if (pawn)
    {   //The MoveSector is a visual item, so it must be set as a child of the
        //PokePawn using QQuickItem::setParentItem() so that the PokePawn knows
        //to paint this child item when its contents are drawn
        moveSector->setParentItem(pawn);
        pawn->moveSectors.append(moveSector);
    }
}
