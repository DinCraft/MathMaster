#include <iostream>

#include "Settings.hpp"

int Settings::step()
{
    int option;
    std::cout<<"Settings"<<std::endl;
    std::cout<<"0 - Back"<<std::endl;
    std::cin>>option;
    return option;
}