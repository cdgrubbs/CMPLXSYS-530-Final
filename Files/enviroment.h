#include <iostream>
#include <vector>
#include "coder.h"
using namespace std;

class Enviroment
{
    public:
    // Constructor
    Enviroment(char p_style_in, char c_style_in, int num_coders_in, int x_size_in, int y_size_in, int t_planning, char difficulty_in, double skill_min_in, double skill_max_in);

    // Changes to the next phase
    void phase_change();

    // Sets inital plans
    void set_plans();

    // Sets all agents to have not communicated
    void clear_communicated();

    // Gets the possible communications in planning phase
    vector<pair<int, int>> possible_communications(int x, int y);

    // Updates tick
    void update_tick(int tick_amount);

    void move(Coder &a, Coder &b);

    // Planning phase
    void plan();

    // Coding phase
    void code();

    // Debugging phase
    void debug();


    struct p_style
    {
        bool global_announcement;
        bool communication;
    };

    struct c_style
    {
        bool communication_local;
    };

    private:
    int x_size;
    int y_size;
    char phase;
    char difficulty;
    int num_coders;
    vector<vector<Coder>> coders;
    vector<vector<bool>> is_coder;
    char planning_style;
    p_style planning_style_s;
    char coding_style;
    c_style coding_style_c;
    int num_bugs;
    int time_planning;
    double progress;
    int ticks;
};