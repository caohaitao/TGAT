#include "stdafx.h"
#include "TGatNotOr.h"


TGatNotOr::TGatNotOr(const char * name)
        :TGat(2, 1,name)
{
}


TGatNotOr::~TGatNotOr()
{
}

bool TGatNotOr::Do()
{
        if (TGat::Do() == false)
        {
                return false;
        }
        if (m_or->Do() == false)
        {
                return false;
        }
        m_outputs[0]->m_value = m_or->GetOutPut(0)->m_value;
        return false;
}

void TGatNotOr::Init()
{
        for (int i = 0; i < m_output_nums; i++)
        {
                m_outputs[i] = CreateAPut(this);
        }

        m_and0 = new TGatAnd("and0");
        m_and1 = new TGatAnd("and1");
        m_not0 = new TGatNot("not0");
        m_not1 = new TGatNot("not1");
        m_or = new TGatOr("or");

        m_not0->SetInput(m_inputs[1], 0);
        m_not0->Init();

        m_and0->SetInput(m_inputs[0], 0);
        m_and0->SetInput(m_not0->GetOutPut(0), 1);
        m_and0->Init();

        m_not1->SetInput(m_inputs[0], 0);
        m_not1->Init();

        m_and1->SetInput(m_not1->GetOutPut(0), 0);
        m_and1->SetInput(m_inputs[1], 1);
        m_and1->Init();

        m_or->SetInput(m_and0->GetOutPut(0), 0);
        m_or->SetInput(m_and1->GetOutPut(0), 1);
        m_or->Init();
}
