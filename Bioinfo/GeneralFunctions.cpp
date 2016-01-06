#include "GeneralFunctions.h"
#include "DataBase.h"
#include "DataBase2.h"
#include "GraphReader.h"
#include "GraphReader2.h"
#include "TransitiveEdgeRemover.h"


#include <algorithm>

using namespace std;

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

void GeneralFunctions::printVector(std::vector<string> v, string s)
{
    std::cout<< s <<" ";
    for(unsigned int i = 0; i<v.size();i++)
        std::cout<<v[i]<<", ";
    std::cout<<std::endl;


}

int GeneralFunctions::getNumberOfEdges()
{
    DataBase *data = DataBase::getInstance();
    return data->graphEdges.size();
}

int GeneralFunctions::getNumberOfEdges2()
{
    DataBase *data = DataBase::getInstance();
    int j=0;
    for(auto& gE : data->neighbors)
    {
      j+= gE.second.size();
    }
    return j;
}

int GeneralFunctions::getNumberOfControlEdges2()
{
    DataBase2 *data = DataBase2::getInstance();
    int j=0;
    for(auto& gE : data->neighbors)
    {
      j+= gE.second.size();
    }
    return j;
}

int GeneralFunctions::getMaxNeigbors()
{
    DataBase *data = DataBase::getInstance();
    int maxi = 0;
    int key = 0;
    for(auto& gE : data->neighbors)
    {
        if(gE.second.size()>maxi)
           { maxi = gE.second.size(); key = gE.first;}
    }
    printVector(data->getNeighbors(key),key);
    return maxi;
}


void GeneralFunctions::startGraph(string fileName, string fileNameReads)
{
    DataBase *b = DataBase::getInstance();
    GraphReader *r = new GraphReader;

    cout<<"reading input"<<std::endl;
    r->read(fileName, fileNameReads);

    cout<<"finished redaing, starting to remove contained edges:"<<std::endl;
    cout<<"contained fragments: "<<b->containedFragments.size()<<std::endl;
    cout<<"vrhova prije brisanja contained:  "<<b->neighbors.size()<<std::endl;

    r->removeContainedEdges(fileNameReads);
    cout<<"vrhova poslje brisanja contained:  "<<b->neighbors.size()<<"\n"<<std::endl;
    cout<<"broj edgeva prije transitiva: "<<getNumberOfEdges2()<<std::endl;
    int j = b->neighbors.size();

    TransitiveEdgeRemover *ter = new TransitiveEdgeRemover;
    cout<<"Removing transitive edges."<<std::endl;
    ter->removeTransitiveEdges();
    r->removeZeroes();
    cout<<"transitive edges removed"<<std::endl;
    cout<<"vrhova nakon brisanja transitiva: "<<b->neighbors.size()<<std::endl;
    cout<<"pobrisano je "<< j - b->neighbors.size()<<" vrhova."<<std::endl;
    cout<<"broj edgeva nakon transitive removera: "<<getNumberOfEdges2()<<std::endl;

    cout<<"pocinjem chunkanje:"<<std::endl;


    delete r;
    delete ter;

}

void GeneralFunctions::inputControlGraph(string FileName)
{
    DataBase2 *b = DataBase2::getInstance();
    GraphReader2 *r = new GraphReader2;

    cout<<"\n\nreading control graph."<<std::endl;
    r->read(FileName);
    cout<<"finished redaing."<<std::endl;

    cout<<"broj vrhova:  "<<b->neighbors.size()<<std::endl;
    cout<<"broj edgeva: "<<getNumberOfControlEdges2()<<std::endl;

}

void GeneralFunctions::printVector(std::vector<int> v)
{
    for(unsigned int i = 0; i<v.size();i++)
        std::cout<<v[i]<<", ";
    std::cout<<std::endl;
}

void GeneralFunctions::differenceControlGraphVertex()
{
    DataBase *b1 = DataBase::getInstance();
    DataBase2 *b2 = DataBase2::getInstance();
    vector<int> diff;

    for(auto& gE : b2->neighbors)
        if(b1->getNeighbors(gE.first).size()==0) diff.push_back(gE.first);

    cout<<"U controlu ima "<<diff.size()<<" vrhova kojih nema u grafu. To su:"<<std::endl;
    printVector(diff);
}

void GeneralFunctions::differencelGraphControlVertex()
{
    DataBase *b1 = DataBase::getInstance();
    DataBase2 *b2 = DataBase2::getInstance();
    vector<int> diff;

    for(auto& gE : b1->neighbors)
        if(b2->getNeighbors(gE.first).size()==0) diff.push_back(gE.first);

    cout<<"U grafu ima "<<diff.size()<<" vrhova kojih nema u controlu. To su:"<<std::endl;
    printVector(diff);
}

void GeneralFunctions::listJointVertexes()
{
    DataBase *b1 = DataBase::getInstance();
    DataBase2 *b2 = DataBase2::getInstance();
    vector<int> diff;

    for(auto& gE : b1->neighbors)
        if(b2->getNeighbors(gE.first).size()>0) diff.push_back(gE.first);

    cout<<"Zajednickih vrhova ima "<<diff.size()<<". To su:"<<std::endl;
    printVector(diff);
}

bool GeneralFunctions::sameList(std::vector<int> list1, std::vector<int> list2)
{
    sort(list1.begin(),list1.end());
    sort(list2.begin(),list2.end());

    if(list1.size()!=list2.size()) return false;
    for(unsigned int i = 0; i < list1.size(); i++)
        if(list1[i] != list2[i]) return false;
    return true;



}

void GeneralFunctions::howManySame()
{
    DataBase *b1 = DataBase::getInstance();
    DataBase2 *b2 = DataBase2::getInstance();
    vector<int> diff;

    for(auto& gE : b1->neighbors)
    {
        if (sameList(b2->getNeighbors(gE.first),gE.second))
            diff.push_back(gE.first);
    }

    if(diff.size()>0)
    {
        cout<<"Vrhova sa istim susjedima ima "<<diff.size()<<". To su:"<<std::endl;
        printVector(diff);
    }
    else cout<<"Nema vrhova sa istim susjedima"<<std::endl;
}

void GeneralFunctions::howManyDifferent()
{
    DataBase *b1 = DataBase::getInstance();
    DataBase2 *b2 = DataBase2::getInstance();
    vector<int> diff;

    for(auto& gE : b1->neighbors)
    {
        if (!sameList(b2->getNeighbors(gE.first),gE.second))
            diff.push_back(gE.first);
    }

    if(diff.size()>0)
    {
        cout<<"Vrhova sa razlicitim susjedima ima "<<diff.size()<<". To su:"<<std::endl;
        printVector(diff);
    }
    else cout<<"Nema vrhova sa razlicitim susjedima"<<std::endl;
}

void GeneralFunctions::listAllNeigbors(int id)
{
    DataBase *b1 = DataBase::getInstance();
    DataBase2 *b2 = DataBase2::getInstance();

    if(b1->getNeighbors(id).size()>0)
    {
        cout<<"U grafu su susjedi od "<<id<<": "<<std::endl;
        printVector(sortedVector(b1->getNeighbors(id)));
    }
    else cout<<"U grafu nema vrha "<<id<<". "<<std::endl;

    if(b2->getNeighbors(id).size()>0)
    {
        cout<<"U controlu su susjedi od "<<id<<": "<<std::endl;
        printVector(sortedVector(b2->getNeighbors(id)));
    }
    else cout<<"U controlu nema vrha "<<id<<". "<<std::endl;
}

vector <int> GeneralFunctions:: sortedVector(vector<int> v)
{
    sort(v.begin(),v.end());
    return v;
}











