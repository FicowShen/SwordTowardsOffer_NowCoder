//
//  20 PrintMatrixClockwise.cpp
//  NowCoder
//
//  Created by Ficow on 2018/11/5.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"


/**
 顺时针打印矩阵

 @param matrix 二维矩阵
 @return 顺时针打印后的矩阵
 */
vector<int> printMatrix(vector<vector<int> > matrix) {
    
    vector<int> result;
    
    if (matrix.empty()) {
        return result;
    }
    
    long circle = 0;
    long rows = matrix.size(), cols = matrix[0].size();
    
    while (rows > circle * 2 && cols > circle * 2) {

        long x = circle, y = circle;
        long endX = cols - circle - 1, endY = rows - circle - 1;
        
        for (; x <= endX; x++) { // 右移
            result.push_back(matrix[y][x]);
        }
        if (circle < endY) { // 下移，开始行小于结束行
            x = endX;
            y++;
            for (; y <= endY; y++) {
                result.push_back(matrix[y][x]);
            }
        }
        if (circle < endX && circle < endY) { // 左移，开始行小于结束行，且开始列小于结束列
            x--;
            y = endY;
            for ( ;x >= circle; x--) {
                result.push_back(matrix[y][x]);
            }
        }
        if (circle < endX && circle < endY) { // 上移，开始行小于结束行，且开始列小于结束列
            y--;
            x = circle;
            for ( ; y > circle; y--) {
                result.push_back(matrix[y][x]);
            }
        }
        
        circle++; // 新的一圈
//        printf("circle=%d\n", circle);
    }
    
    return result;
}

void print(vector<int> matrix) {
    
    re(i, matrix.size()) {
        printf("%d,", matrix[i]);
    }
    printf("\n\n");
}
void Solution::testPintMatrix() {
    
    vector<int> l1 = {1,2};
    vector<int> l2 = {3,4};
    // 1,2,4,3
    printf("1,2,4,3\n");
    print(printMatrix({l1,l2}));
    
    l1 = {1,2,3};
    l2 = {4,5,6};
    // 1,2,3,6,5,4
    printf("1,2,3,6,5,4\n");
    print(printMatrix({l1,l2}));
    
                l1 = {1,2};
                l2 = {3,4};
    vector<int> l3 = {5,6};
    // 1,2,4,6,5,3
    printf("1,2,4,6,5,3\n");
    print(printMatrix({l1,l2,l3}));
    
    l1 = {1,2,3};
    l2 = {4,5,6};
    l3 = {7,8,9};
    // 1,2,3,6,9,8,7,4,5
    printf("1,2,3,6,9,8,7,4,5\n");
    print(printMatrix({l1,l2,l3}));

    l1 = {1, 2, 3, 4};
    l2 = {5, 6, 7, 8};
    l3 = {9,10,11,12};
    // 1,2,3,4,8,12,11,10,9,5,6,7
    printf("1,2,3,4,8,12,11,10,9,5,6,7\n");
    print(printMatrix({l1,l2,l3}));
    
                l1 = {1, 2, 3};
                l2 = {4, 5, 6};
                l3 = {7, 8, 9};
    vector<int> l4 = {10,11,12};
    // 1,2,3,6,9,12,11,10,7,4,5,8
    printf("1,2,3,6,9,12,11,10,7,4,5,8\n");
    print(printMatrix({l1,l2,l3,l4}));
    
    l1 = {1, 2, 3, 4};
    l2 = {5, 6, 7, 8};
    l3 = {9, 10,11,12};
    l4 = {13,14,15,16};
    printf("1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10\n");
    print(printMatrix({l1,l2,l3,l4}));
    
}
