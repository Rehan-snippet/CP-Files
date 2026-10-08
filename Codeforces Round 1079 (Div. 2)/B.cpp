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
        ll n;
        cin>>n;
        vl p(n), a(n);
        input(p); input(a);
        vl idx(n+1), fq(n+1);
        vector<bool> tf(n+1, true);
        loop(i,n){
            idx[p[i]]= i;
        }
        loop(i,n){
            fq[a[i]]++;
            if(a[i]!=p[i]){
                for(ll j= min(i, idx[a[i]])+1; j<max(i, idx[a[i]]); j++) tf[p[j]]= false;
            }
        }

        bool f=0;
        loop(i,n){
            if(tf[p[i]]==false && fq[p[i]]){
                f=1;
                break;
            }
        }
        if(f) no;
        else yes;
        

    }
    
    return 0;
}