#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define ll long long int
#define ld long double
#define ull unsigned long long
#define lll __int128
#define vl vector<ll>
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
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
        ll ans=n-1;
        vl v(n);
        vl b(n,1);
        input(v);
        if(n==1) ans=0;
        else if(n==2) ans=1;
        else if(n==3) ans=2;
        else{
            for(ll i=1; i<n-2; i++){
                if(((v[i]-v[i-1]) + (v[i+2]-v[i+1])) <= (v[i+1]-v[i])) {
                    ans--; b[i+1]=0;
                }    
            }
            for(ll i=1; i<n; i++){
                
            }
        }


        cout<<ans<<endl;    
    }
    return 0;
}