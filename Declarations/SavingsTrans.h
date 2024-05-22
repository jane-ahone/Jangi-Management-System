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
    int sid = -1;
    SavingsTrans(string mId, int amnt)
    {
        memberId = mId;
        amount = amnt;
        sid++;
        // set datetime
    }
};

#endif //_SAVINGSTRANS_H