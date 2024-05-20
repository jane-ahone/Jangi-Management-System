#include <./Declarations/FinancialTransaction.h>
#include <./Declarations/BorrowTransactions.h>
#include <./Declarations/Bureau.h>
#include <./Declarations/Fine.h>
#include <./Declarations/Jangi.h>
#include <./Declarations/Member.h>
#include <./Declarations/MonthlyPaymentsTrans.h>
#include <./Declarations/SavingsTrans.h>
#include <./Declarations/SocialContribution.h>

int main()
{
    string name = "Zaine";
    double amount = 20000000;
    Jangi firstJangi = Jangi(name, 1500);
    firstJangi.registerMem(name, amount);
    firstJangi.printAllTransactions();

    return 0;
}
