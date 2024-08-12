#include <iostream>
#include <fstream>

#include "Data.hpp"
#include "json.hpp"

using json = nlohmann::json;

int Data::xp;
int Data::rnd;
int Data::lvl;
json Data::jsonData;

void Data::load()
{
    std::ifstream in ("data.json");
    std::string data;
    in>>data;
    if (data=="")
    {
        std::cout<<"Create"<<std::endl;
        xp = 0;
        rnd = 0;
        lvl = 1;
        updateJsonData();
    }
    else
    {
        std::cout<<"Open"<<std::endl;
        jsonData = json::parse(data);
        updateFields();
    }
    in.close();
}

void Data::save()
{
    std::ofstream outfile ("data.json");
    updateJsonData();
    std::string stringData = jsonData.dump();
    outfile<<stringData;
    outfile.close();
}

void Data::updateJsonData()
{
    jsonData["xp"] = xp;
    jsonData["rnd"] = rnd;
    jsonData["lvl"] = lvl;
}

void Data::updateFields()
{
    xp = jsonData["xp"];
    rnd = jsonData["rnd"];
    lvl = jsonData["lvl"];
}

void Data::addXp(int xp_)
{
    xp+=xp_;
    getLvl();
}

int Data::getLvl()
{
    int inc = 10;
    int inc2 = 10;
    int incXp = 0;
    int incLvl = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            incXp+=inc;
            incLvl++;
            std::cout<<xp<<" "<<incXp<<" "<<lvl<<std::endl;
            if (incXp<xp)
            {
                lvl = incLvl;
                goto end;
            }
            if (j!=4)
            {    
                inc+=inc2;
            }
        }
        inc2+=10;
        inc+=inc2;
        // FIXME
        // Ещё один мат - и нет игры.
    }
    end:;
}