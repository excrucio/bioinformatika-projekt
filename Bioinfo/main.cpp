#include <QCoreApplication>

#include "GraphReader.h"
#include "TransitiveEdgeRemover.h"
#include "LayoutWriter.h"
#include "DataBase.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GraphReader* reader = new GraphReader;
    reader->testGraphReader();
    delete reader;
    reader = NULL;
    return a.exec();
}

