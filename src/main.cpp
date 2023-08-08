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
    enigma.set_ring_setting("PQB");
    enigma.set_key("QBZ");
    // enigma.rightRotor.show();

    std::string message = "AAAA";
    
    // enigma.rightRotor.show();
    std::cout << enigma.encipher_string(message) << std::endl;
    // std::cout << enigma.encipher_string(message) << std::endl;
    // enigma.rightRotor.show();
    

//     I.show();
//     std::cout << "--------------------\n";
//     I.set_ring('B');
//     I.show();
}