#include "enviroment.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        // test mode
    }
    else
    {
        char p_style_in = *argv[1];
        char c_style_in = *argv[2];
        int num_coders_in = stoi(argv[3]);
        int x_size_in = stoi(argv[4]);
        int y_size_in = stoi(argv[5]);
        int t_planning = stoi(argv[6]);
        char difficulty_in = *argv[7];
        double skill_min_in = stod(argv[8]);
        double skill_max_in = stod(argv[9]);
        Enviroment e(p_style_in, c_style_in, num_coders_in, x_size_in, y_size_in, t_planning, difficulty_in, skill_min_in, skill_max_in);
        e.plan();
        e.phase_change();
        e.code();
        e.phase_change();
        e.debug();
        return 0;
    }
}