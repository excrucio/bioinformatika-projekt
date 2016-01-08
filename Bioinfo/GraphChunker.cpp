#include "GraphChunker.h"
#include "DataBase.h"
#include "GeneralFunctions.h"
#include "MapEdge.h"

#include <algorithm>

GraphChunker::GraphChunker()
{

}

void GraphChunker::makeNeighbors(string idA, string idB)
{
    unordered_map<string,vector<string>>::const_iterator got = neighbors.find (idA);

    if(got!=neighbors.end())
     {
        vector<string> n = neighbors[idA];
        for(unsigned int i = 0; i<n.size(); i++)
            if (n[i]== idB) return;
        neighbors[idA].push_back(idB);

     }
    else
     {
        vector<string> newVectorA;
        newVectorA.push_back(idB);
        neighbors[idA]=newVectorA;

     }


     got = neighbors.find (idB);
     if(got!=neighbors.end())
      {
        neighbors[idB].push_back(idA);
      }
     else
      {
         vector<string> newVectorB;
         newVectorB.push_back(idA);
         neighbors[idB]=newVectorB;

      }

}

bool GraphChunker::exsistC(string id)
{
   unordered_map<string,ChunkInfo*> ::const_iterator got = chunks2.find (id);
   if(got!=chunks2.end()) return true;
   return false;
}

void GraphChunker::eraseNeighbor(string idA, string idB)
{
    unordered_map<string,vector<string>>::const_iterator got = neighbors.find (idA);
    if(got!=neighbors.end())
    {
        unsigned int position = 0;
        bool found = false;
        vector<string> n = neighbors[idA];

        for(unsigned int i = 0; i<n.size(); i++)
            if (n[i]== idB)
            {
                position = i;
                found = true;
                break;
            }

        if(found)
        {
            vector<string>::iterator it = neighbors[idA].begin() + position;
            neighbors[idA].erase(it);
        }
        else {/*cout<<"nisu susjedi 1"<<std::endl;*/return;}
    }
    else {cout<<"nisu susjedi 2"<<std::endl;return;}

    //nisam napravila provjeru za b. ali se ovaj dio koda
    //ne bi nikad smio odvrtiti ako ne postoji
    unsigned int position = 0;
    bool found = false;
    vector<string> n = neighbors[idB];

    for(unsigned int i = 0; i<n.size(); i++)
        if (n[i]== idA)
        {
            position = i;
            found = true;
            break;
        }

    if(found)
    {
        vector<string>::iterator it = neighbors[idB].begin() + position;
        neighbors[idB].erase(it);
    }
    else {cout<<"nisu susjedi 3"<<std::endl;return;}
}


bool GraphChunker::isFork(string id, vector<int>neighbors1)
{

    int key = atoi(id.c_str());
    DataBase *db = DataBase::getInstance();


    vector<string> constituents;
    int beginning1, end1, beginning2, end2;
    float fuzz = 0;
    bool pisi = false;
    bool edge1P = false;
    bool edge2P = false;
    int orientation1 = 0;
    int orientation2 = 0;



    for(unsigned int i = 0; i < neighbors1.size(); i++)      
    {
        edge1P = false;
        orientation1 = 0;
        if(pisi) cout<<std::endl;
        pisi = false;
        MapEdge *edge1 = DataBase::getInstance()->getEdge(key,neighbors1[i]);
        if(key == edge1->readA)
        {
            beginning1 = edge1->aStart-edge1->bMinus;
            if(beginning1 < 0)beginning1 = 0;
            end1 = edge1->aEnd + edge1->BPlus;
            if(end1>edge1->aLenghth)end1 = edge1->aLenghth;
        }
        else
        {
            beginning1 = edge1->bStart-edge1->AMinus;
            if(beginning1 < 0)beginning1 = 0;
            end1 = edge1->bEnd +  edge1->APlus;
            if(end1>edge1->bLenght)end1 = edge1->bLenght;
            edge1P = true;
            if(edge1->oB == 1)
            {
                orientation1 = 1;
                //beginning1 -= edge1->bMinus;
            }

        }

       for(unsigned int j = 0; j < neighbors1.size(); j++)
       {

            edge2P = false;
             orientation2 = 0;
           if(db->neighbors[neighbors1[i]].size()==1 || db->neighbors[neighbors1[j]].size()==1)
           {
                if(!checkExsistance(constituents,to_string(neighbors1[i])))
                    constituents.push_back(to_string(neighbors1[i]));

                if(!checkExsistance(constituents,to_string(neighbors1[j])))
                    constituents.push_back(to_string(neighbors1[j]));


                continue;
           }
           if(neighbors1[i]==neighbors1[j])continue;

         MapEdge *edge2 = DataBase::getInstance()->getEdge(key,neighbors1[j]);
           if(key == edge2->readA)
           {
               beginning2 = edge2->aStart-edge2->bMinus;
               if(beginning2 < 0)beginning2 = 0;
               end2 = edge2->aEnd + edge2->BPlus;
               if(end2>edge2->aLenghth)end2 = edge2->aLenghth;
           }
           else
           {
               beginning2 = edge2->bStart - edge2->AMinus;
               if(beginning2 < 0)beginning2= 0;
               end2 = edge2->bEnd + edge2->APlus;
               if(end2>edge2->bLenght)end2 = edge2->bLenght;
               edge2P = true;
               if(edge1->oB == 1)
               {
                   orientation2 = 1;
                   //beginning2 -= edge2->bMinus;
               }

           }

               //checking intervals
           if( ((beginning1-edge1->oLenght*fuzz <=beginning2) &&  (beginning2<= end1 + edge1->oLenght*fuzz )) ||
                ((beginning2-edge2->oLenght*fuzz <=beginning1) &&  (beginning1<= end2 + edge2->oLenght*fuzz )) ||
                 ((beginning1-edge1->oLenght*fuzz <=end2) &&  (end2<= end1 + edge1->oLenght*fuzz )) ||
                 ((beginning2-edge2->oLenght*fuzz <=end1) &&  (end1<= end2 + edge2->oLenght*fuzz ))  ||
                 (edge1P && edge2P) ||
                 (!edge1P && !edge2P) ||
                 (edge1P && !edge2P && (beginning2 <= beginning1)) ||
                 (!edge1P && edge2P && (beginning1 <= beginning2))  )

           {
                if(!checkExsistance(constituents,to_string(neighbors1[i])))
                    constituents.push_back(to_string(neighbors1[i]));

                if(!checkExsistance(constituents,to_string(neighbors1[j])))
                    constituents.push_back(to_string(neighbors1[j]));
           }

       }
    }

    for(unsigned int i = 0; i < neighbors1.size(); i++)
    {
        if(!checkExsistance(constituents,to_string(neighbors1[i])));// &&
    }
    if(constituents.size() == neighbors1.size())return false;
    if(neighbors1.size()==1) return false;

    return true;

}


