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
vl A, S;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    A.resize(N);
    S.resize(N + 1, 0);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
        S[i + 1] = S[i] + A[i];
    }
    ll s = 0, ans = 0;
    for (ll i = 0; i < M; i++)
    {
        s += (i + 1) * A[i];
        ans = s;
    }
    for (ll r = M; r < N; r++)
    {
        s -= S[r] - S[r - M];
        s += M * A[r];
        ans = max(ans, s);
    }
    cout << ans << endl;
}