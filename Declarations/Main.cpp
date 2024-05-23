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
    Member member1("John Doe", "m0", 0, "Normal", 500);
    Member member2("Jane Smith", "m1", 0, "Normal", 500);
    Member member3("Mike Johnson", "m2", 0, "Normal", 500);

    int choice;
    string name, memberId;
    string transactionType = "";
    int amount, duration, month;
    int regFee;

    while (true)
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add member to Jangi" << endl;
        cout << "2. Perform member transactions" << endl;
        cout << "3. Perform balloting" << endl;
        cout << "4. Display member information" << endl;
        cout << "5. Display all members" << endl;
        cout << "6. Remove a member" << endl;
        cout << "7. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new member's name: ";
            cin >> name;
            cout << "Enter registration Fee ";
            cin >> regFee;
            cout << "How much are you willing to play every month? ";
            cin >> amount;
            myJangi.addMember(regFee, name, amount);
            myJangi.printAllMembers();
            break;

        case 2:
            myJangi.printAllMembers();
            cout << "Enter member ID: ";
            cin >> memberId;

            string mIndex;
            // Extract the numeric part
            for (char c : memberId)
            {
                if (isdigit(c))
                {
                    mIndex += c;
                }
            }

            // Convert the numeric part to an integer
            int num = stoi(mIndex);

            cout << "Enter transaction type (save, borrow, payjangi): ";

            cin >> transactionType;

            if (transactionType == "save")
            {
                cout << "Enter amount to save: ";
                cin >> amount;

                myJangi.members[num]->save(amount, memberId);
            }
            else if (transactionType == "borrow")
            {
                cout << "Enter amount to borrow: ";
                cin >> amount;
                cout << "Enter duration (in months): ";
                cin >> duration;

                myJangi.members[num]->borrow(amount, duration, memberId);
            }
            else if (transactionType == "payjangi")
            {
                cout << "Enter amount to pay: ";
                cin >> amount;
                cout << "Enter month: you're paying for ";
                cin >> month;
                myJangi.members[num]->payjangi(amount, memberId, month);
            }
            else
            {
                cout << "Invalid transaction type" << endl;
            }
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
            myJangi.printAllMembers();

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