void GraphChunker::recursion(vector<string> *chunked)
{
    unsigned int i = 0;
    DataBase *db = DataBase::getInstance();
    if(chunked->size()>0)nodes[chunked->at(0)].rec = true;

    while (i<chunked->size())
    {
        int key = atoi(chunked->at(i).c_str());

        for(unsigned int j = 0; j < db->neighbors[key].size(); j++)
        {
            string key2 = to_string(db->neighbors[key][j]);
            if(nodes[key2].rec)continue;


             nodes[key2].rec = true;
             if(!nodes[key2].bridge)chunked->push_back(key2);


        }
        i++;
    }    
}

bool wayToSort(ChunkInfo *i, ChunkInfo *j) { return i->chunkedString.size() > j-> chunkedString.size(); }
void GraphChunker:: mapChunks2()
{
    cout<<"mapping chunks"<<std::endl;
    DataBase *db = DataBase::getInstance();



    for(auto & gE : chunks)
    {

        string chromosome = "";
        vector<char>chrome;
        bool begining = true;
        int pocetak = 0;

        int brojac = 0;
        for(auto & chunkString : gE->constituents)
        {
            chromosome += db->v_strings[atoi(chunkString.c_str())];
            if(begining)
            {
                for(auto & element: db->v_strings[atoi(chunkString.c_str())])
                    if( element!='\0')chrome.push_back(element);
                begining = false;
                //cout<<chrome.size()<<std::endl;
                continue;
            }

            int firstElement = atoi(gE->constituents[brojac].c_str());
            brojac ++;
            int secondElement = atoi(chunkString.c_str());

            int pocetak2 = 0;

            MapEdge *edge = db->getEdge(firstElement,secondElement);
            if(firstElement == edge->readA)
            {
               pocetak += edge->aStart;
               pocetak2 = edge->bStart;

            }
            else
            {
               pocetak += edge->bStart;
               pocetak2 = edge->aStart;

            }
            int l = 0;
            int velicina_originala = chrome.size();
            velicina_originala--;

            for(pocetak2; pocetak2 < db->v_strings[secondElement].size() ; pocetak2++)
            {
                if(pocetak + l < velicina_originala)
                  chrome[pocetak + l] = db->v_strings[secondElement][pocetak2];
                else  chrome.push_back(db->v_strings[secondElement][pocetak2]);
                l++;
            }



        }
        gE->chunkedString = "";//chromosome;
        for(auto & el : chrome)
            gE->chunkedString = gE->chunkedString + el;
        //cout<<chrome.size()<<" "<<gE->chunkedString.size()<<std::endl;
        //if ()//cout<<chromosome.size()<<std::endl;
    }

    sort(chunks.begin(), chunks.end(), wayToSort);
    //for(auto & gE : chunks)
      //  if( gE->chunkedString.size()>500000)pom.push_back(gE);

    //cout<<pom.size()<<std::endl;


}



