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
#define pi 3.14159265358979323846LL

int ncr[32][32];

ll nCr(ll n, ll r){
    double ans=1;
    for(ll i=1; i<=r; i++){
        ans*=((n-r+i)/i);
    }
    return (ll)ans;
}

int main() {
    fastio;
    
    ncr[1][0]=1; ncr[1][1]=1;
    for(int i=2;i<32; i++){
        ncr[i][0]=1;
        for(int j=1;j<=i;j++){
            ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
        }
    }

    test{
        ll n,k,ans=0;
        cin>>n>>k;
        int p=0;
        while(n!=0){
            n>>=1;
            p++;
        }
        //cout<<p<<endl;
        if(p>k)ans++;
        for(int i=p-1; i>1; i--){
            for(int j=0; j<i; j++){
                if(i+j>k) ans+=ncr[i-1][j];
            }
            if(2*i-1<k) break;
        }
        cout<<ans<<endl;
    }
    

    
    return 0;
}