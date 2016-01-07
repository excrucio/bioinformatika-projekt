#ifndef GRAPHREADER_H
#define GRAPHREADER_H

#include <iostream>

//class that reads input

class MapEdge;

using namespace std;

class GraphReader
{
public:
    GraphReader();
    ~GraphReader();

    void read(string, string);
    void testGraphReader(); //a function that loads a test graph (for transitive edge remover) not used & don't use it, final version uses different structures
                            //& you'll crash program if you use this function designed for very early stage of transitive edge remover
    void removeContainedEdges(string); //removes contained edges.
    void checkOrientation(int orientationA, int orientationB, MapEdge* edge);//checks orientation of strings.
    void removeZeroes();//removes verteces with 0 neighbors
    bool calculateEdge //calculates all data of an edge that are necessary for all other components of program
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
