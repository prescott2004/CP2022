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
ll N, Y;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Y;
    Y /= 1000;
    ll a = -1, b = -1, c = -1;
    for (ll x = 0; x < N + 1; x++)
    {
        for (ll y = 0; x + y <= N; y++)
        {

            if (9 * x + 4 * y == Y - N)
            {
                a = x, b = y, c = N - a - b;
                goto FIN;
            }
        }
    }
FIN:
    printf("%lld %lld %lld\n", a, b, c);
}