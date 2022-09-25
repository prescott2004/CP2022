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
ll N, P, Q, R;
vl A;
bool solver()
{
    sl s;
    s.emplace(0);
    ll tmp = 0;
    for (ll i = 0; i < N; i++)
    {
        tmp += A[i];
        s.emplace(tmp);
    }
    for (auto e : s)
    {
        if (s.count(e + P) && s.count(e + P + Q) && s.count(e + P + Q + R))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> P >> Q >> R;
    A.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    if (solver())
    {
        yes();
    }
    else
    {
        no();
    }
}