#ifndef QPOKE_H
#define QPOKE_H

#include <QObject>
#include "poke.h"

struct QMoveAttack
{	std::string name;
    ColorType color;
    unsigned char stars;
    std::string textPower;
    std::string power;
    unsigned int probabilityMin;
    unsigned int probabilityMax;
};

class QPoke : public QObject
{
    Q_OBJECT
public:
    explicit QPoke(QObject *parent = nullptr);
    explicit QPoke(Poke poke, QObject *parent = nullptr);

    //Setters
    //General pokemon setter methods
    Q_INVOKABLE void setNumber(unsigned int pokeNumber);
    Q_INVOKABLE void setName(QString pokeName);
    void setName(std::string pokeName);
    Q_INVOKABLE void setType(Type pokeType);
    Q_INVOKABLE void setMovePoints(unsigned int pokeMovePoints);
    Q_INVOKABLE void setNamePokemonPower(QString pokeNamePokemonPower);
    void setNamePokemonPower(std::string pokeNamePokemonPower);
    Q_INVOKABLE void setTextPokemonPower(QString pokeTextPokemonPower);
    void setTextPokemonPower(std::string pokeTextPokemonPower);
    Q_INVOKABLE void setNumberOfMoves(unsigned int numberOfMoves);
    //Setter methods of pokemon movements
    // These methods should be called after defining the number of pokémon
    // movements using the method setNumberOfMoves(unsigned int numberOfMoves);
    // The methods do not check if the movement number is valid;
    Q_INVOKABLE void setMoveName ( QString name, unsigned int moveNumber);
    void setMoveName (std::string name, unsigned int moveNumber);
    Q_INVOKABLE void setMoveColor (ColorType color, unsigned int moveNumber);
    Q_INVOKABLE void setMoveStars(unsigned int stars, unsigned int moveNumber);
    Q_INVOKABLE void setMoveTextPower(QString textPower,
                                      unsigned int moveNumber);
    void setMoveTextPower(std::string textPower,
                                          unsigned int moveNumber);
    Q_INVOKABLE void setMovePower(QString power, unsigned int moveNumber);
    void setMovePower(std::string power, unsigned int moveNumber);
    Q_INVOKABLE void setMoveMin(unsigned int probabilityMin,
                                unsigned int moveNumber);
    Q_INVOKABLE void setMoveMax(unsigned int probabilityMax,
                                unsigned int moveNumber);
    //Getters
    //General pokemon getter methods
    Q_INVOKABLE unsigned int getNumber();
    Q_INVOKABLE QString getNameQString();
    std::string getName();
    Q_INVOKABLE Type getType();
    //mode U: UPPERCASE letters
    //mode L: lower case letters
    //mode different from U, L: First letter uppercase
    Q_INVOKABLE QString getTypeQString(int mode);
    std::string getType(int mode);
    Q_INVOKABLE unsigned int getMovePoints();
    Q_INVOKABLE QString getNamePokemonPowerQString();
    std::string getNamePokemonPower();
    Q_INVOKABLE QString getTextPokemonPowerQString();
    std::string getTextPokemonPower();
    Q_INVOKABLE unsigned int getNumberOfMoves();
    //Getter methods of pokemon movements
    // These methods should be called after defining the number of pokémon
    // movements using the method setNumberOfMoves(unsigned char numberOfMoves);
    // The methods do not check if the movement number is valid;
    Q_INVOKABLE QString getMoveNameQString (unsigned int moveNumber);
    std::string getMoveName (unsigned int moveNumber);
    Q_INVOKABLE ColorType getMoveColor (unsigned int moveNumber);
    //mode U: UPPERCASE letters
    //mode L: lower case letters
    //mode different from U, L: First letter uppercase
    Q_INVOKABLE QString  getMoveColorQString(unsigned int moveNumber, int mode);
    std::string  getMoveColor(unsigned int moveNumber, int mode);
    Q_INVOKABLE unsigned int getMoveStars(unsigned int moveNumber);
    Q_INVOKABLE QString getMoveTextPowerQString(unsigned int moveNumber);
    std::string getMoveTextPower(unsigned int moveNumber);
    Q_INVOKABLE QString getMovePowerQString(unsigned int moveNumber);
    std::string getMovePower(unsigned int moveNumber);
    Q_INVOKABLE unsigned int getMoveMin(unsigned int moveNumber);
    Q_INVOKABLE unsigned int getMoveMax(unsigned int moveNumber);

    //Battle methods
    // Call it once before using PokemonMove(struct MoveAttack& attack)
    void InitPokemonMoveRand();
    void PokemonMove(struct MoveAttack&  attack);
    //Return index to identify the MoveAttack and the ramdomNumber in the
    //parameters
    unsigned int PokemonMove(int& ramdomNumber);

    //In case of confusion
    unsigned int nextMove(unsigned int indexPreviosRamdomMove);

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
    unsigned int numberMoves;
    std::vector <QMoveAttack> movement;

};

#endif // QPOKE_H
