/**
 * Project Jangi
 */

#ifndef _FINE_H
#define _FINE_H

#include "FinancialTransaction.h"

class Fine : public FinancialTransaction
{

public:
    int fineId = -1;
    int monthPay;

    Fine(string mId, int amnt, int mnthPay)
    {
        fineId++;
        memberId = mId;
        amount = 500;
        // date time
    }
};

#endif //_FINE_H