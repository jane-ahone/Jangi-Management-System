/**
 * Project Jangi
 */

#ifndef _JANGI_H
#define _JANGI_H
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <Member.h>

using namespace std;

class Jangi
{
public:
    string name;
    int regFee;
    enum Status
    {
        Ongoing,
        Pending
    };
    Status jangiStatus;
    int startMonth;
    int numMembers;
    vector<Member *> members;

    // Used to store balloting information
    struct memberBallot
    {                     // Structure declaration
        string memberId;  // Member (string variable)
        int benefitMonth; // Member (int variable)
        int benefitAmount;
    };

    vector<memberBallot> memberBallots; // stores information about member ballots and beneffiting amount

    int static currentMonth;

    Jangi(string n, int rFee, int agreedAmnt, int strtMonth)
    {
        name = n;
        regFee = rFee;
        startMonth = 1; // Jangi starts in the first Month of the year
        numMembers = 0;
        jangiStatus = Pending;
        currentMonth = 0;
    }

    void balloting()
    { // loop through vector Member and assign months
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

    /**
     * @param rFee // default fee to be paid by new members
     * @param n  // name of new Member
     */
    void addMember(int rFee, string n) // complete
    {

        if (jangiStatus != Ongoing)
        {
            auto it = find(members.begin(), members.end(), n);

            if (it != members.end())
            {
                cout << "Registration failed. Name already exists. Try again";
            }
            else
            {
                // If name isn't found in existing database( or vector)
                string newMemberId = "m" + numMembers;
                if (rFee == regFee)
                {
                    Member *newMember = new Member(n, newMemberId, 0, "normal");
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
    void exit(string n) // complete
    {
        // Find the element with name n
        vector<Member *>::iterator it = find(members.begin(), members.end(), n);

        // Check if the element was found
        if (it != members.end())
        {
            string mId = "m" + distance(members.begin(), it);
            cout << "Member found at with Id: " << mId << endl;
            auto iterator = find_if(members.begin(), members.end(), [=](Member *member)
                                    { return member->memberID == mId; });
            members.erase(iterator);
        }
        else
        {
            cout << "Member not found." << endl;
        }
    };
};

#endif //_JANGI_H