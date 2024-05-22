#include <./Declarations/FinancialTransaction.h>
#include <./Declarations/BorrowTransactions.h>
#include <./Declarations/Bureau.h>
#include <./Declarations/Fine.h>
#include <./Declarations/Jangi.h>
#include <./Declarations/Member.h>
#include <./Declarations/MonthlyPaymentsTrans.h>
#include <./Declarations/SavingsTrans.h>
#include <./Declarations/SocialContribution.h>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());

    int choice;
    cout << "************************" << endl;
    cout << "*  WELCOME TO OUR SYSTEM  *" << endl;
    cout << "************************" << endl;
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            adminLogin();
            break;
        case 2:
            createMemberAccount();
            break;
        case 3:
            displayTermsAndConditions();
            break;
        case 4:
        {
            // Get the number of months in the system
            int numMonths = 12;
            uniform_int_distribution<> dis(1, numMonths > 12 ? 12 : numMonths);
            int randomBenefittingMonth = dis(gen);
            cout << "EXITING THE SYSTEM. GOODBYE!" << endl;
            cout << "Randomly paired benefitting month: " << randomBenefittingMonth << endl;
            break;
        }
        default:
            cout << "INVALID CHOICE. PLEASE TRY AGAIN." << endl;
        }
    } while (choice != 4);

    return 0;
}
