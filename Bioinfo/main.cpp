#include <QCoreApplication>

#include <iostream>
#include <vector>

#include "GraphReader.h"
#include "TransitiveEdgeRemover.h"
#include "LayoutWriter.h"
#include "DataBase.h"
#include "GeneralFunctions.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GeneralFunctions *f = new GeneralFunctions;
    GraphReader *r = new GraphReader;

    r->testGraphReader();
    DataBase *b = DataBase::getInstance();
    for (int i = 1; i<14; i++)
        f->printVector(b->getNeighbors(i),i);


    delete r;
    delete f;
    f=NULL;
    r=NULL;
    return a.exec();
}

