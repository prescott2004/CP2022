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
ll H, W, N;
ll r0, c0;
ll Q;
vl ar, ac;
vector<char> ad;
vl al;
map<ll, sl> sr, sc;

ll left(ll r, ll c, ll times)
{
    sl &m = sr[r];
    auto _p = m.lower_bound(c);
    if (_p == m.begin())
    {
        return max(c - times, 0ll);
    }
    else
    {
        ll p = *(--_p);
        return max(c - times, p + 1);
    }
}
ll right(ll r, ll c, ll times)
{
    sl &m = sr[r];
    auto _p = m.upper_bound(c);
    if (_p == m.end())
    {
        return min(c + times, W - 1);
    }
    else
    {
        ll p = *(_p);
        return min(c + times, p - 1);
    }
}
ll up(ll r, ll c, ll times)
{
    sl &m = sc[c];
    auto _p = m.lower_bound(r);
    if (_p == m.begin())
    {
        return max(r - times, 0ll);
    }
    else
    {
        ll p = *(--_p);
        return max(r - times, p + 1);
    }
}
ll down(ll r, ll c, ll times)
{
    sl &m = sc[c];
    auto _p = m.upper_bound(r);
    if (_p == m.end())
    {
        return min(r + times, H - 1);
    }
    else
    {
        ll p = *(_p);
        return min(r + times, p - 1);
    }
}
void solver()
{
    ll r = r0 - 1, c = c0 - 1;
    for (ll i = 0; i < Q; i++)
    {
        if (ad[i] == 'L')
        {
            c = left(r, c, al[i]);
        }
        if (ad[i] == 'R')
        {
            c = right(r, c, al[i]);
        }
        if (ad[i] == 'U')
        {
            r = up(r, c, al[i]);
        }
        if (ad[i] == 'D')
        {
            r = down(r, c, al[i]);
        }
        cout << r + 1 << ' ' << c + 1 << endl;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> r0 >> c0;
    cin >> N;
    ar.resize(N);
    ac.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> ar[i] >> ac[i];
        sr[ar[i] - 1].emplace(ac[i] - 1);
        sc[ac[i] - 1].emplace(ar[i] - 1);
    }
    cin >> Q;
    ad.resize(Q);
    al.resize(Q);
    for (ll i = 0; i < Q; i++)
    {
        cin >> ad[i] >> al[i];
    }
    solver();
}