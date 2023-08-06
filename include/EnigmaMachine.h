#pragma once

#include "../include/utils.h"
#include "../include/EnigmaMachine.h"
#include "../include/keyboard.h"
#include "../include/plugboard.h"
#include "../include/rotor.h"
#include "../include/reflector.h"

class EnigmaMachine
{
private:
    Rotor leftRotor;
    Rotor middleRotor;
    Rotor rightRotor;

    Reflector reflector;
    Keyboard keyboard;
    Plugboard plugboard;

public:
    EnigmaMachine(Rotor leftRotor,
    Rotor middleRotor,
    Rotor rightRotor,
    Reflector reflector,
    Keyboard keyboard,
    Plugboard plugboard);
    ~EnigmaMachine();

    char encipher(char letter);
};