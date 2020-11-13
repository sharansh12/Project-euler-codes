#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int a,int b){
    if(a==b)return 1;
    if(b>a)return 0;
    string st=to_string(a);
    for(int i=1;i<st.size();i++){
        int p=stoll(st.substr(i));
        int q=stoll(st.substr(0,i));
        if(check(p,b-q))return 1;
    }
    return 0;
}
int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int ans=0;
    for(int i=9;i<=(int)1e6;i++){
        if(i%9>1)continue;
        if(check(i*i,i))ans+=i*i;
    }
    cout << ans;
}
