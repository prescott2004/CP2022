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
vector<vl> DP;
ll solve()
{
    // DP[i][j]: A[0]~A[j-1]の中からi個選んだときの最大値
    // DP[0][j]:何も選ばないときの最大値
    // DP[M][N]:答え
    for (ll i = 0; i < M; i++)
    {
        for (ll j = i; j < N; j++)
        {
            if (j == i)
            {
                DP[i + 1][j + 1] = DP[i][j] + (i + 1) * A[j];
            }
            else
            {
                DP[i + 1][j + 1] = max(DP[i + 1][j], DP[i][j] + (i + 1) * A[j]);
            }
        }
    }
    // for (ll i = 0; i < M; i++)
    // {
    //     for (ll j = 0; j < N; j++)
    //     {
    //         cout << DP[i + 1][j + 1] << ' ';
    //     }
    //     cout << endl;
    // }
    return DP[M][N];
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
    DP.resize(M + 1, vl(N + 1, 0));
    cout << solve() << endl;
}