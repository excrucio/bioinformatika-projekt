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
int TransitiveEdgeRemover::FUZZ = 30;
float TransitiveEdgeRemover::err = 0.2;

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
                        if(db->hasEdge(gE.first,db->neighbors[gE.second[i]][j]))
                        {if(((db->getEdge(gE.second[i],db->neighbors[gE.second[i]][j])->edgeLenght +
                            db->getEdge(gE.first,gE.second[i])->edgeLenght)<=
                            (db->getEdge(gE.first,db->neighbors[gE.second[i]][j])->edgeLenght + db->getEdge(gE.first,db->neighbors[gE.second[i]][j])->oLenght*err+ 2*FUZZ))
                             && arrowheadOrientationCheccker(gE.first,gE.second[i],db->neighbors[gE.second[i]][j]))
                            {vertexInfo[db->neighbors[gE.second[i]][j]].mark = ELIMINATED;}}


                }
            }
        }

        setReduce(gE.second, gE.first);

    }

    removeTransitives();

}


bool TransitiveEdgeRemover::arrowheadOrientationCheccker(int a, int b, int c)
{
    DataBase *db = DataBase::getInstance();
    if((db->getEdge(a,b)->orientationA == db->getEdge(a,c)->orientationA) &&
        (db->getEdge(b,c)->orientationB == db->getEdge(a,c)->orientationB) )
            return true;
    return false;
}

void TransitiveEdgeRemover::removeTransitives()
{
    DataBase *db = DataBase::getInstance();

    for(auto& gE : vertexInfo)
    {
        for (int i = 0; i< gE.second.reduce.size();i++)
        {if(gE.second.mark!=0)cout<<gE.second.mark<<std::endl;
            db->eraseNeighbor(gE.first,gE.second.reduce[i]);}
    }

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





