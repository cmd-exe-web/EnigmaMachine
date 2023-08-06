#include "../include/reflector.h"

#include <string>

Reflector::Reflector(char letter)
{
    std::string wire;

    // historical reflector wirings
    switch (letter)
    {
    case 'A':
        wire = "EJMZALYXVBWFCRQUONTSPIKHGD";
        break;

    case 'B':
        wire = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
        break;
    case 'C':
        wire = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
        break;
    
    default:
        break;
    }

    for(int i = 0; i < 26; i++){
        wiring[i] = wire[i] - 'A';
    }
}

Reflector::~Reflector()
{
}


int Reflector::reflect(int letter)
{
    return wiring[letter];
}