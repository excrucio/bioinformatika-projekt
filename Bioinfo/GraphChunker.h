#ifndef GRAPHCHUNKER_H
#define GRAPHCHUNKER_H


#include <iostream>
#include <unordered_map>
#include <vector>


//this is class that chunks graph. It has many functions that are not actually used.
//This is because we tried some different algorhitms. Are not deleted becasue maybe can be of some use
//some day :D

using namespace std;

typedef struct
{
    string id;
    string id_first;
    string id_last;
    vector<string> neighbors;
    vector<string> neighbors2;
    vector<string> constituents;
    int cMap;
    string chunkedString;

}ChunkInfo; //just a structure where all data of a chunk is stored. Layout writer uses this info to print stuff

typedef struct
{
    string id;
    bool bridge;
    string chunkId;
    bool rec;
    int beginning;
    int first;

}nBor; //not used in final version





class GraphChunker
{
public:
    GraphChunker();
    void ChunkGraph(unordered_map<int,vector<int>> neighbors);//not used in final version
    void ChunkGraph2();//not used in final version
    void ChunkGraph3();//chunks graph. Algorithm that chunks all that can in chunk untill it hits a vertex alredy placed in chunk. Not hamiltonian (for obvious reasons) but still works ok.
    void ChunkGraph4();
    void makeNeighbors(string idA, string idB); //support function used to access local data structures
    void eraseNeighbor(string idA, string idB); //support function used to access local data structures
    bool exsistC(string id);

    void removeChunkNeighbor(ChunkInfo *chunk, string idA);
    bool checkExsistance(vector<string> chunked, string id); //series of functions that are used to check existance of vertex in various strutures
    bool checkExsistance(vector<int> chunked, int id);
    bool checkExsistance(vector<int> chunked, int position,int id);
    bool checkExsistanceChunk(vector<ChunkInfo*> chunks, string id, string idChunk);
    bool checkExsistanceChunk(unordered_map<string,ChunkInfo *> connectors, string id, string idChunk);
    bool isFork(string id, vector<int> neighbors1);//not used in final version
    void recursion(vector<string> *chunked);//not used in final version
    void mapChunks();//not used in final version
    void mapChunks2();//makes strings of entire chunks. This is unfortunately very slow :(

    void addElement(vector<int> *field, int position, int element);//support function used to access local data structures
    char inverseBase(char base);//makes complement of base. Not used

    int chunkCount;


    unordered_map<string,vector<string>> neighbors;
    unordered_map<string,nBor> nodes;
    vector<ChunkInfo*> chunks; //this is the most important data structures. Here are all chunks & their info stored. The resta are just some support structures.
    vector<ChunkInfo*> chunksBetweenForks;
    vector<ChunkInfo*> pom;
    unordered_map<string,ChunkInfo*> chunks2;



};

#endif // GRAPHCHUNKER_H
