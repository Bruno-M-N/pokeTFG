//http://www.cplusplus.com/reference/cstdio/stdin/?kw=stdin
//http://www.cplusplus.com/reference/ios/ios/good/
//http://www.cplusplus.com/reference/iolibrary/

#include "file_operations.h"

void WriteUint32_t (std::ofstream& file, uint32_t value)
{   uint8_t bytes[4];
    //Formating the value to 4 individual bytes
    bytes[0] = (value)& 255; // 0b11111111 LSB Less Significant Byte First
    bytes[1] = (value >> 8) & 255; //0b11111111
    bytes[2] = (value >> 16) & 255; //0b11111111
    bytes[3] = (value >> 24) & 255; //0b11111111 MSB Most Significant Byte Last

    //Write bytes LSB byte first, regardless platform
    //These is intended to guarante the reading of a file made in one plataform
    //on a different one
    file.write((char*) bytes,4 );

    //TODO Checar bits de checagem
}

uint32_t ReadUint32_t (std::istream& file)
{   uint32_t value;
    uint8_t bytes[4];

    //Read 4 bytes from the file
    file.read( (char*) bytes, 4);
    //Recovering the uint32_t (32 bits value) from the 4 bytes
    value = bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3]<<24);
    return value;
}

void WriteString  (std::ofstream& file, std::string str)
{   uint32_t length = str.size();
    //std::cout << "String size: " << length << std::endl;

    WriteUint32_t(file,length);
    file.write( str.c_str() ,length);
}

std::string ReadString (std::istream& file)
{   uint32_t length = ReadUint32_t(file);
    char* buffer = new char [length];
    //http://www.cplusplus.com/doc/tutorial/exceptions/
    file.read(buffer,length);

    std::string str(buffer, length);
    delete[] buffer;

    return str;
}
