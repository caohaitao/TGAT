#include "stdafx.h"
#include "TGatNFullAdder.h"


TGatNFullAdder::TGatNFullAdder(const char * name, int n)
        :TGat(2,1,name)
        ,m_adders_nums(n)
{
}


TGatNFullAdder::~TGatNFullAdder()
{
        for (int i = 0; i < m_adders_nums; i++)
        {
                delete m_adders[i];
        }
        delete[] m_adders;
        delete m_c0;
}

bool TGatNFullAdder::Do()
{
        if (m_adders[m_adders_nums - 1]->Do() == false)
        {
                return false;
        }
        for (int i = 0; i < m_adders_nums; i++)
        {
                TElectricPut** p= m_adders[i]->GetOutPut(0);
                TElectricPut* pp = (*p);
                ((TElectricPutN *)m_outputs[0])->m_values[i]->m_value = pp->m_value;
        }
        return true;
}

void TGatNFullAdder::Init()
{
        for (int i = 0; i < m_output_nums; i++)
        {
                m_outputs[i] = CreateAPutN(this, m_adders_nums);
        }

        m_adders = new TGatFullAdder*[m_adders_nums];
        for (int i = 0; i < m_adders_nums; i++)
        {
                char temp_name[512] = { 0 };
                snprintf(temp_name, sizeof(temp_name) - 1,
                        "NFullAdder-%d", i);
                m_adders[i] = new TGatFullAdder(temp_name);
        }

        TElectricPutN * temp_put0 = (TElectricPutN *)(*(m_inputs[0]));
        TElectricPutN * temp_put1 = (TElectricPutN *)(*(m_inputs[1]));

        m_c0 = CreateAPut(NULL);
        m_c0->m_value = 0;
        m_adders[0]->SetInput(&(temp_put0->m_values[0]), 0);
        m_adders[0]->SetInput(&(temp_put1->m_values[0]), 1);
        m_adders[0]->SetInput(&m_c0, 2);
        m_adders[0]->Init();

        for (int i = m_adders_nums - 1; i > 0; i--)
        {

                int i_pre = i - 1;
                m_adders[i]->SetInput(&(temp_put0->m_values[i]),0);
                m_adders[i]->SetInput(&(temp_put1->m_values[i]), 1);
                m_adders[i]->SetInput(m_adders[i_pre]->GetOutPut(1), 2);
                m_adders[i]->Init();
        }


}
