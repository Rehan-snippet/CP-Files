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
        vl a(n);
        input(a);
        vector<vector<ll>> adj(n+1); vl deg(n+1,0);
        loop(i,n-1){
            ll p,q;
            cin>>p>>q;
            adj[p].pb(q);
            adj[q].pb(p);
            deg[p]++; deg[q]++;
        }
        ll ans=0;
        loop2(i,n){
            if( sqrt(a[i-1])* sqrt(a[i-1]) == a[i-1]) {
                //cout<<a[i-1]<<" ";
                if(deg[i]==2) ans+=deg[adj[i][0]]*deg[adj[i][1]];
                else if(deg[i]>2){
                    ll p1=0, p2=0, p3=0;
                    for(auto x:adj[i]){
                        ll y= deg[x]+1;
                        p1+=y; p2+=y*y; p3+=y*y*y;
                    }
                    ans+= (p1*p1 - p2)/2;
                    ans+= (p1*p1*p1 - 3*p1*p2 + 2*p3)/6;
                }   
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}