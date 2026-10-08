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
        ll n,k,q;
        cin>>n>>k>>q;
        vl c(q), l(q), r(q), a(n+1,-1);
        //output(a);
        loop(i,q){
            cin>>c[i]>>l[i]>>r[i];

            if(c[i]==1) {
                for(int j=l[i]; j<=r[i]; j++){
                    a[j]=k;
                }
            }
        }
        loop(i,q){
            if(c[i]==2){
                ll t=0,f=0;
                for(int j=l[i]; j<=r[i]; j++){
                    if(a[j]==k) a[j]++;
                    else {
                        if(a[j-1]!=-1) {f=1; t=a[j-1]+1;}
                        if(a[j]==-1 || f) {a[j] = t++ %k;}
                        
                    }
                }
            }
        }
        for(int i=1; i<=n; i++) cout<<max(a[i],0LL)<<" ";
        cout<<endl;

    }
    
    return 0;
}