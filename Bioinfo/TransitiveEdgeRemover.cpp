#include <iostream>
#include <vector>
#include <algorithm>

#include "TransitiveEdgeRemover.h"
#include "DataBase.h"

#define VACANT 0
#define INPLAY 1
#define ELIMINATED 2

TransitiveEdgeRemover::TransitiveEdgeRemover(){}
TransitiveEdgeRemover::~TransitiveEdgeRemover(){}


void TransitiveEdgeRemover::removeTransitiveEdges()
{
    DataBase *db = DataBase::getInstance();

}
