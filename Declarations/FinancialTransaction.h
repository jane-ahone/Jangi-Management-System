/**
 * Project Jangi
 */

#ifndef _FINANCIALTRANSACTION_H
#define _FINANCIALTRANSACTION_H
#include <ctime>
#include <string>
using namespace std;

class FinancialTransaction
{
public:
    string memberId;
    int amount;
    time_t datetime;
};

#endif //_FINANCIALTRANSACTION_H