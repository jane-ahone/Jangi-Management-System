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
    static int sid;

    SavingsTrans(string mId, int amnt);
};

#endif //_SAVINGSTRANS_H