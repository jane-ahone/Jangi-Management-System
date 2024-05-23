#ifndef _MONTHLYPAYMENTSTRANS_H
#define _MONTHLYPAYMENTSTRANS_H

#include "FinancialTransaction.h"
#include <string>

using namespace std;

class MonthlyPaymentsTrans : public FinancialTransaction
{
public:
    int monthPay;

    MonthlyPaymentsTrans(string mId, int amnt, int mthPay);
};

#endif //_MONTHLYPAYMENTSTRANS_H