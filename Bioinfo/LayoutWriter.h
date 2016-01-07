#ifndef LAYOUTWRITER_H
#define LAYOUTWRITER_H

//class that writes graph

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <GraphChunker.h>
using namespace std;

class LayoutWriter
{
public:
    LayoutWriter();
    ~LayoutWriter();

    void writeGraph(string name); //not used
    void writeGraph2(string name); //not used
    void writeGraph(vector<ChunkInfo*> chunks, string graph1, string constituensts, int num); //writes graph
    void writeGraph(vector<ChunkInfo *> chunks,string graph1, string constituensts, vector<string> chunkies);
    bool contain(vector<int> *V, int item);//not used
    void rec(vector<int> V, vector <int> *read, vector<int> *cycle, int parent, int *k, bool swich1);//not used
    ofstream myfile;
    unordered_map<int,vector<int>> toWrite;//not used
    void makeEdge(int idA, int idB);//not used

};

#endif // LAYOUTWRITER_H
