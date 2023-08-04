#include <iostream>

#include "../include/utils.h"
#include "../include/rotor.h"

int main() {
    std::unordered_map<char, char> randomPair2 = createRandomPair();

    for (auto&& it : randomPair2)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }


    saveRandomPairToFile(randomPair2, "rotor1");


    // std::unordered_map<char, char> randomPair = readDataFromFile("rotor1");
    // Rotor rotor(randomPair);
    // rotor.setPosition(6);
    // std::string plaintext = "hello";
    // std::string encodedText = rotor.encode(plaintext);

    // std::cout << "Plaintext: " << plaintext << std::endl;
    // std::cout << "Encoded string: " << encodedText << std::endl;

    // rotor.setPosition(6);

    // std::string decodedText = rotor.decode(encodedText);
    // std::cout << "Decoded Text: " << decodedText << std::endl;

}