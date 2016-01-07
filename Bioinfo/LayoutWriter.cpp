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
       // myfile << "ddddigraph G {\n";
        for(auto& gE : db->neighbors)
        {
            for (unsigned int i=0; i < gE.second.size(); i++)
                makeEdge(gE.first,gE.second[i]);

        }


        string wEdges = "";


        for(auto& gE: toWrite)
        {
            for (unsigned int z = 0; z< gE.second.size();z++)
            {wEdges = wEdges + db->getEdge(gE.first,gE.second[z])->edgeInfo+"\n";k++;}
               //myfile << "\t"<<gE.first<<" -> "<<gE.second[z]<<";\n";
        }
        //cout<<"read size "<<toWrite.size()<<" "<<k<<std::endl;
        myfile << wEdges;
        myfile.close();
      }
      else cout << "Unable to open file";
}

void LayoutWriter::writeGraph(vector<ChunkInfo *> chunks,string graph1, string constituensts, int num)
{
    myfile.open(graph1);
    ofstream myfile2;
    myfile2.open(constituensts);
    string vertices="";
    string edges="";
    string constituents="";
    int number;
    if(num == -1)number = chunks.size();
    else number = num;
    int i = 0;
    //int lookup[] = {26,18,9,8,75,85,36,26,8,69,25,29,72,13,165,54,0,64,11,58,101,57,19,169,45,5,50,47,1,122,18,92,7,13,32,2};
    //while(i < 36)
    //{
    for(unsigned int j = 0; j < chunks.size(); j++ )
    {
        //string key = "Chunk" + to_string(lookup[i]);
        //if (chunks[j]->id != key) continue;
        //if(gE->neighbors.size()==0)continue;
        vertices = vertices + "S\t" + chunks[j]->id +"\t"+ chunks[j]->chunkedString+ "\tLC:i:"+to_string(chunks[j]->cMap)+"\n";
        constituents = constituents + chunks[j]->id +"\n[ ";

        for (unsigned int i = 0; i< chunks[j]->neighbors.size();i++)
          edges = edges + "L\t" + chunks[j]->id + "\t+\t" +chunks[j]->neighbors[i] + "\t+\t1M1D2M1S\n";

        for (unsigned int i = 0; i< chunks[j]->constituents.size();i++)
        {
            constituents = constituents + chunks[j]->constituents[i];
            if(i!=(chunks[j]->constituents.size()-1))  constituents =  constituents + ", ";
        }
        constituents = constituents + " ]\n\n";
        i++;
        //j = 0;

       if(i>number)break;

    }

    myfile<<vertices;
    myfile<<edges;
    myfile2<<constituents<<std::endl;
    myfile.close();
    myfile2.close();



}

void LayoutWriter::writeGraph(vector<ChunkInfo *> chunks,string graph1, string constituensts, vector<string> chunkies)
{
    myfile.open(graph1);
    ofstream myfile2;
    myfile2.open(constituensts);
    string vertices="";
    string edges="";
    string constituents="";

    int i = 0;
    //int lookup[] = {26,18,9,8,75,85,36,26,8,69,25,29,72,13,165,54,0,64,11,58,101,57,19,169,45,5,50,47,1,122,18,92,7,13,32,2};
    while(i < chunkies.size())
{
    for(unsigned int j = 0; j < chunks.size(); j++ )
    {
        string key = "Chunk" + chunkies[i];
        if (chunks[j]->id != key) continue;
        //if(gE->neighbors.size()==0)continue;
        vertices = vertices + "S\t" + chunks[j]->id +"\t"+ chunks[j]->chunkedString+ "\tLC:i:"+to_string(chunks[j]->cMap)+"\n";
        constituents = constituents + chunks[j]->id +"\n[ ";

        for (unsigned int i = 0; i< chunks[j]->neighbors.size();i++)
          edges = edges + "L\t" + chunks[j]->id + "\t+\t" +chunks[j]->neighbors[i] + "\t+\t1M1D2M1S\n";

        for (unsigned int i = 0; i< chunks[j]->constituents.size();i++)
        {
            constituents = constituents + chunks[j]->constituents[i];
            if(i!=(chunks[j]->constituents.size()-1))  constituents =  constituents + ", ";
        }
        constituents = constituents + " ]\n\n";
        //i++;
        //j = 0;

       //if(i>number)break;

    }
i++;
}
    myfile<<vertices;
    myfile<<edges;
    myfile2<<constituents<<std::endl;
    myfile.close();
    myfile2.close();



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