void GraphChunker::mapChunks()

{
    cout<<"mapping chunks"<<std::endl;


    unsigned int i = 0;
    DataBase *db = DataBase::getInstance();

    for(auto & gE : nodes)
    {
        gE.second.rec = false;
        gE.second.beginning = 0;
    }


int k = -1;
    for(auto & gE : chunks)
    {

        int addedForward = 0;
        int addedBackward = 0;
        int ukupno=0;
        int counter = 0;
        k++;
        string chunkedString =  db->v_strings[atoi(gE->constituents[0].c_str())];

        for(unsigned int l=0; l <gE->constituents.size(); l++ )
          {
        i = 0;
        vector<int> constituentsPom;
        nodes[gE->constituents[l]].rec = false;
        int f = atoi(gE->constituents[l].c_str());
        //if(gE->constituents.size()>65)f = atoi(gE->constituents[66].c_str());


        //gE->cMap.push_back(key1);
        constituentsPom.push_back(f);


        while (i<constituentsPom.size())
        {

            int key1 = constituentsPom[i];

            if(nodes[to_string(key1)].rec){i++;continue;}
            nodes[to_string(key1)].rec = true;
            int pos = 0;
            for(unsigned int j = 0; j < db->neighbors[constituentsPom[i]].size(); j++)
            {
                int key2 = db->neighbors[key1][j];

                if(!checkExsistance(constituentsPom,key2))
                {
                    pos ++;
                    addElement(&constituentsPom, i+pos, db->neighbors[constituentsPom[i]][j]);
                    nodes[to_string(key2)].first = constituentsPom[i];

                }

                if(checkExsistance(constituentsPom,i+pos,key2))nodes[to_string(key2)].first = constituentsPom[i];

                MapEdge *edge = db->getEdge(constituentsPom[i],db->neighbors[constituentsPom[i]][j]);



                int aPlus, aMinus, bPlus,bMinus,zbroj, first, start;
                if(constituentsPom[i] == edge->readA)
                {
                   aPlus = edge->APlus;
                   aMinus = edge->AMinus;
                   bPlus = edge->BPlus;
                   bMinus= edge->bMinus;
                   zbroj=edge->bLenght;
                   first = edge->first;
                   start = edge ->aStart;

                }
                else
                {
                    aPlus = edge->BPlus;
                    aMinus = edge->bMinus;
                    bPlus = edge->APlus;
                    bMinus= edge->AMinus;
                    zbroj=edge->aLenghth;
                    if(edge->first == 0) first = 1;
                    else first = 0;
                    start = edge->bStart;

                }
                if( first == 0)
                {

                    if(checkExsistance(constituentsPom,i+pos,key2))
                        nodes[to_string(key2)].beginning =
                            nodes[to_string(key1)].beginning
                            +(start - bMinus);
                }
                else
                {

                    if(checkExsistance(constituentsPom,i+pos,key2))
                        nodes[to_string(key2)].beginning =
                            nodes[to_string(key1)].beginning
                             - (start- bMinus);

                }

            }


            if (i == 0){i++;continue;}


            MapEdge *edge = db->getEdge(constituentsPom[i],nodes[to_string(constituentsPom[i])].first);

            int aPlus, aMinus, bPlus,bMinus,zbroj, first, start, isInverse;
            if(constituentsPom[i] == edge->readB)
            {
               aPlus = edge->APlus;
               aMinus = edge->AMinus;
               bPlus = edge->BPlus;
               bMinus= edge->bMinus;
               zbroj=edge->bLenght;
               first = edge->first;
               start = edge ->aStart;
               isInverse = edge ->orientationB;

            }
            else
            {
                aPlus = edge->BPlus;
                aMinus = edge->bMinus;
                bPlus = edge->APlus;
                bMinus= edge->AMinus;
                zbroj=edge->aLenghth;
                if(edge->first == 0) first = 1;
                else first = 0;
                start = edge->bStart;
                isInverse = edge ->orientationA;

            }
            if( first == 0)
            {

                if( (bPlus > addedForward - nodes[to_string(nodes[to_string(constituentsPom[i])].first)].beginning) )
                {
                    int pom = bPlus - (addedForward - nodes[to_string(nodes[to_string(constituentsPom[i])].first)].beginning);
                    //pom = bPlus-1;


                    if (addedForward - nodes[to_string(nodes[to_string(constituentsPom[i])].first)].beginning<0)pom = bPlus -1;//{i++;continue;}

                    string pomString = "";


                    int h = 0;
                    while( h <= pom )//= db->v_strings[db->neighbors[constituentsPom[i]][j]].size(); h > db->v_strings[db->neighbors[constituentsPom[i]][j]].size()-pom-2; h--)
                    {
                        int s = db->v_strings[constituentsPom[i]].size();
                        if(db->v_strings[constituentsPom[i]][s-h] == '\0')
                            {h++;continue;}

                         string p="";
                         if(isInverse == 1)
                            p = inverseBase(db->v_strings[constituentsPom[i]][s-h])+pomString;
                         else p= db->v_strings[constituentsPom[i]][s-h]+pomString;
                         pomString = p;
                         h++;

                    }

                    chunkedString +=pomString;
                    addedForward += pom;
                    ukupno +=zbroj;
                    counter++;

                }


            }
            else
            {

               if( (-bMinus < (addedBackward - nodes[to_string(nodes[to_string(constituentsPom[i])].first)].beginning)) )
                {
                    int pom = -(bMinus) - (addedBackward - nodes[to_string(nodes[to_string(constituentsPom[i])].first)].beginning);

                    pom = -(bMinus)+1;
                    string pomString = "";


                    for(unsigned int h = 0; h < -pom; h++)
                    {
                       if(db->v_strings[constituentsPom[i]][h] == '\0')
                             continue;
                       string p="";
                       if(isInverse == 1)
                              p = pomString + inverseBase(db->v_strings[constituentsPom[i]][h]);
                       else p= pomString +  db->v_strings[constituentsPom[i]][h];
                       pomString = p;

                    }

                    string p = pomString+chunkedString;
                    chunkedString = p;
                    addedBackward += pom;
                    ukupno +=zbroj;
                    counter++;


                }


            }
            i++;
        }


        }
        //cout<<"mapirano: "<<" "<<addedForward-addedBackward<<std::endl;
        gE->cMap=addedForward-addedBackward;
        gE->chunkedString = chunkedString;
    }





}

