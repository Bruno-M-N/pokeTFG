#include "pokemonfileoperations.h"
//pokemons to Binary File


void WriteType(std::ofstream& file, Type type)
{	char charType = (char) type;
    //Write 1 byte to the file
    file.write((char*) (&charType),1 );
}

Type ReadType (std::istream& file)
{   char charType = 0;
    //Read 1 byte from the file
    file.read( (char*) (&charType), 1);
    Type type = (Type) charType;

    return type;
}

void WriteColorType(std::ofstream& file, ColorType colorType)
{   char charType = (char) colorType;
    //Write 1 byte to the file
    file.write((char*) (&charType),1 );
}

ColorType ReadColorType (std::istream& file)
{   char charColorType = 0;
    //Read 1 byte from the file
    file.read( (char*) (&charColorType), 1);
    ColorType colorType = (ColorType) charColorType;
    return colorType;
}

void savePokesToFile(std::string fileName, std::vector<Poke> & VectorPoke )
{	std::cout << fileName << std::endl;
    std::ofstream File;
    File.open(fileName, std::ios::out | std::ios::binary);

    unsigned int size = VectorPoke.size();

    if (File.is_open())
    {	for (unsigned int i = 0; i < size; i++)
        {	WriteClassPoke(File, VectorPoke[i]);
        }
    }else
    {	std::cout<<"\nCouldn't open the file.\n";
    }
    File.close();
}

void savePokesToFile(std::string fileName, Poke & poke )
{	std::cout << fileName << std::endl;
    std::ofstream File;
    File.open(fileName, std::ios::out | std::ios::app | std::ios::binary);

    if (File.is_open())
    {	WriteClassPoke(File,poke);
        std::cout<<"\nSaved in the file.\n";
    }else
    {	std::cout<<"\nCouldn't open the file.\n";
    }
    File.close();
}

void loadPokesFromFile(std::string fileName, std::vector<Poke> & VectorPoke )
{	std::cout << fileName << std::endl;
    std::ifstream File;
    File.open(fileName, std::ios::in | std::ios::ate | std::ios::binary);

    if (File.is_open())
    {	std::streampos fileSize, current;



        Poke pokemon;

        fileSize = File.tellg();
        File.seekg(0, std::ios::beg);
        std::cout << "\nLoading data from binary file \"" << fileName << "\". File data size: "
            << fileSize << " bytes.\n" << std::endl;

        ReadClassPoke(File, pokemon);
        VectorPoke.push_back(pokemon);
        current = File.tellg();
        //std::cout << "\nCurrent: " << current;
        // Minimize the number of potential reallocations, by reserving an approximation of the
            //number of pokemons written in the file + 1 + the current size
        VectorPoke.reserve(VectorPoke.size() + (int)(fileSize / current + 1));

        for (;;)//current < fileSize;)
        {	ReadClassPoke(File,pokemon);
            current = File.tellg();
            //std::cout << "\nCurrent: " << current;
            VectorPoke.push_back(pokemon);
            if (File.peek() == EOF) break;
        }
    }else
    {	std::cout<<"\nCouldn't open the file.\n";
    }
    File.close();
}

//void loadPokesFromFile(std::string fileName, Poke & poke);

void WriteClassPoke (std::ofstream& file, Poke toWritePoke)
{	uint8_t data;

    unsigned char numberOfMoves = toWritePoke.getNumberOfMoves();

    WriteUint32_t(file,(uint32_t) toWritePoke.getNumber() );
    WriteString(file, toWritePoke.getName() );
    data = toWritePoke.getMovePoints();
    file.write((char*) &data,1 );
    WriteType(file,  toWritePoke.getType() );
    WriteString(file, toWritePoke.getNamePokemonPower() );
    WriteString(file, toWritePoke.getTextPokemonPower() );
    file.write((char*) &numberOfMoves,1 );

    for (unsigned char i = 0; i < numberOfMoves; i++)
    {	WriteString(file, toWritePoke.getMoveName(i) );
        WriteColorType(file, toWritePoke.getMoveColor(i) );
        data = toWritePoke.getMoveStars(i);
        file.write((char*) &data, 1 );
        WriteString(file, toWritePoke.getMoveTextPower(i) );
        WriteString(file, toWritePoke.getMovePower(i) );
        WriteUint32_t(file,(uint32_t) toWritePoke.getMoveMin(i) );
        WriteUint32_t(file,(uint32_t) toWritePoke.getMoveMax(i) );
    }
    //std::cout<<"\nWriteClassPoke succssesfully realised\n";
}

void ReadClassPoke (std::istream& file, Poke & toReadPoke)
{   uint8_t data;

    //unsigned char numberOfMoves = toWritePoke.getNumberOfMoves();
    toReadPoke.setNumber(ReadUint32_t(file));
    toReadPoke.setName(ReadString(file));
    file.read( (char*) &data, 1);//
    toReadPoke.setMovePoints((unsigned char)data);
    toReadPoke.setType(ReadType(file));
    toReadPoke.setNamePokemonPower(ReadString(file));
    toReadPoke.setTextPokemonPower(ReadString(file));
    file.read( (char*) &data, 1);//
    toReadPoke.setNumberOfMoves((unsigned char)data);

    unsigned char numberOfMoves = data;

    for (unsigned char i = 0; i < numberOfMoves; i++)
    {	toReadPoke.setMoveName(ReadString(file), i);
        toReadPoke.setMoveColor(ReadColorType(file), i);
        file.read( (char*) &data, 1);//
        toReadPoke.setMoveStars((unsigned char)data, i);
        toReadPoke.setMoveTextPower(ReadString(file), i);
        toReadPoke.setMovePower(ReadString(file), i);
        toReadPoke.setMoveMin(ReadUint32_t(file), i);
        toReadPoke.setMoveMax(ReadUint32_t(file), i);
    }
    //std::cout<<"\nReadClassPoke succssesfully realised\n";
}
