#include "DataBase2.h"

DataBase2::DataBase2(){}

bool DataBase2::instanceFlag = false;
DataBase2* DataBase2::single = NULL;

DataBase2* DataBase2::getInstance()
{
    if(!instanceFlag)
    {
      single = new DataBase2();
      instanceFlag = true;
      return single;
     }
     else
     {
       return single;
     }
}

 MapEdge* DataBase2::getEdge(int idA, int idB)
{
    string key1 = to_string(idA)+ ","+to_string(idB);
    string key2 = to_string(idB)+ ","+to_string(idA);

    unordered_map<string,MapEdge*>::const_iterator got = graphEdges.find (key1);
    if(got!=graphEdges.end()) return graphEdges[key1];

    got = graphEdges.find(key2);
    if(got!=graphEdges.end()) return graphEdges[key2];

    return NULL;


}