bool exsists(unordered_map<int,int> notUsed, int id)
{
    unordered_map<int,int>::const_iterator got = notUsed.find (id);
    if(got!=notUsed.end()) return true;
    return false;
}

void GraphChunker::ChunkGraph3()
{
    DataBase *db = DataBase::getInstance();
    //prepare structures for chunking
    unordered_map<int,int> notUsed;

    for (auto & gE : db->neighbors)
    {
        notUsed[gE.first] = 1;
    }

    for(auto & gE : db->neighbors)
    {
        nBor n;
        n.id = to_string(gE.first);
        n.chunkId = "";
        n.rec = false;
        if(!isFork(n.id,gE.second))n.bridge = false;
        else n.bridge = true;
        nodes[n.id] = n;


        string key1 = to_string(gE.first);
        for(unsigned int i = 0; i < gE.second.size(); i++)
        {
            string key2 = to_string(gE.second[i]);
            makeNeighbors(key1, key2);
        }
    }



    while(notUsed.size()>0)
    {
        vector<string> chunked;
        int first = -1;

        for (auto & gE : notUsed)
        {
            first =  gE.first;
            break;
        }

        int last = -1;
        if(first != -1)
        {

            while(exsists(notUsed, first))
            {
                chunked.push_back(to_string(first));
                notUsed.erase(first);
                for (auto & gE : db->neighbors[first])
                {
                    if(exsists(notUsed,gE))
                    {
                        first = gE;
                        last = first;
                        break;
                    }

                }
            }
        }

       /*if(chunked.size()!=1) cout<<chunked.size()<<std::endl;

        for (auto & gE : db->neighbors[ atoi(chunked[0].c_str()) ])
        {
            if(exsists(notUsed,gE))
            {
                first = gE;
                break;
                cout<<"yes!"<<std::endl;
            }
        }

        if(last != -1 && last != first)
            while(exsists(notUsed, first))
            {
                chunked.insert(chunked.begin(),to_string(first));
                notUsed.erase(first);
                for (auto & gE : db->neighbors[first])
                {
                    if(exsists(notUsed,gE))
                    {
                        first = gE;
                        last = first;
                        break;
                    }

                }
            }

       if(chunked.size()!=1) cout<<chunked.size()<<"\n"<<std::endl;*/







        //cout<<chunked.size()<<std::endl;

        ChunkInfo *newChunk = new ChunkInfo;
        newChunk->id = "Chunk"+to_string(chunks.size());

        for(unsigned int i = 0; i < chunked.size(); i++)
        {
            newChunk->constituents.push_back(chunked[i]);
            nodes[chunked[i]].chunkId = newChunk->id;
            for(unsigned int j = 0; j < neighbors[chunked[i]].size(); j++)
            {
                if(!checkExsistance(newChunk->neighbors2,neighbors[chunked[i]][j]))
                    newChunk->neighbors2.push_back(neighbors[chunked[i]][j]);
            }

        }
        if(newChunk->neighbors2.size() != 1 || newChunk->constituents.size() != 1)
            chunks.push_back(newChunk);
        chunks2[newChunk->id] = newChunk;

    }

    for(auto & gE : chunks)
    {
        for (auto & i : gE -> neighbors2)
            for(auto & a : chunks)
            {
                if (a->id == gE->id)continue;
                if(checkExsistance(a->constituents,i))
                {if(!checkExsistance(gE -> neighbors, a->id) /*&& a->id != gE->id*/) gE -> neighbors.push_back(a->id); }
            }

    }

    for(auto & gE : chunks)
    {
        gE -> id_first = gE -> constituents[0];
        gE -> id_last = gE -> constituents[gE -> constituents.size() -1];
    }

    cout<<chunks[0]->neighbors.size()<<std::endl;

   /* bool connected = true;
    while (connected)
    {
        for(auto & gE : chunks2["Chunk0"]->neighbors)
        {

           if( checkExsistance(neighbors[chunks2[gE]->id_first], chunks2["Chunk0"]->id_first) )
           {
              cout<<"yes"<<std::endl;
           }
           if( checkExsistance(neighbors[chunks2[gE]->id_first], chunks2["Chunk0"]->id_last) )
           {
              cout<<"yes"<<std::endl;
           }
           else cout<<"no"<<std::endl;
        }

    }*/



   // cout<<"ima u susjedi2 "<< gE->neighbors2.size()<<" a u zbilji"<< gE->neighbors.size()<<std::endl;

    mapChunks2();
}



