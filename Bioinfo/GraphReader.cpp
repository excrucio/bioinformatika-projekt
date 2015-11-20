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
    edge12->orientationA = 1;
    edge12->orientationB = 1;
    data->putEdge(edge12);

    MapEdge* edge13 = new MapEdge;
    edge13->readA = 1;
    edge13->readB = 3;
    edge13->orientationA = 1;
    edge13->orientationB = 1;
    data->putEdge(edge13);

    MapEdge* edge14 = new MapEdge;
    edge14->readA = 1;
    edge14->readB = 4;
    edge14->orientationA = 1;
    edge14->orientationB = 0;
    data->putEdge(edge14);

    MapEdge* edge23 = new MapEdge;
    edge23->readA = 2;
    edge23->readB = 3;
    edge23->orientationA = 0;
    edge23->orientationB = 1;
    data->putEdge(edge23);

    MapEdge* edge24 = new MapEdge;
    edge24->readA = 2;
    edge24->readB = 4;
    edge24->orientationA = 0;
    edge24->orientationB = 0;
    data->putEdge(edge24);

    MapEdge* edge34 = new MapEdge;
    edge34->readA = 3;
    edge34->readB = 4;
    edge34->orientationA = 0;
    edge34->orientationB = 0;
    data->putEdge(edge34);

    MapEdge* edge35 = new MapEdge;
    edge35->readA = 3;
    edge35->readB = 5;
    edge35->orientationA = 0;
    edge35->orientationB = 1;
    data->putEdge(edge35);

    MapEdge* edge36 = new MapEdge;
    edge36->readA = 3;
    edge36->readB = 6;
    edge36->orientationA = 0;
    edge36->orientationB = 1;
    data->putEdge(edge36);

    MapEdge* edge37 = new MapEdge;
    edge37->readA = 3;
    edge37->readB = 7;
    edge37->orientationA = 0;
    edge37->orientationB = 1;
    data->putEdge(edge37);

    MapEdge* edge45 = new MapEdge;
    edge45->readA = 4;
    edge45->readB = 5;
    edge45->orientationA = 0;
    edge45->orientationB = 1;
    data->putEdge(edge45);

    MapEdge* edge46 = new MapEdge;
    edge46->readA = 4;
    edge46->readB = 6;
    edge46->orientationA = 1;
    edge46->orientationB = 1;
    data->putEdge(edge46);

    MapEdge* edge47 = new MapEdge;
    edge47->readA = 4;
    edge47->readB = 7;
    edge47->orientationA = 1;
    edge47->orientationB = 1;
    data->putEdge(edge47);

    MapEdge* edge56 = new MapEdge;
    edge56->readA = 4;
    edge56->readB = 7;
    edge56->orientationA = 0;
    edge56->orientationB = 1;
    data->putEdge(edge56);

    MapEdge* edge67 = new MapEdge;
    edge67->readA = 6;
    edge67->readB = 7;
    edge67->orientationA = 0;
    edge67->orientationB = 1;
    data->putEdge(edge67);

    MapEdge* edge68 = new MapEdge;
    edge68->readA = 6;
    edge68->readB = 8;
    edge68->orientationA = 0;
    edge68->orientationB = 1;
    data->putEdge(edge68);

    MapEdge* edge611 = new MapEdge;
    edge611->readA = 6;
    edge611->readB = 11;
    edge611->orientationA = 0;
    edge611->orientationB = 0;
    data->putEdge(edge611);

    MapEdge* edge78 = new MapEdge;
    edge78->readA = 7;
    edge78->readB = 8;
    edge78->orientationA = 0;
    edge78->orientationB = 1;
    data->putEdge(edge78);

    MapEdge* edge79 = new MapEdge;
    edge79->readA = 7;
    edge79->readB = 9;
    edge79->orientationA = 0;
    edge79->orientationB = 1;
    data->putEdge(edge79);

    MapEdge* edge710 = new MapEdge;
    edge710->readA = 7;
    edge710->readB = 10;
    edge710->orientationA = 0;
    edge710->orientationB = 0;
    data->putEdge(edge710);

    MapEdge* edge711 = new MapEdge;
    edge711->readA = 7;
    edge711->readB = 11;
    edge711->orientationA = 0;
    edge711->orientationB = 0;
    data->putEdge(edge711);

    MapEdge* edge89 = new MapEdge;
    edge89->readA = 8;
    edge89->readB = 9;
    edge89->orientationA = 0;
    edge89->orientationB = 1;
    data->putEdge(edge89);

    MapEdge* edge810 = new MapEdge;
    edge810->readA = 8;
    edge810->readB = 10;
    edge810->orientationA = 0;
    edge810->orientationB = 0;
    data->putEdge(edge810);

    MapEdge* edge811 = new MapEdge;
    edge811->readA = 8;
    edge811->readB = 11;
    edge811->orientationA = 0;
    edge811->orientationB = 0;
    data->putEdge(edge811);

    MapEdge* edge910 = new MapEdge;
    edge910->readA = 9;
    edge910->readB = 10;
    edge910->orientationA = 1;
    edge910->orientationB = 0;
    data->putEdge(edge910);

    MapEdge* edge911 = new MapEdge;
    edge911->readA = 9;
    edge911->readB = 11;
    edge911->orientationA = 0;
    edge911->orientationB = 0;
    data->putEdge(edge911);

    MapEdge* edge1011 = new MapEdge;
    edge1011->readA = 10;
    edge1011->readB = 11;
    edge1011->orientationA = 1;
    edge1011->orientationB = 0;
    data->putEdge(edge1011);

    MapEdge* edge1012 = new MapEdge;
    edge1012->readA = 10;
    edge1012->readB = 12;
    edge1012->orientationA = 1;
    edge1012->orientationB = 1;
    data->putEdge(edge1012);

    MapEdge* edge1013 = new MapEdge;
    edge1013->readA = 10;
    edge1013->readB = 13;
    edge1013->orientationA = 1;
    edge1013->orientationB = 1;
    data->putEdge(edge1013);

    MapEdge* edge1112 = new MapEdge;
    edge1112->readA = 11;
    edge1112->readB = 12;
    edge1112->orientationA = 1;
    edge1112->orientationB = 1;
    data->putEdge(edge1112);

    MapEdge* edge1113 = new MapEdge;
    edge1113->readA = 11;
    edge1113->readB = 13;
    edge1113->orientationA = 1;
    edge1113->orientationB = 1;
    data->putEdge(edge1113);

    MapEdge* edge1213 = new MapEdge;
    edge1213->readA = 12;
    edge1213->readB = 13;
    edge1213->orientationA = 0;
    edge1213->orientationB = 1;
    data->putEdge(edge1213);


}

