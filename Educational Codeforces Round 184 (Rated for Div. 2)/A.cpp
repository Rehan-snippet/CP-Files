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
        ll n,a,b;
        cin>>n>>a;
        vl v(n);
        ll t=n,f=0;
        int j= INT_MAX;
        input(v);
        b=v[0];
        loop(i,n){
            if(a==v[i]){
                j=min(j,i);
                f=1;
            }
            else if(a<v[i]){
                t=i;
                break;
            }
        }
        if(f){
            if(j>=(n-t)){
                if(j>0) b=v[j-1];
            }
            else {
            if(t<n) b=v[t];
            }
        }
        else{
             if(t>=(n-t)){
                if(t>0) b=v[t-1];
            }
            else {
             if(t<n) b=v[t];
            }
        }
        
        cout<<b<<endl;
    }
    
    return 0;
}