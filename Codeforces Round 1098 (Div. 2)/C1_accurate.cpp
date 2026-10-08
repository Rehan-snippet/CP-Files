#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long int
#define ull unsigned long long
#define lll __int128
#define vl vector<ll>
#define vpl vector<pair<ll, ll>>
#define pb push_back
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loop2(i, n) for (ll i = 1; i <= n; i++)
#define input(a)      \
    for (auto &x : a) \
    cin >> x
#define output(a)         \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define pi 3.14159265358979323846LL
#define MOD 998244353
// memset(a, -1, sizeof(a));

int main()
{
    fastio;
    test
    {
        ll a, ans = LONG_LONG_MAX;
        int n;
        cin >> a >> n;
        vl d(n);
        input(d);
        if (a == 0)
            ans = d[0];
        else
        {
            ll k = 0;
            int dig = 0;
            ll num = a;
            while (num > 0)
            {
                dig++;
                num /= 10;
            }
            if (dig == 1)
            {
                ans = min({abs(a - d[0]), abs(a - d[1]),
                           abs(a - (d[1] * 10 + d[0])), abs(a - (d[0] * 10 + d[0])),
                           abs(a - (d[0] * 10 + d[1])), abs(a - (d[1] * 10 + d[1]))});
            }
            else
            {
                string s = to_string(a);
                string t = s;
                int l = s.size();

                if (d[0] == 0 && s[0] - '0' != d[1])
                {

                    string b = t;
                    b[0] = d[1] + '0';
                    if (s[0] - '0' > d[1])
                    {
                        ll j = 1;
                        while (j < s.size())
                        {
                            // cout<<"m";
                            b[j] = d[1] + '0';
                            j++;
                        }
                        k = stoll(b);
                        ans = min(ans, abs(a - k));
                    }
                    else
                    {
                        ll j = 1;
                        while (j < s.size())
                        {
                            // cout<<"m";
                            b[j] = d[0] + '0';
                            j++;
                        }
                        k = stoll(b);
                        ans = min(ans, abs(a - k));
                    }
                }

                else
                {
                    bool f = 0;
                    for (int i = 0; i < s.size(); i++)
                    {
                        int c = s[i] - '0';
                        if (c == d[0])
                        {
                            // cout<<"m";
                            string b = t;

                            b[i] = d[1] + '0';
                            // cout<<b;
                            ll j = i + 1;
                            while (j < s.size())
                            {
                                // cout<<"m";
                                b[j] = d[0] + '0';
                                j++;
                            }
                            // cout<<b;
                            k = stoll(b);
                            ans = min(ans, abs(a - k));
                        }
                        else if (c == d[1])
                        {
                            string b = t;
                            b[i] = d[0] + '0';
                            ll j = i + 1;
                            while (j < s.size())
                            {
                                b[j] = d[1] + '0';
                                j++;
                            }
                            k = stoll(b);

                            ans = min(ans, abs(a - k));
                        }
                        else
                        {
                            int idx1 = i, idx2 = i, idx3=i, idx4=i;
                            
                                t[idx1] = d[0] + '0';
                                if (d[0] == 0 && idx1 == 0)
                                    t[idx1] = d[1] + '0';
                                idx1++;
                                while (idx1 < s.size())
                                    t[idx1++] = d[1] + '0';
                                k = stoll(t);
                                ans = min(ans, abs(a - k));
                            

                            t[idx2++] = d[1] + '0';
                            while (idx2 < s.size())
                                t[idx2++] = d[0] + '0';
                            k = stoll(t);
                            ans = min(ans, abs(a - k));

                            if (d[0] == 0 && idx3 == 0)
                                    t[idx3++] = d[1] + '0';
                            while (idx3 < s.size())
                                t[idx3++] = d[0] + '0';
                            k = stoll(t);
                            ans = min(ans, abs(a - k));

                            while (idx4 < s.size())
                                t[idx4++] = d[1] + '0';
                            k = stoll(t);
                            ans = min(ans, abs(a - k));


                            f = 1;
                            break;
                        }
                    }
                    if (f == 0)
                        ans = 0;
                }
                if (l > 1)
                {
                    k = 0;
                    loop(i, l - 1) k = k * 10 + d[n - 1];
                    ans = min(ans, abs(a - k));
                }
                k = 0;
                loop(i, l + 1) k = k * 10 + d[0];
                ans = min(ans, abs(a - k));

                if (d[0] == 0 && n > 1)
                {
                    k = d[1];
                    loop(i, l) k = k * 10 + d[0];
                    ans = min(ans, abs(a - k));
                }
                // cout<<k<<" ";
            }
        }
        cout << ans << endl;
    }

    return 0;
}