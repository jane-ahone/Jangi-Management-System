#ifndef _FINE_H
#define _FINE_H

#include "FinancialTransaction.h"

class Fine : public FinancialTransaction
{
public:
    static int fineId;
    int monthPay;

    Fine(string mId, int amnt, int mnthPay);
};

#endif //_FINE_H