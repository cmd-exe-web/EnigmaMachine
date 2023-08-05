#include "../include/rotor.h"

#include <iostream>
#include <string>

Rotor::Rotor(int number)
{
    std::string rotor;
    switch (number)
    {
    case 1:
        rotor = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        break;
    case 2:
        rotor = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        break;
    case 3:
        rotor = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        break;
    case 4:
        rotor = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        break;
    case 5:
        rotor = "VZBRGITYUPSDNHLXAWMJQOFECK";
        break;
    
    default:
        std::cerr << "Provide a rotor number" << std::endl;
        return;
    }
    for(int i = 0; i < 26; i++){
        forwardMap[i] = rotor[i] - 'A';
        reverseMap[rotor[i] - 'A'] = i;
    }
}
Rotor::~Rotor()
{

}