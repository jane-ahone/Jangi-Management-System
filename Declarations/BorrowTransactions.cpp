#include "BorrowTransactions.h"

int BorrowTransactions::lid = 0;

BorrowTransactions::BorrowTransactions(string mId, int amnt, float duration)
{
    interest = 0.01; // in percentage
    status = "Active";
    memberId = mId;
    amount = amnt;
    loanrepaymentdate = datetime + duration; // fix this
    lid++;
}

void BorrowTransactions::calcInterest()
{
    // Implementation of calcInterest function
}