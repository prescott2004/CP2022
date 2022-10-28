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
struct Edge
{
    ll a, b, c;
    Edge(ll a, ll b, ll c) : a(a), b(b), c(c) {}
};

int main()
{
    ll N, M, K;
    vector<Edge> es;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    ll a, b, c;
    for (ll i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        es.emplace_back(a - 1, b - 1, c);
    }
    vl dist(N, INFTY);
    dist[0] = 0;
    ll e;
    for (ll i = 0; i < K; i++)
    {
        cin >> e;
        auto &edge = es[e - 1];
        dist[edge.b] = min(dist[edge.b], dist[edge.a] + edge.c);
    }
    ll ans = (dist[N - 1] == INFTY) ? -1 : dist[N - 1];
    cout << ans << endl;
}