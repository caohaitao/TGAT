#pragma once
#include "TGat.h"
#include "TGatHalfAdder.h"
#include "TGatOr.h"

//s=out[0],c=out[1]
class TGatFullAdder :
        public TGat
{
public:
        TGatFullAdder(const char * name);
        virtual ~TGatFullAdder();
        virtual bool Do() override;
        virtual void Init() override;
protected:
        TGatHalfAdder * m_half0;
        TGatHalfAdder * m_half1;
        TGatOr * m_or;
};

