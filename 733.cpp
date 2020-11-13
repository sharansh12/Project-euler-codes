#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6+1;
int mod=10000019;
vector <int> a(N,0);
vector <vector <int> > cnt(5,vector <int> (N,0));
vector <vector <int> > sum;
map <int,int> m;

void udt(vector <int> &tr,int i,int d){
    while(i<N)(tr[i]+=d)%=mod,i+=i&-i;
}
int get(vector <int> &tr,int i){
    int res=0;
    while(i)(res+=tr[i])%=mod,i-=i&-i;
    return res;
}
int pw(int a,int t=mod-2){
    int x=1;
    while(t>0){
        if(t&1)x=x*a%mod;
        a=a*a%mod,t/=2;
    }
    return x;
}
int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i=1;i<N;i++)
        a[i]=pw(153,i);
    vector <int> v=a;
    sort(a.begin(),a.end());
    int c=0;
    for(int i=1;i<N;i++)
        m[a[i]]=++c;
    sum=cnt;
    mod=1e9+7;
    udt(cnt[0],1,1);
    for(int i=1;i<N;i++){
        int p=m[v[i]];
        for(int j=4;j;j--){
            c=get(cnt[j-1],p);
            udt(cnt[j],p,c);
            int x=get(sum[j-1],p);
            x=(x+c*v[i]%mod)%mod;
            udt(sum[j],p,x);
        }
    }
    cout << get(sum[4],N-1);
}
