#ifndef TRANSITIVEEDGEREMOVER_H
#define TRANSITIVEEDGEREMOVER_H

#include <iostream>
#include <vector>
#include <unordered_map>

typedef struct
{
    int mark;
    std::vector<int> reduce;

}vertexReduceInfo;

class TransitiveEdgeRemover
{
public:
    TransitiveEdgeRemover();
    ~TransitiveEdgeRemover();

    void removeTransitiveEdges();
    static bool myDataSort(int d1, int  d2);
    void sortNeighbors();
    void initiateStructures();

    static int FUZZ; //= 30;
    static float err; //= 0.3;
    static int presentVertex;
    std::unordered_map<int,vertexReduceInfo> vertexInfo;

private:
    void setInplay(std::vector<int>);
    void setReduce(std::vector<int>neighbors, int vert);
    void printReduce();
    void removeTransitives();
    bool arrowheadOrientationCheccker(int a, int b, int c);

};

#endif // TRANSITIVEEDGEREMOVER_H
