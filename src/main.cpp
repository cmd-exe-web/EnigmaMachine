#include <iostream>

#include "../include/utils.h"
#include "../include/rotor.h"

int main() {
    std::unordered_map<char, char> data = readDataFromFile("rotor1");

    Rotor rotor(data);

    // std::cout << "Forward Map" << std::endl;
    // rotor.PrintForwardMap();
    // std::cout << "Reverse Map" << std::endl;
    // rotor.PrintReverseMap();

    char inputChar = 'a';
    std::cout << "Original char: " << inputChar << std::endl;
    char encryptedChar = rotor.encrypt(inputChar);
    std::cout << "Encrypted char: " << encryptedChar << std::endl;

    char decryptedChar = rotor.decrypt(encryptedChar);
    std::cout << "Decrypted char: " << decryptedChar << std::endl;


    inputChar = 'b';
    std::cout << "Original char: " << inputChar << std::endl;


    encryptedChar = rotor.encrypt(inputChar);
    std::cout << "Encrypted char: " << encryptedChar << std::endl;

    decryptedChar = rotor.decrypt(encryptedChar);
    std::cout << "Decrypted char: " << decryptedChar << std::endl;

}