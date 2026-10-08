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
        vl p(n), d(n);
        input(p);
        ll imp=p[0];
        string ans="Yes";
        ll count=n-imp;
        for(int i=1; i<n; i++){
            if(p[i]>imp){
                count--;
                //d[i]=1;
                continue;
            }
            if(!count) {
                ans="No";
                break;
            }
           // d[i]=1;
            count+=imp-p[i]-1;
            imp=p[i];

            // for(int j=i; j<n; j++){
            //     if(p[j]>p[i] && p[j]>imp){ d[i]=1; break;}
            // }
            // imp=p[i];
        }
        // loop(i,n){
        //     if(d[i]==0) {ans="No"; break;}
        // }
        cout<<ans<<endl;
    }
    
    return 0;
}