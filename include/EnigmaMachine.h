#pragma once

#include "../include/utils.h"
#include "../include/EnigmaMachine.h"
#include "../include/keyboard.h"
#include "../include/plugboard.h"
#include "../include/rotor.h"
#include "../include/reflector.h"

#include <string>

class EnigmaMachine
{
public:
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

    void set_key(std::string key);

    char encipher(char letter);
};