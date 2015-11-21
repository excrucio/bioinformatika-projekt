#include <algorithm>

#include "TransitiveEdgeRemover.h"
#include "DataBase.h"

#define VACANT 0
#define INPLAY 1
#define ELIMINATED 2

TransitiveEdgeRemover::TransitiveEdgeRemover(){}
TransitiveEdgeRemover::~TransitiveEdgeRemover(){}

int TransitiveEdgeRemover::presentVertex = 0;

void TransitiveEdgeRemover::sortNeighbors()
{
    DataBase *db = DataBase::getInstance();

    for(auto& gE : db->neighbors)
    {
        presentVertex = gE.first;
        sort( gE.second.begin(),gE.second.end(),TransitiveEdgeRemover::myDataSort);

    }
}

void TransitiveEdgeRemover::removeTransitiveEdges()
{
    sortNeighbors();
    DataBase *db = DataBase::getInstance();



}

bool TransitiveEdgeRemover:: myDataSort(int d1, int  d2)
{
    DataBase *db = DataBase::getInstance();

     return db->getEdge(presentVertex,d1)->edgeLenght < db->getEdge(presentVertex,d2)->edgeLenght;

}
