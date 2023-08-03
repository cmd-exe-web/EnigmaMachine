#include <iostream>
#include <unordered_map>
#include <random>
#include <algorithm>
#include <fstream>


std::unordered_map<char, char> createRandomPair()
{
    std::vector<int> randomNumbers(26);
    std::iota(randomNumbers.begin(), randomNumbers.end(), 0);

    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(randomNumbers.begin(), randomNumbers.end(), gen);


    std::unordered_map<char, char> randomPairs;

    for (int i = 0; i < 26; i++)
    {
        randomPairs['a' + i] = 'a' + randomNumbers[i];
    }

    return randomPairs;
}



void saveRandomPairToFile(const std::unordered_map<char, char>& data, std::string filename) {
    std::ofstream outputFile("db/" + filename);

    if (!outputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& pair : data) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }

    outputFile.close();
}

std::unordered_map<char, char> readDataFromFile(const std::string& filename) {
    std::unordered_map<char, char> data;
    std::ifstream inputFile("db/" + filename);

    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }

    char key, value;

    while (inputFile >> key >> value) {
        data[key] = value;
    }

    inputFile.close();
    return data;
}