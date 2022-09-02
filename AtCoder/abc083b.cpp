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
ll N, A, B;
ll sum(ll value)
{
    ll ret = 0;
    while (value)
    {
        ret += value % 10;
        value /= 10;
    }
    return ret;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> A >> B;
    ll s;
    ll ans = 0;
    for (ll i = 1; i < N + 1; i++)
    {
        s = sum(i);
        if (s >= A && s <= B)
        {
            ans += i;
        }
    }
    cout << ans << endl;
}