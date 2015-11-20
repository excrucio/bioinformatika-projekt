#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <unordered_map>
#include <vector>


#include "MapEdge.h"

using namespace std;


//this is singleton class where all our data structures relevant for our program will be stored

class DataBase
{
public:
    ~DataBase()
    {
        instanceFlag = false;
        for(auto& gE : graphEdges)
        {
          delete gE.second;
        }
    }

    static DataBase* getInstance();

    MapEdge* getEdge(int idA,int idB);
    void putEdge(MapEdge*);
    vector<int> getNeighbors(int id);
    void makeNeighbors(int idA, int idB);
    void eraseNeighbor(int idA, int idB);
    void addContained(int containedFragment, int containerFragment);


    unordered_map <string,MapEdge*> graphEdges;
    unordered_map<int,vector<int>> neighbors;
    unordered_map<int,vector<int>> containedFragments;


private:
    DataBase();

    static bool instanceFlag;
    static DataBase *single;
};

#endif // DATABASE_H
