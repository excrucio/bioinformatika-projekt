#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <unordered_map>
#include <vector>

//this is a singleton class used as a "data base" where all the structures & functions
// for access & work with these structures necessary for algorithm are contained.

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


    unordered_map <string,MapEdge*> graphEdges; //contains all ooriginal verlaps
    unordered_map<int,vector<int>> neighbors; //containes all vertices + their neighbors. This is changed how each component of program removes stuff
    unordered_map<int,string> v_strings; //here are dumped all strings of vertices that go in final stage (after contained edge removal & transitive edge removal
    unordered_map<int,vector<int>> containedFragments; //list of all contained fragments



private:
    DataBase();

    static bool instanceFlag;
    static DataBase *single;
};

#endif // DATABASE_H
