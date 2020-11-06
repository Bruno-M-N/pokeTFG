#include "poke.h"

//Constructor
Poke::Poke ()
{	number = 0;
}


//Setters

void Poke::setNumber(unsigned int pokeNumber)
{	number = pokeNumber;
}

void Poke::setName(std::string pokeName)
{	name = pokeName;
}

void Poke::setType(Type pokeType)
{	type = pokeType;
}

void Poke::setMovePoints(unsigned char pokeMovePoints)
{	movePoints = pokeMovePoints;
}

void Poke::setNamePokemonPower(std::string pokeNamePokemonPower)
{	namePokemonPower = pokeNamePokemonPower;
}

void Poke::setTextPokemonPower(std::string pokeTextPokemonPower)
{	textPokemonPower = pokeTextPokemonPower;
}

void Poke::setNumberOfMoves(unsigned char numberOfMoves)
{	numberMoves = numberOfMoves;
    movement.resize(numberOfMoves);
}

////

void Poke::setMoveName ( std::string name, unsigned char moveNumber)
{	movement[moveNumber].name = name;
}

void Poke::setMoveColor(ColorType color, unsigned char moveNumber)
{	movement[moveNumber].color = color;
}

void Poke::setMoveStars(unsigned char stars, unsigned char moveNumber)
{	movement[moveNumber].stars = stars;
}

void Poke::setMoveTextPower(std::string textPower, unsigned char moveNumber)
{	movement[moveNumber].textPower = textPower;
}

void Poke::setMovePower(std::string power, unsigned char moveNumber)
{	movement[moveNumber].power = power;
}

void Poke::setMoveMin(unsigned int probabilityMin, unsigned char moveNumber)
{	movement[moveNumber].probabilityMin = probabilityMin;
}

void Poke::setMoveMax(unsigned int probabilityMax,unsigned char moveNumber)
{	movement[moveNumber].probabilityMax = probabilityMax;
}


//Getters
unsigned int Poke::getNumber()
{	return number;
}

std::string Poke::getName()
{	return name;
}

Type Poke::getType()
{	return type;

}

//L: lowercase
//default: first letter uppercase
//U: uppercase
std::string Poke::getType( char mode)
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
}

unsigned char Poke::getMovePoints()
{	return movePoints;
}

std::string Poke::getNamePokemonPower()
{	return namePokemonPower;
}

std::string Poke::getTextPokemonPower()
{	return textPokemonPower;
}

unsigned char Poke::getNumberOfMoves()
{	return numberMoves;
}

////

std::string Poke::getMoveName (unsigned char moveNumber)
{	return movement[moveNumber].name;
}

ColorType Poke::getMoveColor (unsigned char moveNumber)
{	return movement[moveNumber].color;
}

//L: lowercase
//default: first letter uppercase
//U: uppercase: " << defaultPoke.getNamePokemonPower() << "\n";
std::string Poke::getMoveColor(unsigned char moveNumber, char mode)
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
}

unsigned char Poke::getMoveStars (unsigned char moveNumber)
{	return movement[moveNumber].stars;
}

std::string Poke::getMoveTextPower(unsigned char moveNumber)
{	return movement[moveNumber].textPower;
}

std::string Poke::getMovePower(unsigned char moveNumber)
{	return movement[moveNumber].power;
}

unsigned int Poke::getMoveMin(unsigned char moveNumber)
{	return movement[moveNumber].probabilityMin;
}

unsigned int Poke::getMoveMax(unsigned char moveNumber)
{	return movement[moveNumber].probabilityMax;
}

//Battle methods
void Poke::InitPokemonMoveRand()
{	srand( time(NULL) );
}

void Poke::PokemonMove(struct MoveAttack&  attack)
{	int golpe = 0;
    unsigned char i = 0;
    golpe=1+rand()%1000;
    for (i = 0; i < numberMoves; i++)
    {	if (golpe > movement[i].probabilityMin &&
                golpe <= movement[i].probabilityMax)
        {	attack = movement[i];
        }
    }

}

unsigned char Poke::PokemonMove(int& ramdomNumber)
{	unsigned char i = 0;
    ramdomNumber = 1 + rand()%1000;
    for (i = 0; i < numberMoves; i++)
    {	if (ramdomNumber > movement[i].probabilityMin &&
                ramdomNumber <= movement[i].probabilityMax)
        {	return i;
        }
    }

}

unsigned char Poke::nextMove(unsigned char indexPreviosRamdomMove)
{	if (indexPreviosRamdomMove < numberMoves - 1)
    {	return (indexPreviosRamdomMove + 1);
    }else
    {	return 0;
    }
}


