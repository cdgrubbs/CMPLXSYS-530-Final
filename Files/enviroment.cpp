#include "enviroment.h"

Enviroment::Enviroment(char p_style_in, char c_style_in, int num_coders_in, int x_size_in, int y_size_in, int t_planning, char difficulty_in, double skill_min_in, double skill_max_in) :
planning_style(p_style_in), coding_style(c_style_in), num_coders(num_coders_in), x_size(x_size_in), y_size(y_size_in), time_planning(t_planning),
difficulty(difficulty_in) 
{
    phase = 'p';
    set_plans();
    int cur_coders = 0;

    for (int i = 0; i < x_size; i++)
    {
        vector<Coder> temp;
        vector<bool> temp2;
        for (int j = 0; j < y_size; j++)
        {
            Coder temp3(i, j, 0.0, 0.0);
            temp.push_back(temp3);
            temp2.push_back(false);
        }
        coders.push_back(temp);
        is_coder.push_back(temp2);
    }

    int test = 50;
    bool to_break = false;
    while (cur_coders != num_coders)
    {
        for (int i = 0; i < x_size; i++)
        {
            for (int j = 0; j < y_size; j++)
            {
                if (!is_coder[i][j] && (rand() % 100) < test)
                {
                    is_coder[i][j] = true;
                    Coder c(i, j, skill_min_in, skill_max_in);
                    coders[i][j] = c;
                    cur_coders++;
                    if (cur_coders == num_coders)
                    {
                        to_break = true;
                        break;
                    }
                }
            }
            if (to_break)
            {
                break;
            }
        }
        test = test + (100 - test) / 2;
    }

    cout << "I " << x_size << " " << y_size << " " << num_coders << endl;
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            if (is_coder[i][j])
            {
                cout << "T " << coders[i][j].get_skill() << " ";
            }
            else
            {
                cout << "F 0.0 ";
            }
        }
        cout << endl;
    }

    num_bugs = 0;
    progress = 0;
    ticks = 0;
}

void Enviroment::phase_change()
{
    switch(phase)
    {
        case 'p':
            phase = 'c';
            break;
        case 'c':
            phase = 'd';
            break;
    }
    return;
}

void Enviroment::set_plans()
{
    // Change later with actual plans
    planning_style_s.global_announcement = true;
    planning_style_s.communication = true;
    coding_style_c.communication_local = true;
}

void Enviroment::clear_communicated()
{
    for (int i = 0; i < x_size; i++)
    {
        for (int j = 0; j < y_size; j++)
        {
            if (is_coder[i][j])
            {
                coders[i][j].set_communicated(false);
            }
        }
    }
}

vector<pair<int, int>> Enviroment::possible_communications(int x, int y)
{
    vector<pair<int, int>> potential;
    if (x > 0 && is_coder[x - 1][y] && !coders[x - 1][y].is_communicated())
    {
        potential.push_back({x - 1, y});
    }

    if (y > 0 && is_coder[x][y - 1] && !coders[x][y - 1].is_communicated())
    {
        potential.push_back({x, y - 1});
    }

    if (x < x_size - 1 && is_coder[x + 1][y] && !coders[x + 1][y].is_communicated())
    {
        potential.push_back({x + 1, y});
    }

    if (y < y_size - 1 && is_coder[x][y + 1] && !coders[x][y + 1].is_communicated())
    {
        potential.push_back({x, y + 1});
    }
    return potential;
}

void Enviroment::update_tick(int tick_amount)
{
    ticks += tick_amount;
    cout << "T " << ticks << endl;
}

void Enviroment::move(Coder &a, Coder &b)
{
    cout << "M " << a.get_x() << " " << a.get_y() << " " << b.get_x() << " " << b.get_y() << endl;

    int temp_x = a.get_x();
    int temp_y = a.get_y();
    double temp_skill = a.get_skill();
    double temp_understanding = a.get_understanding();
    bool temp_communicated = a.is_communicated();

    a.set_x(b.get_x());
    a.set_y(b.get_y());
    a.set_skill(b.get_skill());
    a.set_understanding(b.get_understanding());
    a.set_communicated(b.is_communicated());
    b.set_x(temp_x);
    b.set_y(temp_y);
    b.set_skill(temp_skill);
    b.set_understanding(temp_understanding);
    b.set_communicated(temp_communicated);
    return;
}

