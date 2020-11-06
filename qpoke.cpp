#include "qpoke.h"

QPoke::QPoke(Poke poke, QObject *parent) : QObject(parent)
{
    this->setNumber(poke.getNumber());
    this->setName(poke.getName());
    this->setType(poke.getType());
    this->setMovePoints(poke.getMovePoints());
    this->setNamePokemonPower(poke.getNamePokemonPower());
    this->setTextPokemonPower(poke.getTextPokemonPower());
    this->setNumberOfMoves(poke.getNumberOfMoves());

    //Getter methods of pokemon movements
    // These methods should be called after defining the number of pokémon
    // movements using the method setNumberOfMoves(unsigned char numberOfMoves);
    // The methods do not check if the movement number is valid;
    unsigned char numberOfMoves = poke.getNumberOfMoves();

    for (unsigned int i = 0; i < numberOfMoves; i++)
    {   this->setMoveName(poke.getMoveName(i), i);
        this->setMoveColor(poke.getMoveColor(i), i);
        this->setMoveStars(poke.getMoveStars(i), i);
        this->setMoveTextPower(poke.getMoveTextPower(i), i);
        this->setMovePower(poke.getMovePower(i), i);
        this->setMoveMin(poke.getMoveMin(i), i);
        this->setMoveMax(poke.getMoveMax(i), i);
    }
}

QPoke::QPoke(QObject *parent) : QObject(parent)
{

}

void QPoke::setNumber(unsigned int pokeNumber)
{	number = pokeNumber;
}

void QPoke::setName(QString pokeName)
{	name = pokeName.toStdString();
}

void QPoke::setName(std::string pokeName)
{	name = pokeName;
}

void QPoke::setType(Type pokeType)
{	type = pokeType;
}

void QPoke::setMovePoints(unsigned int pokeMovePoints)
{	movePoints = pokeMovePoints;
}

void QPoke::setNamePokemonPower(QString pokeNamePokemonPower)
{	namePokemonPower = pokeNamePokemonPower.toStdString();
}

void QPoke::setNamePokemonPower(std::string pokeNamePokemonPower)
{	namePokemonPower = pokeNamePokemonPower;
}

void QPoke::setTextPokemonPower(QString pokeTextPokemonPower)
{	textPokemonPower = pokeTextPokemonPower.toStdString();
}

void QPoke::setTextPokemonPower(std::string pokeTextPokemonPower)
{	textPokemonPower = pokeTextPokemonPower;
}

void QPoke::setNumberOfMoves(unsigned int numberOfMoves)
{	numberMoves = numberOfMoves;
    movement.resize(numberOfMoves);
}

////

void QPoke::setMoveName (QString name, unsigned int moveNumber)
{	movement[moveNumber].name = name.toStdString();
}

void QPoke::setMoveName (std::string name, unsigned int moveNumber)
{	movement[moveNumber].name = name;
}

void QPoke::setMoveColor(ColorType color, unsigned int moveNumber)
{	movement[moveNumber].color = color;
}

void QPoke::setMoveStars(unsigned int stars, unsigned int moveNumber)
{	movement[moveNumber].stars = stars;
}

void QPoke::setMoveTextPower(QString textPower, unsigned int moveNumber)
{	movement[moveNumber].textPower = textPower.toStdString();
}

void QPoke::setMoveTextPower(std::string textPower, unsigned int moveNumber)
{	movement[moveNumber].textPower = textPower;
}

void QPoke::setMovePower(QString power, unsigned int moveNumber)
{	movement[moveNumber].power = power.toStdString();
}

void QPoke::setMovePower(std::string power, unsigned int moveNumber)
{	movement[moveNumber].power = power;
}

void QPoke::setMoveMin(unsigned int probabilityMin, unsigned int moveNumber)
{	movement[moveNumber].probabilityMin = probabilityMin;
}

void QPoke::setMoveMax(unsigned int probabilityMax, unsigned int moveNumber)
{	movement[moveNumber].probabilityMax = probabilityMax;
}

//Getters
unsigned int QPoke::getNumber()
{	return number;
}

QString QPoke::getNameQString()
{	return QString::fromStdString(name);
}

std::string QPoke::getName()
{	return name;
}

Type QPoke::getType()
{	return type;

}

