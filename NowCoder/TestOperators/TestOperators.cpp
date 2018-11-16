//
//  TestOperators.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/27.
//  Copyright © 2018 ficow. All rights reserved.
//

#include <iostream>
#include "TestOperators.hpp"

using namespace std;

void testDivide() {
    
    for (int i = 0; i < 1e7; i++) {
        int j = i;
        while (j) {
            j /= 2;
        }
    }
}

void testBinaryMove() {
    for (int i = 0; i < 1e7; i++) {
        int j = i;
        while (j) {
            j >>= 1;
        }
    }
}

void testMod() {
    
    for (int i = 0; i < 1e8; i++) {
        if (i % 2 == 0) {

        }
    }
}

void testBinaryAnd() {
    for (int i = 0; i < 1e8; i++) {
        if ((i & 1) == 0) {

        }
    }
}


/**
 比较除法、按位右移的效率；比较模运算和二进制与e的效率；
 */
void testOperators() {
    
    double start = clock();
    testDivide();
    printf("testDivide:%.5f\n", double(clock() - start) / CLOCKS_PER_SEC);
    
    start = clock();
    testBinaryMove();
    printf("testBinaryMove:%.5f\n", double(clock() - start) / CLOCKS_PER_SEC);
    
    printf("-----\n");
    
    start = clock();
    testMod();
    printf("testMod:%.5f\n", double(clock() - start) / CLOCKS_PER_SEC);
    
    start = clock();
    testBinaryAnd();
    printf("testBinaryAnd:%.5f\n", double(clock() - start) / CLOCKS_PER_SEC);
    
}
