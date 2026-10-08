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
        vl a(n),b(n);
        input(a); input(b);
        ll aji=0,mai=0, move=0;

        loop(i,n){
            if(a[i]==1) aji++;
            if(b[i]==1) mai++;
            if(i%2==0) {
                if(a[i]!=b[i]) move=1;
            }
            else if(i%2) {
                if(a[i]!=b[i]) move =2; 
            }
        }
        string ans;
        aji%=2; mai%=2;
        if((aji%2) ==(mai%2)) ans="Tie";
        else if(move==1) ans="Ajisai";
        else if(move==2) ans="Mai";
        else if(move==0) {
            if(aji>mai) ans="Ajisai";
            else ans="Mai";
        }
        cout<<ans<<endl;
    }
    
    return 0;
}