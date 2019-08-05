#pragma once
#include "TGat.h"
class TGatOr :
        public TGat
{
public:
        TGatOr(const char * name);
        virtual ~TGatOr();
        virtual bool Do() override;
        virtual void Init() override;
protected:
};

