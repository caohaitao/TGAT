#include "stdafx.h"
#include "TGatHalfAdder.h"


TGatHalfAdder::TGatHalfAdder(const char * name)
        :TGat(2,2,name)
{
}


TGatHalfAdder::~TGatHalfAdder()
{
        delete m_and0;
        delete m_not_or0;
}

bool TGatHalfAdder::Do()
{
        if (TGat::Do() == false)
        {
                return false;
        }
        if (m_and0->Do() == false)
        {
                return false;
        }
        if (m_not_or0->Do() == false)
        {
                return false;
        }
        m_outputs[0]->m_value = (*(m_not_or0->GetOutPut(0)))->m_value;
        m_outputs[1]->m_value = (*(m_and0->GetOutPut(0)))->m_value;
        return true;
}

void TGatHalfAdder::Init()
{
        for (int i = 0; i < m_output_nums; i++)
        {
                m_outputs[i] = CreateAPut(this);
        }

        m_not_or0 = new TGatNotOr("HalfAdder-notor0");
        m_and0 = new TGatAnd("HalfAdder-and0");

        m_not_or0->SetInput(m_inputs[0], 0);
        m_not_or0->SetInput(m_inputs[1], 1);
        m_not_or0->Init();

        m_and0->SetInput(m_inputs[0], 0);
        m_and0->SetInput(m_inputs[1], 1);
        m_and0->Init();
}
