#include "stdafx.h"
#include "TGatNotOr.h"


TGatNotOr::TGatNotOr(const char * name)
        :TGat(2, 1,name)
{

}


TGatNotOr::~TGatNotOr()
{
        delete m_and0;
        delete m_and1;
        delete m_not0;
        delete m_not1;
        delete m_or;
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
        m_outputs[0]->m_value = (*(m_or->GetOutPut(0)))->m_value;
        return true;
}

void TGatNotOr::Init()
{
        for (int i = 0; i < m_output_nums; i++)
        {
                m_outputs[i] = CreateAPut(this);
        }

        m_and0 = new TGatAnd("NotOr-and0");
        m_and1 = new TGatAnd("NotOr-and1");
        m_not0 = new TGatNot("NotOr-not0");
        m_not1 = new TGatNot("NotOr-not1");
        m_or = new TGatOr("NotOr-or");

        m_not0->SetInput(m_inputs[1], 0);
        m_not0->Init();

        m_not1->SetInput(m_inputs[0], 0);
        m_not1->Init();

        m_or->SetInput(m_and0->GetOutPut(0), 0);
        m_or->SetInput(m_and1->GetOutPut(0), 1);
        m_or->Init();

        m_and1->SetInput(m_not1->GetOutPut(0), 0);
        m_and1->SetInput(m_inputs[1], 1);
        m_and1->Init();

        m_and0->SetInput(m_inputs[0], 0);
        m_and0->SetInput(m_not0->GetOutPut(0), 1);
        m_and0->Init();
}
