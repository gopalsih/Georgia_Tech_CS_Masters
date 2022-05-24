#include "modern_cpp_lib/DynamicProgramming.h"
#include <iostream>
#include <algorithm>    // std::max
#include <cstdlib> 
#include <string.h>

using namespace std;
/*
* Notes:
* Subproblem: L[i] = max length on the ith sample {a1,a2....ai} 0<= i <= n
* Recurrence Relationship : L[i] =   { 
                                    1 + max{L1, L2 .....Lj}, a[i] > a[j]
                                    1 if a[i] < a[j]
                                } 
*/
template <typename T>
int DynamicProgramming<T>::LIS(vector<T> input) {
    if (input.size() == 0) {
        return 0;
    }
    if (input.size() == 1) {
        return 1;
    }

    vector<int> lengthTable = {0};
    lengthTable[0] = 1;

    for (int i = 1; i < input.size(); i++) {
        int maxSubLen = 0;
        for (int j = 0; j < i; j++) {
            if ((input[i] > input[j]) && (maxSubLen < lengthTable[j])) {
                maxSubLen = lengthTable[j];
            }
        }
        lengthTable.push_back(maxSubLen + 1);
    }
    int ret = 0;
    for (int i = 0; i < lengthTable.size(); i++) {
        if (ret < lengthTable[i]) {
            ret = lengthTable[i];
        }
    }
    return ret;
}

/*
* Notes:
* Subproblem: L[i, j] = length of LCS in X1....Xi Y1.....Yj 
* Recurrence Relationship : L[i,j] =   { 
                                    max {L[i-1, j], L[i, j-1]} if X[i] != Y[j]
                                    1 + max{L[i-1, j-1]} if X[i] = Y[j]
                                } 
*/


template <>
int DynamicProgramming<string>::LCS(string input1, string input2) {
    int string1Size =  input1.size();
    int string2Size  = input2.size();

    const char * input1String =  input1.c_str();
    const char * input2String =  input2.c_str();

    if ((string1Size == 0) || (string2Size == 0)) {
        return 0;
    }

    int dpTable[string1Size + 1][string2Size + 1] = {0}; // +1 for intial condition of the algorithm
    memset(dpTable, 0, sizeof(dpTable));

    for (int i = 1; i < string1Size + 1; i++) {
        for (int j =  1; j < string2Size + 1; j++) {
            if (input1String[i-1] == input2String[j-1]) {
                dpTable[i][j] = 1 + dpTable[i-1][j-1]; 
                //printf("dp[%d][%d]: %d\n", i, j, dpTable[i][j]);     
            } else {
                dpTable[i][j] = dpTable[i][j-1];
                if (dpTable[i][j-1] < dpTable[i-1][j]) {
                    dpTable[i][j] = dpTable[i-1][j];
                    //printf("dp[%d][%d]: %d\n", i, j, dpTable[i][j]);
                }
            }
        }
    }
    return dpTable[string1Size][string2Size];
}


/*
* Notes: KnapSack propblem (no repeats)
* Subproblem: k(i,b) where it's the max value for items 1->i and b < B (max limit)
* Recurrence Relationship : k(i,b) = {
                                        max{k(i-1,b) , vi + k(i, b-wi)} , wi < b
                                        i.e max if we include ith object or not
                                        }
*/
template <>
int DynamicProgramming<int>::KnapSackNoRecurrence(vector<pair<int,int>> input, int weightLimit) {
    if (input.size() == 0) {
        return 0;
    }
    if (input.size() == 1) {
        return 1;
    }

    int dpTable[input.size() + 1][weightLimit + 1] = {0};
    memset(dpTable, 0 , sizeof(dpTable));

    for (int i = 1; i < input.size() + 1; i++) {
        for (int j = 1; j < weightLimit + 1; j++) {
            if (input[i-1].second <= weightLimit) {
                dpTable[i][j] = max(dpTable[i-1][j], input[i-1].first + dpTable[i-1][j-input[i-1].second]);
            }
         }
    }

    return dpTable[input.size()][weightLimit];
}

template class DynamicProgramming<int>;