#pragma once

class Rotor
{
public:
    int forwardMap[26];
    int reverseMap[26];
    int currentPosition;
    int notch;
    
public:
    Rotor(int number);
    ~Rotor();

    void print();

    int forwardPass(int letter);
    int backwardPass(int letter);

    void rotate();
    void show();

    void set(char letter);
};
