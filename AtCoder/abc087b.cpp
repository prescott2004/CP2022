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
ll A, B, C, X;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> B >> C >> X;
    ll r;
    ll ans = 0;
    for (ll a = 0; a < A + 1; a++)
    {
        for (ll b = 0; b < B + 1; b++)
        {
            r = X - 500 * a - 100 * b;
            if (r >= 0 && r % 50 == 0 && r / 50 <= C)
            {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}