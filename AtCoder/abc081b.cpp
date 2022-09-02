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
vl A;
ll my_gcd(ll a, ll b)
{
    if (a < b)
    {
        swap(a, b);
    }
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return my_gcd(b, a % b);
    }
}
ll solve()
{
    ll x = A[0];
    for (ll i = 1; i < N; i++)
    {
        x = my_gcd(x, A[i]);
    }
    ll ans = 0;
    while ((x & 1) == 0)
    {
        ++ans;
        x >>= 1;
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    A.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << solve() << endl;
}