#include "TElectricPut.h"
#include "TGatAnd.h"
#include "TGatNotOr.h"

int main(int argc, char ** argv)
{
        TGatNotOr and("notor");
        TElectricPut* put1 = CreateAPut(NULL);
        TElectricPut* put2 = CreateAPut(NULL);
        put1->m_value = 1;
        put2->m_value = 1;
        and.SetInput(put1, 0);
        and.SetInput(put2, 1);
        and.Init();
        and.Do();

        int outnum = and.GetOutPutNums();
        for (int i = 0; i < outnum; i++)
        {
                TElectricPut* output = and.GetOutPut(i);
                printf("value(%d)=%d\n", i, output->m_value);
        }
        

}