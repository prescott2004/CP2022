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
ll N, x, y;
vl A;
bool solver()
{
    ll Z = 10000;
    // p0=(0,0)
    // p1=(A1,0)
    vector<vb> DPx(N + 1, vb(Z * 2 + 1, false));
    vector<vb> DPy(N + 1, vb(Z * 2 + 1, false));
    DPx[0][Z] = true;
    DPx[1][A[0] + Z] = true;
    DPy[0][Z] = true;
    for (ll i = 3; i < N + 1; i += 2)
    {
        for (ll j = 0; j < Z * 2 + 1; j++)
        {
            if (DPx[i - 2][j])
            {
                DPx[i][j + A[i - 1]] = true;
                DPx[i][j - A[i - 1]] = true;
            }
        }
    }
    for (ll i = 2; i < N + 1; i += 2)
    {
        for (ll j = 0; j < Z * 2 + 1; j++)
        {
            if (DPy[i - 2][j])
            {
                DPy[i][j + A[i - 1]] = true;
                DPy[i][j - A[i - 1]] = true;
            }
        }
    }
    ll Nx, Ny;
    if (N % 2 == 0)
    {
        Nx = N - 1, Ny = N;
    }
    else
    {
        Nx = N, Ny = N - 1;
    }
    if (DPx[Nx][x + Z] && DPy[Ny][y + Z])
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> x >> y;
    A.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
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