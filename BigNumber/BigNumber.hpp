//
//  BigNumber.hpp
//  CppToySolution
//
//  Created by QZQ on 17/09/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef BigNumber_hpp
#define BigNumber_hpp

#include <iostream>
const int DIGITNUMBER = 1000;
const int BASE = 10;
const char OUTPUT_BASE[] = "%01d";

class BigNumber
{
public:
    BigNumber();
    BigNumber(int v);
    ~BigNumber();
    
    bool IsNegtive() const;
    bool operator > (const BigNumber &y) const;
    bool operator < (const BigNumber &y) const;
    BigNumber operator + (const BigNumber &y) const;
//    BigNumber operator - (BigNumber y);
//    BigNumber operator * (BigNumber y);
//    BigNumber operator / (BigNumber y);
    friend std::ostream &operator << (std::ostream &out, const BigNumber &x);
    
private:
    void AdjustDigit();
    
private:
    int digit[DIGITNUMBER];
};

#endif /* BigNumber_hpp */
