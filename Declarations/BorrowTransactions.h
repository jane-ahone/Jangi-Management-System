/**
 * Project Jangi
 */
#ifndef _BORROWTRANSACTIONS_H
#define _BORROWTRANSACTIONS_H

#include <ctime>
#include <string>
#include "FinancialTransaction.h"

using namespace std;

class BorrowTransactions : public FinancialTransaction
{
public:
    static int lid;
    int interest;             // interest rate
    time_t loanrepaymentdate; // date the loan is to be repaid
    string status;            // indicates if loan is pending, complete or late

    BorrowTransactions(string mId, int amnt, float duration);
    void calcInterest();
};

#endif //_BORROWTRANSACTIONS_H