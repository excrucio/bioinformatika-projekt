#include <iostream>
#include "GraphReader.h"
#include "DataBase.h"
#include "MapEdge.h"


GraphReader::GraphReader(){}
GraphReader::~GraphReader(){}

void GraphReader::read(string overlapsPath, string readsPath)
{
    //this is where the graph data is loaded, all structures in data base are initialised
    //and all the fragments contained in other fragments + all the appropriate edges are removed


}


void GraphReader::testGraphReader()
{
    //this is a dummy function that creates our initial test graph
    //I'll add code here, this funtion will be removed
    //in the final incarnation of our program :)

    DataBase* data = DataBase::getInstance();
    MapEdge* edge12 = new MapEdge;
    edge12->readA = 1;
    edge12->readB = 2;

}

