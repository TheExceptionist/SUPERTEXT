#ifndef DEFS_H
#define DEFS_H

#include <stdint.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdexcept> 
#include <stdlib.h>  

#define TRUE 1
#define FALSE 0

#define ACCEPT 0
#define STORE 1
#define ACCEPT_INT 2

#define EXIT_CODE -100

#define DEBUG

namespace e_std
{
    typedef uint8_t e_byte;
    typedef uint16_t e_halfword;
    typedef uint32_t e_word;
    typedef uint64_t e_doubleword;

    typedef int8_t e_int8;
    typedef int16_t e_int16;
    typedef int32_t e_int32;
    typedef int64_t e_int64;

    typedef const char* e_str;
    typedef e_byte e_bool;

	bool accept(const std::string& question, const std::string& match);
	void store(const std::string& question, std::string* storeTo);
    int acceptIntln(const std::string& question);
    int acceptInt(const std::string& question);
    int loopAccept(const std::string& question, const std::string& match, std::string* storeTo, const int type);
    void println(const std::string& str);
    int randInt(int min, int max);
    //Unix systems only
    void clear();
}
#endif
