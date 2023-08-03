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

void Rotor::rotate() {
    currentPosition = (currentPosition + 1) % 26;
}

char Rotor::encrypt(char input) const {
    char mappedChar = forwardMap.at(input);
    mappedChar = 'a' + (mappedChar - 'a' + currentPosition) % 26;
    return mappedChar;
}

char Rotor::decrypt(char input) const {
    char mappedChar = 'a' + (input - 'a' - currentPosition + 26) % 26;
    return reverseMap.at(mappedChar);
}

std::string Rotor::encode(const std::string& data)
{

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