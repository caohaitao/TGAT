#pragma once
#include "TGat.h"
#include "TGatAnd.h"
#include "TGatOr.h"
#include "TGatNot.h"
class TGatNotOr :
        public TGat
{
public:
        TGatNotOr(const char * name);
        ~TGatNotOr();
        virtual bool Do() override;
        virtual void Init() override;
protected:
        TGatAnd * m_and0;
        TGatAnd * m_and1;
        TGatNot * m_not0;
        TGatNot * m_not1;
        TGatOr * m_or;
};

