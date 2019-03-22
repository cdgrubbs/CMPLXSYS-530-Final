# Model Proposal for Developement Planner

Cory Grubbs and Tia Esposito

* Course ID: CMPLXSYS 530,
* Course Title: Computer Modeling of Complex Systems
* Term: Winter, 2019



&nbsp; 

### Goal 
*****
 
In the world of software development, it is a difficult and pervasive problem to get a team of coders to work together efficiently. The problem comes from getting multiple files and functions made by multiple coders to work well together all the while they are developed simultaneously. While there are platforms that allow for simultaneous editing, merger conflicts are commonplace. The goal of the model is to find the best and fastest way to plan and code and entire program with no bugs.

&nbsp;  
### Justification
****
_Short explanation on why you are using ABM_

Everything that is done to develop a program is completely reliant on how the coders work and plan both together and individually. By using an ABM I will be able to see all of the emergant effects of changing a paticular of planning or coding since it all boils down to the agents themselves. If I didn't use ABM I wouldn't be able to know if the style I have used actually works, since it would just be applying unsupported numbers.

*LS COMMENTS: Solid motivation and justification for use of ABM.*

&nbsp; 
### Main Micro-level Processes and Macro-level Dynamics of Interest
****

_Short overview of the key processes and/or relationships you are interested in using your model to explore. Will likely be something regarding emergent behavior that arises from individual interactions_

I am very interested how each of the decisions in the phases affect each other. For example if I apply a short planning phase, the planning phase would obiously be shorter, but how would that affect the coding and debugging phases? What If I make the planning phase 1 tick longer, how would that affect the other phases now? I am interested in finding the optimal balance in terms of style that makes the overall developement shortest. All of this ends up relying on the style chosen and how this makes the agents interact.

&nbsp; 

*LS COMMENTS: One way to frame these issues would be to focus on the interaction of a variety of individual styles with different types of institutional or collaboration infrastructures.*

## Model Outline
****

### Disclaimer
 * _The model will not only contain 1 Enviroment but will contain 3. One for each phase of development: Planning, Coding, and Debugging, and I will split each of the descriptions into 3 sections as such._
 * _The model will also contain more than one language for it's implementation. For the purpose of speed I will be using C++ to do all of the computations to allow me to quickly run through many possibilities and allow me to not deal with the slowness of displaying graphics when it is not neccessary. For the purpose of showing graphics, when it is needed, we will be using Python._
&nbsp; 

*LS COMMENTS: Sounds good and no problem using C++ for this project if that is where you feel most comfortable.*

### 1) Environment
_Description of the environment in your model. Things to specify *if they apply*:_

* _Boundary conditions (e.g. wrapping, infinite, etc.)_
  * The boundary will be a finite square grid with no wrapping. 
* _Dimensionality (e.g. 1D, 2D, etc.)_
  * The enviroment will always be a 2D grid regardless of the phase that the enviorment is in
* _List of environment-owned variables (e.g. resources, states, roughness)_
  * Phase: The phase that the enviroment currently is: Planning, Coding, and Debugging
  * Agents: A double array of agent pointers about which agent (if any) is on each part of the grid of the enviroment
  * Planning Style: The way that the agents communicate information about the project during the planning phase
  * Coding Style: The way that the agents code during the coding phase
  * Number of bugs: The number of bugs the coders have accumulated
  * Time of Planning: The time that the agents spend in the planning phase
  * Progress: Precentage of the program completed during coding phase
* _List of environment-owned methods/procedures (e.g. resource production, state change, etc.)_
  * Phase Change: Changes to the next phase in the order of Planning -> Coding -> Debugging
  * Communicate: Depending on the Planning Style, agents change their understanding of the project during the planning phase
  * Code: Depending on the coding style, agents progress towards finishing the progress while accumulating bugs dependant on agents levels of understanding and skill
  * Debug: Depending on number of agents and their levels of understanding and skill, decreases bugs until the program is finished

*LS COMMENTS: I'm a little unclear about whether the "planning" and "coding style" are agent or environment variables? Also, interested in knowing more about how you are thinking about planning on representing coding styles and code here. How you implement these will be very important here. Also, I am not sure that the phases necessarily belong to the environment unless it is going to affect which agents interact which others or if there will be different "feedbacks" coming in from the environment at those points.*

