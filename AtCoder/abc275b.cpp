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
ll a, b, c, d, e, f;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c >> d >> e >> f;
    const ll N = 998244353;
    a %= N;
    b %= N;
    c %= N;
    d %= N;
    e %= N;
    f %= N;
    ll ans1 = a, ans2 = d;
    ans1 = (ans1 * b) % N;
    ans1 = (ans1 * c) % N;
    ans2 = (ans2 * e) % N;
    ans2 = (ans2 * f) % N;
    ll ans = ans1 - ans2 >= 0 ? ans1 - ans2 : N + ans1 - ans2;
    cout << ans << endl;
}