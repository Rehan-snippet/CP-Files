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
        ll n,m,t;
        cin>>n>>m;
        vector<vl> M(n);
        vl tempr(n);
        vl tempc(m);
        ll  c=0,r=0,f=0;

        loop(i,n){
            loop(j,m){
                cin>>t;
                M[i].pb(t);
                tempr[i]^=t;
            }
            r+=tempr[i];
        }
        
        loop(j,m){
            loop(i,n){
                tempc[j]^=M[i][j];
            }
            //cout<<tempc[j]<<"  ";
            c+=tempc[j];
        }

        ll ans=LONG_LONG_MAX,it=LONG_LONG_MAX;
        loop(i,n){
            loop(j,m){
                it=min((tempr[i]^tempc[j]),it);
                ans=min(ans,(r+c-tempr[i]-tempc[j]+it));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}