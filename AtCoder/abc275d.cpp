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
mll M;
ll solver(ll a)
{
    if (a == 0)
    {
        return 1;
    }
    auto ip = M.find(a / 2);
    auto iq = M.find(a / 3);
    ll p = ip == M.end() ? solver(a / 2) : M[a / 2];
    ll q = iq == M.end() ? solver(a / 3) : M[a / 3];
    M[a / 2] = p;
    M[a / 3] = q;
    return p + q;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    M[0] = 1;
    cout << solver(N) << endl;
}