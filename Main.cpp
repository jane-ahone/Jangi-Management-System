#include <iostream>
#include <string>
#include "Jangi.h"

using namespace std;

int main()
{
    // Create a Jangi instance
    Jangi myJangi("My Jangi", 1000, 12000, 1);

    // Add members to the Jangi
    myJangi.addMember(1000, "John Doe");
    myJangi.addMember(1000, "Jane Smith");
    myJangi.addMember(1000, "Mike Johnson");
    myJangi.addMember(1000, "Emily Brown");

    // Perform balloting
    myJangi.balloting();

    // Display member information
    cout << "Jangi Name: " << myJangi.name << endl;
    cout << "Number of Members: " << myJangi.numMembers << endl;
    cout << "Jangi Status: " << (myJangi.jangiStatus == Jangi::Ongoing ? "Ongoing" : "Pending") << endl;

    // Display member ballots
    cout << "\nMember Ballots:" << endl;
    for (const auto &ballot : myJangi.memberBallots)
    {
        cout << "Member ID: " << ballot.memberId << endl;
        cout << "Benefit Month: " << ballot.benefitMonth << endl;
        cout << "Benefit Amount: " << ballot.benefitAmount << endl;
        cout << endl;
    }

    // Remove a member
    myJangi.exit("Jane Smith");

    // Display updated member information
    cout << "Updated Number of Members: " << myJangi.numMembers << endl;

    return 0;
}