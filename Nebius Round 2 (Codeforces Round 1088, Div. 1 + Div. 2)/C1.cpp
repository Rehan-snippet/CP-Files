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
#define MOD  676767677
// memset(a, -1, sizeof(a));

int main() {
    fastio;
    test{
        ll n,k;
        cin>>n>>k;
        vl a(n), b(n);
        input(a); input(b);
        int f=0;
        ll imp= n-k;
        loop(i,imp){
            if(b[i]==-1) b[i]=a[i];
            else if ( b[i]!=a[i]) {
                f=1;
                break;
            }
        }
        if(f==0){
            for(ll i=n-imp; i<n; i++){
            if(b[i]==-1) b[i]=a[i];
            else if ( b[i]!=a[i]) {
                f=1;
                break;
                }
            }
        }
        if(f==0){
            vl c(n+1,0);
            loop(i,n){
                if(b[i]==-1) continue;
                if(c[b[i]]==1) {
                    f=1;
                    break;
                }
                c[b[i]]=1;
            }
        }

        if(f) no;
        else yes;

        
    }
    
    return 0;
}