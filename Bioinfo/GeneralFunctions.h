#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <iostream>
#include <vector>


//class where all "general" functions will be. Functions that print lists
//print unordered_maps & such. Generally functions that we will use for debuuging & checking
//if our functions are working properly
class GeneralFunctions
{
public:
    GeneralFunctions();
    ~GeneralFunctions();

    void printVector(std::vector<int> v, int a);//this is used for printing all neigbors v of vertex a
};

#endif // GENERALFUNCTIONS_H
