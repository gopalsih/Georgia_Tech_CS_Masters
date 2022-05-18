
#ifndef DYNAMICPROGRAMMMING_H
#define DYNAMICPROGRAMMMING_H

#include <vector>
#include <string>
using namespace std;
template <typename T> 
class DynamicProgramming {
public:
    int LIS(vector<T> input);
    int LCS(string input1, string input2);

};

#endif