void GraphChunker::ChunkGraph4()
{
    DataBase *db = DataBase::getInstance();
    //prepare structures for chunking
    unordered_map<int,int> notUsed;

    for (auto & gE : db->neighbors)
    {
        notUsed[gE.first] = 1;
    }

    for(auto & gE : db->neighbors)
    {
        nBor n;
        n.id = to_string(gE.first);
        n.chunkId = "";
        n.rec = false;
        if(!isFork(n.id,gE.second))n.bridge = false;
        else n.bridge = true;
        nodes[n.id] = n;


        string key1 = to_string(gE.first);
        for(unsigned int i = 0; i < gE.second.size(); i++)
        {
            string key2 = to_string(gE.second[i]);
            makeNeighbors(key1, key2);
        }
    }


for(auto & gE: pom)
{
    notUsed.empty();

    for (auto & element: gE->constituents)
        notUsed[atoi(element.c_str())] = 1;

    while(notUsed.size()>0)
    {
        vector<string> chunked;
        int first = -1;

        for (auto & gE : notUsed)
        {
         first =  gE.first;
            break;
        }

        int last = -1;
        if(first != -1)
        {

            while(exsists(notUsed, first))
            {
                chunked.push_back(to_string(first));
                notUsed.erase(first);
                for (auto & gE : db->neighbors[first])
                {
                    if(exsists(notUsed,gE) && !nodes[to_string(gE)].bridge)
                    {
                        first = gE;
                        last = first;
                        break;
                    }

                }
            }
        }



        ChunkInfo *newChunk = new ChunkInfo;
        newChunk->id = "Chunk"+to_string(chunks.size());

        for(unsigned int i = 0; i < chunked.size(); i++)
        {
            newChunk->constituents.push_back(chunked[i]);
            nodes[chunked[i]].chunkId = newChunk->id;
            for(unsigned int j = 0; j < neighbors[chunked[i]].size(); j++)
            {
                if(!checkExsistance(newChunk->neighbors2,neighbors[chunked[i]][j]))
                    newChunk->neighbors2.push_back(neighbors[chunked[i]][j]);
            }

        }
        if(newChunk->neighbors2.size() != 1 || newChunk->constituents.size() != 1)
            chunks.push_back(newChunk);
        chunks2[newChunk->id] = newChunk;

    }
}

    for(auto & gE : chunks)
    {
        for (auto & i : gE -> neighbors2)
            for(auto & a : chunks)
            {
                if (a->id == gE->id)continue;
                if(checkExsistance(a->constituents,i))
                {if(!checkExsistance(gE -> neighbors, a->id) /*&& a->id != gE->id*/) gE -> neighbors.push_back(a->id); }
            }

    }

    for(auto & gE : chunks)
    {
        gE -> id_first = gE -> constituents[0];
        gE -> id_last = gE -> constituents[gE -> constituents.size() -1];
    }

    cout<<chunks[0]->neighbors.size()<<std::endl;

   /* bool connected = true;
    while (connected)
    {
        for(auto & gE : chunks2["Chunk0"]->neighbors)
        {

           if( checkExsistance(neighbors[chunks2[gE]->id_first], chunks2["Chunk0"]->id_first) )
           {
              cout<<"yes"<<std::endl;
           }
           if( checkExsistance(neighbors[chunks2[gE]->id_first], chunks2["Chunk0"]->id_last) )
           {
              cout<<"yes"<<std::endl;
           }
           else cout<<"no"<<std::endl;
        }

    }*/



   // cout<<"ima u susjedi2 "<< gE->neighbors2.size()<<" a u zbilji"<< gE->neighbors.size()<<std::endl;

    mapChunks2();
}