//L: lowercase
//default: first letter uppercase
//U: uppercase
QString QPoke::getTypeQString(int mode)
{	if (mode == 'U')//UPPERCASE
    {	if (type == Type::COLORLESS) return "COLORLESS";
        if (type == Type::FIRE) return "FIRE";
        if (type == Type::WATER) return "WATER";
        if (type == Type::GRASS) return "GRASS";
        if (type == Type::LIGHTNING) return "LIGHTNING";
        if (type == Type::FIGHTING) return "FIGHTING";
        if (type == Type::PSYCHIC) return "PSYCHIC";
        if (type == Type::DARKNESS) return "DARKNESS";
        if (type == Type::METAL) return "METAL";
        if (type == Type::TRAINER) return "TRAINER";
    }
    else if (mode == 'L')
    {	if (type == Type::COLORLESS) return "colorless";
        if (type == Type::FIRE) return "fire";
        if (type == Type::WATER) return "water";
        if (type == Type::GRASS) return "grass";
        if (type == Type::LIGHTNING) return "lightning";
        if (type == Type::FIGHTING) return "fighting";
        if (type == Type::PSYCHIC) return "psychic";
        if (type == Type::DARKNESS) return "darkness";
        if (type == Type::METAL) return "metal";
        if (type == Type::TRAINER) return "trainer";
    }
    else
    {	if (type == Type::COLORLESS) return "Colorless";
        if (type == Type::FIRE) return "Fire";
        if (type == Type::WATER) return "Water";
        if (type == Type::GRASS) return "Grass";
        if (type == Type::LIGHTNING) return "Lightning";
        if (type == Type::FIGHTING) return "Fighting";
        if (type == Type::PSYCHIC) return "Psychic";
        if (type == Type::DARKNESS) return "Darkness";
        if (type == Type::METAL) return "Metal";
        if (type == Type::TRAINER) return "Trainer";
    }
    return "None";
}

std::string QPoke::getType(int mode)
{	if (mode == 'U')//UPPERCASE
    {	if (type == Type::COLORLESS) return "COLORLESS";
        if (type == Type::FIRE) return "FIRE";
        if (type == Type::WATER) return "WATER";
        if (type == Type::GRASS) return "GRASS";
        if (type == Type::LIGHTNING) return "LIGHTNING";
        if (type == Type::FIGHTING) return "FIGHTING";
        if (type == Type::PSYCHIC) return "PSYCHIC";
        if (type == Type::DARKNESS) return "DARKNESS";
        if (type == Type::METAL) return "METAL";
        if (type == Type::TRAINER) return "TRAINER";
    }
    else if (mode == 'L')
    {	if (type == Type::COLORLESS) return "colorless";
        if (type == Type::FIRE) return "fire";
        if (type == Type::WATER) return "water";
        if (type == Type::GRASS) return "grass";
        if (type == Type::LIGHTNING) return "lightning";
        if (type == Type::FIGHTING) return "fighting";
        if (type == Type::PSYCHIC) return "psychic";
        if (type == Type::DARKNESS) return "darkness";
        if (type == Type::METAL) return "metal";
        if (type == Type::TRAINER) return "trainer";
    }
    else
    {	if (type == Type::COLORLESS) return "Colorless";
        if (type == Type::FIRE) return "Fire";
        if (type == Type::WATER) return "Water";
        if (type == Type::GRASS) return "Grass";
        if (type == Type::LIGHTNING) return "Lightning";
        if (type == Type::FIGHTING) return "Fighting";
        if (type == Type::PSYCHIC) return "Psychic";
        if (type == Type::DARKNESS) return "Darkness";
        if (type == Type::METAL) return "Metal";
        if (type == Type::TRAINER) return "Trainer";
    }
    return "None";
}

unsigned int QPoke::getMovePoints()
{	return movePoints;
}

QString QPoke::getNamePokemonPowerQString()
{	return QString::fromStdString(namePokemonPower);
}

std::string QPoke::getNamePokemonPower()
{	return namePokemonPower;
}

QString QPoke::getTextPokemonPowerQString()
{	return QString::fromStdString(textPokemonPower);
}

std::string QPoke::getTextPokemonPower()
{	return textPokemonPower;
}

