#ifndef GRAPHREADER_H
#define GRAPHREADER_H

#include <iostream>

using namespace std;

class GraphReader
{
public:
    GraphReader();
    ~GraphReader();

    void read(string, string);
    void testGraphReader();
};

#endif // GRAPHREADER_H
