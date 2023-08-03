#include <iostream>

#include "../include/utils.h"
#include "../include/rotor.h"

int main() {
    std::unordered_map<char, char> data = readDataFromFile("rotor1");

    Rotor rotor(data);

    rotor.Print();


}