unsigned int QPoke::getNumberOfMoves()
{	return numberMoves;
}

////

QString QPoke::getMoveNameQString (unsigned int moveNumber)
{	return QString::fromStdString(movement[moveNumber].name);
}

std::string QPoke::getMoveName (unsigned int moveNumber)
{	return movement[moveNumber].name;
}

ColorType QPoke::getMoveColor (unsigned int moveNumber)
{	return movement[moveNumber].color;
}

//L: lowercase
//default: first letter uppercase
//U: uppercase: " << defaultPoke.getNamePokemonPower() << "\n";
QString QPoke::getMoveColorQString(unsigned int moveNumber, int mode)
{	if (mode == 'U')//UPPERCASE
    {	if (movement[moveNumber].color == ColorType::BLUE) return "BLUE";
        if (movement[moveNumber].color == ColorType::PURPLE) return "PURPLE";
        if (movement[moveNumber].color == ColorType::WHITE) return "WHITE";
        if (movement[moveNumber].color == ColorType::RED) return "RED";
        if (movement[moveNumber].color == ColorType::GOLD) return "GOLD";
    }
    else if (mode == 'L')
    {	if (movement[moveNumber].color == ColorType::BLUE) return "blue";
        if (movement[moveNumber].color == ColorType::PURPLE) return "purple";
        if (movement[moveNumber].color == ColorType::WHITE) return "white";
        if (movement[moveNumber].color == ColorType::RED) return "red";
        if (movement[moveNumber].color == ColorType::GOLD) return "gold";
    }
    else
    {	if (movement[moveNumber].color == ColorType::BLUE) return "Blue";
        if (movement[moveNumber].color == ColorType::PURPLE) return "Purple";
        if (movement[moveNumber].color == ColorType::WHITE) return "White";
        if (movement[moveNumber].color == ColorType::RED) return "Red";
        if (movement[moveNumber].color == ColorType::GOLD) return "Gold";
    }
    return "None";
}

std::string QPoke::getMoveColor(unsigned int moveNumber, int mode)
{	if (mode == 'U')//UPPERCASE
    {	if (movement[moveNumber].color == ColorType::BLUE) return "BLUE";
        if (movement[moveNumber].color == ColorType::PURPLE) return "PURPLE";
        if (movement[moveNumber].color == ColorType::WHITE) return "WHITE";
        if (movement[moveNumber].color == ColorType::RED) return "RED";
        if (movement[moveNumber].color == ColorType::GOLD) return "GOLD";
    }
    else if (mode == 'L')
    {	if (movement[moveNumber].color == ColorType::BLUE) return "blue";
        if (movement[moveNumber].color == ColorType::PURPLE) return "purple";
        if (movement[moveNumber].color == ColorType::WHITE) return "white";
        if (movement[moveNumber].color == ColorType::RED) return "red";
        if (movement[moveNumber].color == ColorType::GOLD) return "gold";
    }
    else
    {	if (movement[moveNumber].color == ColorType::BLUE) return "Blue";
        if (movement[moveNumber].color == ColorType::PURPLE) return "Purple";
        if (movement[moveNumber].color == ColorType::WHITE) return "White";
        if (movement[moveNumber].color == ColorType::RED) return "Red";
        if (movement[moveNumber].color == ColorType::GOLD) return "Gold";
    }
    return "None";
}

unsigned int QPoke::getMoveStars (unsigned int moveNumber)
{	return movement[moveNumber].stars;
}

QString QPoke::getMoveTextPowerQString(unsigned int moveNumber)
{	return QString::fromStdString(movement[moveNumber].textPower);
}

std::string QPoke::getMoveTextPower(unsigned int moveNumber)
{	return movement[moveNumber].textPower;
}

QString QPoke::getMovePowerQString(unsigned int moveNumber)
{	return QString::fromStdString(movement[moveNumber].power);
}

std::string QPoke::getMovePower(unsigned int moveNumber)
{	return movement[moveNumber].power;
}

unsigned int QPoke::getMoveMin(unsigned int moveNumber)
{	return movement[moveNumber].probabilityMin;
}

unsigned int QPoke::getMoveMax(unsigned int moveNumber)
{	return movement[moveNumber].probabilityMax;
}
