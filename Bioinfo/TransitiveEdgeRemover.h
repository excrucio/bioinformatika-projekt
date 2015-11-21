#ifndef TRANSITIVEEDGEREMOVER_H
#define TRANSITIVEEDGEREMOVER_H

#include <iostream>
#include <vector>

typedef struct
{
    int idV;
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

    int FUZZ = 10;
    static int presentVertex;
    std::vector<vertexReduceInfo> vertexInfo;

};

#endif // TRANSITIVEEDGEREMOVER_H
