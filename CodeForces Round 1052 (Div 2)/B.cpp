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
        ll n,m,flag=1;
        cin>>n>>m;
        vector<vector<int>> v(n);
        vl f(m+1), a(n);
        loop(i,n){
            int x,y;
            cin>>x;
            loop(j,x){
                cin>>y;
                v[i].pb(y);
                f[y]++;
            }
        }
        // output(v[0]);
        // cout<<"\n";
        loop(i,n){
            for(auto x:v[i]){
                if(f[x]<2) {
                    a[i]=1;
                    break;
                }
            }
        }
        loop(i,m){
            if(!f[i+1]) {
                flag=0;
                break;
            }
        }
        int rem=0;
        loop(i,n){
            if(!a[i]) rem++;
        }
        if(rem<2) flag=0;

        if(flag) yes;
        else no;
    }
    
    return 0;
}