void GraphChunker::ChunkGraph2()
{
    DataBase *db = DataBase::getInstance();
    //prepare structures for chunking

    for(auto & gE : db->neighbors)
    {
        nBor n;
        n.id = to_string(gE.first);
        n.chunkId = "";
        n.rec = false;
        if(!isFork(n.id,gE.second))n.bridge = false;
        else n.bridge = true;
        nodes[n.id] = n;


        string key1 = to_string(gE.first);
        for(unsigned int i = 0; i < gE.second.size(); i++)
        {
            string key2 = to_string(gE.second[i]);
            makeNeighbors(key1, key2);
        }
    }

    vector<string> chunked;
    bool exitDo = false;
    int brojac = 0;

    do
    {
        brojac ++;
        exitDo = false;
        chunked.clear();

        for (auto & gE : neighbors)
        {
            if( !nodes[gE.first].bridge && nodes[gE.first].chunkId=="")
            {
               chunked.push_back(gE.first);
               recursion(&chunked);
               //if(chunked.size()==1)chunked.clear();
                break;
               //cout<<chunked.size()<<std::endl;

            }
        }
        string cId = "";

        for(unsigned int i = 0; i < chunked.size(); i++)
            if(nodes[chunked[i]].chunkId != ""){cId = nodes[chunked[i]].chunkId;break;}


        if(chunked.size()>0)
        {
            exitDo = true;

            for(unsigned int i = 1; i < chunked.size(); i++)
                eraseNeighbor(chunked[0], chunked[i]);

            if(cId != "")
            {
                for(unsigned int i = 0; i< chunked.size(); i++)
                {
                    nodes[chunked[i]].chunkId = cId;
                    removeChunkNeighbor(chunks2[cId],chunked[i]);
                }

                 for(unsigned int i = 0; i < chunked.size(); i++)
                 {
                     if(!checkExsistance(chunks2[cId]->constituents,chunked[i]))
                     {
                         chunks2[cId]->constituents.push_back(chunked[i]);
                         for (unsigned int n = 0; n < db->neighbors[atoi(chunked[i].c_str())].size(); n++)
                         {

                             if(!checkExsistance(chunks2[cId]->neighbors,to_string(db->neighbors[atoi(chunked[i].c_str())][n])))
                                 chunks2[cId]->neighbors.push_back( to_string(db->neighbors[atoi(chunked[i].c_str())][n]));
                         }
                     }
                 }



            }
            else
            {
                ChunkInfo *newChunk = new ChunkInfo;
                newChunk->id = "Chunk"+to_string(pom.size());
                for(unsigned int i = 0; i < chunked.size(); i++)
                {
                    newChunk->constituents.push_back(chunked[i]);
                    nodes[chunked[i]].chunkId = newChunk->id;

                    for (unsigned int n = 0; n < neighbors[chunked[i]].size(); n++)
                    {

                        if(!checkExsistance(newChunk->neighbors,neighbors[chunked[i]][n]) &&
                           !checkExsistance(chunked,neighbors[chunked[i]][n]))
                        newChunk->neighbors.push_back(neighbors[chunked[i]][n]);

                    }
                }
                pom.push_back(newChunk);
                chunks2[newChunk->id] = newChunk;
            }



        }
        chunked.clear();

    }while(exitDo);

    //adding connectors
     unordered_map<string,ChunkInfo*>connectors;

    for (unsigned int i = 0; i < pom.size(); i++)
    {
        for(unsigned int j = 0; j < pom[i]->neighbors.size();j++)
            if(!checkExsistanceChunk(connectors,pom[i]->neighbors[j], pom[i]->id))
            {
                ChunkInfo *newInfo = new ChunkInfo;
                newInfo->id = pom[i]->neighbors[j];
                newInfo->constituents.push_back( pom[i]->neighbors[j]);
                newInfo->neighbors.push_back(pom[i]->id);
                connectors[newInfo->id]=newInfo;
            }

    }

    //collapsing chunk singles
    unordered_map<string,string> deleteMap;

    for (auto & gE :connectors)
    {
        int nCneigbors = 0;
        string chunkToMerge;
        for(unsigned int i = 0; i < gE.second->neighbors.size();i++)
        {
            if(gE.second->neighbors[i][0]=='C')
            {
                nCneigbors++;
                chunkToMerge = gE.second->neighbors[i];
            }

        }
       if(nCneigbors == 1) deleteMap[gE.first]=chunkToMerge;

    }



     for (auto & gE :deleteMap)
     {

         chunks2[gE.second]->constituents.push_back(gE.first);
         nodes[gE.first].chunkId = chunks2[gE.second]->id;
         removeChunkNeighbor(chunks2[gE.second],gE.first);
         for(unsigned int i = 0; i < connectors[gE.first]->neighbors.size(); i++)
         {
             if(connectors[gE.first]->neighbors[i] == gE.second)continue;
             if(checkExsistance(chunks2[gE.second]->neighbors,connectors[gE.first]->neighbors[i]))
                 chunks2[gE.second]->neighbors.push_back(connectors[gE.first]->neighbors[i]);
         }
         connectors.erase(gE.first);
     }


    for (auto & gE :connectors)
    {
        pom.push_back(gE.second);
    }

   ChunkGraph4();



}


