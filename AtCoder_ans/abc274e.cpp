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
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }
void error()
{
    for (ll i = 0; i < 1000000000000000; i++)
    {
        cout << "Error\n";
    }
}
ll N, M, W;
vl X, Y, P, Q;
void solver()
{
    ll W2 = 1 << W;
    vd r(W2, 1);
    for (ll i = 0; i < W2; i++)
    {
        for (ll j = 0; j < M; j++)
        {
            if ((i >> (N + j)) & 1)
            {
                r[i] *= 2;
            }
        }
    }
    vector<vd> dp(W2, vd(W, INFTY));

    dp[0][W - 1] = 0;
    vb v(W);
    for (ll i = 0; i < W2; i++)
    {

        for (ll j = 0; j < W; j++)
        {
            if (dp[i][j] == INFTY)
            {
                continue;
            }
            for (ll k = 0; k < W; k++)
            {
                if (((i >> k) & 1) == 0)
                {
                    auto d = [&]() -> double
                    {
                        ll dx = X[j] - X[k];
                        ll dy = Y[j] - Y[k];
                        return sqrt(dx * dx + dy * dy) / r[i];
                    };
                    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + d());
                }
            }
        }
    }
    double ans = INFTY;
    ll t = ((1 << N) - 1) | (1 << (W - 1));
    for (ll i = 0; i < W2; i++)
    {

        if ((i & t) == t)
        {
            ans = min(ans, dp[i][W - 1]);
        }
    }
    cout << fixed;
    cout << setprecision(6) << ans << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    W = N + M + 1;
    X.resize(W);
    Y.resize(W);
    for (ll i = 0; i < N + M; i++)
    {
        cin >> X[i] >> Y[i];
    }
    X[W - 1] = 0;
    Y[W - 1] = 0;
    solver();
}