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
class UnionFind
{
private:
    vl par;
    vl size;

public:
    UnionFind(ll N) : par(N), size(N)
    {
        for (ll i = 0; i < N; i++)
        {
            this->par[i] = i;
            this->size[i] = 1;
        }
    }
    void init(ll N)
    {
        this->par.resize(N);
        this->size.resize(N);
        for (ll i = 0; i < N; i++)
        {
            this->par[i] = i;
            this->size[i] = 1;
        }
    }
    ll root(ll x)
    {
        while (this->par[x] != x)
        {
            this->par[x] = this->par[this->par[x]];
            x = this->par[x];
        }
        return x;
    }
    void unite(ll x, ll y)
    {
        ll rx = this->root(x);
        ll ry = this->root(y);
        if (rx == ry)
        {
            return;
        }
        if (this->size[rx] > this->size[ry])
        {
            swap(rx, ry);
        }
        this->par[rx] = ry;
        this->size[ry] += this->size[rx];
    }
    bool same(ll x, ll y)
    {
        return this->root(x) == this->root(y);
    }
    ll get_size(ll x)
    {
        return this->size[x];
    }
};
ll N;
vl X, Y;
map<pair<ll, ll>, ll> M;

ll find(ll i, ll j)
{
    auto found = M.find(make_pair(i, j));
    if (found != M.end())
    {
        return found->second;
    }
    return -1;
}
ll solver()
{
    UnionFind U(N);
    for (ll i = 0; i < N; i++)
    {
        vl x{-1, -1, 0, 0, 1, 1};
        vl y{-1, 0, -1, 1, 0, 1};
        ll s;
        for (ll j = 0; j < 6; j++)
        {
            s = find(X[i] + x[j], Y[i] + y[j]);
            if (s != -1)
            {
                U.unite(i, s);
            }
        }
    }
    sl ans;
    for (ll i = 0; i < N; i++)
    {
        ans.emplace(U.root(i));
    }
    return ans.size();
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    X.resize(N);
    Y.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
        M[make_pair(X[i], Y[i])] = i;
    }
    cout << solver() << endl;
}