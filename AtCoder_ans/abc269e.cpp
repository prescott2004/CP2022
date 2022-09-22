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
    ll a = 1;
    for (ll i = 0; i < 10000000; i++)
    {
        a += i;
    }
}
ll N, T;
void output(ll A, ll B, ll C, ll D)
{
    cout << "? " << A << ' ' << B << ' ' << C << ' ' << D << endl;
    ;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    ll a, b, c, d, m;
    ll ans_i, ans_j;
    a = 1, b = N, c = 1, d = N;

    for (ll i = 0; i < 10; i++)
    {

        m = (a + b) / 2;
        output(a, m, 1, N);
        cin >> T;

        if (T == 0)
        {
            ans_i = a;
            break;
        }
        else if (T < (m - a + 1))
        {
            b = m;
        }
        else
        {
            ans_i = m + 1;
            a = m + 1;
        }
    }
    for (ll i = 0; i < 10; i++)
    {

        m = (c + d) / 2;
        output(1, N, c, m);
        cin >> T;

        if (T == 0)
        {
            ans_j = c;
            break;
        }
        else if (T < (m - c + 1))
        {
            d = m;
        }
        else
        {
            ans_j = m + 1;
            c = m + 1;
        }
    }
    cout << "! " << ans_i << ' ' << ans_j << endl;
}