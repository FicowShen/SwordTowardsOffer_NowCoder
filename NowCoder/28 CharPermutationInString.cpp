//
//  28 CharPermutationInString.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/26.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

void doPermutation(string str, long begin, vector<string> &result) {
    
    if (begin == str.size()) {
        result.push_back(str);
        return;
    }
    
    long idx = begin;
    long size = str.size();
    for (; idx < size; idx++) {
        
        // 有重复字母，跳过
        if (idx != begin && str[idx] == str[begin]) {
            continue;
        }
        char t = str[idx];
        str[idx] = str[begin];
        str[begin] = t;
        
        doPermutation(str, begin + 1, result);
        
        t = str[idx];
        str[idx] = str[begin];
        str[begin] = t;
    }
    
}

vector<string> Permutation(string str) {

    vector<string> results;
    if (str.empty()) return results;

    doPermutation(str, 0, results);
    
    // 保证结果字典序
    sort(results.begin(), results.end());
    
    return results;
}

//// 指针操作
//void doPermutation(char* chars, char* begin, vector<string> &result) {
//
//    if (*begin == '\0') {
//        string s;
//        for (int i = 0; chars[i]; i++) {
//            s.push_back(chars[i]);
//        }
//        result.push_back(s);
//        return;
//    }
//
//    char* p = begin;
//    for (; *p; p++) {
//
//        // 有重复字母，跳过
//        if (p != begin && *p == *begin) {
//            continue;
//        }
//
//        char t = *p;
//        *p = *begin;
//        *begin = t;
//
//        doPermutation(chars, begin + 1, result);
//
//        t = *p;
//        *p = *begin;
//        *begin = t;
//    }
//
//}
//
//vector<string> Permutation(string str) {
//
//    vector<string> results;
//    if (str.empty()) return results;
//
//    long size = str.size();
//    char* chars = new char[size + 1];
//
//    chars[size] = '\0';
//    for(long i = 0; i < size; i++) {
//        chars[i] = str[i];
//    }
//
//    doPermutation(chars, chars, results);
//
//    delete []chars;
//    chars = NULL;
//
//    // 保证结果字典序
//    sort(results.begin(), results.end());
//    return results;
//}


void Solution::testCharPermutationInString() {
    
    printVector(Permutation("abc"));
    printVector(Permutation("aa"));
}
