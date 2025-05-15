// leetcode problem - 372.super pow

class Solution {
public:
    const int MOD = 1337;
    const int PHI_MOD = 1140; 

    
    int modPow(int a, int b, int mod) {
        int result = 1;
        a %= mod;
        while (b > 0) {
            if (b & 1) result = (result * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }

  
    int modB(const vector<int>& b, int m) {
        int result = 0;
        for (int digit : b) {
            result = (result * 10 + digit) % m;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        int reducedExp = modB(b, PHI_MOD);
        
        if (__gcd(a, MOD) != 1) {
            reducedExp += PHI_MOD;
        }
        return modPow(a, reducedExp, MOD);
    }
};
