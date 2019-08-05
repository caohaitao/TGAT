#pragma once
#include "TGat.h"

class TGatAnd :public TGat
{
public:
        TGatAnd(const char * name);
        virtual ~TGatAnd();
        virtual bool Do() override;
        virtual void Init() override;
protected:
};