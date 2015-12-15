#include "GeneralFunctions.h"
#include "DataBase.h"
#include "DataBase2.h"
#include "GraphReader.h"
#include "GraphReader2.h"
#include "TransitiveEdgeRemover.h"

#include <algorithm>

using namespace std;

GeneralFunctions::GeneralFunctions(){}
GeneralFunctions::~GeneralFunctions(){}



void GeneralFunctions:: printVector(std::vector<int> v, int a)
{
    std::cout<<a<<" ima "<<v.size()<<" susjeda: "<<std::endl;
    for(unsigned int i = 0; i<v.size();i++)
        std::cout<<v[i]<<", ";
    std::cout<<std::endl;
    std::cout<<std::endl;
}

int GeneralFunctions::getNumberOfEdges()
{
    DataBase *data = DataBase::getInstance();
    return data->graphEdges.size();
}

int GeneralFunctions::getNumberOfEdges2()
{
    DataBase *data = DataBase::getInstance();
    int j=0;
    for(auto& gE : data->neighbors)
    {
      j+= gE.second.size();
    }
    return j;
}

int GeneralFunctions::getNumberOfControlEdges2()
{
    DataBase2 *data = DataBase2::getInstance();
    int j=0;
    for(auto& gE : data->neighbors)
    {
      j+= gE.second.size();
    }
    return j;
}








