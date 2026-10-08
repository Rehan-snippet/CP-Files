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

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl p(n);
        input(p);
        ll idx1=-1, idx2=-1, big=-1;
        loop(i,n){
            if(p[i]==n-i) continue;
            else{
                idx1=i;
                big=n-i;
                break;
            }
        }
        if(idx1!=-1){
            loop(i,n){
                if(p[i]==big){
                    idx2=i;
                    break;
                }
            }
        }
        if(idx1==-1){
            output(p);
        }
        else{
            ll imp=idx2+1;
            loop(i,idx1) cout<<p[i]<<" ";
            while(idx2!=idx1) cout<<p[idx2--]<<" ";
            cout<<p[idx2]<<" ";
            while(imp!=n) cout<<p[imp++]<<" ";
            
            cout<<endl;
        }
        //cout<<idx1<<" "<<idx2<<endl;
        
    }
    
    return 0;
}