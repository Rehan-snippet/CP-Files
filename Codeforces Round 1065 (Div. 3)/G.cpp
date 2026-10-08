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
#define pi 3.14159265358979323846L

int main() {
    fastio;
    test{
        ll n;
        cin>>n;
        vl p(n), b(n,0);
        vector<pair<ll,ll>> edge;
        input(p);
        ll imp=n+1;
        b[p[0]]=1;
        string ans="Yes";


        ll count=n-imp;

        for(int i=0; i<n; i++){
            if(b[p[i]]){
                for(int j=p[i]+1; j<imp; j++){
                    if(b[j]!=1){
                    edge.pb({j,p[i]});
                    b[j]=1;
                    }
                }
            }
            // if(p[i]>imp){
            //     if(b[p[i]]!=1) edge.pb({p[i],imp});
            //     b[p[i]]=1;
            //     count--;
            //     continue;
            // }
            // if(!count) {
            //     ans="No";
            //     break;
            // }
            // int j=i, index=0;
            // while(j<n){
            //     if(p[j]>imp){
            //         if(b[p[j]]!=1) edge.pb({p[j],imp});
            //         b[p[j]]=1;
            //         if(!index) index=j;
            //     }
            //     j++;
            // }
            // edge.pb({p[index],p[i]});
            // count+=imp-p[i]-1;
            // for(int k=p[i]+1; k<imp; k++){
            //     edge.pb({k,p[i]});
            //     b[k]=1;
            // }
            imp=p[i];
        }
        cout<<ans<<endl;
        if(ans=="Yes"){
            for(auto x:edge){
                cout<<x.first<<" "<<x.second<<endl;
            }
        }
        // output(b); cout<<endl;
    }
    
    return 0;
}