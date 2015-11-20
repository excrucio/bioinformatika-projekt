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
    for(int i = 0; i<v.size();i++)
        std::cout<<v[i];
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataBase* d = DataBase::getInstance();
    d->makeNeighbors(1,2);
    d->makeNeighbors(1,3);
    d->makeNeighbors(1,4);
    d->makeNeighbors(1,5);
    printVector( d->getNeighbors(1),1);
    printVector( d->getNeighbors(2),2);
    d->eraseNeighbor(2,1);
    printVector( d->getNeighbors(1),1);
    printVector( d->getNeighbors(2),2);





    delete d;
    return a.exec();
}

