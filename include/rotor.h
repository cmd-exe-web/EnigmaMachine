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

    void rotate();

    char encrypt(char input) const;
    char decrypt(char input) const;

    std::string encode(const std::string& data);

    void PrintForwardMap();
    void PrintReverseMap();
};
