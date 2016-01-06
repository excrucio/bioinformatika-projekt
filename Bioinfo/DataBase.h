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
    void putEdge(MapEdge*); //puts all edge info in database (graphEdges)

    vector<int> getNeighbors(int id);//gets all the neighbors of vertex with id (neighbors)

    void makeNeighbors(int idA, int idB);//makes an edge between vertexes A and B. (neighbors) It doesn't
                                        //matter the order of vertexes A & B.
                                        //void makeNeighbors(A,B) == void makeNeighbors(B,A), so call only once

    void eraseNeighbor(int idA, int idB);//removes the edge between vertexes A & B (neighbors)
                                        //eraseNeighbor(A, B)  == eraseNeighbor(B, A), so call this function only once.

    void addContained(int containedFragment, int containerFragment); //adds container fregment in
                                                                     //map containedFragments under key
                                                                     //containedFragment

    bool isContained(int fragmentId);
    bool hasEdge(int idA,int idB);


    unordered_map <string,MapEdge*> graphEdges;
    unordered_map<int,vector<int>> neighbors;
    unordered_map<int,string> v_strings;
    unordered_map<int,vector<int>> containedFragments;



private:
    DataBase();

    static bool instanceFlag;
    static DataBase *single;
};

#endif // DATABASE_H
