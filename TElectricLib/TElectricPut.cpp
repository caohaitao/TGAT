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

static int GetPutNumber()
{
        static int number = 0;
        int res = number;
        number++;
        return res;
}

TElectricPut * CreateAPutN(void * owner, int n)
{
        TElectricPutN * res = new TElectricPutN(n);
        res->number = GetPutNumber();
        res->m_owner = owner;
        return res;
}

TElectricPut* CreateAPut(void * owner)
{
        TElectricPut * res = new TElectricPut();
        res->number = GetPutNumber();
        res->m_owner = owner;
        return res;
}

TElectricPutN::~TElectricPutN()
{
        for (int i = 0; i < m_value_nums; i++)
        {
                delete m_values[i];
        }
        delete[] m_values;
}

bool TElectricPutN::SetValue(const char * sv)
{
        if (strlen(sv) != m_value_nums)
        {
                return false;
        }
        for (int i = 0; i < m_value_nums; i++)
        {
                if (sv[i] == '1')
                {
                        m_values[i]->m_value = 1;
                }
                else if (sv[i] == '0')
                {
                        m_values[i]->m_value = 0;
                }
                else {
                        return false;
                }
        }
        return true;
}

TElectricPutN::TElectricPutN(int n)
        :TElectricPut()
        ,m_value_nums(n)
{
        m_values = new TElectricPut*[n];
        for (int i = 0; i < n; i++)
        {
                m_values[i] = CreateAPut(NULL);
        }
}
