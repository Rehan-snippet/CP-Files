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
        string s;
        cin>>s;
        int ans=-1,f=1;
        int n=s.size();
        int a=INT_MAX,b=-1;
        int c=-1, d=INT_MAX;
        loop(i,n-1){
            if(s[i]=='>'){
                if(s[i+1]=='<' || s[i+1]=='*') {
                    f=0;
                    break;
                }
            }
            else if(s[i]=='*'){
                if(s[i+1]=='<' || s[i+1]=='*') {
                    f=0;
                    break;
                }
            }
        }
        if(f){
            loop(i,n){
                if(s[i]=='*') {
                    a=min(a,i);
                    b=i;
                }
                else if(s[i]=='<'){
                    c=i;
                }
                else if(s[i]=='>'){
                    d=min(d,i);
                }
            }
            if(a>b){
                if(c>=0){
                    if(d<INT_MAX){
                        ans=max((c+1),(n-d));
                    }
                    else ans=c+1;
                }
                else ans=n-d;
            }
            else{
                ans=max((b+1),(n-a));
            }
        }
        cout<<ans<<endl;

    }
    
    return 0;
}