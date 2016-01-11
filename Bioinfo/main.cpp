#include <QCoreApplication>

#include <iostream>
#include <vector>
#include <sstream>
#include <sys/time.h>


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
    //start mjerenja
    double start = clock();

    QCoreApplication a(argc, argv);
    int brojac = 1;

    string overlaps="";
    string reads = "";
    string graph1 = "";
    string constituents = "";
    string graph = "";
    int mode = 0;
    int num = -1;
    vector<string> chunkies;

    for(unsigned int i = 0; i < argc; i++)
    {
        if(i==1) overlaps += argv[i];
        if(i==2) reads += argv[i];
        if(i==3) graph1 += argv[i];
        if(i==4) constituents += argv[i];
        if(i==5) graph += argv[i];
        if(i==6) mode = atoi(argv[i]);
        if(i==7 && mode == 0) num = atoi(argv[i]);
        if(i>6 && mode == 1) chunkies.push_back(argv[i]);
    }

    //for(auto & c: chunkies)
    //cout<<c<<std::endl;
    //cout<<reads<<std::endl;
    //cout<<graph1<<std::endl;


    GeneralFunctions *f = new GeneralFunctions;
    f->startGraph(overlaps,reads);

    double lap1 = clock();

    GraphChunker *ch = new GraphChunker;
    ch ->ChunkGraph2();

    double lap2 = clock();

    cout<<"nakon chunkanja ima: "<<ch->chunks.size()<<" chunkova."<<std::endl;
    LayoutWriter *lw = new LayoutWriter;
    if(mode == 0)lw->writeGraph(ch->chunks, graph1, constituents, num);
    if(mode == 1)lw->writeGraph(ch->chunks, graph1, constituents, chunkies);
    lw->writeGraph(graph);

    delete ch;
    delete lw;
    delete f;


    //this part just prints some statistics Not used in final version.

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

    // kraj mjerenja
    double end=clock();
    //ispis mjerenja
    cout<<"\nTrajanja programa:"<<std::endl;
    cout<<"Ucitavanje i edge removing: "<<(double)(lap1-start)/(double)CLOCKS_PER_SEC<<" s"<<std::endl;
    cout<<"Chunker: "<<(double)(lap2-lap1)/(double)CLOCKS_PER_SEC<<" s"<<std::endl;
    cout<<"Ispis rezultata u datoteke: "<<(double)(end-lap2)/(double)CLOCKS_PER_SEC<<" s"<<std::endl;
    cout<<"Ukupno vrijeme: "<<(double)(double)(end-start)/(double)CLOCKS_PER_SEC<<" s"<<std::endl;

    exit(0);

    return a.exec();

}

