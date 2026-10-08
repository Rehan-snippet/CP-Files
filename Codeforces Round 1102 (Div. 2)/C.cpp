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
        vl h(n);
        input(h);

        ll ans=0;
        for(ll i=-1; i<n-1; i++){
            vl right, left;
            ll x=-1, sum=0;
            for(ll j=i+1; j<n+i; j++){
                x= max(x, h[j%n]);
                left.pb(x);
                

            }
            x=-1;
            for(ll j=i; j>i-n+1; j--){
                x= max(x, h[(j+2*n)%n]);
                right.pb(x); 
            }

            loop(j,n-1){
                sum+=min(right[n-2-j],left[j]);
            }
            cout<<sum<<" ";
            //cout<<endl;
            //output(left); 
            //output(right);
        }
        cout<<endl;
       
        
    }
    
    return 0;
}