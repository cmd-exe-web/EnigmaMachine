#pragma once

#include <unordered_map>
#include <string>

std::unordered_map<char, char> createRandomPair();

void saveRandomPairToFile(const std::unordered_map<char, char>& data, std::string filename);

std::unordered_map<char, char> readDataFromFile(const std::string& filename);