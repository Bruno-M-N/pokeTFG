#ifndef POKEMONFILEOPERATIONS_H
#define POKEMONFILEOPERATIONS_H

// basic file operations
#include <iostream>
#include <fstream>

#include "file_operations.h"

#include "poke.h"

//pokemons to/from Binary File

void WriteType(std::ofstream& file,Type type);

Type ReadType(std::istream& file);

void WriteColorType(std::ofstream& file, ColorType colorType);

ColorType ReadColorType(std::istream& file);


/// Delete previous contend and replace it
void savePokesToFile(std::string fileName, std::vector<Poke> & VectorPoke);

/// All output operations are performed at the end of the file,
//appending the content to the current content of the file.
void savePokesToFile(std::string fileName, Poke & poke);

void loadPokesFromFile(std::string fileName, std::vector<Poke> & VectorPoke );

//void loadPokesFromFile(std::string fileName, Poke & poke);

void WriteClassPoke(std::ofstream& file, Poke toWritePoke);

void ReadClassPoke(std::istream& file, Poke & toReadPoke);

#endif // POKEMONFILEOPERATIONS_H
