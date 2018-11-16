//
//  12 PrintOneToMaxNDigits.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/29.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"
#include <cstring>


void printNumbers(char* numbers) {
    
    long nonZeroIndex = -1;
    long len = strlen(numbers);
    for (long i = 0; i < len; i++) {
        if (numbers[i] != '0') {
            nonZeroIndex = i;
            break;
        }
    }
    //    sleep(1e5);
    if (nonZeroIndex != -1) {
        printf("%s\n", numbers + nonZeroIndex);
    }
    
}


// MARK: - Iteratively

bool incrementNumbers(char* numbers) {
    
    long length = strlen(numbers);
    long index = length - 1;
    int carry = 0;
    
    for (; index >= 0; index--) {
        int sum = numbers[index] - '0' + carry;
        // 最后一位加1
        if (index == length - 1) {
            sum++;
        }
        carry = sum / 10;
        
        if (carry > 0) {
            if (index == 0) {
                // 要在第一位进行进位，已经是最大数字
                return false;
            }
            // 计算后续的进位
            sum %= 10;
            numbers[index] = sum + '0';
        }else{
            // 不进位，计算结束
            numbers[index] = sum + '0';
            break;
        }
    }
    
    return true;
}


/**
 打印从1到最大N位数的递增排列 （循环）

 @param n N位数
 */
void printOneToMaxNDigits(int n) {

    if (n <= 0) {
        return;
    }

    char* numbers = new char[n + 1];
    memset(numbers, '0', sizeof(char) * n);
    numbers[n] = '\0';

    while (incrementNumbers(numbers)) {
        printNumbers(numbers);
    }

    delete []numbers;

}


// MARK: - Recusively

void incrementAndPrintNumber(char* numbers, int len, int index) {
    
    if (index == len) {
        printNumbers(numbers);
        return;
    }
    
    for (int i = 0; i < 10; i++) {
        numbers[index] = i + '0';
        incrementAndPrintNumber(numbers, len, index + 1);
    }
    
}

/**
 打印从1到最大N位数的递增排列 （递归）
 
 @param n N位数
 */
void printOneToMaxNDigitsRecursively(int n) {
    
    if (n <= 0) {
        return;
    }
    
    char* numbers = new char[n + 1];
    memset(numbers, '0', sizeof(char) * n);
    numbers[n] = '\0';
    
    incrementAndPrintNumber(numbers, n, 0);
    
    delete []numbers;
}


// MARK: - Test

void Solution::testPrintOneToMaxNDigits() {
    
//    printOneToMaxNDigits(-1);
//    printOneToMaxNDigits(0);
//
//    printOneToMaxNDigits(3);
//    printOneToMaxNDigits(11);
    
    printOneToMaxNDigitsRecursively(-1);
    printOneToMaxNDigitsRecursively(0);
    
    printOneToMaxNDigitsRecursively(3);
}
