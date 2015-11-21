#include <algorithm>

#include "TransitiveEdgeRemover.h"
#include "DataBase.h"
#include "GeneralFunctions.h"

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

void TransitiveEdgeRemover::initiateStructures()
{
    DataBase *db = DataBase::getInstance();
    for(auto& gE : db->neighbors)
    {
        vertexReduceInfo info;
        info.mark = VACANT;
        vertexInfo[gE.first] = info;
        cout<<gE.first<<std::endl;

    }

}

void TransitiveEdgeRemover::setInplay(std::vector<int> inplay)
{
    for (unsigned int i = 0; i<inplay.size();i++)
    {
        vertexInfo[inplay[i]].mark = INPLAY;
    }
}

void TransitiveEdgeRemover::setReduce(std::vector<int> neighbors, int vert)
{
    for (unsigned int i = 0; i<neighbors.size();i++)
    {
        if(vertexInfo[neighbors[i]].mark ==ELIMINATED) vertexInfo[neighbors[i]].reduce.push_back(vert);
        vertexInfo[neighbors[i]].mark = VACANT;
    }
}

void TransitiveEdgeRemover::removeTransitiveEdges()
{
    sortNeighbors();
    initiateStructures();

    DataBase *db = DataBase::getInstance();

    for(auto& gE : db->neighbors)
    {
        if(gE.second.size()==0)continue;
        setInplay(gE.second);
        //int longest = db->getEdge(gE.first,gE.second.back())->edgeLenght + FUZZ;

        for (unsigned int i = 0; i<gE.second.size();i++)
        {
            if (vertexInfo[gE.second[i]].mark == INPLAY)
            {
                for (unsigned int j = 0; j<db->neighbors[gE.second[i]].size();j++)
                {
                    if(vertexInfo[db->neighbors[gE.second[i]][j]].mark==INPLAY)
                        if((db->getEdge(gE.second[i],db->neighbors[gE.second[i]][j])->edgeLenght +
                            db->getEdge(gE.first,gE.second[i])->edgeLenght)<=
                            db->getEdge(gE.first,db->neighbors[gE.second[i]][j])->edgeLenght + FUZZ)
                            vertexInfo[db->neighbors[gE.second[i]][j]].mark = ELIMINATED;

                }
            }
        }

        setReduce(gE.second, gE.first);

    }

    printReduce();

}

bool TransitiveEdgeRemover:: myDataSort(int d1, int  d2)
{
    DataBase *db = DataBase::getInstance();

     return db->getEdge(presentVertex,d1)->edgeLenght < db->getEdge(presentVertex,d2)->edgeLenght;

}

void TransitiveEdgeRemover::printReduce()
{
    cout<<"hello world"<<std::endl;
    GeneralFunctions *f = new GeneralFunctions;
    for(auto& gE : vertexInfo)
    {
        f->printVector(gE.second.reduce, gE.first);
    }
    delete f;
    f = NULL;
}





