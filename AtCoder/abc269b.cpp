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
string s[10];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    for (ll i = 0; i < 10; i++)
    {
        cin >> s[i];
    }
    ll A, B, C, D;
    for (ll i = 0; i < 10; i++)
    {
        for (ll j = 0; j < 10; j++)
        {
            if (s[i][j] == '#')
            {
                A = i + 1;
                C = j + 1;
                goto X;
            }
        }
    }
X:
    for (ll i = 9; i > -1; i--)
    {
        for (ll j = 9; j > -1; j--)
        {
            if (s[i][j] == '#')
            {
                B = i + 1;
                D = j + 1;
                goto Y;
            }
        }
    }
Y:
    cout << A << ' ' << B << endl;
    cout << C << ' ' << D << endl;
}