#ifndef DATA
#define DATA

#include "json.hpp"

class Data
{
public:
    static nlohmann::json jsonData;
    static int xp;
    static int lvl;
    static int rnd;
    static void load();
    static void save();
    static void updateJsonData();
    static void updateFields();
    static void addXp(int);
    static int getLvl();
    //  0 10 30 60 100 150
    // 10 20 30 40 50

    // 150 220 310 420 550 700
    // 70   90  110 130 150
    
    // 700 880 1090 1330 1600 1900
    // 180 210 240   270   300

    // 1900 2240 2620 3040 3500 4000
    // 340   380   420  460   500

    // 4000 4550 5150 5800 6500 7250
    // 550   600   650  700   750
};

#endif