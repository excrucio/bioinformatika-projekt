#include "LayoutWriter.h"
#include <vector>
#include <unordered_map>



#include "DataBase.h"
#include "DataBase2.h"

LayoutWriter::LayoutWriter(){}
LayoutWriter::~LayoutWriter(){}

bool LayoutWriter::contain(vector<int> *V, int item)
{
    for (unsigned int g; g<V->size();g++)
        if(V->at(g)==item)
        {
           //cout<<"jok jok"<<std::endl;
            return true;
        }

    return false;
}

void LayoutWriter:: rec(vector<int> V,  vector <int> *read, vector<int> *cycle, int parent, int *k, bool swich1)
{
    DataBase *db1 = DataBase::getInstance();
    DataBase2 *db2 = DataBase2::getInstance();

    int brojac = 0;
    int brojac2 = 0;
    for(unsigned int i=0; i< V.size();i++)
    {
        if(V.size()==1)
        {
            //cout<<"palim"<<std::endl;
             if(/**k<1000 &&*/ (!contain(read,V[i])))
             {
                 read->push_back(V[i]);
                 makeEdge(parent,V[i]);
                 //myfile << "\t"<<parent<<" -> "<<V[i]<<";\n";
             }
             *k= *k+1;
            return;
        }

        if(!contain(cycle,V[i])){cycle->push_back(V[i]);brojac2++;}
        else
        {
            for(int l = 0; l< brojac2; l++)cycle->pop_back();
            return;
        }

        if(swich1)rec(db1->neighbors[V[i]], read, cycle, V[i],k, swich1 );
        else rec(db2->neighbors[V[i]], read, cycle, V[i],k, swich1 );

        if(!contain(read,V[i]))
        {
            read->push_back(V[i]);
            brojac ++;
            //cout<<"palim"<<std::endl;

            /*if(*k<1000)*/makeEdge(parent,V[i]);//myfile << "\t"<<parent<<" -> "<<V[i]<<";\n";
           *k= *k+1;
        }

    }
    for(int l = 0; l< brojac; l++)read->pop_back();

}

void LayoutWriter::writeGraph(string name)
{
    myfile.open(name);

    DataBase *db = DataBase::getInstance();

      if (myfile.is_open())
      {
          int k = 0;
          vector <int> read;
          vector<int>cycle;
          bool swich = false;
        myfile << "ddddigraph G {\n";
        for(auto& gE : db->neighbors)
        {
            rec(gE.second,&read,&cycle,gE.first,&k, true);
            cycle.clear();
            /*if(gE.second.size()==1)continue;

            for (unsigned int g; g<read.size();g++)
                if(gE.first==read[g])
                {
                    swich = true;
                    break;
                }
            if(swich)
            {
                swich = false;
                continue;
            }
            read.push_back(gE.first);

            for(unsigned int i=0; i< gE.second.size();i++)
            {myfile << "\t"<<gE.first<<" -> "<<gE.second[i]<<";\n";k++;}
            if (k>100) break;*/
        }

        for(auto& gE: toWrite)
        {
            for (unsigned int z = 0; z< gE.second.size();z++)
               myfile << "\t"<<gE.first<<" -> "<<gE.second[z]<<";\n";
        }
        cout<<read.size()<<" "<<k<<std::endl;
        myfile << "}\n";
        myfile.close();
      }
      else cout << "Unable to open file";
}

void LayoutWriter::writeGraph2(string name)
{
    myfile.open(name);

    DataBase2 *db = DataBase2::getInstance();

      if (myfile.is_open())
      {
          int k = 0;
          vector <int> read;
          vector<int>cycle;
          bool swich = false;
        myfile << "ddddigraph G {\n";
        for(auto& gE : db->neighbors)
        {
            rec(gE.second,&read,&cycle,gE.first,&k, false);
            cycle.clear();

        }

        for(auto& gE: toWrite)
        {
            for (unsigned int z = 0; z< gE.second.size();z++)
               myfile << "\t"<<gE.first<<" -> "<<gE.second[z]<<";\n";
        }
        cout<<read.size()<<" "<<k<<std::endl;
        myfile << "}\n";
        myfile.close();
      }
      else cout << "Unable to open file";
}


void LayoutWriter::makeEdge(int idA, int idB)
{
    unordered_map<int,vector<int>>::const_iterator got = toWrite.find (idB);
    if(got!=toWrite.end())
     {
        vector<int> n = toWrite[idB];
        for(unsigned int i = 0; i<n.size(); i++)
            if (n[i]== idA) return;
        //toWrite[idA].push_back(idB);

        got = toWrite.find (idA);
        if(got!=toWrite.end())
         {
            vector<int> n = toWrite[idA];
            for(unsigned int i = 0; i<n.size(); i++)
                if (n[i]== idB) return;
           toWrite[idA].push_back(idB);
         }
        else
         {
            vector<int> newVectorA;
            newVectorA.push_back(idB);
            toWrite[idA]=newVectorA;

         }

     }
    else
    {
        got = toWrite.find (idA);
        if(got!=toWrite.end())
         {
            vector<int> n = toWrite[idA];
            for(unsigned int i = 0; i<n.size(); i++)
                if (n[i]== idB) return;
           toWrite[idA].push_back(idB);
         }
        else
         {
            vector<int> newVectorA;
            newVectorA.push_back(idB);
            toWrite[idA]=newVectorA;
        }
    }

}


