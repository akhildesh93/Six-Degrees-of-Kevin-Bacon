#include <iostream>
#include "graphsearch.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <cstring>
#include <list>
#include <unordered_map>

using namespace std;


int main(int argc, char** argv)
{

    
    if (argc < 3) // must provide two arguments as input
    {
        throw std::invalid_argument("Usage: ./treewrapper <INPUT FILE> <OUTPUT FILE>"); // throw error
    }


    ifstream input; // stream for input file
    ofstream output; // stream for output file
    
    string movie, actor;
    char *com;
    Graph g;
    string command;

    input.open("cleaned_movielist.txt");

    int counter = 0;

    while(getline(input,command)){
        if (command.length() == 0) // command is empty
            continue;
        com = strdup(command.c_str()); // annoying, first copy string into a "C-style" string

        int whitespaces = 0;
        //cout<<"jao"<<endl;
        for(int i = 0;i<(int)command.length();i++){
            if(com[i]==' '){
                whitespaces++;
            }
        }

        movie = strtok(com, " \t"); // next token is value, as string (check out documentation on strtok, to understand the parsing)
        //cout<<movie<<endl;
        vector<string> actorsinmovie;

        //cout<<counter<<endl;
        counter++;
        //cout<<whitespaces<<endl;
        for(int i = 1;i<whitespaces;i++){
            actor = strtok(NULL, " \t"); // next token is value, as string (check out documentation on strtok, to understand the parsing)
            //cout<<actor<<endl;
            actorsinmovie.push_back(actor);
            //cout<<"added to list"<<endl;
            g.addActor(actor);
            //cout<<"added actor"<<endl;
            
        }
        //cout<<"baaaaa"<<endl;
        if(whitespaces > 1){
            for(int i = 0;i<whitespaces-1;i++){
                for(int j = i+1;j<whitespaces-1;j++){
                    //cout<<"adding edges between "<<actorsinmovie[i]<<", "<<actorsinmovie[j]<<endl;
                    g.addEdge(actorsinmovie[i], actorsinmovie[j], movie);
                    g.addEdge(actorsinmovie[j], actorsinmovie[i], movie);
                    //cout<<"added edges"<<endl;
                    
                }
            }
        } 
        
        

        
    }

    //cout<<"done making graph"<<endl;
    input.close();
    input.open(argv[1]);
    output.open(argv[2]);
    string actor1, actor2;

    while(getline(input, command)){
        if (command.length() == 0) // command is empty
            continue;

        com = strdup(command.c_str()); // annoying, first copy string into a "C-style" string
        actor1 = strtok(com, " \t"); // next token is value, as string (check out documentation on strtok, to understand the parsing)
        actor2 = strtok(NULL, " \t"); // next token is value, as string (check out documentation on strtok, to understand the parsing)
        //cout<<actor1<<" "<<actor2<<endl;
        output<<g.pathBFS(actor1, actor2)<<endl;
    }

    input.close();
    output.close();
      


}