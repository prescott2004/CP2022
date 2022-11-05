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
ll N;
vl A;
ll solver()
{
    sort(A.begin(), A.end());
    sl s;
    for (ll i = 1; i <= sqrt(A[0]) + 1; i++)
    {
        if (A[0] % i == 0)
        {
            s.emplace(i);
            s.emplace(A[0] / i);
        }
    }
    ll ans = -1;
    vl B(N);
    for (auto first : s)
    {
        bool flg = true;
        ll cnt = 0;
        for (ll i = 0; i < N; i++)
        {
            if (A[i] % first)
            {
                flg = false;
                break;
            }
            B[i] = A[i] / first;
        }
        for (ll i = 0; i < N; i++)
        {
            while (B[i] % 3 == 0)
            {
                ++cnt;
                B[i] /= 3;
            }
            while (B[i] % 2 == 0)
            {
                ++cnt;
                B[i] /= 2;
            }
            if (B[i] != 1)
            {
                flg = false;
                break;
            }
        }
        if (flg)
        {
            ans = (ans == -1) ? cnt : min(ans, cnt);
        }
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    A.resize(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << solver() << endl;
}