#pragma once
#include "TGat.h"
#include "TGatAnd.h"
#include "TGatNotOr.h"

//s=out[0],c=out[1]
class TGatHalfAdder :
        public TGat
{
public:
        TGatHalfAdder(const char * name);
        virtual ~TGatHalfAdder();
        virtual bool Do() override;
        virtual void Init() override;
protected:
        TGatAnd * m_and0;
        TGatNotOr * m_not_or0;
};

