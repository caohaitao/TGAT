#include "stdafx.h"
#include "TElectricPut.h"


TElectricPut::TElectricPut()
        :m_owner(NULL)
        ,m_value(-1)
        ,number(0)
{
}


TElectricPut::~TElectricPut()
{
}

TElectricPut* CreateAPut(void * owner)
{
        static int number = 0;
        TElectricPut * res = new TElectricPut();
        res->number = number;
        number++;
        res->m_owner = owner;
        return res;
}





