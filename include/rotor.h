#pragma once

#include <unordered_map>

class Rotor
{
private:
    std::unordered_map<char, char> forwardMap;
    std::unordered_map<char, char> reverseMap;
    int currentPosition;
public:
    Rotor(std::unordered_map<char, char> substitutions);
    ~Rotor();

    void setPosition(int position);

    void rotate();

    char encrypt(char input);
    char decrypt(char input);

    void PrintForwardMap();
    void PrintReverseMap();
};