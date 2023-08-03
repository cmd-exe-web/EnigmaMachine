#pragma once

#include <unordered_map>

class Rotor
{
private:
    std::unordered_map<char, char> substitutionTable;
public:
    Rotor(std::unordered_map<char, char> substitutions);
    ~Rotor();

    void Print();
};
