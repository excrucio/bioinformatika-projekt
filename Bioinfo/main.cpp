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


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GeneralFunctions *f = new GeneralFunctions;
    f->startGraph("/home/gongo/Desktop/bioinfoprojekt/overlaps.mhap");

    cout<<"\n\nwhat do you want:\n 1. Read control graph\n 2. Quit."<<std::endl;

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

    }

    exit(0);;
    /*GraphReader *r = new GraphReader;
    cout<<"reading input"<<std::endl;
    r->read("/home/gongo/Desktop/bioinfoprojekt/overlaps.mhap");
    cout<<"finished redaing, starting to remove contained edges:"<<std::endl;

    int j = 0;
   for(auto& gE : b->neighbors)
   {
       j++;
       //f->printVector(b->getNeighbors(gE.first),gE.first);

   }
   cout<<"vrhova prije brisanja  "<<j<<std::endl;


   j = 0;
  for(auto& gE : b->containedFragments)
  {
      j++;
      //f->printVector(b->getNeighbors(gE.first),gE.first);

  }
  cout<<"contained fragments prije brisanja"<<j<<std::endl;
   r->removeContainedEdges();
   cout<<"kapacitet edgeva prije transitiva"<<f->getNumberOfEdges2()<<std::endl;

    cout<<std::endl;
    //r->testGraphReader();

    /*for (int i = 1; i<14; i++)
        f->printVector(b->getNeighbors(i),i);*/

    /*TransitiveEdgeRemover *ter = new TransitiveEdgeRemover;
    cout<<"contained edges removed. Removing transitive edges."<<std::endl;
    ter->removeTransitiveEdges();
    r->removeZeroes();
    cout<<"transitive edges removed"<<std::endl;
    cout<<"nakon redukcije"<<std::endl;
    /*for (int i = 1; i<14; i++)
        f->printVector(b->getNeighbors(i),i);*/

    /* j = 0;
    for(auto& gE : b->containedFragments)
    {
        j++;
        //f->printVector(b->getNeighbors(gE.first),gE.first);

    }
    cout<<"contained fragments "<<j<<std::endl;

     j = 0;
    for(auto& gE : b->neighbors)
    {
        j++;
        //f->printVector(b->getNeighbors(gE.first),gE.first);

    }
    cout<<"vrhova "<<j<<std::endl;


    cout<<"kapacitet edgeva "<<f->getNumberOfEdges2()<<std::endl;
    cout<<"maksimalno susjeda "<<f->getMaxNeigbors()<<std::endl;
    delete r;
    delete f;
    delete ter;
    ter = NULL;
    f=NULL;
    r=NULL;*/
    return a.exec();
}

