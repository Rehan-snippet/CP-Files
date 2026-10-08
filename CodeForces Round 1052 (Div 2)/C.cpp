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
         int n;
         string s;
         cin>>n>>s;
         int flag=1;
         if((s[0]=='0' && s[1]=='1')|| (s[n-1]=='0' && s[n-2]=='1')) flag=0;
         loop(i,n-2){
            if(s[i]=='1' && s[i+1]=='0' && s[i+2]=='1'){
                flag=0; break;
            }
         }
         
         vector<int> a(n);
         if(flag){
         loop(i,n){
            int c=0;
            if(s[i]=='1') a[i]=i+1;
            else{
                while(s[i]=='0') {c++; i++;}
                i--;
                loop(j,c){
                    a[i-j]=i-c+2+j;
                }
            }
         }
        }
        if(flag){
            yes;
            output(a);
            cout<<"\n";
        }
        else no;
    }
    
    return 0;
}