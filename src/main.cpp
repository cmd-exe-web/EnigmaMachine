#include <iostream>
#include <string>

#include "../include/utils.h"
#include "../include/EnigmaMachine.h"
#include "../include/keyboard.h"
#include "../include/plugboard.h"
#include "../include/rotor.h"
#include "../include/reflector.h"

int main() {
    Rotor I(1);
    Rotor II(2);
    Rotor III(3);
    Rotor IV(4);
    Rotor V(5);

    Reflector A('A');
    Reflector B('B');
    Reflector C('C');

    Keyboard keyboard;
    
    Plugboard plugboard;
    std::string swit[] = {"AR", "GK", "OX"};
    plugboard.swap(swit, 3);

    EnigmaMachine enigma(I, II, III, A, keyboard, plugboard);

    std::cout << enigma.encipher('A') << std::endl;
    

    // I.show();
    // std::cout << "--------------------\n";
    // I.set(6);
    // I.show();
}