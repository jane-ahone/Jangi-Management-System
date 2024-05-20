/**
 * Project Jangi
 */

#ifndef _SOCIALCONTRIBUTION_H
#define _SOCIALCONTRIBUTION_H

#include "FinancialTransaction.h"

class SocialContribution : public FinancialTransaction
{
public:
    string type;
};

#endif //_SOCIALCONTRIBUTION_H