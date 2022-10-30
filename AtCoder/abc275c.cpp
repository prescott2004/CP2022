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
vector<pll> e;
ll d(ll ax, ll ay, ll bx, ll by)
{
    return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}
ll solver()
{
    ll cnt = 0;
    for (ll i = 0; i < e.size(); i++)
    {
        for (ll j = i + 1; j < e.size(); j++)
        {
            for (ll k = j + 1; k < e.size(); k++)
            {
                for (ll l = k + 1; l < e.size(); l++)
                {
                    vl v = {i, j, k, l};
                    vl ans;
                    for (ll vi = 0; vi < 4; vi++)
                    {
                        for (ll vj = vi + 1; vj < 4; vj++)
                        {
                            ans.emplace_back(d(e[v[vi]].first, e[v[vi]].second, e[v[vj]].first, e[v[vj]].second));
                        }
                    }
                    sort(ans.begin(), ans.end());
                    if (ans[0] == ans[1] && ans[1] == ans[2] && ans[2] == ans[3] && ans[4] == ans[0] * 2 && ans[5] == ans[0] * 2)
                    {
                        ++cnt;
                    }
                }
            }
        }
    }
    return cnt;
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
                e.emplace_back(i, j);
            }
        }
    }
    cout << solver() << endl;
}