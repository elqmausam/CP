#include <iostream>
using namespace std;
 
const int mx = 1e5 + 5;
typedef long long ll;
 
ll phi[mx], phi_sum[mx];
 
void compute_totient() {
    for (int i = 0; i < mx; ++i)
        phi[i] = i;
 
    for (int i = 2; i < mx; ++i) {
        if (phi[i] == i) {
            for (int j = i; j < mx; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
 
    
    for (int i = 1; i < mx; ++i) {
        phi_sum[i] = phi_sum[i - 1] + phi[i];
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    compute_totient();
 
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; ++cs) {
        int n;
        cin >> n;
 
        
        ll total_pairs = (1LL * n * (n + 1)) / 2;
 
        
        ll ans = total_pairs - phi_sum[n];
        cout << "Case " << cs << ": " << ans << '\n';
    }
 
    return 0;
}
