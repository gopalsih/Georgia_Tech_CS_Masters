#include "modern_cpp_lib/DynamicProgramming.h"
#include <iostream>
#include <cstdlib> 

using namespace std;
/*
* Notes:
* Subproblem: L[i] = max length on{a1,a2....an}
* Repetitive Problem : L[i] =   { 
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
* Subproblem: L[i] = max length for common s1:a1...ai | s2:b1....bj 
* Repetitive Problem : L[i] =   { 
                                    1 + max{L1, L2 .....Lj}, a[i] > a[j]
                                    1 if a[i] < a[j]
                                } 
*/
template <>
int DynamicProgramming<string>::LCS(string input1, string input2) {

}



template class DynamicProgramming<int>;