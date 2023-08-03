#include <iostream>
#include "../include/rotor.h"

Rotor::Rotor(std::unordered_map<char, char> substitutions)
    :substitutionTable(substitutions)
{

}

Rotor::~Rotor()
{
}


void Rotor::Print()
{
    for (auto&& it : substitutionTable)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }

}