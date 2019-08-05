#pragma once
#include "vector"
using namespace std;

class TElectricPut
{
public:
        ~TElectricPut();

        friend TElectricPut* CreateAPut(void * owner);

        void * m_owner;
        //-1,0,1
        char m_value;
        int number;
private:
        TElectricPut();

};

TElectricPut* CreateAPut(void * owner);
