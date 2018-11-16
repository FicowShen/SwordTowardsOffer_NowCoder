//
//  1 Find.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/24.
//  Copyright © 2018 ficow. All rights reserved.
//

#include "Solution.hpp"


/**
 找出二维数组(从左至右递增、从上至下递增)中是否存在某个值

 @param target 要寻找的目标值
 @param array 二维数组
 @return 二维数组中是否存在目标值
 */
bool Find(int target, vector<vector<int>> array) {
    
    long rows = array.size();
    // no row
    if (rows <= 0) { return false; }
    
    long cols = array[0].size();
    // no column
    if (cols <= 0) { return false; }
    
    long row = 0, col = cols - 1;
    while (col >= 0 && row < rows) {
        if (target == array[row][col]) {
            return true;
        }
        if (target < array[row][col]) {
            col--;
        }else{
            row++;
        }
    }
    
    return false;
}

void Solution::testFind() {
    
    vector<vector<int>> v = {};
    bool res = Find(7, v);
    cout << "res: " << res << endl;
    
    v = {{1,5,9}};
    res = Find(7, v);
    cout << "res: " << res << endl;
    
    v = {{1,5,9}, {2,6,10}, {3,7,14}};
    res = Find(7, v);
    cout << "res: " << res << endl;
    
    res = Find(0, v);
    cout << "res: " << res << endl;
    
    res = Find(15, v);
    cout << "res: " << res << endl;
    
    
    v = {{1,2,8,9}, {4,7,10,13}};
    res = Find(7, v);
    cout << "res: " << res << endl;
    
    
    v = {{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
    res = Find(1, v);
    cout << "res: " << res << endl;
}


