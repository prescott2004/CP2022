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
vector<vl> B;
void solver()
{
    vector<pll> D;
    for (ll di = -N; di < N; di++)
    {
        if (di * di > M)
        {
            continue;
        }
        ll dj = sqrt(M - di * di);
        if (di * di + dj * dj == M)
        {
            D.emplace_back(di, dj);
            D.emplace_back(di, -dj);
        }
    }
    B[0][0] = 0;
    queue<pll> Q;
    Q.emplace(0, 0);
    while (!Q.empty())
    {
        ll i = Q.front().first, j = Q.front().second;
        Q.pop();
        for (pll &p : D)
        {
            ll ni = i + p.first, nj = j + p.second;
            if (ni >= 0 && ni < N && nj >= 0 && nj < N && B[ni][nj] == -1)
            {
                B[ni][nj] = B[i][j] + 1;
                Q.emplace(ni, nj);
            }
        }
    }
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    B.resize(N, vl(N, -1));
    solver();
}
