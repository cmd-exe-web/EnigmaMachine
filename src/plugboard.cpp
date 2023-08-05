#include "../include/plugboard.h"


Plugboard::Plugboard()
{
    for(int i = 0; i < 26; i++)
        wiring[i] = i;
}

Plugboard::~Plugboard()
{
}
