// Agents Header
using namespace std;

class Coder
{
    public:
        // Constructor, sets skill_min and skill_max to default which is 0 and 100 respectivly
        Coder(int x_pos, int y_pos);

        // Constructor
        Coder(int x_pos, int y_pos, double skill_min, double skill_max);

        // Initalizes Skill to a random number between skill_min and skill_max
        void init_skill(double skill_min, double skill_max);

        // Updates understanding based on understanding that is passed in
        void update_understanding(double understanding_in, bool global_anouncment);

        // Returns how much progress the agent made towards completion
        double update_progress(char dif);

        // Decides if an agent generates a bug or not depending on skill and understanding
        bool generate_bug();

        // Decides if an agent squashes a bug or not depending on skill and understanding
        bool squash_bug();

        // Sets x value
        void set_x(int x_in)
        {
            x = x_in;
            return;
        }

        // Sets y value
        void set_y(int y_in)
        {
            y = y_in;
            return;
        }

        void set_skill(double skill_in)
        {
            skill = skill_in;
            return;
        }

        void set_understanding(double understanding_in)
        {
            understanding = understanding_in;
            return;
        }

        // Sets communicated
        void set_communicated(bool com)
        {
            communicated = com;
            return;
        }

        // Getter Funcitons
        int get_x()
        {
            return x;
        }

        int get_y()
        {
            return y;
        }

        double get_skill()
        {
            return skill;
        }

        double get_understanding()
        {
            return understanding;
        }

        bool is_communicated()
        {
            return communicated;
        }

    private:
        int x;
        int y;
        double skill;
        double understanding;
        bool communicated;
};