#include "Member.h"
#include "Jangi.h"

class Jangi;

extern Jangi myObj;

// Constructor
Member::Member(string n, string mId, int monthofbenefit, string memberStatus)
{
    name = n;
    memberID = mId;
    this->memberStatus = "Normal";
    jangiDay = 23; // Day in a month in which jangi takes place
}

void Member::borrow(int amnt, float duration, string mId)
{
    BorrowTransactions *newBorrowTrans = new BorrowTransactions(mId, amnt, duration);
    memberBorrowTrans.push_back(newBorrowTrans);
}

void Member::save(int amnt, string mId)
{
    SavingsTrans *newSaveTrans = new SavingsTrans(mId, amnt);
    memberSaveTrans.push_back(newSaveTrans);
}

void Member::payjangi(int amnt, string mId, int monthPay)
{
    if (monthPay > myObj.currentMonth)
    {
        cout << "Transaction failure, month not valid";
        return;
    }
    if (monthPay < myObj.currentMonth)
    {
        if (monthPay - myObj.currentMonth < -1)
        {
            cout << "Jangi payment is 2 months late. Immediate removal from jangi";
            // myObj.exit(mId); // arrange this
        }
        Fine *newFine = new Fine(mId, amnt, monthPay);
        memberFines.push_back(newFine);
    }
    MonthlyPaymentsTrans *newJangiPayment = new MonthlyPaymentsTrans(mId, amnt, monthPay);
    memberMonthlyPayTrans.push_back(newJangiPayment);
}

void Member::payloan(string mId, int amnt)
{
    BorrowTransactions *loantrans = printLoans(mId);
    if (loantrans->amount == amnt)
    {
        loantrans->status = "Completed";
    }
    else
    {
        cout << "Transaction failed. Try again. Amount is less than expected";
    }
}

BorrowTransactions *Member::printLoans(string mId)
{
    cout << "\nBorrow Transactions:" << endl;
    for (const auto &trans : memberBorrowTrans)
    {
        if (trans->memberId == mId)
        {
            cout << "Member ID: " << trans->memberId << ", Amount: " << trans->amount;
            cout << "Status:" << trans->status;
            return trans;
        }
    }
    return nullptr;
}

void Member::contributions()
{
    // Implementation of contributions function
}