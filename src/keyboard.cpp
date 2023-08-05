#include "../include/keyboard.h"


Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

int Keyboard::forward(char ch)
{
    return ch - 'A';
}

char Keyboard::backward(int signal)
{
    return 'A' + signal;
}