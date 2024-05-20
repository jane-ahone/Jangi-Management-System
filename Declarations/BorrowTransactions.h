/**
 * Project Jangi
 */

#ifndef _BORROWTRANSACTIONS_H
#define _BORROWTRANSACTIONS_H

#include <ctime>
#include <string>
using namespace std;
#include <FinancialTransaction.h>

class BorrowTransactions : public FinancialTransaction
{
public:
    int interest;             // interest rate
    time_t loanrepaymentdate; // date the loan is to be repaid
    string status;            // indicates if loan is pending, complete or late

    BorrowTransactions(string mId, int amnt, time_t lrd)
    {
        interest = 0.01; // in percentage
        status = "Active";
        memberId = mId;
        amount = amnt;
        loanrepaymentdate = lrd;
    }

    void calcInterest() {
    };
};

#endif //_BORROWTRANSACTIONS_H