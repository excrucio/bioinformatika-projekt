#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <iostream>




//class where all "general" functions will be. Functions that print lists
//print unordered_maps & such. Generally functions that we will use for debuuging & checking
//if our functions are working properly
//also here is function that starts the program, is called from main. Don't ask why this one is here it's an eye sore :D
class GeneralFunctions
{
public:
    GeneralFunctions();
    ~GeneralFunctions();

    void printVector(std::vector<int> v, int a);//this is used for printing all neigbors v of vertex a
    int getNumberOfEdges();
    int getNumberOfEdges2();
    int getNumberOfControlEdges2();
    int getMaxNeigbors();
    void startGraph(std::string FileName, std::string FileNameReads); //starts program
    void inputControlGraph(std::string FileName);
    void differenceControlGraphVertex();
    void differencelGraphControlVertex();
    void listJointVertexes();
    void howManySame();
    void howManyDifferent();
    void listAllNeigbors(int id);
    std::vector<int> sortedVector(std::vector<int> v);
    bool sameList(std::vector<int> list1,std::vector<int> list2);
    void printVector(std::vector<int> v);
    void printVector(std::vector<std::string> v, std::string s);

};

#endif // GENERALFUNCTIONS_H

