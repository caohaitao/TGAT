#pragma once
#include "vector"
using namespace std;

class TElectricPut
{
public:
        virtual ~TElectricPut();

        friend TElectricPut* CreateAPut(void * owner);

        void * m_owner;
        //-1,0,1
        char m_value;
        int number;
protected:
        TElectricPut();

};

class TElectricPutN:public TElectricPut
{
public:
        virtual ~TElectricPutN();

        friend TElectricPut* CreateAPutN(void * owner, int n);
        bool SetValue(const char * sv);

        TElectricPut** m_values;
        int m_value_nums;
private:
        TElectricPutN(int n);
};

TElectricPut* CreateAPut(void * owner);
TElectricPut* CreateAPutN(void * owner, int n);