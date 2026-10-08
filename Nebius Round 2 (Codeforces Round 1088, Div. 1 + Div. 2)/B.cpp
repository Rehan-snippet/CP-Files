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
#define MOD  676767677
// memset(a, -1, sizeof(a));

int main() {
    fastio;
    test{
        ll x,y;
        cin>>x>>y;
        ll n= abs(x-y);
        ll ans=1;

        for(ll i=2; i<=n; i++){
            if(n%i==0) ans++;
            ans%=MOD;
        }

        cout<<ans<<endl;
        loop(i,x) cout<<1<<" ";
        loop(i,y) cout<<-1<<" ";
        cout<<endl;
        
    }
    
    return 0;
}