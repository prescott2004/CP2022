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
ll N, S;
vl a, b;
vector<vb> DP;
ll MAX = 10000;
void solver()
{
    DP[0][0] = true;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < MAX + 1; j++)
        {
            if (j >= a[i] && DP[i][j - a[i]])
            {
                DP[i + 1][j] = true;
            }
            if (j >= b[i] && DP[i][j - b[i]])
            {
                DP[i + 1][j] = true;
            }
        }
    }
    if (DP[N][S])
    {
        yes();
        vector<char> ans(N);
        ll s = S;
        for (ll i = N - 1; i > -1; i--)
        {
            if (s >= a[i] && DP[i][s - a[i]])
            {
                s -= a[i];
                ans[i] = 'H';
            }
            else if (s >= b[i] && DP[i][s - b[i]])
            {
                s -= b[i];
                ans[i] = 'T';
            }
        }
        for (ll i = 0; i < N; i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    else
    {
        no();
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> S;
    a.resize(N);
    b.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }

    DP.resize(N + 1, vb(MAX + 1, false));
    solver();
}