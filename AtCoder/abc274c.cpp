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
ll N;
ll a;
mll M;
void solver()
{
    vl ans(2 * N + 2, -1);
    ans[1] = 0;
    queue<ll> Q;
    Q.emplace(1);
    while (!Q.empty())
    {
        ll p = Q.front();
        Q.pop();
        auto _ip = M.find(p);
        if (_ip != M.end())
        {
            ll np = 2 * _ip->second;
            ans[np] = ans[p] + 1;
            ans[np + 1] = ans[p] + 1;
            Q.emplace(np);
            Q.emplace(np + 1);
        }
    }
    for (ll i = 1; i < 2 * N + 2; i++)
    {
        cout << ans[i] << endl;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for (ll i = 0; i < N; i++)
    {
        cin >> a;
        M[a] = i + 1;
    }
    solver();
}