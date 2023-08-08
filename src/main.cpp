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
    // std::string swit[] = {"AB", "CD", "EF"};
    // plugboard.swap(swit, 3);

    EnigmaMachine enigma(IV, II, I, B, keyboard, plugboard);
    enigma.set_key("AAZ");
    enigma.set_ring_setting("AAA");
    // enigma.rightRotor.show();

    std::string message = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    
    std::cout << enigma.encipher_string(message) << std::endl;
    

    // I.show();
    // std::cout << "--------------------\n";
    // I.set(6);
    // I.show();
}