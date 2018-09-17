//
//  BigNumber.cpp
//  CppToySolution
//
//  Created by QZQ on 17/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include "BigNumber.hpp"
#include <algorithm>
BigNumber::BigNumber():digit{0}
{
    
}

BigNumber::BigNumber(int v):digit{0}
{
    int i = 0;
    while(v)
    {
        digit[i++] = v%BASE;
        v/=BASE;
    }
}

BigNumber::~BigNumber()
{
    
}

bool BigNumber::IsNegtive() const
{
    for(int i = 0; i < DIGITNUMBER; ++i)
    {
        if(digit[i]) return digit[i] < 0;
    }
    return false;
}

std::ostream &operator << (std::ostream &out, const BigNumber &x)
{
    int i = DIGITNUMBER-1;
    while(i > 0 && !x.digit[i]) i--;
    printf("%d", x.digit[i--]);
    
    bool negtive = x.IsNegtive();
    for(; i >= 0; --i) printf(OUTPUT_BASE, negtive ? -x.digit[i] : x.digit[i]);
    return out;
}

bool BigNumber::operator > (const BigNumber &y) const
{
    for(int i = DIGITNUMBER-1; i >= 0; --i)
    {
        if(this->digit[i] != y.digit[i])
            return this->digit[i] > y.digit[i];
    }
    return false; // equal
}

bool BigNumber::operator < (const BigNumber &y) const
{
    for(int i = DIGITNUMBER-1; i >= 0; --i)
    {
        if(this->digit[i] != y.digit[i])
            return this->digit[i] < y.digit[i];
    }
    return false; // equal
}

BigNumber BigNumber::operator + (const BigNumber &y) const
{
    const BigNumber * pa = *this > y ? this : &y;
    const BigNumber * pb = *this > y ? &y : this;
    
    int remain = 0;
    BigNumber ret;
    for(int i = 0; i < DIGITNUMBER; ++i)
    {
        ret.digit[i] = pa->digit[i] + pb->digit[i] + remain;
        remain = ret.digit[i] / BASE;
        ret.digit[i] %= BASE;
    }
    ret.AdjustDigit();
    return ret;
}


void BigNumber::AdjustDigit()
{
    if(IsNegtive())
    {
        for(int i = 0; i < DIGITNUMBER; ++i)
        {
            if(digit[i] <= 0) continue;
            digit[i] -= BASE;
            digit[i+1] += 1;
        }
    }
    else
    {
        for(int i = 0; i < DIGITNUMBER; ++i)
        {
            if(digit[i] >= 0) continue;
            digit[i] += BASE;
            digit[i+1] -= 1;
        }
    }
}

