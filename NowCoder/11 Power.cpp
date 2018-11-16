//
//  Power.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/28.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"

/**
 实现库函数pow的功能

 @param base 基数
 @param exponent 指数
 @return 计算结果
 */
double Power(double base, int exponent) {
    
    bool isZero = base > -1e-6 && base < 1e-6;
    if (isZero && exponent < 0) {
        return 0;
    }
    
    bool isNegative = false;
    if (exponent == 0) {
        return 1;
    } else if (exponent == 1) {
        return base;
    } else if (exponent < 0) {
        isNegative = true;
        exponent = -exponent;
    }
    
    double result = 1;
    // 使用快速幂进行求解，去除多余的重复计算
//    printf("\n");
    while (exponent > 0) {
        
        if (exponent % 2 == 1) {
            result *= base;
//            printf(" (%lf) ", result);
        }
//        printf(" %d", exponent);
        base *= base;
        exponent >>= 1;
    }
//    printf("\n");
    
    if (isNegative) {
        return 1.0 / result;
    }
    
    return result;
    
    //// bad algorithm
    //    double result = 1;
    //    for (int i = 0; i < exponent; i++) {
    //        result *= base;
    //    }
//    return result;
}

void Solution::testPower() {
    
    printf("Power(2, 2)=%lf\n", Power(2, 2));
    printf("Power(2, 5)=%lf\n", Power(2, 5));
    printf("Power(2, 10)=%lf\n", Power(2, 10));
    printf("Power(2, 16)=%lf\n\n", Power(2, 16));

    printf("Power(0, -1)=%lf\n", Power(0, -1));
    printf("Power(2, -5)=%lf\n", Power(2, -5));
    printf("Power(-2, -5)=%lf\n", Power(-2, -5));
    printf("Power(-2, -6)=%lf\n", Power(-2, -6));
    
}
