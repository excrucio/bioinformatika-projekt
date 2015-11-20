#include "GeneralFunctions.h"

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
