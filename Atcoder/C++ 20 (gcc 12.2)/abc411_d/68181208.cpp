#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    struct Query {
        int type, p;
        string s;  // 仅 type==2 时用
    };
    vector<Query> qs(Q);
    for (int i = 0; i < Q; i++) {
        cin >> qs[i].type >> qs[i].p;
        if (qs[i].type == 2)
            cin >> qs[i].s;
    }

    // need[0] 表示「需要 server」，need[1..N] 表示「需要 PC1..PCN」
    vector<char> need(N+1, 0);
    need[0] = 1;  // 一开始我们要最终的 server

    vector<string> segments;  // 倒序收集要输出的 append 片段

    // 倒序扫描
    for (int i = Q-1; i >= 0; i--) {
        auto &q = qs[i];
        if (q.type == 3) {
            // 3 p: server <- PC[p]
            if (need[0]) {
                need[q.p] = 1;
                need[0] = 0;
            }
        }
        else if (q.type == 1) {
            // 1 p: PC[p] <- server
            if (need[q.p]) {
                need[0] = 1;
                need[q.p] = 0;
            }
        }
        else {
            // 2 p s: PC[p] append s
            if (need[q.p]) {
                segments.push_back(q.s);
                // need[q.p] 保持为 true，表示还要它前一刻的状态
            }
        }
    }

    // 现在 segments 是倒序，把它反过来再拼输出
    for (int i = (int)segments.size()-1; i >= 0; i--) {
        cout << segments[i];
    }
    cout << "\n";
    return 0;
}
