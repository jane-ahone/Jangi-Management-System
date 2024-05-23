#include <iostream>
#include <string>
#include "Jangi.h"
#include "Member.h"

using namespace std;

int main()
{
    // Create a Jangi instance
    Jangi myJangi("My Jangi", 1000, 1);

    // Create Member instances
    Member member1("John Doe", "m0", 0, "Normal");
    Member member2("Jane Smith", "m1", 0, "Normal");
    Member member3("Mike Johnson", "m2", 0, "Normal");

    int choice;
    string name, memberId;
    string transactionType = "";
    int amount, duration, month;

    while (true)
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add member to Jangi" << endl;
        cout << "2. Set agreed amount for member" << endl;
        cout << "3. Perform balloting" << endl;
        cout << "4. Display member information" << endl;
        cout << "5. Perform member transactions" << endl;
        cout << "6. Remove a member" << endl;
        cout << "7. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter member name: ";
            cin >> name;
            myJangi.addMember(1000, name);
            break;

        case 2:
            cout << "Enter member ID: ";
            cin >> memberId;
            cout << "Enter agreed amount: ";
            cin >> amount;

            if (memberId == "m0")
                member1.agreedAmount = amount;
            else if (memberId == "m1")
                member2.agreedAmount = amount;
            else if (memberId == "m2")
                member3.agreedAmount = amount;
            else
                cout << "Invalid member ID" << endl;
            break;

        case 3:
            myJangi.balloting();
            break;

        case 4:
            cout << "Jangi Name: " << myJangi.name << endl;
            cout << "Number of Members: " << myJangi.numMembers << endl;
            cout << "Jangi Status: " << (myJangi.jangiStatus == Jangi::Ongoing ? "Ongoing" : "Pending") << endl;

            cout << "\nMember Ballots:" << endl;
            for (const auto &ballot : myJangi.memberBallots)
            {
                cout << "Member ID: " << ballot.memberId << endl;
                cout << "Benefit Month: " << ballot.benefitMonth << endl;
                cout << "Benefit Amount: " << ballot.benefitAmount << endl;
                cout << endl;
            }
            break;

        case 5:
            cout << "Enter member ID: ";
            cin >> memberId;
            cout << "Enter transaction type (save, borrow, payjangi): ";

            cin >> transactionType;

            if (transactionType == "save")
            {
                cout << "Enter amount to save: ";
                cin >> amount;
                if (memberId == "m0")
                    member1.save(amount, memberId);
                else if (memberId == "m1")
                    member2.save(amount, memberId);
                else if (memberId == "m2")
                    member3.save(amount, memberId);
                else
                    cout << "Invalid member ID" << endl;
            }
            else if (transactionType == "borrow")
            {
                cout << "Enter amount to borrow: ";
                cin >> amount;
                cout << "Enter duration (in months): ";
                cin >> duration;
                if (memberId == "m0")
                    member1.borrow(amount, duration, memberId);
                else if (memberId == "m1")
                    member2.borrow(amount, duration, memberId);
                else if (memberId == "m2")
                    member3.borrow(amount, duration, memberId);
                else
                    cout << "Invalid member ID" << endl;
            }
            else if (transactionType == "payjangi")
            {
                cout << "Enter amount to pay: ";
                cin >> amount;
                cout << "Enter benefit month: ";
                cin >> month;
                if (memberId == "m0")
                    member1.payjangi(amount, memberId, month);
                else if (memberId == "m1")
                    member2.payjangi(amount, memberId, month);
                else if (memberId == "m2")
                    member3.payjangi(amount, memberId, month);
                else
                    cout << "Invalid member ID" << endl;
            }
            else
            {
                cout << "Invalid transaction type" << endl;
            }
            break;

        case 6:
            cout << "Enter member name to remove: ";
            cin >> name;
            myJangi.exit(name);
            cout << "\nUpdated Number of Members: " << myJangi.numMembers << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}