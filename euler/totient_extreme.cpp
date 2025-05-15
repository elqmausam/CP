#include <iostream>
using namespace std;

const int mx = 1e6 + 1;
typedef long long ll;

ll phi[mx], phi_sum[mx];


void compute_totient() {
    for (int i = 1; i < mx; i++) {
        phi[i] = i;
    }

    for (int p = 2; p < mx; p++) {
        if (phi[p] == p) {
            for (int i = p; i < mx; i += p) {
                phi[i] = (phi[i] / p) * (p - 1);
            }
        }
    }

   
    for (int i = 1; i < mx; i++) {
        phi_sum[i] = phi_sum[i - 1] + phi[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute_totient();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        ll sum_phi = phi_sum[n];
        ll H = sum_phi * sum_phi;
        cout << H << '\n';
    }

    return 0;
}
