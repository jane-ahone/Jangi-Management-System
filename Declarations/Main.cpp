#include <iostream>
#include <string>
#include "Jangi.h"
#include "Member.h"

using namespace std;

class Member;

int main()
{
    // Create a Jangi instance
    Jangi myJangi("My Jangi", 1000, 1);
    Member mymember("Jack", "m2", 3, "Normal", 56);

    int choice;
    string name, memberId, mIndex;
    string transactionType = "";
    int amount, duration, month, num;
    int regFee;
    std::vector<Member *>::iterator it;

    while (true)
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add member to Jangi" << endl;
        cout << "2. Perform member transactions" << endl;
        cout << "3. Perform balloting" << endl;
        cout << "4. Display Jangi information " << endl;
        cout << "5. Display member's information" << endl;
        cout << "6. Remove a member" << endl;
        cout << "7. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new member's name: ";
            cin.ignore(); // Ignore any remaining characters in the input stream
            getline(cin, name);
            cout
                << "Enter registration Fee ";
            cin >> regFee;
            cout << "How much are you willing to play every month? ";
            cin >> amount;
            myJangi.addMember(regFee, name, amount);
            myJangi.printAllMembers();
            break;

        case 2:
            myJangi.printAllMembers();
            cout << endl;
            cout << "Enter member ID: ";
            cin >> memberId;

            // Find the member with the given memberId
            it = find_if(myJangi.members.begin(), myJangi.members.end(),
                         [&](const Member *member)
                         { return member->memberID == memberId; });

            if (it != myJangi.members.end())
            {
                Member *selectedMember = *it;

                cout << "Enter transaction type (save, borrow, payjangi): ";
                cin >> transactionType;

                if (transactionType == "save")
                {
                    cout << "Enter amount to save: ";
                    cin >> amount;
                    selectedMember->save(amount, memberId);
                }
                else if (transactionType == "borrow")
                {
                    cout << "Enter amount to borrow: ";
                    cin >> amount;
                    cout << "Enter duration (in months): ";
                    cin >> duration;
                    selectedMember->borrow(amount, duration, memberId);
                }
                else if (transactionType == "payjangi")
                {
                    cout << "Enter amount to pay: ";
                    cin >> amount;
                    cout << "Enter month: you're paying for ";
                    cin >> month;
                    selectedMember->payjangi(amount, memberId, month);
                                }
                else
                {
                    cout << "Invalid transaction type" << endl;
                }
            }
            else
            {
                cout << "Member not found." << endl;
            }
            break;
        case 3:
            myJangi.balloting();
            break;

        case 4:
            myJangi.printAllMembers();

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

            cout << "Printing transactions for all members:" << endl;
            for (const auto &member : myJangi.members)
            {
                cout << "Transactions for Member: " << member->name << " (ID: " << member->memberID << ")" << endl;
                member->printTransactions();
                cout << endl;
            }
            break;

        case 5:
            myJangi.printAllMembers();
            cout << "Enter member ID: ";
            cin >> memberId;

            // Find the member with the given memberId
            it = find_if(myJangi.members.begin(), myJangi.members.end(),
                         [&](const Member *member)
                         { return member->memberID == memberId; });

            if (it != myJangi.members.end())
            {
                Member *selectedMember = *it;
                selectedMember->printTransactions();
            }
            else
            {
                cout << "Member not found." << endl;
            }
            break;

        case 6:
            cout << "Enter member name to remove: ";
            cin >> name;
            myJangi.exit(name);
            cout << "\nUpdated Number of Members: " << myJangi.numMembers << endl;
            break;

        case 7:
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}