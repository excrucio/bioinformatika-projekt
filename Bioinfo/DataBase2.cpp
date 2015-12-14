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

bool DataBase2::hasEdge(int idA, int idB)
{
    string key1 = to_string(idA)+ ","+to_string(idB);
    string key2 = to_string(idB)+ ","+to_string(idA);

    unordered_map<string,MapEdge*>::const_iterator got = graphEdges.find (key1);
    if(got!=graphEdges.end()) return true;

    got = graphEdges.find(key2);
    if(got!=graphEdges.end()) return true;

    return false;
}

void DataBase2::putEdge(MapEdge* edge)
{
    string key = to_string(edge->readA)+","+to_string(edge->readB);
    graphEdges[key] = edge;

}

vector<int> DataBase2::getNeighbors(int id)
{
    vector<int> returnEmpty;
    unordered_map<int,vector<int>>::const_iterator got = neighbors.find (id);
    if(got!=neighbors.end()) return neighbors[id];
    return returnEmpty;
}


void DataBase2::makeNeighbors(int idA, int idB)
{
    unordered_map<int,vector<int>>::const_iterator got = neighbors.find (idA);
    if(got!=neighbors.end())
     {
        vector<int> n = neighbors[idA];
        for(unsigned int i = 0; i<n.size(); i++)
            if (n[i]== idB) return;
        neighbors[idA].push_back(idB);

     }
    else
     {
        vector<int> newVectorA;
        newVectorA.push_back(idB);
        neighbors[idA]=newVectorA;

     }


     got = neighbors.find (idB);
     if(got!=neighbors.end())
      {
        neighbors[idB].push_back(idA);
      }
     else
      {
         vector<int> newVectorB;
         newVectorB.push_back(idA);
         neighbors[idB]=newVectorB;

      }



}


