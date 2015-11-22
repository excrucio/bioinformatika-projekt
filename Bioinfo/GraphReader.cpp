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
    // Josip? Tu treba dodati ulaz i odmah tu isto ukloniti viškove bridova?
    // jesam dobro shvatio?

}


void GraphReader::testGraphReader()
{
    //this is a dummy function that creates our initial test graph
    //I'll add code here, this funtion will be removed
    //in the final incarnation of our program :)
    //samo za test


    DataBase* data = DataBase::getInstance(); //access to database

    //mapping graph
    MapEdge* edge12 = new MapEdge; //making new edge info
    edge12->readA = 1;
    edge12->readB = 2;
    edge12->orientationA = 1;
    edge12->orientationB = 1;
    edge12->ahang = 900;
    edge12->bhang = 900;
    edge12->oLenght=100;
    edge12->edgeLenght = 1800;
    data->putEdge(edge12); //putting edge info to database
    data->makeNeighbors(1,2);//creating adge between vertex 1 & vertex 2

    MapEdge* edge13 = new MapEdge;
    edge13->readA = 1;
    edge13->readB = 3;
    edge13->orientationA = 1;
    edge13->orientationB = 1;
    edge13->ahang = 900;
    edge13->bhang = 900;
    edge13->oLenght=100;
    edge13->edgeLenght = 1900;
    data->putEdge(edge13);
    data->makeNeighbors(1,3);

    MapEdge* edge14 = new MapEdge;
    edge14->readA = 1;
    edge14->readB = 4;
    edge14->orientationA = 1;
    edge14->orientationB = 0;
    edge14->ahang = 900;
    edge14->bhang = 900;
    edge14->oLenght=100;
    edge14->edgeLenght = 2000;
    data->putEdge(edge14);
    data->makeNeighbors(1,4);

    MapEdge* edge23 = new MapEdge;
    edge23->readA = 2;
    edge23->readB = 3;
    edge23->orientationA = 0;
    edge23->orientationB = 1;
    edge23->ahang = 900;
    edge23->bhang = 900;
    edge23->oLenght=100;
    edge23->edgeLenght = 100;
    data->putEdge(edge23);
    data->makeNeighbors(2,3);

    MapEdge* edge24 = new MapEdge;
    edge24->readA = 2;
    edge24->readB = 4;
    edge24->orientationA = 0;
    edge24->orientationB = 0;
    edge24->ahang = 900;
    edge24->bhang = 900;
    edge24->oLenght=100;
    edge24->edgeLenght = 200;
    data->putEdge(edge24);
    data->makeNeighbors(2,4);

    MapEdge* edge34 = new MapEdge;
    edge34->readA = 3;
    edge34->readB = 4;
    edge34->orientationA = 0;
    edge34->orientationB = 0;
    edge34->ahang = 900;
    edge34->bhang = 900;
    edge34->oLenght=100;
    edge34->edgeLenght = 100;
    data->putEdge(edge34);
    data->makeNeighbors(3,4);

    MapEdge* edge35 = new MapEdge;
    edge35->readA = 3;
    edge35->readB = 5;
    edge35->orientationA = 0;
    edge35->orientationB = 1;
    edge35->ahang = 900;
    edge35->bhang = 900;
    edge35->oLenght=100;
    edge35->edgeLenght = 100;
    data->putEdge(edge35);
    //data->makeNeighbors(3,5);

    MapEdge* edge36 = new MapEdge;
    edge36->readA = 3;
    edge36->readB = 6;
    edge36->orientationA = 0;
    edge36->orientationB = 1;
    edge36->ahang = 900;
    edge36->bhang = 900;
    edge36->oLenght=100;
    edge36->edgeLenght = 200;
    data->putEdge(edge36);
    data->makeNeighbors(3,6);

    MapEdge* edge37 = new MapEdge;
    edge37->readA = 3;
    edge37->readB = 7;
    edge37->orientationA = 0;
    edge37->orientationB = 1;
    edge37->ahang = 900;
    edge37->bhang = 900;
    edge37->oLenght=100;
    edge37->edgeLenght = 300;
    data->putEdge(edge37);
    data->makeNeighbors(3,7);

    MapEdge* edge45 = new MapEdge;
    edge45->readA = 4;
    edge45->readB = 5;
    edge45->orientationA = 0;
    edge45->orientationB = 1;
    edge45->ahang = 900;
    edge45->bhang = 900;
    edge45->oLenght=100;
    edge45->edgeLenght = 1800;
    data->putEdge(edge45);
    //data->makeNeighbors(4,5);

    MapEdge* edge46 = new MapEdge;
    edge46->readA = 4;
    edge46->readB = 6;
    edge46->orientationA = 1;
    edge46->orientationB = 1;
    edge46->ahang = 900;
    edge46->bhang = 900;
    edge46->oLenght=100;
    edge46->edgeLenght = 100;
    data->putEdge(edge46);
    data->makeNeighbors(4,6);

    MapEdge* edge47 = new MapEdge;
    edge47->readA = 4;
    edge47->readB = 7;
    edge47->orientationA = 1;
    edge47->orientationB = 1;
    edge47->ahang = 900;
    edge47->bhang = 900;
    edge47->oLenght=100;
    edge47->edgeLenght = 200;
    data->putEdge(edge47);
    data->makeNeighbors(4,7);

    MapEdge* edge56 = new MapEdge;
    edge56->readA = 4;
    edge56->readB = 7;
    edge56->orientationA = 0;
    edge56->orientationB = 1;
    edge56->ahang = 900;
    edge56->bhang = 900;
    edge56->oLenght=100;
    edge56->edgeLenght = 1600;
    data->putEdge(edge56);
    //data->makeNeighbors(5,6);

    MapEdge* edge67 = new MapEdge;
    edge67->readA = 6;
    edge67->readB = 7;
    edge67->orientationA = 0;
    edge67->orientationB = 1;
    edge67->ahang = 900;
    edge67->bhang = 900;
    edge67->oLenght=100;
    edge67->edgeLenght = 100;
    data->putEdge(edge67);
    data->makeNeighbors(6,7);

    MapEdge* edge68 = new MapEdge;
    edge68->readA = 6;
    edge68->readB = 8;
    edge68->orientationA = 0;
    edge68->orientationB = 1;
    edge68->ahang = 900;
    edge68->bhang = 900;
    edge68->oLenght=100;
    edge68->edgeLenght = 200;
    data->putEdge(edge68);
    data->makeNeighbors(6,8);

    MapEdge* edge611 = new MapEdge;
    edge611->readA = 6;
    edge611->readB = 11;
    edge611->orientationA = 0;
    edge611->orientationB = 0;
    edge611->ahang = 900;
    edge611->bhang = 900;
    edge611->oLenght=100;
    edge611->edgeLenght = 100;
    data->putEdge(edge611);
    data->makeNeighbors(6,11);

    MapEdge* edge78 = new MapEdge;
    edge78->readA = 7;
    edge78->readB = 8;
    edge78->orientationA = 0;
    edge78->orientationB = 1;
    edge78->ahang = 900;
    edge78->bhang = 900;
    edge78->oLenght=100;
    edge78->edgeLenght = 100;
    data->putEdge(edge78);
    data->makeNeighbors(7,8);

    MapEdge* edge79 = new MapEdge;
    edge79->readA = 7;
    edge79->readB = 9;
    edge79->orientationA = 0;
    edge79->orientationB = 1;
    edge79->ahang = 900;
    edge79->bhang = 900;
    edge79->oLenght=100;
    edge79->edgeLenght = 200;
    data->putEdge(edge79);
    //data->makeNeighbors(7,9);

    MapEdge* edge710 = new MapEdge;
    edge710->readA = 7;
    edge710->readB = 10;
    edge710->orientationA = 0;
    edge710->orientationB = 0;
    edge710->ahang = 900;
    edge710->bhang = 900;
    edge710->oLenght=100;
    edge710->edgeLenght = 200;
    data->putEdge(edge710);
    data->makeNeighbors(7,10);

    MapEdge* edge711 = new MapEdge;
    edge711->readA = 7;
    edge711->readB = 11;
    edge711->orientationA = 0;
    edge711->orientationB = 0;
    edge711->ahang = 900;
    edge711->bhang = 900;
    edge711->oLenght=100;
    edge711->edgeLenght = 300;
    data->putEdge(edge711);
    data->makeNeighbors(7,11);

    MapEdge* edge89 = new MapEdge;
    edge89->readA = 8;
    edge89->readB = 9;
    edge89->orientationA = 0;
    edge89->orientationB = 1;
    edge89->ahang = 900;
    edge89->bhang = 900;
    edge89->oLenght=100;
    edge89->edgeLenght = 100;
    data->putEdge(edge89);
    //data->makeNeighbors(8,9);

    MapEdge* edge810 = new MapEdge;
    edge810->readA = 8;
    edge810->readB = 10;
    edge810->orientationA = 0;
    edge810->orientationB = 0;
    edge810->ahang = 900;
    edge810->bhang = 900;
    edge810->oLenght=100;
    edge810->edgeLenght = 100;
    data->putEdge(edge810);
    data->makeNeighbors(8,10);

    MapEdge* edge811 = new MapEdge;
    edge811->readA = 8;
    edge811->readB = 11;
    edge811->orientationA = 0;
    edge811->orientationB = 0;
    edge811->ahang = 900;
    edge811->bhang = 900;
    edge811->oLenght=100;
    edge811->edgeLenght = 200;
    data->putEdge(edge811);
    data->makeNeighbors(8,11);

    MapEdge* edge910 = new MapEdge;
    edge910->readA = 9;
    edge910->readB = 10;
    edge910->orientationA = 1;
    edge910->orientationB = 0;
    edge910->ahang = 900;
    edge910->bhang = 900;
    edge910->oLenght=100;
    edge910->edgeLenght = 100;
    data->putEdge(edge910);
    //data->makeNeighbors(9,10);

    MapEdge* edge911 = new MapEdge;
    edge911->readA = 9;
    edge911->readB = 11;
    edge911->orientationA = 0;
    edge911->orientationB = 0;
    edge911->ahang = 900;
    edge911->bhang = 900;
    edge911->oLenght=100;
    edge911->edgeLenght = 100;
    data->putEdge(edge911);
    //data->makeNeighbors(9,11);

    MapEdge* edge1011 = new MapEdge;
    edge1011->readA = 10;
    edge1011->readB = 11;
    edge1011->orientationA = 1;
    edge1011->orientationB = 0;
    edge1011->ahang = 900;
    edge1011->bhang = 900;
    edge1011->oLenght=100;
    edge1011->edgeLenght = 100;
    data->putEdge(edge1011);
    data->makeNeighbors(10,11);

    MapEdge* edge1012 = new MapEdge;
    edge1012->readA = 10;
    edge1012->readB = 12;
    edge1012->orientationA = 1;
    edge1012->orientationB = 1;
    edge1012->ahang = 900;
    edge1012->bhang = 900;
    edge1012->oLenght=100;
    edge1012->edgeLenght = 200;
    data->putEdge(edge1012);
    data->makeNeighbors(10,12);

    MapEdge* edge1013 = new MapEdge;
    edge1013->readA = 10;
    edge1013->readB = 13;
    edge1013->orientationA = 1;
    edge1013->orientationB = 1;
    edge1013->ahang = 900;
    edge1013->bhang = 900;
    edge1013->oLenght=100;
    edge1013->edgeLenght = 300;
    data->putEdge(edge1013);
    data->makeNeighbors(10,13);

    MapEdge* edge1112 = new MapEdge;
    edge1112->readA = 11;
    edge1112->readB = 12;
    edge1112->orientationA = 1;
    edge1112->orientationB = 1;
    edge1112->ahang = 900;
    edge1112->bhang = 900;
    edge1112->oLenght=100;
    edge1112->edgeLenght = 100;
    data->putEdge(edge1112);
    data->makeNeighbors(11,12);

    MapEdge* edge1113 = new MapEdge;
    edge1113->readA = 11;
    edge1113->readB = 13;
    edge1113->orientationA = 1;
    edge1113->orientationB = 1;
    edge1113->ahang = 900;
    edge1113->bhang = 900;
    edge1113->oLenght=100;
    edge1113->edgeLenght = 200;
    data->putEdge(edge1113);
    data->makeNeighbors(11,13);

    MapEdge* edge1213 = new MapEdge;
    edge1213->readA = 12;
    edge1213->readB = 13;
    edge1213->orientationA = 0;
    edge1213->orientationB = 1;
    edge1213->ahang = 900;
    edge1213->bhang = 900;
    edge1213->oLenght=100;
    edge1213->edgeLenght = 100;
    data->putEdge(edge1213);
    data->makeNeighbors(12,13);

    data->addContained(5,4); //adding contained edges to database structure
    data->addContained(9,8);
    data->addContained(9,10);


}

