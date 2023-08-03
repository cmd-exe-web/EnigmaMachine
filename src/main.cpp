#include <iostream>

#include "../include/utils.h"
#include "../include/rotor.h"

std::string encode(const std::string& plaintext) {
    std::unordered_map<char, char> randomPair = readDataFromFile("rotor1");
    Rotor rotor(randomPair);
    std::string encodedText;

    for (char c : plaintext) {
        encodedText += rotor.encrypt(c);
    }
    return encodedText;
}

std::string decode(const std::string& encodedText) {
    std::unordered_map<char, char> randomPair = readDataFromFile("rotor1");
    Rotor rotor(randomPair);
    std::string decodedText;

    for (char c : encodedText) {
        decodedText += rotor.decrypt(c);
    }
    return decodedText;
}

int main() {
    std::string plaintext = "hello";
    std::string encodedText = encode(plaintext);

    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Encoded string: " << encodedText << std::endl;

    std::string decodedText = decode(encodedText);
    std::cout << "Decoded Text: " << decodedText << std::endl;

}