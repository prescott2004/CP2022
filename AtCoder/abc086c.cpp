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
ll N;
vl t, x, y;
bool solve()
{
    ll dt, dx, dy;
    for (ll i = 0; i < N; i++)
    {
        dt = t[i + 1] - t[i];
        dx = x[i + 1] - x[i];
        dy = y[i + 1] - y[i];
        if (abs(dx) + abs(dy) > dt)
        {
            return false;
        }
        else if (((dt - abs(dx) - abs(dy)) & 1) == 1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    t.resize(N + 1);
    x.resize(N + 1);
    y.resize(N + 1);
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for (ll i = 0; i < N; i++)
    {
        cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
    }
    bool ans = solve();
    if (ans)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}