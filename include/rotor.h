#pragma once

class Rotor
{
private:
    int forwardMap[26];
    int reverseMap[26];
    int currentPosition;
public:
    Rotor(int number);
    ~Rotor();
};
