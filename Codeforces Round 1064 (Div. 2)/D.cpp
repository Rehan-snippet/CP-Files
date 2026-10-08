#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ld long double
#define ull unsigned long long
#define vl vector<ll>
#define pb push_back
#define loop(i,n) for(int i=0;i<n;i++)
#define input(a) for(auto &x:a) cin>>x;
#define output(a) for(auto x:a) cout<<x<<" ";
#define endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(x) x.begin(), x.end()
#define allr(a) a.rbegin(), a.rend()
#define pi 3.14159265358979323846L

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl a(n);
        input(a);
        vl f;
        sort(all(a));
        ll count=1;
        for(int i=1; i<n; i++){
            if(a[i]==a[i-1]) count++;
            else {
                f.pb(count);
                count=1;
            }
        }
        f.pb(count);
        sort(all(f));
        ll sz=f.size();
        vl sf(sz);
        sf[0]=f[0];
        for(int i=1; i<sz;i++){
            sf[i]=sf[i-1]+f[i];
        }
        ll t=0;
        while(sf[t]<f[sz-1] && t<sz){
            
        }
        // ll ans=1,m=-1;
        // for(auto x:f){
        //     ans*=x;
        //     if(x>m) m=x;
        // }
        // for(auto x:f){
        //     if(x>1 && x!=m){
        //         ans-=x;
        //     }
        // }
        // cout<<ans<<endl;
    }
    
    return 0;
}