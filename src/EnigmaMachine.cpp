#include "../include/EnigmaMachine.h"


EnigmaMachine::EnigmaMachine(Rotor leftRotor, Rotor middleRotor, Rotor rightRotor, Reflector reflector, Keyboard keyboard, Plugboard plugboard)
    :leftRotor(leftRotor), middleRotor(middleRotor), rightRotor(rightRotor), reflector(reflector), keyboard(keyboard), plugboard(plugboard)
{
}

EnigmaMachine::~EnigmaMachine()
{
}

void EnigmaMachine::set_key(std::string key)
{
    leftRotor.set(key[0]);
    middleRotor.set(key[1]);
    rightRotor.set(key[2]);
}

char EnigmaMachine::encipher(char letter)
{
    // rotating the rotor
    if(middleRotor.currentPosition == middleRotor.notch && rightRotor.currentPosition == rightRotor.notch)
    {
        rightRotor.rotate();
        middleRotor.rotate();
        leftRotor.rotate();
    }
    // double step anomaly
    else if(middleRotor.currentPosition == middleRotor.notch)
    {
        rightRotor.rotate();
        middleRotor.rotate();
        leftRotor.rotate();
    }
    else if(rightRotor.currentPosition == rightRotor.notch)
    {
        middleRotor.rotate();
        rightRotor.rotate();
    }
    else
    {
        rightRotor.rotate();
    }

    // passing signal through the machine
    int signal = keyboard.forward(letter);
    signal = plugboard.forward(signal);
    signal = rightRotor.forwardPass(signal);
    signal = middleRotor.forwardPass(signal);
    signal = leftRotor.forwardPass(signal);
    signal = reflector.reflect(signal);
    signal = leftRotor.backwardPass(signal);
    signal = middleRotor.backwardPass(signal);
    signal = rightRotor.backwardPass(signal);
    signal = plugboard.backward(signal);
    char encoded = keyboard.backward(signal);

    return encoded;
}

std::string EnigmaMachine::encipher_string(std::string message)
{
    std::string ciphertext;
    for (auto letter : message)
    {
        ciphertext += encipher(letter);
    }

    return ciphertext;
}
void EnigmaMachine::set_ring_setting(char str[])
{
    
}