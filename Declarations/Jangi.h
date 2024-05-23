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
#include "Member.h"

using namespace std;

class Member;

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
    static int currentMonth;

    Jangi(string n, int rFee, int strtMonth);

    void printAllMembers();

    void balloting(); // loop through vector Member and assign months

    /**
     * @param rFee // default fee to be paid by new members
     * @param n  // name of new Member
     */
    void addMember(int rFee, string n, int amount); // complete

    void exit(string n); // complete
};

#endif //_JANGI_H