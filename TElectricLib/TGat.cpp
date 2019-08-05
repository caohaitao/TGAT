#include "stdafx.h"
#include "TGat.h"

TGat::TGat(int input_nums, int output_nums, const char * name)
        :m_input_nums(input_nums)
        , m_output_nums(output_nums)
        , m_name(name)
{
        m_inputs = new TElectricPut**[m_input_nums];
        memset(m_inputs, 0, sizeof(TElectricPut*)*m_input_nums);
        m_outputs = new TElectricPut*[m_output_nums];
        memset(m_outputs, 0, sizeof(TElectricPut*)*m_output_nums);
}

TGat::~TGat()
{
        for (int i = 0; i < m_output_nums; i++)
        {
                delete m_outputs[i];
        }
        delete[] m_inputs;
        delete[] m_outputs;
}

void TGat::SetInput(TElectricPut ** p, int index)
{
        m_inputs[index] = p;
}

bool TGat::Do()
{
        for (int i = 0; i < m_input_nums; i++)
        {
                if (m_inputs[i] == NULL)
                {
                        return false;
                }
        }
        for (int i = 0; i < m_input_nums; i++)
        {
                if ((*(m_inputs[i]))->m_value == -1)
                {
                        if (((TGat*)(*(m_inputs[i]))->m_owner)->Do() == false)
                        {
                                return false;
                        }
                }
        }
        return true;
}

int TGat::GetOutPutNums()
{
        return m_output_nums;
}

TElectricPut ** TGat::GetOutPut(int index)
{
        return &m_outputs[index];
}

void TGat::Init()
{
}
