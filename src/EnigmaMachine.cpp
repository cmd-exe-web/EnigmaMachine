#include "../include/EnigmaMachine.h"


EnigmaMachine::EnigmaMachine(Rotor leftRotor, Rotor middleRotor, Rotor rightRotor, Reflector reflector, Keyboard keyboard, Plugboard plugboard)
    :leftRotor(leftRotor), middleRotor(middleRotor), rightRotor(rightRotor), reflector(reflector), keyboard(keyboard), plugboard(plugboard)
{
}

EnigmaMachine::~EnigmaMachine()
{
}

char EnigmaMachine::encipher(char letter)
{
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