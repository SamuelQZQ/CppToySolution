//
//  Base64.cpp
//  CppToySolution
//
//  Created by QZQ on 21/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#include "Base64.hpp"

const std::string Base64::ENCODE_TABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const int Base64::DECODE_TABLE[] =
{
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -2, -2, -1, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 62, -2, -2, -2, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -2, -2, -2, -2, -2, -2,
    -2,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -2, -2, -2, -2, -2,
    -2, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2
};

std::string Base64::Encode(const unsigned char * str,int bytes)
{
    std::string ret;
    while(bytes >= 3)
    {
        char b1 = *str++;
        char b2 = *str++;
        char b3 = *str++;
        ret += ENCODE_TABLE[(b1 >> 2) & 0x3F];
        ret += ENCODE_TABLE[((b1 << 4) | (b2 >> 4)) & 0x3F];
        ret += ENCODE_TABLE[((b2 << 2) | (b3 >> 6)) & 0x3F];
        ret += ENCODE_TABLE[(b3) & 0x3F];
        
        bytes -= 3;
    }
    
    if(bytes == 2)
    {
        char b1 = *str++;
        char b2 = *str++;
        ret += ENCODE_TABLE[(b1 >> 2) & 0x3F];
        ret += ENCODE_TABLE[((b1 << 4) | (b2 >> 4)) & 0x3F];
        ret += ENCODE_TABLE[((b2 << 2)) & 0x3F];
        ret += base64_pad;
    }
    else if(bytes == 1)
    {
        char b1 = *str++;
        ret += ENCODE_TABLE[(b1 >> 2) & 0x3F];
        ret += ENCODE_TABLE[((b1 << 4)) & 0x3F];
        ret += base64_pad;
        ret += base64_pad;
    }
    return ret;
}

std::string Base64::Decode(const char *str, int bytes)
{
    std::string ret;
    while(bytes > 0)
    {
        char b1 = DECODE_TABLE[*str++];
        char b2 = DECODE_TABLE[*str++];
        char a3 = *str++;
        char b3 = DECODE_TABLE[a3];
        char a4 = *str++;
        char b4 = DECODE_TABLE[a4];
        
        if(a3 == base64_pad && a4 == base64_pad)
        {
            ret += (b1<<2) | (b2 >> 4);
        }
        else if(a4 == base64_pad)
        {
            ret += (b1<<2) | (b2 >> 4);
            ret += (b2<<4) | (b3>>2);
        }
        else
        {
            ret += (b1<<2) | (b2 >> 4);
            ret += (b2<<4) | (b3>>2);
            ret += (b3<<6) | b4;
        }
        
        bytes -= 4;
    }
    return ret;
}
