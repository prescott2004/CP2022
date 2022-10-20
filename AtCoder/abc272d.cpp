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
ll N, M;
ll solver(ll i, ll j)
{
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    vector<vl> ans(N, vl(N));
    ans[0][0] = 0;
    for (ll i = 0; i < M; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            ans[i][j] = solver(i, j);
        }
    }
}