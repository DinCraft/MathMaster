#include <random>
#include <iostream>

#include "Game.hpp"
#include "Data.hpp"

using std::cout;

int Game::step()
{
    int option;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(10,99);
    std::uniform_int_distribution<std::mt19937::result_type> dist2(2,9);
    for (int i = 0; i < Data::rnd; i++)
    {
        dist(rng);
        dist2(rng);
    }
    int correct = 0;
    for (int i = 0; i < 10; i++)
    {
        int a = dist(rng);
        int b = dist2(rng);
        int c = a*b;
        std::cout<<c<<"/"<<b<<"=";
        std::cin>>option;
        std::cout<<std::endl;
        if (option==a)
        {
            correct++;
        }
        if (option==0)
        {
            break;
        }
    }
    Data::rnd+=20;
    Data::xp+=correct;
    Data::save();
    std::cout<<"You have "<<correct<<" correct answers."<<std::endl;
    return 0;
}