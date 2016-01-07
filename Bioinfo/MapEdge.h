#ifndef MAPEDGE_H
#define MAPEDGE_H

#include <iostream>

class MapEdge
{
public:
    MapEdge();
    ~MapEdge();

    int readA; //id of first fragment
    int readB; //id of second fragment
    int ahang;
    int bhang;
    int aStart;
    int aEnd;
    int bStart;
    int bEnd;
    int APlus;
    int AMinus;
    int BPlus;
    int bMinus;
    int aLenghth;
    int bLenght;
    int oLenght; //lenght of overlap
    int edgeLenght; //lenght of edge
    int orientationA; //orientation of readA
    int orientationB; //orientation of readB
    int oB;
    int first;
    std::string edgeInfo;


};

#endif // MAPEDGE_H
