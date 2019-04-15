#include <fstream>
#include "enviroment.h"

using namespace std;

void data_suite();

void run(Enviroment &e, ofstream &data, ofstream &informative, double skill_min, double skill_max, int count);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        data_suite();
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


void data_suite()
{
    ofstream data;
    ofstream informative;
    data.open("data.txt");
    informative.open("informative.txt");

    vector<char> possible_plannings {'a', 'b', 'c', 'd'};
    vector<char> possible_codings {'a', 'b'};
    vector<int> possible_num_coders {1, 4, 10, 25, 50, 75, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    vector<pair<int, int>> possible_sizes {{1, 1}, {2, 2}, {5, 5}, {10, 10}, {15, 15}, {25, 25}, {50, 50}, {75, 75}, {100, 100}};
    vector<int> possible_t_planning {0, 5, 10, 20, 30, 40, 50, 100};
    vector<char> possible_difficulties {'e', 'm', 'h'};
    vector<pair<double, double>> possible_skill_ranges {{0, 100}, {30, 70}, {50, 50}};

    unsigned int count = 0;
    for (int i = 0; i < static_cast<int>(possible_plannings.size()); i++)
    {
        for (int j = 0; j < static_cast<int>(possible_codings.size()); j++)
        {
            for (int k = 0; k < static_cast<int>(possible_num_coders.size()); k++)
            {
                for (int l = 0; l  < static_cast<int>(possible_sizes.size()); l++)
                {
                    for (int m = 0; m < static_cast<int>(possible_t_planning.size()); m++)
                    {
                        for (int n = 0; n < static_cast<int>(possible_difficulties.size()); n++)
                        {
                            for (int o = 0; o < static_cast<int>(possible_skill_ranges.size()); o++)
                            {
                                if (possible_sizes[l].first * possible_sizes[l].second >= possible_num_coders[k])
                                {   
                                    Enviroment e(possible_plannings[i], possible_codings[j], possible_num_coders[k],
                                    possible_sizes[l].first, possible_sizes[l].second, possible_t_planning[m], 
                                    possible_difficulties[n], possible_skill_ranges[o].first, possible_skill_ranges[o].second);
                                    run(e, data, informative, possible_skill_ranges[o].first, possible_skill_ranges[o].second, count);
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    data.close();
    informative.close();
    return;
}

void run(Enviroment &e, ofstream &data, ofstream &informative, double skill_min, double skill_max, int count)
{
    informative << "Run Number: " << count << endl;
    data << "Run Number: " << count << endl;
    informative << "Planning Style: " << e.get_p_style() << endl;
    informative << "Coding Style: " << e.get_c_style() << endl;
    informative << "Number of Coders: " << e.get_num_coders() << endl;
    informative << "Dimensions: " << e.get_x_size() << "X" << e.get_y_size() << endl;
    informative << "Time Planning: " << e.get_time_planning() << endl;
    informative << "Difficulty: " << e.get_difficulty() << endl;
    informative << "Initial Skill Range: " << skill_min << "-" << skill_max << endl;
    e.plan();
    e.phase_change();
    e.code();
    int bugs = e.get_num_bugs();
    e.phase_change();
    e.debug();
    int ticks = e.get_ticks();
    informative << "Bugs: " << bugs << endl;
    informative << "Ticks: " << ticks << endl << endl;
    data << bugs << endl;
    data << ticks << endl;
    return;
}