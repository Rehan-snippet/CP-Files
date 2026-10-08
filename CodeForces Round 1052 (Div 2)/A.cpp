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
        ll n;
        cin>>n;
        vl a(n);
        vector<int> b(n+1,0),c(n+1,0);
        loop(i,n){
            cin>>a[i];
            b[a[i]]++;
        }
        // loop(i,n+1){
        //     c[b[i]]++;
        // }
        sort(allr(b));
        // output(b);
        // cout<<"\n";
        loop(i,n){
            loop(j,n){
                if(b[j]<b[i] || !b[j]) break;
                else c[i]+=b[i];
            }
            if(!b[i]) break;
        }
        // output(c);
        // cout<<"\n";
        cout<<*max_element(all(c))<<endl;

    }
    
    return 0;
}