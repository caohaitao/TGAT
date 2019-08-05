#pragma once
#include "TGat.h"
class TGatNot :
        public TGat
{
public:
        TGatNot(const char * name);
        virtual ~TGatNot();
        virtual bool Do() override;
        virtual void Init() override;
protected:
};

