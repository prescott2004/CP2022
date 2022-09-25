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
ll X, Y, Z;
ll solver()
{
    // XとYが逆方向orXの先にYがある
    if (X * Y < 0 || abs(X) < abs(Y))
    {
        return abs(X);
    }
    // Yの先にXがある
    else
    {
        // YとZが逆方向
        if (Y * Z < 0)
        {
            return 2 * abs(Z) + abs(X);
        }
        // Zの先にYがある
        else if (abs(Z) < abs(Y))
        {
            return abs(X);
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> X >> Y >> Z;
    cout << solver() << endl;
}