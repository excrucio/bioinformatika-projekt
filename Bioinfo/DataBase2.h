#ifndef DATABASE2_H
#define DATABASE2_H


//this class is not used. Just here for internal testing of main program.

#include <iostream>
#include <unordered_map>
#include <vector>


#include "MapEdge.h"

using namespace std;


class DataBase2
{
public:
    ~DataBase2()
    {
        instanceFlag = false;
        for(auto& gE : graphEdges)
        {
          delete gE.second;
        }
    }

    static DataBase2* getInstance();

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
    unordered_map<int,vector<int>> containedFragments;


private:
    DataBase2();

    static bool instanceFlag;
    static DataBase2 *single;
};

#endif // DATABASE2_H
