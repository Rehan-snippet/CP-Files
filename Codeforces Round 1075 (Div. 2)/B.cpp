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

int main() {
    fastio;
    test{
        ll n, x, xc;
        cin>>n>>x;
        vl a(n), b(n), c(n);
        ll net_jump=0, ans=-1, limit=0;
        loop(i,n) {
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]*b[i]-c[i]> net_jump){
                net_jump= a[i]*b[i]-c[i];
            }
            limit+=a[i]*(b[i]-1);
        }
        x=max(0LL, x-limit);
        if(net_jump>0 || x==0){
            if(x%net_jump) ans=x/net_jump +1;
            else ans=x/net_jump;
            //ans=ceil((double)x/net_jump);
        }
        cout<<ans<<endl;

        
    }
    
    return 0;
}