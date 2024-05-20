/**
 * Project Jangi
 */

#ifndef _SAVINGSTRANS_H
#define _SAVINGSTRANS_H

#include "FinancialTransaction.h"
#include <string>
using namespace std;

class SavingsTrans : public FinancialTransaction
{
public:
    SavingsTrans(string mId, int amnt)
    {
        memberId = mId;
        amount = amnt;
        // set datetime
    }
};

#endif //_SAVINGSTRANS_H