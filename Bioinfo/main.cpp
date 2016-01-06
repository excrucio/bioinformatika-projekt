#include <QCoreApplication>

#include <iostream>
#include <vector>
#include <sstream>


#include "GraphReader.h"
#include "TransitiveEdgeRemover.h"
#include "LayoutWriter.h"
#include "DataBase.h"
#include "GeneralFunctions.h"
#include "LayoutWriter.h"
#include "GraphChunker.h"
#include "DataBase2.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*GraphReader *r = new GraphReader;
    r->testGraphReader();
    GraphChunker *ch = new GraphChunker;
    ch ->ChunkGraph();
    LayoutWriter *lw = new LayoutWriter;
    lw->writeGraph(ch->chunks);

    delete r;
    delete ch;
    delete lw;*/



    GeneralFunctions *f = new GeneralFunctions;
    //f->inputControlGraph("/home/gongo/Desktop/bioinfoprojekt/overlaps.after_unitigger.mhap");
   f->startGraph("/home/gongo/Desktop/bioinfoprojekt/overlaps.mhap","/home/gongo/Desktop/bioinfoprojekt/reads.fq");
    GraphChunker *ch = new GraphChunker;
    ch ->ChunkGraph3();//(DataBase::getInstance()->neighbors);
    cout<<"nakon chunkanja ima: "<<ch->chunks.size()<<" chunkova."<<std::endl;
    LayoutWriter *lw = new LayoutWriter;
    lw->writeGraph(ch->chunks);
    lw->writeGraph("/home/gongo/Desktop/bioinfoprojekt/graph");

    delete ch;
    delete lw;
   delete f;



   /* cout<<"\n\nwhat do you want:\n 1. Read control graph\n 2. Quit."<<std::endl;

    std::string mystring;
    int choice = 0;




    while(true)
    {
        getline (std::cin,mystring);
        stringstream(mystring) >> choice;
        if(choice == 2 || choice ==1) break;

    }

    if (choice==2) exit(0);

    f->inputControlGraph("/home/gongo/Desktop/bioinfoprojekt/overlaps.after_unitigger.mhap");
    //ch->ChunkGraph(DataBase2::getInstance()->neighbors);
    //lw->writeGraph(ch->chunks);
     delete ch;
     delete lw;
    delete f;
/*
    while(true)
    {
        cout<<"\n\nwhat do you want:\n 1. What vertexes exist in control and not in graph"
              "\n 2. What vertexes exist in graph and not in control."
              "\n 3. List all vertexes that exist in both"
              "\n 4. How many same vertexes have same neighbors"
              "\n 5. List all vertexes with different neighbors"
              "\n 6. List all neigbors of vertex"
              "\n 7. Open difference statistics"
              "\n 8. Write graph"
              "\n 9. Write test"
              "\n 10. Quit"<<std::endl;

        getline (std::cin,mystring);
        stringstream(mystring) >> choice;
        if(choice == 1) f->differenceControlGraphVertex();
        if(choice == 2) f->differencelGraphControlVertex();
        if(choice == 3) f->listJointVertexes();
        if(choice == 4) f->howManySame();
        if(choice == 5) f->howManyDifferent();
        if(choice == 6)
        {
            string id;
            int id2;
            cout<<"Unesi id vrha za kojeg zelis vidjeti susjede: "<<std::endl;
            getline (std::cin,id);
            stringstream(id) >> id2;
            f->listAllNeigbors(id2);
        }
        if(choice == 8)
        {
            LayoutWriter *lw = new LayoutWriter;
            cout<<"crtam graf"<<std::endl;
            lw->writeGraph("/home/gongo/Desktop/bioinfoprojekt/graph");
        }
        if(choice == 9)
        {
            LayoutWriter *lw = new LayoutWriter;
            cout<<"crtam testni graf"<<std::endl;
            lw->writeGraph2("/home/gongo/Desktop/bioinfoprojekt/graph");
        }
        if(choice == 10 ) break;

    }*/

    exit(0);

    return a.exec();
}

