#ifndef ERORI_H
#define ERORI_H
#include <exception>
#include <iostream>

using namespace std;

class Erori:public exception
{
    public:
        Erori();
        const char* what(){
            return "Eror: Name not found!";}
};

#endif
