# Model Proposal for _[Project Name]_

Cory Grubbs

* Course ID: CMPLXSYS 530,
* Course Title: Computer Modeling of Complex Systems
* Term: Winter, 2019



&nbsp; 

### Goal 
*****
 
In the world of software development, it is a difficult problem to get a team of coders to work together efficiently. The problem comes from getting multiple files and functions made by multiple coders to work well together all the while they are developed simultaneously. The goal of my model is to find the best and fastest way to plan and code and entire program with no bugs.

&nbsp;  
### Justification
# *TODO*
****
_Short explanation on why you are using ABM_

&nbsp; 
### Main Micro-level Processes and Macro-level Dynamics of Interest
# *TODO*
****

_Short overview of the key processes and/or relationships you are interested in using your model to explore. Will likely be something regarding emergent behavior that arises from individual interactions_

&nbsp; 


## Model Outline
****

### Disclaimer
 * _My model will not only contain 1 Enviroment but will contain 3. One for each phase of development: Planning, Coding, and Debugging, and I will split each of the descriptions into 3 sections as such._
 * _My model will also contain more than one language for it's implementation. For the purpose of speed I will be using C++ to do all of the computations to allow me to quickly run through many possibilities and allow me to not deal with the slowness of displaying graphics when it is not neccessary. For the purpose of showing graphics, when it is needed, I will be using Python._
&nbsp; 
### 1) Environment
# *TODO*
_Description of the environment in your model. Things to specify *if they apply*:_

* _Boundary conditions (e.g. wrapping, infinite, etc.)_
  * ASD
* _Dimensionality (e.g. 1D, 2D, etc.)_
  * The enviroment will always be a 2D grid regardless of the phase that the enviorment is in
* _List of environment-owned variables (e.g. resources, states, roughness)_
  * Phase: The phase that the enviroment currently is: Planning, Coding, and Debugging
  * Has Agent: A double array of agent pointers about which agent (if any) is on each part of the grid of the enviroment
  * Planning Style: The way that the agents communicate/Get information about the project during the planning phase
  * Coding Style: The way that the agents code during the coding phase
  * Number of bugs: The number of bugs the coders have accumulated
  * Time of Planning: The time that the agents spend in the planning phase
* _List of environment-owned methods/procedures (e.g. resource production, state change, etc.)_
  * Phase_Change: Changes to the next phase in the order of Planning -> Coding -> Debugging
  * Communicate: Depending on the Planning Style, agents change their understanding of the project during the planning phase
  * Code: Depending on the coding style, agents progress towards finishing the progress while accumulating bugs dependant on agents levels of understanding and skill
  * Debug: Depending on number of agents and their levels of understanding and skill, decreases bugs until the program is finished


```cpp
# Include first pass of the code you are thinking of using to construct your environment
# This may be a set of "patches-own" variables and a command in the "setup" procedure, a list, an array, or Class constructor
# Feel free to include any patch methods/procedures you have. Filling in with pseudocode is ok! 
# NOTE: If using Netlogo, remove "python" from the markdown at the top of this section to get a generic code block
```

&nbsp; 

### 2) Agents
# *TODO*
 
 _Description of the "agents" in the system. Things to specify *if they apply*:_
 
* _List of agent-owned variables (e.g. age, heading, ID, etc.)_
* _List of agent-owned methods/procedures (e.g. move, consume, reproduce, die, etc.)_


```python
# Include first pass of the code you are thinking of using to construct your agents
# This may be a set of "turtle-own" variables and a command in the "setup" procedure, a list, an array, or Class constructor
# Feel free to include any agent methods/procedures you have so far. Filling in with pseudocode is ok! 
# NOTE: If using Netlogo, remove "python" from the markdown at the top of this section to get a generic code block
```

&nbsp; 

### 3) Action and Interaction
# *TODO*
 
**_Interaction Topology_**
# *TODO*

_Description of the topology of who interacts with whom in the system. Perfectly mixed? Spatial proximity? Along a network? CA neighborhood?_
 
**_Action Sequence_**
# *TODO*

_What does an agent, cell, etc. do on a given turn? Provide a step-by-step description of what happens on a given turn for each part of your model_

1. Step 1
2. Step 2
3. Etc...

&nbsp; 
### 4) Model Parameters and Initialization
# *TODO*

_Describe and list any global parameters you will be applying in your model._

_Describe how your model will be initialized_

_Provide a high level, step-by-step description of your schedule during each "tick" of the model_

&nbsp; 

### 5) Assessment and Outcome Measures
# *TODO*

_What quantitative metrics and/or qualitative features will you use to assess your model outcomes?_

&nbsp; 

### 6) Parameter Sweep
# *TODO*

_What parameters are you most interested in sweeping through? What value ranges do you expect to look at for your analysis?_
