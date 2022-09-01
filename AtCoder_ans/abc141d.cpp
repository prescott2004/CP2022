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
ll N, M;
vl A;
ll solve()
{
    pque<int> Q;
    ll value;
    for (ll i = 0; i < N; i++)
    {
        Q.push(A[i]);
    }
    for (ll i = 0; i < M; i++)
    {
        value = Q.top();
        Q.pop();
        value >>= 1;
        Q.push(value);
    }
    ll ans = 0;
    while (!Q.empty())
    {
        ans += Q.top();
        Q.pop();
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    A.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << solve() << endl;
}