*Another thing to think about, possibly for future work, is how much the grid structure is likely to drive your results. For instance, if you used a network topology instead of a grid, how much would that impact what you get?*

```cpp
class Enviroment
{
    public:

    Enviroment(char p_style, char c_style, int num_coders, int t_planning) : planning_style(p_style), coding_style(c_style), time_planning(t_planning)
    {
        phase = 'p';
        coder = new coder[sqrt(num_coders)][sqrt(num_coders)]
        num_bugs = 0;
        progress = 0;
    }

    void phase_change()
    {
        switch(phase){
            case 'p':
                phase = 'c';
                break;
            case 'c':
                phase = 'd';
                break;
        }
    }

    void communicate()
    {
        for (int i = 0; i < sqrt(num_coders); i++)
        {
            for (int j = 0; j < sqrt(num_coders); j++)
            {
                if (/*Randomly decides if this agent communicates*/)
                {
                    // Randomly picks a neighboring agent
                    
                    /*Agent with lower understanding*/(*agents)[i][j].update_understanding(((*agents)[i][j].get_understanding() + /*neighboring agent's understanding*/) / 2.0);
                }
            }
        }
    }

    void code()
    {
        for (int i = 0; i < sqrt(num_coders); i++)
        {
            for (int j = 0; j < sqrt(num_coders); j++)
            {
                (*agents)[i][j].update_progress();
                (*agents)[i][j].generate_bug();
            }
        }
    }

    void debug()
    {
        for (int i = 0; i < sqrt(num_coders); i++)
        {
            for (int j = 0; j < sqrt(num_coders); j++)
            {
                (*agents)[i][j].squash_bug();
            }
        }
    }



    private:
    char phase;
    coder *agents[][];
    char planning_style;
    char coding_style;
    int num_bugs;
    int time_planning;
    double progress;
}
```

&nbsp; 

### 2) Agents
 
 _Description of the "agents" in the system. Things to specify *if they apply*:_
 
* _List of agent-owned variables (e.g. age, heading, ID, etc.)_
  * Skill: The level of skill they have at the start, this will not change and will be assigned randomly from the start
  * Understanding: The level at which they they understand the program they are coding, this will be initialy 0 and may or may not change during the planning and coding phases
  * Position: The place that they are currently at in the grid
* _List of agent-owned methods/procedures (e.g. move, consume, reproduce, die, etc.)_
  * Move: Moves the agent to another spot in the grid during the planning phase
  * Set Skill: Randomly assigns a skill level
  * Update Understanding: Takes in a value that changes their understanding
  * Progress: Updates the global amount for how much the program has left to develop
  * Generate Bug: Decides if a bug should be created during coding phase (Dependant on Skill and Understanding)
  * Squash Bug: Decides if a bug should be destroyed during debugging phase (Dependant on Skill and Understanding)

*LS COMMENTS: These and the environmental methods/variables above are a good start, but at present, it looks like there is a lot of  work left to be done to really nail down how these various moving parts are going to be 1) conceptualized and 2) implemented computationally. I would suggest getting the core processes sketched out first, maybe just deciding on how agents will communicate and how you will represent both the "code" product and the "coding style" aspects through which the agents individually and collectively generate and alter it. From there, you can move into bugs, etc. Coming up with a flow chart that captures how the "code" object gets interacted with by the agents might be useful.*

```cpp
class coder
{
    public:

    coder(int x, int y): pos_x(x), pos_y(y)
    {
        skill = set_skill();
        understanding = 0;
    }

    void move(coder *c)
    {
        swap((*c).pos_x, pos_x);
        swap((*c).pos_y, pos_y);
    }

    double set_skill()
    {
        return // Random double between 0 and 100
    }

    void update_understanding(double under)
    {
        understanding = under;
    }

    void update_progress()
    {
        // progress += Some way of using skill and understanding to determine how much to change progress by
    }

    void generate_bug()
    {
        if (.75 < //Some way of using skill and understanding to determine whether bug should be increased or not)
        {
            bugs += 1;
        }
    }

    void squash_bug()
    {
        if (.75 < //Some way of using skill and understanding to determine whether bug should be decreased or not)
        {
            bugs -= 1;
        }
    }

    double get_understanding()
    {
        return understanding;
    }
    private:
    double skill;
    double understanding;
    int pos_x;
    int pos_y;
}
```