void GraphChunker::ChunkGraph(unordered_map<int,vector<int>> neighbor)
{

    //prepare structures for chunking

    for(auto & gE : neighbor)
    {
        string key1 = to_string(gE.first);
        for(unsigned int i = 0; i < gE.second.size(); i++)
        {
            string key2 = to_string(gE.second[i]);
            makeNeighbors(key1, key2);
        }
    }

    //start chunking
    vector<string> chunked;
   //vector<ChunkInfo*> chunks;
    ChunkInfo * last = new ChunkInfo;
    last->id = "last";
    bool exitDo = false;
    int counter = 0;
    do
    {

        exitDo = false;
        bool breaking = false;
        bool added = false;

        for (auto & gE : neighbors)
        {
            //if(!isFork(gE.first,neighbor[atoi(gE.first.c_str())]))counter ++;
            if(gE.second.size() < 3)//(!isFork(gE.first,neighbor[atoi(gE.first.c_str())]))//(gE.second.size() < 3)

            {

                //cout<<isFork(gE.first,neighbor[atoi(gE.first.c_str())])<<std::endl;
                added = false;
                for (unsigned int i = 0; i< gE.second.size(); i++)
                {
                    string end = "-1";
                    if(gE.second[i] == end)continue;
                    if(neighbors[gE.second[i]].size() < 3)//(!isFork(gE.second[i],neighbor[atoi(gE.second[i].c_str())])) //   (neighbors[gE.second[i]].size() < 3)
                    {

                        chunked.push_back(gE.first);
                        added = true;
                        chunked.push_back(gE.second[i]);
                        gE.second.push_back(end);
                        neighbors[gE.second[i]].push_back(end);
                        breaking = true;
                        break;
                    }
                    else
                    {

                        if(neighbors[gE.second[i]][neighbors[gE.second[i]].size()-1] != end)
                            neighbors[gE.second[i]].push_back(end);

                    }
                }

                if (breaking)break;
            }
        }


        //chunking here
        if (chunked.size() == 2)
        {
            exitDo = true;
            string end = "-1";

            eraseNeighbor(chunked[0], chunked[1]);



            bool found = false;

            for (unsigned int j = 0; j < chunks.size(); j++)
            {
                if(checkExsistance(chunks[j]->constituents,chunked[0]) ||
                   checkExsistance(chunks[j]->constituents,chunked[1]))
                {
                    found = true;
                    removeChunkNeighbor(chunks[j],chunked[0]);
                    removeChunkNeighbor(chunks[j],chunked[1]);

                    if(!checkExsistance(chunks[j]->constituents,chunked[0]))
                    {
                        chunks[j]->constituents.push_back(chunked[0]);
                        for (unsigned int n = 0; n < neighbors[chunked[0]].size(); n++)
                        {
                            if (neighbors[chunked[0]][n]==end)continue;
                            if(!checkExsistance(chunks[j]->neighbors,neighbors[chunked[0]][n]))
                                chunks[j]->neighbors.push_back(neighbors[chunked[0]][n]);
                        }
                    }

                    if(!checkExsistance(chunks[j]->constituents,chunked[1]))
                    {
                        chunks[j]->constituents.push_back(chunked[1]);
                        for (unsigned int n = 0; n < neighbors[chunked[1]].size(); n++)
                        {
                            if (neighbors[chunked[1]][n]==end)continue;
                            if(!checkExsistance(chunks[j]->neighbors,neighbors[chunked[1]][n]))
                                chunks[j]->neighbors.push_back(neighbors[chunked[1]][n]);
                        }
                    }
                    break;

                }

            }
            if(!found)
            {
                ChunkInfo *newChunk = new ChunkInfo;
                newChunk->id = "Chunk"+to_string(chunks.size());
                newChunk->constituents.push_back(chunked[0]);
                newChunk->constituents.push_back(chunked[1]);
                string end = "-1";

                for (unsigned int n = 0; n < neighbors[chunked[0]].size(); n++)
                {
                    if(neighbors[chunked[0]][n]==end)continue;
                    if(!checkExsistance(newChunk->neighbors,neighbors[chunked[0]][n]))
                        newChunk->neighbors.push_back(neighbors[chunked[0]][n]);
                }


                for (unsigned int n = 0; n < neighbors[chunked[1]].size(); n++)
                {
                    if(neighbors[chunked[1]][n]==end)continue;
                    if(!checkExsistance(newChunk->neighbors,neighbors[chunked[1]][n]))
                        newChunk->neighbors.push_back(neighbors[chunked[1]][n]);
                }

                chunks.push_back(newChunk);

            }

        }
        chunked.clear();


    }while(exitDo);

    //adding connectors
     vector<ChunkInfo*>connectors;
     cout<<counter<<std::endl;


    for (unsigned int i = 0; i < chunks.size(); i++)
    {
        for(unsigned int j = 0; j < chunks[i]->neighbors.size();j++)
            if(!checkExsistanceChunk(connectors,chunks[i]->neighbors[j], chunks[i]->id))
            {
                ChunkInfo *newInfo = new ChunkInfo;
                newInfo->id = chunks[i]->neighbors[j];
                newInfo->constituents.push_back( chunks[i]->neighbors[j]);
                newInfo->neighbors.push_back(chunks[i]->id);
                connectors.push_back(newInfo);
            }

    }




    for (unsigned int i = 0; i < connectors.size(); i++)
    {
        chunks.push_back(connectors[i]);
    }

    //adding everybody else in same/different chunk



    bool IPushed = false;

    GeneralFunctions *f = new GeneralFunctions;
    string s = "last";
   // f->printVector(last->constituents,s);
    //last->constituents.clear();


    for (auto & gE : neighbors)
    {
       string end = "-1";
       if(gE.second[gE.second.size()-1]!= end)
       {
           ChunkInfo *merry = new ChunkInfo;
           merry->id = gE.first;
           merry->constituents.push_back(gE.first);
           for(unsigned int i = 0; i< gE.second.size(); i++)
               merry->neighbors.push_back(gE.second[i]);
           chunks.push_back(merry);
       }


    }




    int nuls = 0;
    int elements = 0;
    /*for (unsigned int i = 0; i< chunks.size(); i++)
    {
        if(chunks[i]->constituents.size()<2)continue;
        if(chunks[i]->neighbors.size()==0){nuls++; elements += chunks[i]->constituents.size(); continue;}
        cout<<"chunk id: "<<chunks[i]->id<<std::endl;
        cout<<"konstituents: "<<chunks[i]->constituents.size()<<" neighbors: "<<chunks[i]->neighbors.size()<<"\n"<<std::endl;
        cout<<"constiuendts ";f->printVector(chunks[i]->constituents,chunks[i]->id);
        cout<<"neighbors ";f->printVector(chunks[i]->neighbors,chunks[i]->id);
        cout<<std::endl;
    }
    cout<<"\nnuli ima "<< nuls<<" sto je ukupno "<< elements<<"nedostiznih"<<std::endl;*/
    delete f;



}

