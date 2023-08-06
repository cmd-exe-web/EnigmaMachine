#pragma once

class Reflector
{
private:
    int wiring[26];
public:
    Reflector(char letter);
    ~Reflector();

    int reflect(int letter);
};
