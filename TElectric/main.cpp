#include "TElectricPut.h"
#include "TGatAnd.h"
#include "TGatNotOr.h"
#include "TGatHalfAdder.h"
#include "TGatFullAdder.h"
#include "TGatNFullAdder.h"
#include "vld.h"

void NotOrTest()
{
        TGatNotOr and ("notor");
        TElectricPut* put1 = CreateAPut(NULL);
        TElectricPut* put2 = CreateAPut(NULL);
        put1->m_value = 1;
        put2->m_value = 1;
        and.SetInput(&put1, 0);
        and.SetInput(&put2, 1);
        and.Init();
        and.Do();

        int outnum = and.GetOutPutNums();
        for (int i = 0; i < outnum; i++)
        {
                TElectricPut** output = and.GetOutPut(i);
                printf("value(%d)=%d\n", i, (*output)->m_value);
        }

        delete put1;
        delete put2;
}

void HalfAdderTest()
{
        TGatHalfAdder ha("half_adder");
        TElectricPut* put1 = CreateAPut(NULL);
        TElectricPut* put2 = CreateAPut(NULL);
        put1->m_value = 1;
        put2->m_value = 1;
        ha.SetInput(&put1, 0);
        ha.SetInput(&put2, 1);
        ha.Init();
        ha.Do();

        int outnum = ha.GetOutPutNums();
        for (int i = 0; i < outnum; i++)
        {
                TElectricPut** output = ha.GetOutPut(i);
                printf("value(%d)=%d\n", i, (*output)->m_value);
        }

        delete put1;
        delete put2;
}

void FullAdderTest()
{
        TGatFullAdder fa("full_adder");
        TElectricPut* put1 = CreateAPut(NULL);
        TElectricPut* put2 = CreateAPut(NULL);
        TElectricPut* put3 = CreateAPut(NULL);
        put1->m_value = 1;
        put2->m_value = 0;
        put3->m_value = 1;
        fa.SetInput(&put1, 0);
        fa.SetInput(&put2, 1);
        fa.SetInput(&put3, 2);
        fa.Init();
        fa.Do();

        int outnum = fa.GetOutPutNums();
        for (int i = 0; i < outnum; i++)
        {
                TElectricPut** output = fa.GetOutPut(i);
                printf("value(%d)=%d\n", i, (*output)->m_value);
        }

        delete put1;
        delete put2;
        delete put3;
}

void NFullAdderTest()
{
        int bit_num = 8;
        TGatNFullAdder fa("nfull_adder",bit_num);
        TElectricPutN * put1 = (TElectricPutN *)CreateAPutN(NULL, bit_num);
        TElectricPutN * put2 = (TElectricPutN *)CreateAPutN(NULL, bit_num);
        put1->SetValue("01110000");
        put2->SetValue("11100000");

        fa.SetInput((TElectricPut**)(&put1), 0);
        fa.SetInput((TElectricPut**)(&put2), 1);
        fa.Init();
        fa.Do();

        TElectricPutN* p = (TElectricPutN*)(*fa.GetOutPut(0));
        for (int i = 0; i < p->m_value_nums; i++)
        {
                printf("%d", p->m_values[i]->m_value);
        }
        printf("\n");
        delete put1;
        delete put2;
}

int main(int argc, char ** argv)
{
        NFullAdderTest();
}