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
ll N, M, T;
vl A, X, Y;
bool solver()
{
    vl ans(N, 0);
    ans[0] = T;
    for (ll i = 0; i < M; i++)
    {
        ans[X[i] - 1] += Y[i];
    }
    for (ll i = 0; i < N - 1; i++)
    {
        ans[i] -= A[i];
        if (ans[i] <= 0)
        {
            return false;
        }
        ans[i + 1] += ans[i];
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> T;
    A.resize(N - 1);
    X.resize(M);
    Y.resize(M);
    for (ll i = 0; i < N - 1; i++)
    {
        cin >> A[i];
    }
    for (ll i = 0; i < M; i++)
    {
        cin >> X[i] >> Y[i];
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