#include "modern_cpp_lib/DynamicProgramming.h"
#include <iostream>
#include <cstdlib> 

using namespace std;
template <typename T>

/*
* Notes:
* Subproblem: L[i] = max length on{a1,a2....an}
* Repetitive Problem : L[i] =   { 
                                    1 + max{L1, L2 .....Lj}, a[i] > a[j]
                                    1 if a[i] < a[j]
                                } 
*/
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

template class DynamicProgramming<int>;