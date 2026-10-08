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
        string s;
        cin>>s;
        bool f=false;
        loop(i,n){
            if(s[i]=='1'){
                for(int j=i+1; j<n; j++){
                    if(s[j]=='0'){
                        f=true;
                        break;
                    }
                }
                break;
            }
        }
        if(!f) cout<<"Bob"<<endl;
        else{
            ll l=0, r=n-1, one=0, zero=0;
            vl ans;
            while(l<r){
                while(s[l]!='1' && l<n) l++;
                
                while(s[r]!='0' && r>=0) r--;
                if(l<r) {
                    ans.pb(++l);
                    ans.pb(r+1);
                    r--;
                }
            }
            sort(all(ans));
            cout<<"Alice\n"<<ans.size()<<endl;
            output(ans);
            cout<<endl;
        }

    }
    
    return 0;
}