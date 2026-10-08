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
            aji^=a[i];
            mai^=b[i];
            // if(i%2==0) {
            //     if(a[i]!=b[i]) move=1;
            // }
            // else if(i%2) {
            //     if(a[i]!=b[i]) move =2; 
            // }
        }
        ll flag =1, t;
        while(flag){
            flag=0;
            loop(i,n){
                t=a[i]^b[i];
                if(i%2==0){
                    if(((aji^t) - (mai^t)) > (aji-mai)){
                        aji^=t; mai^=t;
                        //flag=1;
                    }
                }
                else{
                    if(((aji^t) - (mai^t)) < (aji-mai)){
                        aji^=t; mai^=t;
                        //flag=1;
                    }
                }
            }
        }
        string ans;
        if(aji ==mai) ans="Tie";
        else if(aji>mai) ans="Ajisai";
        else ans="Mai";
        cout<<ans<<endl;
    }
    
    return 0;
}