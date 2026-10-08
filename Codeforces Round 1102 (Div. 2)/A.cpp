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
#define MOD 998244353
// memset(a, -1, sizeof(a));

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl a(n);
        input(a);
        sort(allr(a));
        ll x=a[0], y=a[1];
        ll r= x%y; int ans=0;
        loop(i,n-2){
            r= a[i]%a[i+1];
            if(a[i+2]!=r) {
                ans=-1;
                break;
            }
        }
        if(ans==-1) cout<<ans<<endl;
        else cout<<x<<" "<<y<<endl;
        
    }
    
    return 0;
}