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
vl A;
vector<vl> d;
void solver()
{
    // l: A[i]が0以上になるのは何回目のとき
    // r: A[i]がN以上になるのは何回目のとき
    ll l, r;
    for (ll i = 0; i < N; i++)
    {
        l = (A[i] >= 0) ? 0 : (-A[i] + i) / (i + 1);
        r = (A[i] >= N) ? 0 : (N - A[i] + i) / (i + 1);
        r = min(r, M + 1);
        for (ll j = l; j < r; j++)
        {
            d[j].emplace_back(A[i] + (i + 1) * j);
        }
    }
    for (ll i = 1; i < M + 1; i++)
    {
        ll ans = 0;
        // d[i]: i回目に含まれている0以上N未満の数一覧
        vl &b = d[i];
        vb e(b.size() + 1);
        for (ll i : b)
        {
            if (i <= b.size())
            {
                e[i] = true;
            }
        }
        while (e[ans])
        {
            ++ans;
        }
        cout << ans << endl;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    A.resize(N);
    d.resize(M + 1);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    solver();
}