#include "SavingsTrans.h"

int SavingsTrans::sid = -1;

SavingsTrans::SavingsTrans(string mId, int amnt)
{
    memberId = mId;
    amount = amnt;
    sid++;
    // set datetime
}