bool GraphChunker::checkExsistance(vector<string> chunked, string id)
{
    for(unsigned int i = 0; i<chunked.size(); i++)
        if (chunked[i]== id)
        {
            return true;
        }

    return false;
}

bool GraphChunker::checkExsistance(vector<int> chunked, int id)
{
    for(unsigned int i = 0; i<chunked.size(); i++)
        if (chunked[i]== id)
        {
            return true;
        }

    return false;
}


bool GraphChunker::checkExsistanceChunk(vector<ChunkInfo *> chunks, string id, string idChunk)
{
    for(unsigned int i = 0; i<chunks.size(); i++)
        if (chunks[i]->id == id)
        {
            if(!checkExsistance(chunks[i]->neighbors,idChunk))
                chunks[i]->neighbors.push_back(idChunk);
            return true;
        }

    return false;

}

bool GraphChunker::checkExsistanceChunk(unordered_map<string,ChunkInfo *> connectors, string id, string idChunk)
{
    for (auto & gE :connectors)
        if (gE.second->id == id)
        {
            if(!checkExsistance(gE.second->neighbors,idChunk))
                gE.second->neighbors.push_back(idChunk);
            return true;
        }

    return false;

}

bool GraphChunker::checkExsistance(vector<int> chunked, int position,int id)
{
    for(unsigned int i = position; i<chunked.size(); i++)
        if (chunked[i]== id)
        {
            return true;
        }

    return false;
}

void GraphChunker::removeChunkNeighbor(ChunkInfo *chunk, string idA)
{
    unsigned int position = 0;
    bool found = false;

    for(unsigned int i = 0; i<chunk->neighbors.size(); i++)
        if (chunk->neighbors[i]== idA)
        {
            position = i;
            found = true;
            break;
        }

    if(found)
    {
        vector<string>::iterator it = chunk->neighbors.begin() + position;
        chunk->neighbors.erase(it);
    }

}

void GraphChunker::addElement(vector<int> *field, int position, int element)
{
   // cout<<"added"<<std::endl;
    //return;
    vector<int>::iterator it = field->begin() + position;
    field->insert(it, element);

}

char GraphChunker::inverseBase(char base)
{
    if(base == 'A')return 'T';
    if(base == 'T')return 'A';
    if(base == 'C')return 'G';
    if(base == 'G')return 'C';
    return 'N';
}











