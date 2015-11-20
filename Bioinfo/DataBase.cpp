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

 MapEdge* DataBase::getEdge(int idA, int idB)
{
    string key1 = to_string(idA)+ ","+to_string(idB);
    string key2 = to_string(idB)+ ","+to_string(idA);

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

vector<int> DataBase::getNeighbors(int id)
{
    vector<int> returnEmpty;
    unordered_map<int,vector<int>>::const_iterator got = neighbors.find (id);
    if(got!=neighbors.end()) return neighbors[id];
    return returnEmpty;
}


void DataBase::makeNeighbors(int idA, int idB)
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


void DataBase::eraseNeighbor(int idA, int idB)
{
    unordered_map<int,vector<int>>::const_iterator got = neighbors.find (idA);
    if(got!=neighbors.end())
    {
        unsigned int position = 0;
        bool found = false;
        vector<int> n = neighbors[idA];

        for(unsigned int i = 0; i<n.size(); i++)
            if (n[i]== idB)
            {
                position = i;
                found = true;
                break;
            }

        if(found)
        {
            vector<int>::iterator it = neighbors[idA].begin() + position;
            neighbors[idA].erase(it);
        }
        else return;
    }
    else return;

    //nisam napravila provjeru za b. ali se ovaj dio koda
    //ne bi nikad smio odvrtiti ako ne postoji
    unsigned int position = 0;
    bool found = false;
    vector<int> n = neighbors[idB];

    for(unsigned int i = 0; i<n.size(); i++)
        if (n[i]== idA)
        {
            position = i;
            found = true;
            break;
        }

    if(found)
    {
        vector<int>::iterator it = neighbors[idB].begin() + position;
        neighbors[idB].erase(it);
    }
    else return;

}






