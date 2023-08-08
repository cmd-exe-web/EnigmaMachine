#include "../include/rotor.h"

#include <iostream>
#include <string>

Rotor::Rotor(int number)
    :currentPosition(0), ringSetting(0)
{
    std::string rotor;
    int notch;
    // historical rotor wirings
    switch (number)
    {
    case 1:
        rotor = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        notch = 16;
        break;
    case 2:
        rotor = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        notch = 4;
        break;
    case 3:
        rotor = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        notch = 21;
        break;
    case 4:
        rotor = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        notch = 9;
        break;
    case 5:
        rotor = "VZBRGITYUPSDNHLXAWMJQOFECK";
        notch = 25;
        break;
    
    default:
        std::cerr << "Provide a rotor number" << std::endl;
        return;
    }
    for(int i = 0; i < 26; i++){
        forwardMap[i] = rotor[i] - 'A';
        reverseMap[rotor[i] - 'A'] = i;
    }
    this->notch = notch;
}
Rotor::~Rotor()
{
}

void Rotor::print(){
    for (size_t i = 0; i < 26; i++)
    {
        std::cout << i << " " << forwardMap[i] << std::endl;
    }
    std::cout << "Notch: " << notch << std::endl;
}

int Rotor::forwardPass(int letter)
{
    std::cout << "forward pass letter: " << letter << std::endl;
    int shift = (letter + currentPosition) % 26;
    std::cout << "shifted letter (index): " << shift << std::endl;
    std::cout << "value at shifted letter (index): " << forwardMap[shift] << std::endl;
    // std::cout << letter << " " << shift << " " << (forwardMap[shift] - currentPosition + 26) % 26 << std::endl;
    return (forwardMap[shift] - currentPosition  + ringSetting + 26) % 26;
}

int Rotor::backwardPass(int letter)
{
    int shift = (letter + currentPosition) % 26;
    return (reverseMap[shift] - currentPosition + ringSetting + 26) % 26;
}

void Rotor::rotate()
{
    currentPosition = (currentPosition + 1) % 26;
}

void Rotor::show()
{

    for (int i = currentPosition; i < 26; i++)
    {
        std::cout << (char)(i + 'A');
    }
    for (int i = 0; i < currentPosition; i++)
    {
        std::cout << (char)(i + 'A');
    }

    std::cout << std::endl;

    for (int i = currentPosition; i < 26; i++)
    {
        std::cout << (char)(forwardMap[i] + 'A');
    }
    for (int i = 0; i < currentPosition; i++)
    {
        std::cout << (char)(forwardMap[i] + 'A');
    }
    std::cout << std::endl;
}

void Rotor::set(char letter)
{
    int number = letter - 'A';
    currentPosition = number;
}

void Rotor::set_ring(char letter)
{
    // mapping letter to integer equivalent
    int shift = letter - 'A';
    int updatedForwardMap[26];
    ringSetting = shift;
    for (int i = 0; i < 26; i++)
    {
        updatedForwardMap[i] = forwardMap[(i - shift + 26) % 26];
    }
    for (int i = 0; i < 26; i++)
    {
        forwardMap[i] = updatedForwardMap[i];
    }

    int updatedReverseMap[26];

    for (int i = 0; i < 26; i++)
    {
        updatedReverseMap[i] = reverseMap[(i - shift + 26) % 26];
    }
    for (int i = 0; i < 26; i++)
    {
        reverseMap[i] = updatedReverseMap[i];
    }
}