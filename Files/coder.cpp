#include <cstdlib>
#include <cmath>
#include <iostream>
#include "coder.h"

Coder::Coder(int pos_x, int pos_y) : x(pos_x), y(pos_y)
{
    init_skill(0, 100);
    understanding = 0;
    communicated = false;
}

Coder::Coder(int pos_x, int pos_y, double skill_min, double skill_max) : x(pos_x), y(pos_y)
{
    init_skill(skill_min, skill_max);
    understanding = 0;
    communicated = false;
}

void Coder::init_skill(double skill_min, double skill_max)
{
    skill = skill_min + (static_cast<double>(rand()) / RAND_MAX) * (skill_max - skill_min);
    return;
}

void Coder::update_understanding(double understanding_in, bool global_anouncement)
{
    double new_understanding = understanding;
    if (global_anouncement)
    {
        new_understanding = understanding + (rand() % 40);
        cout << "G " << x << " " << y << " " << new_understanding << endl;
        understanding = new_understanding;
    }
    else
    {
        if (understanding == 0 && new_understanding == 0)
        {
            new_understanding = rand() % 10;
        }

        if (understanding < understanding_in)
        {
            new_understanding = understanding * (1 + (understanding_in - understanding) / understanding_in);
        }
        else
        {
            new_understanding = understanding * (1 + ((understanding - understanding_in) / understanding) / 5.0);
        }

        if (new_understanding > 100)
        {
            new_understanding = 100;
        }
        
        cout << "U " << x << " " << y << " " << new_understanding << endl;
        understanding = new_understanding;
    }
    
}

double Coder::update_progress(char dif)
{
    int scale_factor = 0;
    double scale_min = 0;
    // Do the stuff
    switch(dif)
    {
        case 'e':
            scale_factor = 25;
            scale_min = 0;
            break;
        case 'm':
            scale_factor = 50;
            scale_min = 25;
            break;
        case 'h':
            scale_factor = 75;
            scale_min = 50;
            break;
    }
    if (skill + understanding > static_cast<double>((rand() % scale_factor)) + scale_min)
    {
        return 1 + (rand() % 2);
    }
    return .25;
}

bool Coder::generate_bug()
{
    if (skill + understanding < static_cast<double>(rand() % 8) * 30.0) // Tweak later
    {
        return true;
    }
    return false;
}

bool Coder::squash_bug()
{
    if (skill + understanding > (static_cast<double>(rand() % 8) + 1) * 25.0) // Tweak later
    {
        return true;
    }
    return false;
}