&nbsp; 

### 3) Action and Interaction
 
**_Interaction Topology_**

_Description of the topology of who interacts with whom in the system. Perfectly mixed? Spatial proximity? Along a network? CA neighborhood?_
* Planning Phase:
  * Depending on the Planning Style, agents will interact in a spatial proximity to each other which will increase their level of understanding. They will be able to swap places with each other and interact with their new neighbors
* Coding Phase:
  * Depending on the Coding Style, agents will interact with any other agents from time to time but will most likely be very infrequent
* Debugging Phase:
  * Agents will not be able to interact with each other at all
 
*LS COMMENTS: I like how interactions change per being in different phases. Very insightful.*

**_Action Sequence_**

_What does an agent, cell, etc. do on a given turn? Provide a step-by-step description of what happens on a given turn for each part of your model_

* Planning Phase
  1. If Planning Style allows for spatial communication: randomly chosen agents will communicate with one of their neigbors and their understanding may increase
  2. If Planning Style allows for movement: randomly chosen agents will swap with one of their neighbors
* Coding Phase
  1. Agent will progress towards completion of the program, progress is based on their level of skill and understanding
  2. Agents may or may not randomly generate a bug depending on their level of skill and understanding
  3. If Coding Style allows for communication: The agent may interact with another agent and their understanding level will increase
* Debugging Phase
  1. Agents may decrease bug count depending on their level of skill and understanding
  
*LS COMMENTS: Good first pass description.*

&nbsp; 
### 4) Model Parameters and Initialization

_Describe and list any global parameters you will be applying in your model._
* Planning Style: A predetermined style which describes how the planning phase will be done. This determines how long it will last, whether there is a global anouncment, if the agents will be able to communicate to each other and possibly more
* Coding Style: A predetermined style which describes how the coding phase will happen. Some styles will be more likely to generate bugs but work quicker and vice versa. This style will also determine whether agents will be able to communicate with each other during the coding phase.

*LS COMMENTS: From this description, I think you mean that the coding and planning styles will be global rules that all the agents follow, correct?*

_Describe how your model will be initialized_
* The set number of agents will be created and randomly put on the grid with a random level of skill and a understanding of 0
* If the Planning Style has a global anouncment, adjust understanding to a random number

_Provide a high level, step-by-step description of your schedule during each "tick" of the model_
* Planning
  * Agents will communicate if spatial communication is allowed and their understanding level may change
  * Agents may swap positions with an adjacent agent
* Coding
  * Agents will change the global progression level
  * Agents will determine if they created a bug
  * Agents will then communicate if the Coding Style allows them to, resulting with their understanding possibly being increased
* Debugging
  * Agents will decide if they squash a bug or not

&nbsp; 

*LS COMMENTS: Lots of parts to implement, but hopefully you've made some headway on that over the past week.

### 5) Assessment and Outcome Measures

_What quantitative metrics and/or qualitative features will you use to assess your model outcomes?_
* How many ticks that the model takes to finish all three phases to rate which ones did best (Lower is better)
* How many ticks each individual phase took
* How many bugs were generated in the coding phase

*LS COMMENTS: Solid.*

&nbsp; 

### 6) Parameter Sweep

_What parameters are you most interested in sweeping through? What value ranges do you expect to look at for your analysis?_
* Parameter sweeps can be used to compare variables (skill, understanding, position) and debugging success.
* We are also interested in varying the length of each segment (planning, programming, debugging).
* How planning and coding styles interact with both variables and segment lengths. 
* The number of agents will change the results, especially dependant on communication and skill.

*LS COMMENTS: Ambitious model that I think could yield some pretty interesting dynamics. As mentioned, the key is going to get first your conceptual and then computational implementations of those above discussed agent interactions really nailed down ASAP. Those are going to be some big design choices that will likely have a lot of impact on what you get out of the model, so you'll want to be very clear about what you are doing and why. As always, I'd advocate developing a simple (even simplistic) representation first, just to get the flow of the model established, and then going back and making those processes more complex. If you get hung up on any decisions, definitely feel free to talk to me - always here to ping ideas off of if nothing else! 18.5/20*
