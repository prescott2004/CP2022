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
ll N, Q;
vector<vl> A;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    ll l, a;
    A.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> l;
        A[i].resize(l);
        for (ll j = 0; j < l; j++)
        {
            cin >> a;
            A[i][j] = a;
        }
    }
    ll s, t;
    vl ans;
    for (ll i = 0; i < Q; i++)
    {
        cin >> s >> t;
        ans.emplace_back(A[s - 1][t - 1]);
    }
    for (auto &e : ans)
    {
        cout << e << endl;
    }
}