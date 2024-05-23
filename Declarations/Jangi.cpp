#include "Jangi.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

class Member;

int Jangi::currentMonth = 0;

Jangi::Jangi(string n, int rFee, int strtMonth)
{
    name = n;
    regFee = rFee;
    startMonth = 1; // Jangi starts in the first Month of the year
    numMembers = 0;
    jangiStatus = Pending;
    currentMonth = 0;
}
void Jangi::printAllMembers()
{
    cout << "Members:" << endl;
    for (const auto &member : members)
    {
        cout << "Name: " << member->name << endl
             << "Member ID: " << member->memberID << endl
             << "Jangi: " << member->agreedAmount << endl
             << "Benefits in the: " << endl;
        // print array;
    }
}

void Jangi::balloting()
{
    // this should work for member of size 12
    // Fix
    int balance = 0;
    int maxAmountMonth; // Maximum amount allowed for disbursement
    int totAmount = 0;
    // Get total maximum monthly amount
    for (Member *member : members)
    {
        totAmount = member->agreedAmount + totAmount;
    }
    int i = 1; // tracking the months

    for (Member *member : members)
    {
        member->benefitMonth.push_back(i); // assign month
        maxAmountMonth = totAmount - balance;

        memberBallot memberballot; // instance of memberBallot
        memberballot.memberId = member->memberID;
        memberballot.benefitMonth = i;
        memberballot.benefitAmount = maxAmountMonth;
        memberBallots.push_back(memberballot);
        i++; // next month

        balance = (member->agreedAmount * 12) - maxAmountMonth;

        if (balance != 0)
        {
            member->benefitMonth.push_back(i); // assign next month
            memberballot.memberId = member->memberID;
            memberballot.benefitMonth = i;
            memberballot.benefitAmount = balance;
            memberBallots.push_back(memberballot);
        }
    }

    jangiStatus = Ongoing;
}

void Jangi::addMember(int rFee, string n, int amount)
{
    if (jangiStatus != Ongoing)
    {
        auto it = find_if(members.begin(), members.end(), [&](Member *p)
                          { return p->name == n; });

        if (it != members.end())
        {
            cout << "Registration failed. Name already exists. Try again";
        }
        else
        {
            // If name isn't found in existing database( or vector)
            string newMemberId = "m" + to_string(numMembers);
            if (rFee == regFee)
            {
                Member *newMember = new Member(n, newMemberId, 0, "normal", amount);
                members.push_back(newMember);
                numMembers++;
            }
            else
            {
                cout << "Invalid Registration Fee. Registration Failed";
            }
        }
    }
    else
    {
        cout << "Jangi is currently ongoing. Try again next year";
    }
}

void Jangi::exit(string n)
{
    // Find the element with name n
    vector<Member *>::iterator it = find_if(members.begin(), members.end(), [=](Member *p)
                                            { return p->name == n; });
    ;

    // Check if the element was found
    if (it != members.end())
    {
        string mId = "m" + to_string(distance(members.begin(), it));
        cout << "Member found at with Id: " << mId << endl;
        auto iterator = find_if(members.begin(), members.end(), [=](Member *member)
                                { return member->memberID == mId; });
        members.erase(iterator);
    }
    else
    {
        cout << "Member not found." << endl;
    }
}