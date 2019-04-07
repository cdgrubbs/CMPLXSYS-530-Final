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
    // Randomly init skill
}

void Coder::update_understanding(double understanding_in, bool global_anouncement)
{
    double new_understanding;
    if (global_anouncement)
    {
        cout << "G " << x << " " << y << " " << new_understanding << endl;
        // Do some stuff
    }
    else
    {
        cout << "U " << x << " " << y << " " << new_understanding << endl;
        // Do some stuff
    }
    
}

double Coder::update_progress(char dif)
{
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
    // Decides if bug generated
}

bool Coder::squash_bug()
{
    // Decides if bug squashed
}

