/**
 * Project Jangi
 */
#ifndef _MEMBER_H
#define _MEMBER_H

#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include "BorrowTransactions.h"
#include "MonthlyPaymentsTrans.h"
#include "Fine.h"
#include "Jangi.h"
#include "SavingsTrans.h"

using namespace std;

class Member
{
public:
    string name;
    string memberID;
    int agreedAmount; // Member agrees to pay a fixed amount say 3000frs every month
    vector<int> benefitMonth;
    int jangiDay;
    string memberStatus;                                  // member can either be normal or part of bureau
    vector<BorrowTransactions *> memberBorrowTrans;       // vector storing all member borrow transactiosn
    vector<SavingsTrans *> memberSaveTrans;               // vector storing all member saving transactions
    vector<MonthlyPaymentsTrans *> memberMonthlyPayTrans; // vector storing all member savin transactions
    vector<Fine *> memberFines;                           // vector storing all member savin transactions

    // Constructor
    Member(string n, string mId, int monthofbenefit, string memberStatus, int monthlyJangi);

    // Member functions
    /**
     * @param amnt // money to be borrowed
     * @param duration // duration of loan, in terms of months
     */
    void borrow(int amnt, float duration, string mId);

    void save(int amnt, string mId);

    /**
     * @param amnt // money to be borrowed
     * @param duration // duration of loan, in terms of months
     * @param monthPay // The month the member is paying for
     * Assumption, user can only pay for jangi on the 23rd of every month
     */
    void payjangi(int amnt, string mId, int monthPay);

    // Can only pay complete loan
    void payloan(string mId, int amnt);

    BorrowTransactions *printLoans(string mId);

    void contributions();
};

#endif //_MEMBER_H