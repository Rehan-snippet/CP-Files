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
        string s= to_string(a);
        int l= s.size();
        ll k=0; 

        loop(i,l){
            int c= s[i]-'0';
            bool f=0;
            for(auto x:d){
                if(x>c){
                    ll b=k*10+x;
                    loop(j, l-i-1) b= b*10 + d[0];
                    ans= min(ans, abs(a-b));
                    //cout<<k<<" ";
                }
                
                else if(x<c){
                    ll b=k*10+x;
                    loop(j, l-i-1) b= b*10 + d[n-1];
                    ans= min(ans, abs(a-b));
                    //cout<<k<<" ";
                }
                else f=1;
            }
            
            if(!f) break;
            k= k*10+c;

        }
        if(k!=0) ans= min(ans, abs(a-k)); 

        if(l>1){
            k=0;
            loop(i,l-1) k= k*10+d[n-1];
            ans= min(ans, abs(a-k));

        }
        k=0;
        loop(i,l+1) k= k*10+d[0];
        ans= min(ans, abs(a-k));

        if(d[0]==0 && n>1){
            k=d[1]; 
            loop(i,l) k= k*10+d[0];
            ans= min(ans, abs(a-k));
        }

        cout<<ans<<endl;
    }

    return 0;
}