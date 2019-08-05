#pragma once
#include "TElectricPut.h"
class TGat
{
public:
        TGat(int input_nums, int output_nums,const char * name);
        ~TGat();

        void SetInput(TElectricPut** p, int index);
        virtual bool Do();

        int GetOutPutNums();
        TElectricPut** GetOutPut(int index);
        virtual void Init();
protected:
        TElectricPut*** m_inputs;
        TElectricPut** m_outputs;
        int m_input_nums;
        int m_output_nums;
        string m_name;
};
