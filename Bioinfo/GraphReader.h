#ifndef GRAPHREADER_H
#define GRAPHREADER_H

#include <iostream>

class MapEdge;

using namespace std;

class GraphReader
{
public:
    GraphReader();
    ~GraphReader();

    void read(string);
    void testGraphReader();
    void removeContainedEdges();
    void checkOrientation(int orientationA, int orientationB, MapEdge* edge);
    void removeZeroes();
    bool calculateEdge
    ( int orientationA,
      int AStart,
      int  AEnd,
      int ALenghth,
      int orientationB,
      int BStart,
      int BEnd,
      int BLenghth,
      int idA,
      int idB,
      MapEdge* edge
    );


};

#endif // GRAPHREADER_H