void Enviroment::plan()
{
    cout << "P" << endl;
    if (planning_style_s.global_announcement)
    {
        for (int i = 0; i < x_size; i++)
        {
            for (int j = 0; j < y_size; j++)
            {
                if (is_coder[i][j])
                {
                    coders[i][j].update_understanding(0.0, true);
                }
            }
        }
        update_tick(5);
    }
    if (planning_style_s.communication)
    {
        for (int i = 0; i < time_planning; i++)
        {
            for (int j = 0; j < x_size; j++)
            {
                for (int k = 0; k < y_size; k++)
                {
                    int rand_num = rand() % 100;
                    if (is_coder[j][k] && !coders[j][k].is_communicated() && rand_num < 75)
                    {
                        coders[j][k].set_communicated(true);
                        vector<pair<int, int>> possible = possible_communications(j, k);
                        if (possible.size() != 0)
                        {
                            int pos = rand() % static_cast<int>(possible.size());
                            coders[possible[pos].first][possible[pos].second].set_communicated(true);
                            coders[j][k].update_understanding(coders[possible[pos].first][possible[pos].second].get_understanding(), false);
                            coders[possible[pos].first][possible[pos].second].update_understanding(coders[j][k].get_understanding(), false);
                            move(coders[j][k], coders[possible[pos].first][possible[pos].second]);
                        }
                    }
                }
            }
            clear_communicated();
            update_tick(1);
        }
    }
}

void Enviroment::code()
{
    cout << "C" << endl;
    while (progress != 100)
    {
        // Progress
        for (int i = 0; i < x_size; i++)
        {
            for (int j = 0; j < y_size; j++)
            {
                bool prog_change = coders[i][j].update_progress(difficulty);
                progress += prog_change;
                cout << "X " << i << " " << j << " " << prog_change << " " << progress << endl;
                if (progress > 100)
                {
                    progress = 100;
                }

                // Bug generation
                if (coders[i][j].generate_bug())
                {
                    num_bugs++;
                    // Print Generate Bugs, x and y position of agent that generates bug
                    cout << "B " << i << " " << j << endl;
                }
            }
        }
        update_tick(1);

        if (coding_style_c.communication_local)
        {
            for (int i = 0; i < x_size; i++)
            {
                for (int j = 0; j < y_size; j++)
                {
                    int rand_num = rand() % 100;
                    if (is_coder[i][j] && !coders[i][j].is_communicated() && rand_num > 75)
                    {
                        vector<pair<int, int>> possible = possible_communications(i, j);
                        if (possible.size() != 0)
                        {
                            int pos = rand() % static_cast<int>(possible.size());
                            coders[i][j].set_communicated(true);
                            coders[possible[pos].first][possible[pos].second].set_communicated(true);
                            coders[i][j].update_understanding(coders[possible[pos].first][possible[pos].second].get_understanding(), false);
                            coders[possible[pos].first][possible[pos].second].update_understanding(coders[i][j].get_understanding(), false);
                        }
                    }
                }
            }
            clear_communicated();
            update_tick(1);
        }
    }
    return;
}

void Enviroment::debug()
{
    cout << "D" << endl;
    bool to_break = false;
    while (num_bugs != 0)
    {
        for (int i = 0; i < x_size; i++)
        {
            for (int j = 0; j < y_size; j++)
            {
                if (is_coder[i][j])
                {
                    if (coders[i][j].squash_bug())
                    {
                        num_bugs--;
                        // Print Debug, x and y position of agent that squashed a bug
                        cout << "S " << i << " " << j << endl;
                    }
                    if (num_bugs == 0)
                    {
                        to_break = true;
                        break;
                    }
                }
            }
            if (to_break)
            {
                break;
            }
        }
        update_tick(1);
    }
    return;
}