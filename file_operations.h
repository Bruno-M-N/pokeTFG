/* The objective of this header is to implement the basic operation for file
   manipulation, either text or bin files.
   Note that strings and uint32_t are defined here.
   The programmer may define a function usign those acording to it's needs.

    The way of handling bin files properly is this article:
    Disch's tutorial to good binary files Avayble at:
    http://www.cplusplus.com/articles/DzywvCM9/

    You may want to do your file_operation_extension.h and
    file_operation_extension.cpp customise for your application.
    (like to implement other types)
*/

#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

// basic file operations
#include <iostream>
#include <fstream>

// Data types consistent across plataforms
#include <cstdint>

#include <string>

void WriteUint32_t (std::ofstream& file, uint32_t value);

uint32_t ReadUint32_t (std::istream& file);

void WriteString  (std::ofstream& file, std::string str);

std::string ReadString (std::istream& file);

#endif // FILE_OPERATIONS_H
