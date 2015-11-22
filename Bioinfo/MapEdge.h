#ifndef MAPEDGE_H
#define MAPEDGE_H


class MapEdge
{
public:
    MapEdge();
    ~MapEdge();

    int readA; //id of first fragment
    int readB; //id of second fragment

    // int ahang;
    // int bhang;

    int oLenght; //lenght of overlap
    int edgeLenght; //lenght of edge
    int orientationA; //orientation of readA
    int orientationB; //orientation of readB


};

#endif // MAPEDGE_H
