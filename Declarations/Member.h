/**
 * Project Jangi
 */

#ifndef _MEMBER_H
#define _MEMBER_H

#include <string>
#include <iostream>
#include <BorrowTransactions.h>
#include <SavingsTrans.h>
#include <ctime>

using namespace std;

class Member
{
public:
    string name;
    string memberID;
    int agreedAmount; // Member agrees to pay a fixed amount say 3000frs every month
    int monthofbenefit;
    string memberStatus;                                  // member can either be normal or part of bureau
    vector<BorrowTransactions *> memberBorrowTrans;       // vector storing all member borrow transactiosn
    vector<SavingsTrans *> memberSaveTrans;               // vector storing all member saving transactions
    vector<MonthlyPaymentsTrans *> memberMonthlyPayTrans; // vector storing all member savin transactions

    // Constructor
    Member(string n, string mId, int monthofbenefit, string memberStatus);

    // Member functions

    void borrow(int amnt, time_t loanRepayDate, string mId)
    {
        BorrowTransactions *newBorrowTrans = new BorrowTransactions(mId, amnt, loanRepayDate);
        memberBorrowTrans.push_back(newBorrowTrans);
    };

    void save(int amnt, string mId)
    {
        SavingsTrans *newSaveTrans = new SavingsTrans(mId, amnt);
        memberSaveTrans.push_back(newSaveTrans);
    };

    void payjangi(int amount, int memberId) {};

    void contributions() {

    };

    void payloan()
    {
    }
};

#endif //_MEMBER_H