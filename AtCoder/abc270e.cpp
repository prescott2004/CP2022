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
ll N, K;
vl A;
void solver()
{
    // A[0]=d[0]
    // A[1]=d[1]+A[0]
    vl d(A);
    sort(d.begin(), d.end());
    vl AA(d);
    for (ll i = 0; i < N - 1; i++)
    {
        d[i + 1] = AA[i + 1] - AA[i];
    }
    sort(AA.begin(), AA.end());
    vl ans(A);
    ll k = K;
    ll cnt = 0;
    for (ll i = 0; i < N; i++)
    {
        if (d[i] * (N - i) <= k)
        {
            k -= d[i] * (N - i);
        }
        else
        {
            cnt = i;
            break;
        }
        cnt = i + 1;
    }
    for (ll i = 0; i < N; i++)
    {
        if (cnt && ans[i] <= AA[cnt - 1])
        {
            ans[i] = 0;
        }
        else
        {
            if (cnt)
            {
                ans[i] -= AA[cnt - 1];
            }
            ans[i] -= k / (N - cnt);
        }
    }
    if (cnt != N)
    {
        k %= (N - cnt);
    }
    else
    {
        k = 0;
    }
    sl s;
    for (ll i = 0; i < N; i++)
    {
        if (ans[i])
        {
            s.emplace(i);
        }
    }
    while (!s.empty() && k > 0)
    {
        for (auto e : s)
        {
            if (!k)
            {
                break;
            }
            --ans[e];
            --k;
            if (!ans[e])
            {
                s.erase(e);
            }
        }
    }
    for (ll i = 0; i < N; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    A.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    solver();
}