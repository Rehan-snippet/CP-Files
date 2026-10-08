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
        ll prev=0, x=0, ans=0;
        for(ll i=1; i<n; i++){
            x-=a[i];
        }
        ans=x;
        x+=(a[0]+a[1]);
        ans=max(x,ans);
        for(ll i=1; i<n-1; i++){
            if(a[i]>0) x+=(a[i]+a[i+1]);
            else x=x-a[i]+a[i+1];
            ans=max(x,ans);
        }
        cout<<ans<<endl;

    }
    
    return 0;
}