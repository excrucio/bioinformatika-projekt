#ifndef TRANSITIVEEDGEREMOVER_H
#define TRANSITIVEEDGEREMOVER_H

#include <iostream>
#include <vector>
#include <unordered_map>

//removes transitive edges

typedef struct
{
    int mark;
    std::vector<int> reduce;

}vertexReduceInfo; //just a structure used

class TransitiveEdgeRemover
{
public:
    TransitiveEdgeRemover();
    ~TransitiveEdgeRemover();

    void removeTransitiveEdges(); //removes transitive edges. Algorhytm described in Eugene W. Myers' "The fragment assembly string graph"
    static bool myDataSort(int d1, int  d2);
    void sortNeighbors();
    void initiateStructures();

    static int FUZZ; //= 30; //fuzz factor for removing edge
    static float err; //= 0.3; //err factor for removing edge
    static int presentVertex;
    std::unordered_map<int,vertexReduceInfo> vertexInfo;

private:
    void setInplay(std::vector<int>); //just a set of funtions that do work on removing transitive edges
    void setReduce(std::vector<int>neighbors, int vert);
    void printReduce();
    void removeTransitives();
    bool arrowheadOrientationCheccker(int a, int b, int c);

};

#endif // TRANSITIVEEDGEREMOVER_H
