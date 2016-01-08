#ifndef GraphReader2_H
#define GraphReader2_H
//this class is not used. Just here for internal testing of main program.

#include <iostream>

class MapEdge;

using namespace std;

class GraphReader2
{
public:
    GraphReader2();
    ~GraphReader2();

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

#endif // GraphReader2_H
