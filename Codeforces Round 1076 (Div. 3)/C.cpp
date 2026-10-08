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
        ll n,q;
        cin>>n>>q;
        vl a(n), b(n);
        input(a);
        input(b);
        a[n-1]=max(a[n-1],b[n-1]);
        for(int i=n-2; i>=0; i--){
            a[i]=max(max(a[i+1],b[i]),a[i]);
        }
        vl prefix(n+1);
        prefix[0]=0;
        loop2(i,n) prefix[i]=prefix[i-1]+a[i-1];
        while(q--){
            ll l,r;
            cin>>l>>r;
            cout<<prefix[r]-prefix[l-1]<<" ";
        }
        // output(a);
        // output(prefix);
        cout<<endl;
        
    }
    
    return 0;
}