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
vector<vb> S(9, vb(9, false));
vector<pll> P;
bool check(ll x)
{
    return (x >= 0 && x < 9);
}
ll solver()
{
    ll ans = 0;
    for (ll i = 0; i < P.size(); i++)
    {
        for (ll j = 0; j < P.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            ll x1 = P[i].first;
            ll y1 = P[i].second;
            ll x2 = P[j].first;
            ll y2 = P[j].second;
            ll dx = x2 - x1, dy = y2 - y1;
            ll x3a = x2 - dy, y3a = y2 + dx;
            ll x3b = x2 + dy, y3b = y2 - dx;
            ll x4a = x3a - dx, y4a = y3a - dy;
            ll x4b = x3b - dx, y4b = y3b - dy;
            if (check(x3a) && check(y3a) && check(x4a) && check(y4a) && S[x3a][y3a] && S[x4a][y4a])
            {
                ++ans;
            }
            if (check(x3b) && check(y3b) && check(x4b) && check(y4b) && S[x3b][y3b] && S[x4b][y4b])
            {
                ++ans;
            }
        }
    }
    return ans / 8;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    for (ll i = 0; i < 9; i++)
    {
        for (ll j = 0; j < 9; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                S[i][j] = true;
                P.emplace_back(i, j);
            }
        }
    }
    cout << solver() << endl;
}