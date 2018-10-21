//
//  Base64Test.h
//  CppToySolution
//
//  Created by QZQ on 21/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef Base64Test_h
#define Base64Test_h
#include "Base64.hpp"
void Test()
{
    unsigned char s[] = "woquni52";
    
    string ret = Base64::Encode(s, sizeof(s)/sizeof(unsigned char) -1);
    cout<<ret<<endl;
    cout<<Base64::Decode(ret.c_str(), ret.length())<<endl;
}

#endif /* Base64Test_h */
