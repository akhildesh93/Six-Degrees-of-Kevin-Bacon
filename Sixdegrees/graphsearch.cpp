#include "graphsearch.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <unordered_map>
#include <tuple>
#include <climits>


using namespace std;

void Graph:: addActor(string actor)
{
    this->actors.insert(actor);
}


void Graph:: addEdge(string actor1, string actor2, string movie)
{
    ActorMovie pair1;
    pair1.actor = actor2;
    pair1.movie = movie;
    (this->map)[actor1].push_back(pair1);
}

bool Graph:: hasActor(string thisactor)
{
    for(set<string>::iterator actor = this->actors.begin();actor!=this->actors.end();actor++){
        //cout<<*actor<<endl;
        if(*actor == thisactor){
            //cout<<thisactor<<endl;
            return true;
        }
    }
    return false;
}


string Graph:: pathBFS(string actor2, string actor1)
{
    //cout<<this->actors.size()<<endl;
    //cout<<"actor 1: "<<actor1<<", "<<"actor 2: "<<actor2<<endl;
    //cout<<"starting method"<<endl;
    if(actor1 == actor2){
        //cout<<"actors are same"<<endl;
        return actor1;
    }
    if(!hasActor(actor1) || !hasActor(actor2)){
        //cout<<"doesnt have actor"<<endl;
        return ("Not present");
    }

    unordered_map<string, bool> actorsseen;
    unordered_map<string, string> predecessors;
    unordered_map<string, int> distances;

    

    list<string> q;
    q.push_back(actor1);

    //cout<<"created maps"<<endl;

    set<string>::iterator actor = this->actors.begin();
    while(actor != this->actors.end()){
        distances[*actor] = INT_MAX;
        actorsseen[*actor] = false;
        predecessors[*actor] = "---";
        actor++;
    }
    //cout<<"set up maps"<<endl;

    actorsseen[actor1] = true;
    distances[actor1] = 0;

    while(q.size()!=0)
    {
        string actorx = q.front();
        q.pop_front();
        //cout<<"poped"<<endl;
        for(int i = 0;i<(int)map[actorx].size();i++){
            string actoridx = map[actorx][i].actor;
            if(!actorsseen[actoridx]){
                distances[actoridx] = 1+ distances[actorx];
                actorsseen[actoridx] = true;
                predecessors[actoridx] = actorx;
                q.push_back(actoridx);
                if(actoridx == actor2){
                    //cout<<"found path"<<endl;
                    return(findShortestPath(predecessors, distances, actor1, actor2));
                }
            }
        }
    }
    return("Not present");

    
}
\
string Graph::findMovie(string actor1, string actor2)
{
    for(int i = 0;i<(int)this->map[actor1].size();i++){
        if(this->map[actor1][i].actor == actor2){
            return this->map[actor1][i].movie;
        }
    }
    return "";
}

string Graph::findShortestPath(unordered_map<string, string> predecessors, unordered_map<string, int> distances, string actor1, string actor2)
{
    vector<string> shortestpath;
    shortestpath.push_back(actor2);
    string end = actor2;
    while(predecessors[end] != "---"){
        shortestpath.push_back(predecessors[end]);
        end = predecessors[end];
    }

    string res = "";
    
    for(int i = 0;i<(int)shortestpath.size()-1;i++){
        //cout<<shortestpath[i]<<" ";
        string movie = findMovie(shortestpath[i], shortestpath[i+1]);
        //cout<<movie<<endl;
        res+=shortestpath[i] + " -(" + movie + ")- ";
    }
    return res + shortestpath[shortestpath.size()-1];
}
