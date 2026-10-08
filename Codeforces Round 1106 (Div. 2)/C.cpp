#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ull unsigned long long
#define lll __int128
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define loop2(i,n) for(ll i=1;i<=n;i++)
#define input(a) for(auto &x:a) cin>>x
#define output(a) for(auto x:a) cout<<x<<" ";cout<<endl
#define endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define pi 3.14159265358979323846LL
const ll MOD = 1e9+7;
// memset(a, -1, sizeof(a));

ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl p(n-1); vl c(n+1,0);
        vector<vector<ll>> par(n+1);
        vector<ll> h(n+1); 
        h[1]=0; ll max_h=0;

        loop(i,n-1){
            cin>>p[i];
            c[p[i]]++;
            par[p[i]].pb(i+1);
            h[i+2]= h[p[i]]+1;
            max_h= max(max_h, h[i+2]);
        }

        vl height(max_h+1,0); ll ans=n;
        loop2(i,n){
            height[h[i]]++;
        }
        for(ll i=1; i<=max_h; i++) if(height[i]>1) ans++;

        
        loop2(i,n){
            if(c[i]>1 && c[i]<height[h[i]+1]) {
                ans++;
                ll child=0, f=0;
                for(auto x:par[i]){
                    child+=c[x];
                    if(c[x]==1) f=1;
                }
                if(child>1 && f==1) ans++;
                }
        
            }
            
        cout<<ans<<endl;
        
    }
    
    return 0;
}