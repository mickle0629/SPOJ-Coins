#include <math.h>
#include <map>
#include <iostream>
#include <vector>
#include <string>

long long exchangeCoins(long long val, std::map<long long, long long> &dp) {
    if (val < 12) {
        dp[val] = val;
        return val;
    }

    // Check if val already has an pre-computed exchange rate in the dp table:
    if (dp.find(val) != dp.end()) {
        return dp[val];
    }
    
    // If current val is not pre-computed, then perform an exchange on said value
    int half = exchangeCoins(floor(val / 2), dp);
    int third = exchangeCoins(floor(val / 3), dp);
    int fourth = exchangeCoins(floor(val / 4), dp);
    return half + third + fourth;
}

int convertCoins(long long val) {
    std::map<long long, long long> dp;
    return exchangeCoins(val, dp);
}

int main() {
    long long n;
    std::vector<long long> results;
    while (std::cin >> n) {
        //results.push_back(convertCoins(n));
        std::cout << convertCoins(n) << std::endl;
    }
/* 
    for (long long result : results) {
        std::cout << result << std::endl;
    } */
    return 0;
}