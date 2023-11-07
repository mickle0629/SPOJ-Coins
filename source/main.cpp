#include <math.h>
#include <map>
#include <iostream>
#include <string>

int exchangeCoins(int val, std::map<int, int> &dp) {
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

int convertCoins(int val) {
    std::map<int, int> dp;
    return exchangeCoins(val, dp);
}

int main() {
    int coin = 100;
    std::cout << "Exchanging " << coin << ": " << convertCoins(coin) << std::endl;
    return 0;
}