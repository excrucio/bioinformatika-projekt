#ifndef LAYOUTWRITER_H
#define LAYOUTWRITER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;

class LayoutWriter
{
public:
    LayoutWriter();
    ~LayoutWriter();

    void writeGraph(string name);
    void writeGraph2(string name);
    bool contain(vector<int> *V, int item);
    void rec(vector<int> V, vector <int> *read, vector<int> *cycle, int parent, int *k, bool swich1);
    ofstream myfile;
    unordered_map<int,vector<int>> toWrite;
    void makeEdge(int idA, int idB);

};

#endif // LAYOUTWRITER_H
