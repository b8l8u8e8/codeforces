#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long INV2 = (MOD + 1) / 2;   // 2 的乘法逆元

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    if (!(cin >> N)) return 0;

    __int128 sum_q = 0;
    long long l = 2;
    while (l <= N) {
        long long t = N / l;
        long long r = N / t;          // 最大 b s.t. floor(N/b)=t
        if (r > N) r = N;
        sum_q += (__int128)t * (r - l + 1);
        l = r + 1;
    }

    long long part1 = ( (__int128)(N % MOD) * ((N - 1) % MOD) ) % MOD;
    part1 = (part1 * INV2) % MOD;

    long long part2 = (long long)(sum_q % MOD);

    long long ans = (part1 - part2) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
    return 0;
}
