#include <iostream>

#include "Start.hpp"

int Start::step()
{
    int option;
    std::cout<<"Welcome to MathMaster!"<<std::endl;
    std::cout<<"0 - Exit"<<std::endl;
    std::cout<<"1 - Play"<<std::endl;
    std::cout<<"2 - Settings"<<std::endl;
    std::cin>>option;
    return option;
}