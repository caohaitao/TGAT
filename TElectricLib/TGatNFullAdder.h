#pragma once
#include "TGat.h"
#include "TGatFullAdder.h"

class TGatNFullAdder :
        public TGat
{
public:
        TGatNFullAdder(const char * name,int n);
        virtual ~TGatNFullAdder();
        virtual bool Do() override;
        virtual void Init() override;
protected:
        TGatFullAdder** m_adders;
        int m_adders_nums;
        TElectricPut * m_c0;
};

