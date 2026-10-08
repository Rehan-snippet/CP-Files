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
        ll a, ans=LONG_LONG_MAX; int n;
        cin>>a>>n;
        vl d(n);
        input(d);
        if(a==0) ans=d[0];
        else{
            ll k=0;
            int dig=0; ll num=a;
            while(num>0){
                dig++; num/=10;
            }
            if(dig==1) {
                ans = min({abs(a-d[0]), abs(a-d[1]), abs(a-(d[1]*10+d[0])),abs(a-(d[0]*10+d[0]))});
            }
            else{
                if(d[0]==0) {
                    dig--;
                    ans= min(ans, a);
                }
                for (int i = 0; i < (1 << dig); i++) {
                    k= (d[0]==0)? d[1]:0;
                    for (int j = dig-1; j >= 0; j--)
                        k=k*10+d[(i >> j) & 1];
                    ans=min(ans, abs(k-a));
                    //cout<<k<<" ";
                }
                k= (d[0]==0)? d[1]:0;
                loop(i,dig-1) k=k*10+d[1];
                ans=min(ans, abs(k-a)); //cout<<k<<" ";

                k= (d[0]==0)? d[1]:0;
                loop(i,dig+1) k=k*10+d[0];
                ans=min(ans, abs(k-a)); //cout<<k<<" ";
            }
        }
        cout<<ans<<endl;


    }
    
    return 0;
}