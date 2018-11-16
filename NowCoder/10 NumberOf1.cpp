//
//  11 NumberOf1.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/26.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

//// 另一种比较低效的解法，从低位到高位进行掩码比较，
//// 切忌通过对原数移位来进行统计，会遭遇补位问题

//int  NumberOf1(int n) {
//
//    int cnt = 0;
//    int flag = 1;
//    while (flag) {
//        if (flag & n) {
//            cnt++;
//        }
//        flag <<= 1;
//    }
//
//    return cnt;
//}



/**
 统计一个数的二进制中有多少个1

 @param n 待统计的数
 @return 该数的二进制中1的个数
 */
int  NumberOf1(int n) {

    int cnt = 0;
    while (n) {
        cnt++;
        
        // 8的二进制1000, 8-1等于0111, &操作之后便将右边的1变为了0；
        n &= (n - 1);
    }

    return cnt;
}

void Solution::testNumberOf1() {
    
    printf("%d\n", NumberOf1(1));
    printf("%d\n", NumberOf1(7));
}
