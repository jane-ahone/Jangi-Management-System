/**
 * Project Jangi
 */

#ifndef _MEMBER_H
#define _MEMBER_H

#include <string>
#include <iostream>
#include <BorrowTransactions.h>
#include <MonthlyPaymentsTrans.h>
#include <Fine.h>
#include <Jangi.h>
#include <SavingsTrans.h>
#include <ctime>

using namespace std;

Jangi myObj;

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
    Member(string n, string mId, int monthofbenefit, string memberStatus)
    {
        name = n;
        memberID = mId;
        memberStatus = "Normal";
        jangiDay = 23; // Day in a month in which jangi takes place
    };

    // Member functions

    /**
     * @param amnt // money to be borrowed
     * @param duration  // duration of loan, in terms of months
     */

    void borrow(int amnt, float duration, string mId)
    {
        BorrowTransactions *newBorrowTrans = new BorrowTransactions(mId, amnt, duration);
        memberBorrowTrans.push_back(newBorrowTrans);
    };

    void save(int amnt, string mId)
    {
        SavingsTrans *newSaveTrans = new SavingsTrans(mId, amnt);
        memberSaveTrans.push_back(newSaveTrans);
    };

    /**
     * @param amnt // money to be borrowed
     * @param duration  // duration of loan, in terms of months
     * @param monthPay  // The month the member is paying for
     * Assumption, user can only pay for jangi on the 23rd of every month
     */

    void payjangi(int amnt, string mId, int monthPay)
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
                myObj.exit(); // arrange this
            }
            Fine *newFine = new Fine(mId, amnt, monthPay);
            memberFines.push_back(newFine);
        }
        MonthlyPaymentsTrans *newJangiPayment = new MonthlyPaymentsTrans(mId, amnt, monthPay);
        memberMonthlyPayTrans.push_back(newJangiPayment);
    };

    // Can only pay complete loan

    void payloan(string mId, int amnt)
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

    BorrowTransactions *printLoans(string mId)
    {

        cout << "\nBorrow Transactions:" << endl;
        for (const auto &trans : memberBorrowTrans)
        {
            if (trans->memberId == mId)
            {
                cout << "Member ID: " << trans->memberId << ", Amount: " << trans->amount;
                cout << "Status:" << trans->status;
            }
            return trans;
        }
    }
    void contributions() {

    };
};

#endif //_MEMBER_H