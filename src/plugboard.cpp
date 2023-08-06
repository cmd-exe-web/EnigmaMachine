#include "../include/plugboard.h"

#include <iostream>
#include <string>

Plugboard::Plugboard()
{
    for (int i = 0; i < 26; i++)
    {
        wiring[i] = i;
    }
    
}

Plugboard::~Plugboard()
{
}

int Plugboard::forward(int letter)
{
    return wiring[letter];
}

int Plugboard::backward(int letter){
    for(int i = 0; i < 26; i++){
        if(wiring[i] == letter)
            return i;
    }
    return -1;
}

void Plugboard::swap(std::string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int original = arr[i][0] - 'A';
        int swap = arr[i][1] - 'A';

        wiring[original] = swap;
        wiring[swap] = original;

    }
    
}

void Plugboard::print()
{
    for (int i = 0; i < 26; i++)
    {
        std::cout << (char)(wiring[i] + 'A');
    }
    std::cout << std::endl;
    for (int i = 0; i < 26; i++)
    {
        std::cout << (char)('A' + i);
    }
    std::cout << std::endl;
}