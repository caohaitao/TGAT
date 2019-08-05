#pragma once
#include "TGat.h"
class TGatOr :
        public TGat
{
public:
        TGatOr(const char * name);
        ~TGatOr();
        virtual bool Do() override;
        virtual void Init() override;
protected:
};

