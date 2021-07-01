#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7, N = 1e16;
struct node{
    int a,b,aa,bb,ab,aab,abb,aabb,c;
};
void modd(node &x){
    x.a %= mod;
    x.b %= mod;
    x.aa %= mod;
    x.bb %= mod;
    x.ab %= mod;
    x.aab %= mod;
    x.abb %= mod;
    x.aabb %= mod;
    x.c %= mod;
}
void add(node &x,const node &y){
    x.a += y.a;
    x.b += y.b;
    x.aa += y.aa;
    x.bb += y.bb;
    x.ab += y.ab;
    x.aab += y.aab;
    x.abb += y.abb;
    x.aabb += y.aabb;
    x.c += y.c;
    modd(x);
}
void add(node &x,const node &y,int p){
    int r = (1ll<<p) % mod;
    int rr = r * r %mod;
    x.a += y.a + r * y.c % mod;
    x.b += y.b + y.c ;
    x.aa += y.aa + 2 * r * y.a % mod + rr * y.c % mod;
    x.bb += y.bb + 2 * y.b + y.c;
    x.ab += y.ab + y.b * r % mod + y.a + r * y.c % mod;
    x.aab += y.aab + 2 * y.ab * r % mod + y.b * rr % mod + y.aa + 2 * y.a * r % mod + rr * y.c % mod;
    x.abb += y.abb + 2 * y.ab + y.a + y.bb * r % mod + 2 * y.b * r % mod + r* y.c % mod;
    x.aabb += y.aabb + 2 * y.abb * r % mod + y.bb * rr % mod + 2 * y.aab + 4 * y.ab * r % mod + 2 * y.b * rr % mod + y.aa + 2 * y.a * r % mod + rr * y.c % mod;
    x.c += y.c;
    modd(x);
}
node dp[60][2];

node calc(int p,int d){
    if(p<0){
        node r = {0,0,0,0,0,0,0,0,1};
        return r;
    }
    if(dp[p][d].c != -1)return dp[p][d];
    dp[p][d] = {0,0,0,0,0,0,0,0,0};
    if((1ll<<p)&N){
        add(dp[p][d],calc(p-1,d),p);
        add(dp[p][d],calc(p-1,0));
    }
    else{
        if(d==0)add(dp[p][d],calc(p-1,d),p);
        add(dp[p][d],calc(p-1,d));
    }
    return dp[p][d];
}
int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i=0;i<60;i++)
        dp[i][0].c = dp[i][1].c = -1;
    cout << calc(59,1).aabb;

}
