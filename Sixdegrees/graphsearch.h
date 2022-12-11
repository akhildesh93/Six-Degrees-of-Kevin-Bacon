// Filename: bst.h
// 
// Header file for the class BST that represents a binary search tree
// 
// C. Seshadhri, Jan 2020

#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <tuple>

using namespace std;

class ActorMovie
{
    public:
        string actor;
        string movie;
};



class Graph
{
        
        private:
                unordered_map<string, vector<ActorMovie>> map;
                set<string> actors;
        public:
                void addEdge(string, string, string);
                string pathBFS(string, string);
                bool hasActor(string);
                void addActor(string);
                string findMovie(string, string);
                string findShortestPath(unordered_map<string, string>, unordered_map<string, int>, string, string);
   
   

};

#endif
