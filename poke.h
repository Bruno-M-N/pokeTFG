#ifndef POKE_H
#define POKE_H

#include <iostream>
#include <string>
#include <vector>

#include <ctime>   // time

#include "colortypeclass.h"

#define POKEMON_IMG_HEIGHT 230// Altura base do objeto
#define POKEMON_IMG_WIDTH 180// Comprimento base do objeto

#define MAX_CHAR_POKEMON_NAME 15
#define MAX_CHAR_NAME_POKEMON_POWER 15
#define MAX_CHAR_TEXT_POKEMON_POWER 164

#define MAX_CHAR_POKEMON_MOVE_NAME 15
#define MAX_CHAR_POKEMON_MOVE_TEXT_POWER 164
#define MAX_CHAR_POKEMON_MOVE_POWER 15

//#define MIN_POKEMON_NUMBER_OF_MOVES 2
#define MAX_POKEMON_NUMBER_OF_MOVES 6

//minimun value for probabilityMin other than 0 (0 is for the first move)
#define MIN_PROBABILITY_MIN_VALUE 42
//maximun value for probabilityMin; correspont to 1000 -42
#define MAX_PROBABILITY_MIN_VALUE 958

enum class Type : char
{	COLORLESS,FIRE,WATER,GRASS,
    LIGHTNING,FIGHTING,PSYCHIC,
    DARKNESS,METAL,TRAINER
};

//enum class ColorType //: char
//{	BLUE = 1,
//    PURPLE,
//    WHITE,
//    RED,
//    GOLD
//};

struct MoveAttack
{	std::string name;
    ColorType color;
    unsigned char stars;
    std::string textPower;
    std::string power;
    unsigned int probabilityMin;
    unsigned int probabilityMax;
};

class Poke
{
public:
    // Constructor
    Poke();
    // Destructor
    //~Pokemon();
    //Setters
    //General pokemon setter methods
    void setNumber(unsigned int pokeNumber);
    void setName(std::string pokeName);
    void setType(Type pokeType);
    void setMovePoints(unsigned char pokeMovePoints);
    void setNamePokemonPower(std::string pokeNamePokemonPower);
    void setTextPokemonPower(std::string pokeTextPokemonPower);
    void setNumberOfMoves(unsigned char numberOfMoves);
    //Setter methods of pokemon movements
    // These methods should be called after defining the number of pokémon
    // movements using the method setNumberOfMoves(unsigned char numberOfMoves);
    // The methods do not check if the movement number is valid;
    void setMoveName ( std::string name, unsigned char moveNumber);
    void setMoveColor (ColorType color, unsigned char moveNumber);
    void setMoveStars(unsigned char stars, unsigned char moveNumber);
    void setMoveTextPower(std::string textPower, unsigned char moveNumber);
    void setMovePower(std::string power, unsigned char moveNumber);
    void setMoveMin(unsigned int probabilityMin, unsigned char moveNumber);
    void setMoveMax(unsigned int probabilityMax, unsigned char moveNumber);
    //Getters
    //General pokemon getter methods
    unsigned int getNumber();
    std::string getName();
    Type getType();
    //mode U: UPPERCASE letters
    //mode L: lower case letters
    //mode different from U, L: First letter uppercase
    std::string  getType(char mode);
    unsigned char getMovePoints();
    std::string getNamePokemonPower();
    std::string getTextPokemonPower();
    unsigned char getNumberOfMoves();
    //Getter methods of pokemon movements
    // These methods should be called after defining the number of pokémon
    // movements using the method setNumberOfMoves(unsigned char numberOfMoves);
    // The methods do not check if the movement number is valid;
    std::string getMoveName (unsigned char moveNumber);
    ColorType getMoveColor (unsigned char moveNumber);
    //mode U: UPPERCASE letters
    //mode L: lower case letters
    //mode different from U, L: First letter uppercase
    std::string  getMoveColor(unsigned char moveNumber, char mode);
    unsigned char getMoveStars(unsigned char moveNumber);
    std::string getMoveTextPower(unsigned char moveNumber);
    std::string getMovePower(unsigned char moveNumber);
    unsigned int getMoveMin(unsigned char moveNumber);
    unsigned int getMoveMax(unsigned char moveNumber);


    //Battle methods
    // Call it once before using PokemonMove(struct MoveAttack& attack)
    void InitPokemonMoveRand();
    void PokemonMove(struct MoveAttack&  attack);
    //Return index to identify the MoveAttack and the ramdomNumber in the
    //parameters
    unsigned char PokemonMove(int& ramdomNumber);

    //In case of confusion
    unsigned char nextMove(unsigned char indexPreviosRamdomMove);



private:
    // General information
    unsigned int number;
    std::string name;
    Type type;
    unsigned char movePoints;

    // Pokemom Power
    std::string namePokemonPower;
    std::string textPokemonPower;

    //Moves
    unsigned char numberMoves;
    std::vector <MoveAttack> movement;
};


#endif // POKEMON_H
