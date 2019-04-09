# Char Guide

* G
    * G x y understanding
    * Global Announcmenet,  x position of agent being affected, y position of agent being affected, New understanding
* U
    * U x y understanding
    * Communication, x position of agent being affected, y position of agent being affected, New understanding
* B
    * B x y
    * Bug Generation, x position of agent generating bug, y position of agent generating bug
* S
    * D x y
    * Bug Squash, x position of agent squashing bug, y position of agent squashing bug
* M
    * M x y x y
    * Moving agents, x position of 1st agent to move, y position of 1st agent to move, x position of 2nd agent to move, y position of 2nd agent to move
* P
    * Starting Planning Phase
* C
    * Starting Coding Phase
* D
    * Starting Debugging Phase
* I
    * x y agents_num grid
    * X dimension of grid, y dimension of grid, number of agents, grid of agents with T meaning there is an agent and F meaning there isn't an agent, followed by their skill levels
    * Example for grid of 3x3 and 7 Agents
    * 3 3 7
    * T 1.2 F 0 T 42.1
    * F 0 T 3.2 T 5.2
    * T 1.2 T 100.0 T 6.2
* T
    * T num
    * Tick and the current tick count
* X
    * X x y progress_increase total progress
    * Progress made, x position of agent affecting progress, y position of agent affecting progress, change in progress that the agent made, total progress as of now
