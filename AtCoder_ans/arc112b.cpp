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
ll B, C;
ll solve()
{
    ll ans;
    if (B == 0)
    {
        ans = (C / 2) + ((C - 1) / 2) + 1;
    }
    else if (B > 0)
    {
        // Bより大きい分と、-Bより小さい分
        ans = ((C - 1) / 2) + ((C - 2) / 2);
        // 0以上B以下の分
        if (B > C / 2)
        {
            ans += (C / 2) + 1;
        }
        else
        {
            ans += B + 1;
        }
        // -B以上0未満の分
        if (B > (C - 1) / 2)
        {
            ans += ((C - 1) / 2) + 1;
        }
        else
        {
            ans += B;
        }
    }
    else
    {
        // -|B|より小さい分と、|B|より大きい分
        ans = (C / 2) + ((C - 1) / 2);
        // 0以上|B|以下の分
        if (-B > (C - 1) / 2)
        {
            ans += ((C - 1) / 2) + 1;
        }
        else
        {
            ans += -B + 1;
        }
        // -|B|以上0未満の分
        if (-B > (C - 2) / 2)
        {
            ans += ((C - 2) / 2) + 1;
        }
        else
        {
            ans += -B;
        }
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> B >> C;
    cout << solve() << endl;
}