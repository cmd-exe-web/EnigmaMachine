#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <algorithm>
#include <fstream>
#include <numeric>


std::unordered_map<char, char> createRandomPair()
{
    std::vector<int> randomLetters;
    std::unordered_map<char, char> randomPair;
    std::unordered_set<int> usedIndices;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 25);

    for (int i = 0; i < 26; i++) {
        int randomIndex = dist(gen);

        while (usedIndices.find(randomIndex) != usedIndices.end() || randomIndex == i) {
            randomIndex = dist(gen);
        }

        usedIndices.insert(randomIndex);
        randomLetters.push_back(randomIndex);
    }

    for (int i = 0; i < 26; i++)
    {
        char original = 'a' + i;
        char mapped = 'a' + randomLetters[i];

        randomPair[original] = mapped;
    }
    return randomPair;
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