#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(6);
    v.push_back(5);    //v.pop_back();
    //v.erase(v.begin()+1);
    //v.pop_back();
    int sz=v.size();
    sort(v.begin(),v.begin()+3); //sorts 3 elements O(nlogn)
 for(int i=0; i<sz; i++){
    cout<<v[i]<<" ";
 }
 cout<<"\n";

   // sort(v[0],v[0]+2);
    v.erase(v.begin());
    deque<int> dq;
    dq.push_back(9);
    dq.push_back(3);
    dq.push_front(13);
    dq.push_front(33);
    dq.pop_back();
   // int max=max_element(dq.begin(),dq.end());
    //cout<<max<<"\n";
    for (int i=0; i<dq.size();i++){
        cout<<dq[i]<<" ";
    }
    cout<<"\n";   
    cout<<v.size()<<"\n";
    cout<<v[0]<<" "<<v[1]<<"\n";
    set<int> st; //set doesn't have any index
    st.insert(7);
    st.insert(88);
    st.insert(0); //O(logn)
    for (auto i:st) { //its basically printing a copoied version of the elements
        cout<<i<<" ";
    }
    cout<<"\n";
     set<int, greater<int>> siu={4,6,3}; //set is in acending order 
     siu.insert(6);
     siu.insert(10);
     siu.insert(3);
     siu.insert(33);
     siu.erase(10);
     for(auto x:siu) cout<<x<<" ";
     cout<<"\n";
    cout<<*siu.rbegin()<<"\n";
     multiset<int> ms;
     ms.insert(30);
     ms.insert(66);
     ms.insert(66); //will be removed first
     ms.erase(66);
    // ms.erase(ms.find(66));
     for (auto x:ms) cout<<x<<" ";
     cout<<"\n";

     queue<int> q; //first in first out
    q.push(99);
    q.push(2);
    q.push(88);
    cout<<q.back()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    cout<<"\n";
    //while q.empty!=1
    stack<int> sk; //first in last out or last in first out
    sk.push(99);
    sk.push(2);
    sk.push(88);
    cout<<sk.top()<<" ";
    sk.pop();
    cout<<sk.top()<<" ";
    sk.pop();
    cout<<sk.top()<<" ";
    //string s;
    //cin>>s;
    //cout<<s;
    string str; cin>>str;

    stack<char> s;
   /*for(auto x:str) {
        if(x=='(') s.push(x);
        else {
            if(s.empty()){
                cout<<"Imabalanced"<<"\n";
                s.push(x);
                break;
            }
            else s.pop();
        }
    }
     if(s.empty()) cout<<"Balanced";*/
     pair<int,char> p;

     p.first=45;
     p.second='c';
     cout<<p.first<<" "<<p.second;
    return 0;
}

