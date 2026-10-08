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
        ll n,x,y;
        cin>>n>>x>>y;
        string s,ans;
        cin>>s;
        x=abs(x); y=abs(y);
        if(x>n || y>n) ans="NO";
        else{
            ll imp=x+y;
            loop(i,n){
                if(s[i]=='4') imp--;
                else imp-=2;
            }
            if(imp<=0) ans="YES";
            else ans="NO";
        }
        cout<<ans<<endl;
    }
    
    return 0;
}