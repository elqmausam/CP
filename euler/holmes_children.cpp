// Codeforces - The Holmes Children

#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;


ll phi(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


ll g(ll n) {
    ll res = 0;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res += phi(i);
            if (i != n / i)
                res += phi(n / i);
        }
    }
    return res;
}


ll compute_Fk(ll n, ll k) {
    while (k--) {
        if (n == 1)
            return 1;
        n = phi(g(n));
    }
    return n % MOD;
}

int main() {
    ll n, k;
    cin >> n >> k;
    cout << compute_Fk(n, k) << endl;
    return 0;
}
