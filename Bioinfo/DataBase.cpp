#include "DataBase.h"


DataBase::DataBase(){}

bool DataBase::instanceFlag = false;
DataBase* DataBase::single = NULL;

DataBase* DataBase::getInstance()
{
    if(!instanceFlag)
    {
      single = new DataBase();
      instanceFlag = true;
      return single;
     }
     else
     {
       return single;
     }
}

 MapEdge* DataBase::getEdge(int fragmentA, int fragmentB)
{
    string key1 = to_string(fragmentA)+ ","+to_string(fragmentB);
    string key2 = to_string(fragmentB)+ ","+to_string(fragmentA);

    unordered_map<string,MapEdge*>::const_iterator got = graphEdges.find (key1);
    if(got!=graphEdges.end()) return graphEdges[key1];

    got = graphEdges.find(key2);
    if(got!=graphEdges.end()) return graphEdges[key2];

    return NULL;


}

void DataBase::putEdge(MapEdge* edge)
{
    string key = to_string(edge->readA)+","+to_string(edge->readB);
    graphEdges[key] = edge;

}
