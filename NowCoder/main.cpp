//
//  main.cpp
//  NowCoder
//
//  Created by Ficow on 2018/10/24.
//  Copyright © 2018 ficow. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include "Solution.hpp"
#include "TestOperators/TestOperators.hpp"

using namespace std;


//#define REOPEN
//#define FOPEN

const char *ProjectPath = "/Users/ficow/Desktop/Projects/NowCoder/NowCoder/";


int main(int argc, const char * argv[]) {

    char inputPath[200], outputPath[200];
    
    strcpy(inputPath, ProjectPath);
    strcat(inputPath, "in.txt");
    
    strcpy(outputPath, ProjectPath);
    strcat(outputPath, "out.txt");
    
#ifdef FOPEN

    FILE *fin, *fout;
    
    fin = fopen(inputPath, "rb");
    fout = fopen(outputPath, "wb");

    int x;
    fprintf(fout, "FOPEN\n");
    while (fscanf(fin, "%d", &x) == 1) {
        fprintf(fout, "%d\n", x);
    }

    fclose(fin);
    fclose(fout);

#else

    #ifdef REOPEN
        printf("inputPath:\n%s\n", inputPath);
        printf("outputPath:\n%s\n\n", outputPath);
        freopen(inputPath, "r", stdin);
        freopen(outputPath, "w", stdout);
    #endif

#endif

    Solution s = Solution();
    
    s.testCharPermutationInString();
    
    return 0;
}
