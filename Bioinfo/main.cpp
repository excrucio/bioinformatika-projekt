#include <QCoreApplication>

#include <iostream>
#include <vector>

#include "GraphReader.h"
#include "TransitiveEdgeRemover.h"
#include "LayoutWriter.h"
#include "DataBase.h"


void printVector(std::vector<int> v, int a)
{
    std::cout<<"susjeda "<<a<<": "<<v.size()<<std::endl;
    for(unsigned int i = 0; i<v.size();i++)
        std::cout<<v[i];
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GraphReader *r = new GraphReader;
    r->testGraphReader();






    delete r;
    r=NULL;
    return a.exec();
}

