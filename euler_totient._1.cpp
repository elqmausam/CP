#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_PRIME = 1000000;
vector<bool> is_prime(MAX_PRIME + 1);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_PRIME; ++i) is_prime[i] = true;

    for (int i = 2; i * i <= MAX_PRIME; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_PRIME; j += i) {
                is_prime[j] = false;
            }
        }
    }
}


int phi(int n) {
    if (n == 0) return 0;
    int result = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> dishes(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> dishes[i];

    sieve(); 

    
    vector<int> prime_sweet(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int sweetness = phi(dishes[i]);
        if (sweetness <= MAX_PRIME && is_prime[sweetness])
            prime_sweet[i] = 1;
    }

    
    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefix[i] = prefix[i - 1] + prime_sweet[i];
    }

    
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << (prefix[r] - prefix[l - 1]) << '\n';
    }

    return 0;
}
