main.cpp 
- reads movielist input and creates graph
- reads input and calls methods in graphsearch.cpp to find pathway between actors

graphsearch.h
- declares functions and variables for ActorMovie pair class and Graph class

graphsearch.cpp
- adds actor to list of unique actors (addActor)
- adds connection between actors based on correlated movie in graph (addEdge)
- checks if list of actors has particular actor (hasActor)
- finds shortest path between actors using BFS (pathBFS)
- returns movie that two actors are in together (findMovie)
- returns the shortest path between two actors (findShortestPath)