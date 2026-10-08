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
        ll n, x, s;
        cin>>n>>x>>s;
        string a;
        cin>>a;
        ll ambi=0, intro=0;
        ll ans= n;
        loop(i,n){
            if(a[i]=='I') intro++;
        }
        
        ll food=0, intro2=0;
        loop(i,n){
            if(a[i]=='A'){
                if(!food || intro<x) {
                    a[i]='I';
                    intro++;
                }
                else ambi++;
            }
            if(a[i]=='I'){
                intro2++;
                if(intro2<=x) food+=(s-1);
                else ans--;
            }
            else{
                if(food) food--;
                else {
                    if(ambi>0  && intro2<=x){
                        ambi--;
                        intro++;
                        intro2++;
                        food+=(s-1);
                    }
                    else ans--;
                }
            }
        }
        cout<<min(ans, x*s)<<endl;  
    }
    
    return 0;
}