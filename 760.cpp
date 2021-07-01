#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e18, mod = 1e9 + 7;
pair <int,int> dp[62][3];

pair <int,int> calc(int p,int d){
    if(p==-1)return {0,1};
    if(dp[p][d].first != -1)return dp[p][d];

    int sum = 0, cnt =0;

    if(N & (1ll<<p)){
        if(d == 0){
            cnt += calc(p-1, d).second*2;
            sum += (calc(p-1,d).first + 2*(1ll<<p)%mod * calc(p-1, d).second)*2%mod;

            cnt += calc(p-1,1).second;
            sum += calc(p-1,1).first;
        }
        else if(d == 1){
            cnt += calc(p-1, d).second;
            sum += (calc(p-1,d).first + 2*(1ll<<p)%mod * calc(p-1, d).second)%mod;

            cnt += calc(p-1, 2).second*2;
            sum += (calc(p-1,2).first + 2*(1ll<<p)%mod * calc(p-1, 2).second)*2%mod;

            cnt += calc(p-1,2).second;
            sum += calc(p-1,2).first;
        }
        else{
            cnt += calc(p-1, 2).second;
            sum += (calc(p-1,2).first + 2*(1ll<<p)%mod * calc(p-1, 2).second)%mod;

            cnt += calc(p-1, 2).second*2;
            sum += (calc(p-1,2).first + 2*(1ll<<p)%mod * calc(p-1, 2).second)*2%mod;

            cnt += calc(p-1,2).second;
            sum += calc(p-1,2).first;
        }
    }
    else{
        if(d == 0){
            cnt += calc(p-1,0).second;
            sum += calc(p-1,0).first;
        }
        else if(d == 1){
            cnt += calc(p-1, 0).second;
            sum += (calc(p-1,0).first + 2*(1ll<<p) %mod * calc(p-1, 0).second)%mod;

            cnt += calc(p-1, 1).second*2;
            sum += (calc(p-1,1).first + 2*(1ll<<p) %mod * calc(p-1, 1).second)*2%mod;

            cnt += calc(p-1,2).second;
            sum += calc(p-1,2).first;
        }
        else{
            cnt += calc(p-1, 2).second;
            sum += (calc(p-1,2).first + 2*(1ll<<p) % mod * calc(p-1, 2).second) % mod;

            cnt += calc(p-1, 2).second*2;
            sum += (calc(p-1,2).first + 2*(1ll<<p) %mod * calc(p-1, 2).second)*2 %mod;

            cnt += calc(p-1,2).second;
            sum += calc(p-1,2).first;
        }
    }
    sum %= mod;
    cnt %= mod;
    return dp[p][d] = {sum, cnt};
}
int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i=0;i<=61;i++){
        for(int j=0;j<3;j++)
            dp[i][j] = {-1,-1};
    }
    cout << calc(61,0).first;
}
