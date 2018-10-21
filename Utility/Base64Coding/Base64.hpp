//
//  Base64.hpp
//  CppToySolution
//
//  Created by QZQ on 21/10/2018.
//  Copyright © 2018 QZQ. All rights reserved.
//

#ifndef Base64_hpp
#define Base64_hpp

#include <string>
/**
 * Base64 编码/解码
 * @author liruixing
 */
class Base64{

private:
    static const std::string ENCODE_TABLE; // Base64编码使用的标准字典
    static const int DECODE_TABLE[];
    static const char base64_pad = '=';

public:

    /**
     * 这里必须是unsigned类型，否则编码中文的时候出错
     */
    static std::string Encode(const unsigned char * str,int bytes);
    static std::string Decode(const char *str,int bytes);
};
#endif /* Base64_hpp */
