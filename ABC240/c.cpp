#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using mld = map<ll, double>;
using mls = map<ll, string>;
using mlb = map<ll, bool>;
using sl = set<ll>;
using sd = set<double>;
using ss = set<string>;
using pll = pair<ll, ll>;
using pls = pair<ll, string>;
using pld = pair<ll, double>;
using plb = pair<ll, bool>;
template <class T>
using pque = priority_queue<T>;
const ll INFTY = 1L << 62L;
ll N, X;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> X;
    vl a(N), b(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }
    vector<vl> DP(N + 1, vl(X + 1, 0));
    DP[0][0] = 1;
    for (ll i = 0; i < N; i++)
    {
        // i+1回目のジャンプで到達できる点にチェック
        for (ll j = 0; j < X + 1; j++)
        {
            if (j - a[i] >= 0)
            {
                DP[i + 1][j] = max(DP[i + 1][j], DP[i][j - a[i]]);
            }
            if (j - b[i] >= 0)
            {
                DP[i + 1][j] = max(DP[i + 1][j], DP[i][j - b[i]]);
            }
        }
    }
    if (DP[N][X])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}