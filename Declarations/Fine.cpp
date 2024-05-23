#include "Fine.h"

int Fine::fineId = -1;

Fine::Fine(string mId, int amnt, int mnthPay)
{
    fineId++;
    memberId = mId;
    amount = 500;
    monthPay = mnthPay;
    // date time
}