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
vl A;
ll my_gcd(ll a, ll b)
{
    ll min_v = min(a, b);
    ll max_v = max(a, b);
    if (min_v == 0)
    {
        return max_v;
    }
    ll r;
    while (r = max_v % min_v)
    {
        max_v = min_v;
        min_v = r;
    }
    return min_v;
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
    sort(A.begin(), A.end());
    vl D(N - 1);
    for (ll i = 0; i < N - 1; i++)
    {
        D[i] = A[i + 1] - A[i];
    }
    ll R = D[0];
    for (ll i = 1; i < N - 1; i++)
    {
        R = my_gcd(R, D[i]);
    }
    if (R == 1)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
}