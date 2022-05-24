#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "modern_cpp_lib/DynamicProgramming.h"
#include <fstream>
#include <iostream>
#define  DYNAMIC_PROGRAMMING_TEST

#ifdef DYNAMIC_PROGRAMMING_TEST

TEST_CASE("LIS Test", "[main]") {
   
    std::vector<int> input = {5,7,1,8,9,10};
    std::vector<int> input2 = {5,1,8,9,10};
    std::vector<int> input3 = {0};
    std::vector<int> input4;
    DynamicProgramming<int> DP;
    int returnVal = 0;
    returnVal = DP.LIS(input);
    REQUIRE(returnVal == 5);
    returnVal = DP.LIS(input2);
    REQUIRE(returnVal == 4);
    returnVal = DP.LIS(input3);
    REQUIRE(returnVal == 1);
    returnVal = DP.LIS(input4);
    REQUIRE(returnVal == 0);
    //printf("Output for LIS is %d", returnVal);
}

TEST_CASE("LCS Test", "[main]") {
    DynamicProgramming<string> DP;
    int returnVal = 0;

    string string1 = "abc";
    string string2  = "abd";
    returnVal = DP.LCS(string1,string2);
    REQUIRE(returnVal == 2);

    string string3 = "bcdbcda";
    string string4  = "abecba";
    returnVal = DP.LCS(string3,string4);
    REQUIRE(returnVal == 4);

    printf("Output for LCS is %d", returnVal);
}

TEST_CASE("Knapsack Test", "[main]") {
    DynamicProgramming<int> DP;
    int returnVal = 0;

    pair<int, int> p1(10,1);
    pair<int, int> p2(20,1);
    pair<int, int> p3(10,2);

    vector<pair<int,int>> vect;
    vect.push_back(p1);
    vect.push_back(p2);
    vect.push_back(p3);

    returnVal = DP.KnapSackNoRecurrence(vect, 4);
    REQUIRE(returnVal == 40);

    printf("return value is %d", returnVal);

}
#endif