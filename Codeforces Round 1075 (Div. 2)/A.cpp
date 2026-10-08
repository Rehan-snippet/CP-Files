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
        ll n,h,l;
        cin>>n>>h>>l;
        vl a(n);
        input(a);

        ll low=0, mid=0, ans;
        loop(i,n){
            if(a[i]<=min(h,l)) low++;
            else if(a[i]<=max(h,l)) mid++;
        }
        if(mid<=low) ans=(mid+low)/2;
        else ans=low;
        cout<<ans<<endl;
        
    }
    
    return 0;
}