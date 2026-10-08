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
    ll n;
    cin>>n;
    vl p(n-1);
    input(p);
    string s;
    cin>>s;

    vl dp(n,0);
    loop(i,n-1){
        if(s[i]=='L') dp[i+1] = dp[p[i]-1] -1;
        else dp[i+1] = dp[p[i]-1] +1;
    }
    sort(all(dp));
    

    ll ans=0;
    for (int i=n-1; i>=0; i--){
        ans += 2*(i*dp[i] - (n-i-1)*dp[i]);
        ans%=998244353;
    }
    //output(dp);
    
    cout<<ans<<endl;
    
    
    return 0;
}