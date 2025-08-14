#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

// 快速幂: 计算 a^e % MOD
ll modpow(ll a, ll e) {
    ll r = 1;
    a %= MOD;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 读入 N 个骰子，每个 6 个面
    vector<array<int,6>> A(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> A[i][j];
        }
    }

    // 1) 收集所有面值，排序去重，得到阈值列表 S
    vector<ll> S;
    S.reserve(6ll * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            S.push_back(A[i][j]);
        }
    }
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    int K = S.size();

    // 2) 预处理：对于每个阈值 S[idx]，记录“哪些骰子有面恰好等于它”
    vector<vector<int>> upd(K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            int idx = lower_bound(S.begin(), S.end(), A[i][j]) - S.begin();
            upd[idx].push_back(i);
        }
    }

    // 3) 预compute 6 的逆元(inv6) 及 inv(6^N) = inv6^N
    ll inv6 = modpow(6, MOD - 2);
    ll inv6n = modpow(inv6, N);

    // 4) 准备扫描阈值所需的状态
    vector<int> b(N, 0);    // b[i] = 骰子 i 目前“纳入”的面数
    int zero_cnt = N;       // 还有多少个 b[i]==0
    ll prod = 1;            // prod = ∏ b[i] （只当 zero_cnt==0 时才有意义）
    
    ll ans = 0;             // 最终答案 E[max]
    ll prevS = 0;           // 上一个阈值 S_{i-1}

    // 5) 依次遍历每个阈值 S[idx]
    for (int idx = 0; idx < K; idx++) {
        ll curS = S[idx];

        // ---- 5.1 累加当前区间 [prevS, curS) 的“面积”贡献 ----
        ll width = (curS - prevS) % MOD;       // 区间宽度
        ll G = 0;                              // G = Pr(max < curS)
        if (zero_cnt == 0) {
            // 只有当所有骰子至少有一面被纳入时，才计算 ∏ b[i] / 6^N
            G = prod * inv6n % MOD;
        }
        ll p_ge = (1 - G + MOD) % MOD;         // Pr(max ≥ curS)
        ans = (ans + width * p_ge) % MOD;

        // ---- 5.2 增量更新：把所有等于 curS 的面“纳入” ----
        for (int die : upd[idx]) {
            if (b[die] == 0) {
                // 第一次让这个骰子参与 prod
                zero_cnt--;
                b[die] = 1;
                // prod *= 1 (没变)
            } else {
                // 先把旧的 b[die] 从 prod 中“除掉”，再加 1 后“乘”回去
                // 除法用乘以逆元
                prod = prod * modpow(b[die], MOD - 2) % MOD;
                b[die]++;
                prod = prod * b[die] % MOD;
            }
        }

        prevS = curS;
    }

    // 输出结果
    cout << ans << "\n";
    return 0;
}
