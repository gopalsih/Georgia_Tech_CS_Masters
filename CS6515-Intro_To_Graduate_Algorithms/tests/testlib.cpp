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
    printf("Output is %d", returnVal);
}
#endif