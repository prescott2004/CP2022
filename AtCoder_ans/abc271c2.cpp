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
vb E;
ll a;
ll solver()
{
    ll cost = 0;
    ll i;
    for (i = 1; i < N + 1; i++)
    {
        cost = E[i] ? cost + 1 : cost + 2;
        if (cost > N)
        {
            return i - 1;
        }
    }
    return i == N + 1 ? N : 0;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    E.resize(N + 1, false);
    for (ll i = 0; i < N; i++)
    {
        cin >> a;
        if (a <= N)
        {
            E[a] = true;
        }
    }
    cout << solver() << endl;
}