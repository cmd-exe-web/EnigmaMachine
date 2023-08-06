#pragma once

#include <string>

class Plugboard
{
public:
    int wiring[26];
public:
    Plugboard();
    ~Plugboard();

    void swap(std::string arr[], int n);

    int forward(int letter);
    int backward(int letter);

    void print();
};
