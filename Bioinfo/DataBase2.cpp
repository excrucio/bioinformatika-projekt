#include "DataBase2.h"

DataBase2::DataBase2(){}

bool DataBase2::instanceFlag = false;
DataBase2* DataBase2::single = NULL;

DataBase2* DataBase2::getInstance()
{
    if(!instanceFlag)
    {
      single = new DataBase2();
      instanceFlag = true;
      return single;
     }
     else
     {
       return single;
     }
}

