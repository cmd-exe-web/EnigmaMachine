#pragma once

class Keyboard
{
private:
    
public:
    Keyboard();
    ~Keyboard();

    static int forward(char ch);
    static char backward(int signal);
};
