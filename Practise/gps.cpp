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
#define summation(a) accumulate(a.begin(), a.end(), 0LL)
#define pi 3.14159265358979323846LL
const ll MOD = 1e9 + 7;
// memset(a, -1, sizeof(a));

ll power(ll base, ll exp, ll mod)
{
    ll result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

ll modInverse(ll a, ll mod = MOD)
{
    return power(((a % mod) + mod) % mod, mod - 2, mod);
}

ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    fastio;

    ll n;
    cin >> n;
    vl x(n), y(n), d(n);
    ll xl = LLONG_MIN / 4, xr = LLONG_MAX / 4, yl = LLONG_MIN / 4, yr = LLONG_MAX / 4;
    loop(i, n)
    {
        cin >> x[i] >> y[i] >> d[i];
        xl = max(xl, x[i] - d[i]);
        xr = min(xr, x[i] + d[i]);
        yl = max(yl, y[i] - d[i]);
        yr = min(yr, y[i] + d[i]);
    }

    vpl ans;
    for (ll i = xl; i <= xr; i++)
    {
        ll a, b;
        ll dist = abs(x[0] - i);
        dist = d[0] - dist;
        if (dist == 0 && y[0] >= yl && y[0] <= yr)
        {
            a = i;
            b = y[0];
            if (n == 1)
                ans.pb({a, b});
            else if ((abs(x[1] - a) + abs(y[1] - b) == d[1]) && n == 2)
                ans.pb({a, b});
            else if (n > 2 && (abs(x[1] - a) + abs(y[1] - b) == d[1]) && (abs(x[2] - a) + abs(y[2] - b) == d[2]))
                ans.pb({a, b});
        }
        else if (dist > 0)
        {
            if (y[0] + dist >= yl && y[0] + dist <= yr)
            {
                a = i;
                b = y[0] + dist;
                if (n == 1)
                    ans.pb({a, b});
                else if ((abs(x[1] - a) + abs(y[1] - b) == d[1]) && n == 2)
                    ans.pb({a, b});
                else if (n > 2 && (abs(x[1] - a) + abs(y[1] - b) == d[1]) && (abs(x[2] - a) + abs(y[2] - b) == d[2]))
                    ans.pb({a, b});
            }

            if (y[0] - dist >= yl && y[0] - dist <= yr)
            {
                a = i;
                b = y[0] - dist;
                if (n == 1)
                    ans.pb({a, b});
                else if ((abs(x[1] - a) + abs(y[1] - b) == d[1]) && n == 2)
                    ans.pb({a, b});
                else if (n > 2 && (abs(x[1] - a) + abs(y[1] - b) == d[1]) && (abs(x[2] - a) + abs(y[2] - b) == d[2]))
                    ans.pb({a, b});
            }
        }
    }

    ll f = 2;
    for (ll i = 3; i < n; i++)
    {
        if (ans.size() == 1)
        {
            f = 0;
            break;
        }
        if (abs(ans[0].first - x[i]) + abs(ans[0].second - y[i]) != d[i])
        {
            f = 1;
            break;
        }
        if (abs(ans[1].first - x[i]) + abs(ans[1].second - y[i]) != d[i])
        {
            f = 0;
            break;
        }
    }
    //
    // cout << xl << " " << xr << " " << yl << " " << yr << endl;
    if (f == 0)
        cout << ans[0].first << " " << ans[0].second << endl;
    else if (f == 1)
        cout << ans[1].first << " " << ans[1].second << endl;
    else
    {
        for (auto [f, s] : ans)
            cout << f << " " << s << endl;
    }
    return 0;
}