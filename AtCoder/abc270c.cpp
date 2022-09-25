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
ll N, X, Y;
vector<vl> G;
vb used;
vl ans;
bool dfs(ll x)
{
    if (x == Y - 1)
    {
        ans.emplace_back(Y);
        return true;
    }
    ll y;
    for (ll i = 0; i < G[x].size(); i++)
    {
        y = G[x][i];
        if (!used[y])
        {
            used[y] = true;
            if (dfs(y))
            {
                ans.emplace_back(x + 1);
                return true;
            }
            used[y] = false;
        }
    }
    return false;
}
void solver()
{
    used.resize(N, false);
    used[X - 1] = true;
    dfs(X - 1);
    for (ll i = ans.size() - 1; i > -1; i--)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> X >> Y;
    G.resize(N);
    ll u, v;
    for (ll i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        G[u - 1].emplace_back(v - 1);
        G[v - 1].emplace_back(u - 1);
    }
    solver();
}
