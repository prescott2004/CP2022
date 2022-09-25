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
ll H, W;
vector<vector<char>> G;
void solver()
{
    vector<vb> used(H, vb(W, false));
    ll h = 0, w = 0;
    while (true)
    {
        if (used[h][w])
        {
            cout << -1 << endl;
            return;
        }
        used[h][w] = true;
        if (G[h][w] == 'U' && h != 0)
        {
            --h;
        }
        else if (G[h][w] == 'D' && h != H - 1)
        {
            ++h;
        }
        else if (G[h][w] == 'L' && w != 0)
        {
            --w;
        }
        else if (G[h][w] == 'R' && w != W - 1)
        {
            ++w;
        }
        else
        {
            cout << h + 1 << ' ' << w + 1 << endl;
            return;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    G.resize(H, vector<char>(W));
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            cin >> G[i][j];
        }
    }
    solver();
}