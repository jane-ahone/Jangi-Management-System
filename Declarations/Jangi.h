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

    Jangi(string n, int rFee, int agreedAmnt, int strtMonth)
    {
        name = n;
        regFee = rFee;
        startMonth = 1; // Jangi starts in the first Month of the year
        numMembers = 0;
        jangiStatus = Pending;
    }

    void balloting()
    {
        jangiStatus = Ongoing;
        // loop through vector Member and assign months
    }

    /**
     * @param rFee // default fee to be paid by new members
     * @param n  // name of new Member
     */
    void addMember(int rFee, string n)
    {
        if (jangiStatus != Ongoing)
        {
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
        else
        {
            cout << "Jangi is currently ongoing. Try again next year";
        }
    }
    void exit(int memberId)
    { // work on memberId being string
        auto iterator = find_if(members.begin(), members.end(), [=](Member *member)
                                { return member->memberID == memberId; });
        members.erase(iterator);
    };
};

#endif //_JANGI_H