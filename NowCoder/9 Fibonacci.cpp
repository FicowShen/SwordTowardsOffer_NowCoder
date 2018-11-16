//
//  7 Fibonacci.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/26.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"
#include <cmath>

/**
 矩形覆盖问题，用1*2的矩形去覆盖n*2的矩形，有多少种覆盖方式？

 @param number 有多少个1*2的矩形
 @return 有多少种覆盖方式
 */
int rectCover(int number) {
    
    if (number < 3) {
        int v[3] = {0, 1, 2};
        return v[number];
    }
    
    int s = 0, l = 2, r = 1;
    for (int i = 3; i <= number; i++) {
        s = l + r;
        r = l;
        l = s;
    }
    
    return s;
}


/**
 负载的青蛙跳台阶，青蛙每次可以跳任意个台阶

 @param number 台阶数
 @return 有多少种跳法
 */
int jumpFloorII(int number) {
    
    return pow(2, number - 1);
}


/**
 简单的青蛙跳台阶，青蛙每次只能跳1个或2个台阶；

 @param number 台阶的数量
 @return 有多少种跳法
 */
int jumpFloor(int number) {
    
    if (number < 0) {
        throw;
    }
    
    if (number < 3) {
        int v[3] = {0, 1, 2};
        return v[number];
    }
    
    int s = 0, l = 2, r = 1;
    for (int i = 3; i <= number; i++) {
        s = l + r;
        r = l;
        l = s;
    }
    
    return s;
}



/**
 求n的斐波那锲数

 @param n 输入值n
 @return 斐波那锲数
 */
int Fibonacci(int n) {
    
    
    if (n < 0) {
        throw;
    }
    
    if (n < 2) {
        int v[2] = {0, 1};
        return v[n];
    }
    
    // 大量重复计算，很容易栈溢出。Fibonacci(100)都需要计算很久很久
//    return Fibonacci(n - 1) + Fibonacci(n - 2);
    
    int s = 0, l = 1, r = 0;
    for (int i = 2; i <= n; i++) {
        s = l + r;
        r = l;
        l = s;
    }
    
    return s;
}

void Solution::testFibonacci() {
    
    printf("Fibonacci\n");
    printf("0:%d\n", Fibonacci(0));
    printf("1:%d\n", Fibonacci(1));
    printf("2:%d\n", Fibonacci(2));
    printf("3:%d\n", Fibonacci(3));
    printf("4:%d\n", Fibonacci(4));
    printf("5:%d\n", Fibonacci(5));
    printf("6:%d\n\n", Fibonacci(6));
    
    printf("jumpFloor\n");
    printf("0:%d\n", jumpFloor(0));
    printf("1:%d\n", jumpFloor(1));
    printf("2:%d\n", jumpFloor(2));
    printf("3:%d\n", jumpFloor(3));
    printf("4:%d\n\n", jumpFloor(4));
    
    printf("jumpFloorII\n");
    printf("1:%d\n", jumpFloorII(1));
    printf("2:%d\n", jumpFloorII(2));
    printf("3:%d\n\n", jumpFloorII(3));
    
    printf("rectCover\n");
    printf("1:%d\n", rectCover(1));
    printf("2:%d\n", rectCover(2));
    printf("3:%d\n", rectCover(3));
    printf("4:%d\n", rectCover(4));
    printf("5:%d\n", rectCover(5));
    printf("6:%d\n\n", rectCover(6));
    
    
}
