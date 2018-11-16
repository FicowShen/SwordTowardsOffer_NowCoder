//
//  2 Replace Space.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/24.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

/**
 替换空格，切忌从前向后替换，效率低下

 @param str 待替换的字符串
 @param length 字符串最大长度
 */
void replaceSpace(char *str,int length) {
    
    long old_end = strlen(str);
    int space_cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            space_cnt++;
        }
    }
    
    long new_end = old_end + space_cnt * 2;
    if (new_end > length) { return; }
    
    while (old_end >= 0) {
        
        if (str[old_end] == ' ') {
            str[new_end--] = '0';
            str[new_end--] = '2';
            str[new_end--] = '%';
        }else{
            str[new_end--] = str[old_end];
        }
        old_end--;
    }
}


void Solution::testReplaceSpace() {
    
    // 空格转换为%20
    char *str = new char[20];//"We Are Happy.";
    strcpy(str, "We Are Happy.");
    replaceSpace(str, 20);
    printf("res:<%s>\n", str);
    
}
