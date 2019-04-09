#include <cstdlib>
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
    double new_understanding;
    if (global_anouncement)
    {
        // Change these later
        new_understanding = understanding + 10;
        cout << "G " << x << " " << y << " " << new_understanding << endl;
        understanding = new_understanding;
    }
    else
    {
        // Change these later
        new_understanding = understanding + rand() % 10;
        cout << "U " << x << " " << y << " " << new_understanding << endl;
        understanding = new_understanding;
    }
    
}

double Coder::update_progress(char dif)
{
    // Change Later just to test
    return 1;
    // Do the stuff
    switch(dif)
    {
        case 'e':
            break;
        case 'm':
            break;
        case 'h':
            break;
    }
}

bool Coder::generate_bug()
{
    if (skill + understanding < static_cast<double>(rand() % 9) * 30.0) // Tweak later
    {
        return true;
    }
    return false;
}

bool Coder::squash_bug()
{
    if (skill + understanding > static_cast<double>(rand() % 9) * 25.0) // Tweak later
    {
        return true;
    }
    return false;
}

