#include <iostream>
#include "../include/rotor.h"

Rotor::Rotor(std::unordered_map<char, char> substitutions)
    :forwardMap(substitutions), currentPosition(0)
{
    for (const auto& pair : forwardMap)
    {
        reverseMap[pair.second] = pair.first;
    }


}

Rotor::~Rotor()
{
}

void Rotor::setPosition(int position) {
    currentPosition = position;
}

void Rotor::rotate() {
    currentPosition = (currentPosition + 1) % 26;
}

char Rotor::encrypt(char input) {
    char mappedChar = forwardMap.at(input);
    mappedChar = 'a' + (mappedChar - 'a' + currentPosition) % 26;

    rotate();
    return mappedChar;
}

char Rotor::decrypt(char input) {
    char mappedChar = 'a' + (input - 'a' - currentPosition + 26) % 26;

    rotate();
    return reverseMap.at(mappedChar);
}

void Rotor::PrintForwardMap()
{
    for (auto&& it : forwardMap)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }

}
void Rotor::PrintReverseMap()
{
    for (auto&& it : reverseMap)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }

}