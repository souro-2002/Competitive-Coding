#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10,MOD=998244353;
vector<int> fac(N),finv(N),inv(N);
int C(int x, int y){
    if (x < 0 || y > x) return 0;
    return fac[x] * finv[y] % MOD * finv[x - y] % MOD;
}
signed main(){
    fac[0] = inv[0] = inv[1] = finv[0] = finv[1] = 1;
    for (int i = 1; i <= N; ++i)
        fac[i] = fac[i - 1] * i % MOD;
    for (int i = 2; i <= N; ++i)
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    for (int i = 2; i <= N; ++i)
        finv[i] = finv[i - 1] * inv[i] % MOD;
    int T;
    cin >> T;
    while (T--){
        int n, x, ct0 = 0, ct1 = 0, t = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> x;
            ct0 += (x == 0);
            ct1 += (x == 1);
        }
        for (int i = 0; i <= ct1; ++i)
            t = (t + i * C(ct1 + ct0 - i, ct0)) % MOD;
        cout << (((t * (ct0 + 1) - C(ct1 + ct0 - 2, ct0 - 1)) % MOD + MOD) % MOD + C(ct1 + ct0 - 2, ct0 - 1)) * fac[ct1] % MOD * fac[ct0] % MOD << endl;
    }
}
