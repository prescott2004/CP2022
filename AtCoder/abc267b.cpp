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
string S;
vb R(7, false);
bool solve()
{
    if (S[0] - '0')
    {
        return false;
    }
    R[0] = S[6] - '0';
    R[1] = S[3] - '0';
    R[2] = (S[7] - '0') | (S[1] - '0');
    R[3] = (S[4] - '0') | (S[0] - '0');
    R[4] = (S[8] - '0') | (S[2] - '0');
    R[5] = S[5] - '0';
    R[6] = S[9] - '0';
    for (ll i = 0; i < 7; i++)
    {
        // cout << i << ": " << R[i] << endl;
        if (R[i])
        {
            for (ll j = i + 1; j < 7; j++)
            {
                if (!R[j])
                {
                    for (ll k = j + 1; k < 7; k++)
                    {
                        if (R[k])
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    if (solve())
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}