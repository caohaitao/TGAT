#include "stdafx.h"
#include "TGatFullAdder.h"


TGatFullAdder::TGatFullAdder(const char * name)
        :TGat(3,2,name)
{
}


TGatFullAdder::~TGatFullAdder()
{
        delete m_half0;
        delete m_half1;
        delete m_or;
}

bool TGatFullAdder::Do()
{
        if (TGat::Do() == false)
        {
                return false;
        }
        if (m_half1->Do() == false)
        {
                return false;
        }
        if (m_or->Do() == false)
        {
                return false;
        }
        m_outputs[0]->m_value = (*(m_half1->GetOutPut(0)))->m_value;
        m_outputs[1]->m_value = (*(m_or->GetOutPut(0)))->m_value;
        
        return true;
}

void TGatFullAdder::Init()
{
        for (int i = 0; i < m_output_nums; i++)
        {
                m_outputs[i] = CreateAPut(this);
        }

        m_half0 = new TGatHalfAdder("FullAdder-half0");
        m_half1 = new TGatHalfAdder("FullAdder-half1");
        m_or = new TGatOr("FullAdder-or");

        m_half0->SetInput(m_inputs[0], 0);
        m_half0->SetInput(m_inputs[1], 1);
        m_half0->Init();

        m_half1->SetInput(m_half0->GetOutPut(0), 0);
        m_half1->SetInput(m_inputs[2], 1);
        m_half1->Init();

        m_or->SetInput(m_half1->GetOutPut(1), 0);
        m_or->SetInput(m_half0->GetOutPut(1), 1);
        m_or->Init();
}
