#include "stdafx.h"
#include "TGatAnd.h"

TGatAnd::TGatAnd(const char * name)
        :TGat(2, 1,name)
{
}

TGatAnd::~TGatAnd()
{
}

bool TGatAnd::Do()
{
        if (TGat::Do() == false)
        {
                return false;
        }

        m_outputs[0]->m_value = (m_inputs[0]->m_value) & (m_inputs[1]->m_value);
        return true;
}

void TGatAnd::Init()
{
        for (int i = 0; i < m_output_nums; i++)
        {
                m_outputs[i] = CreateAPut(this);
        }
}