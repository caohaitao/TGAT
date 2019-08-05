#include "stdafx.h"
#include "TGatNot.h"


TGatNot::TGatNot(const char * name)
        :TGat(1, 1,name)
{
}


TGatNot::~TGatNot()
{
}

bool TGatNot::Do()
{
        if (TGat::Do() == false)
        {
                return false;
        }

        m_outputs[0]->m_value = !((*(m_inputs[0]))->m_value);
        return true;
}

void TGatNot::Init()
{
        for (int i = 0; i < m_output_nums; i++)
        {
                m_outputs[i] = CreateAPut(this);
        }
}
