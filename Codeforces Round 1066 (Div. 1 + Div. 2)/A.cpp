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
         vl a(n),b(n+1);
         loop(i,n){
            cin>>a[i];
            b[a[i]]++;
         }
         ll ans=0;
         for(int i=0; i<=n; i++){
            if(b[i]>i) ans+=(b[i]-i);
            else if(b[i]<i) ans+=b[i];
         }
         cout<<ans<<endl;
        //  output(b);
        //  cout<<endl;

    }
    
    return 0;
}