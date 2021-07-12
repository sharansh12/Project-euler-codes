#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e18,N=10000,K=1<<13;
int dp[N+1][K],mex[N+1];

int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    dp[2][0]=1;
    mex[2]=1;
    for(int i=3;i<=N;i++){
        for(int j=1;j<K;j++){
            dp[i][j^(mex[i-1]+1)] = (dp[i][j^(mex[i-1]+1)] + dp[i-2][j-1]) % mod;
            dp[i][j^(mex[i-2]+1)] = (dp[i][j^(mex[i-2]+1)] + dp[i-1][j-1]) % mod;
        }
        dp[i][mex[i-1]+1] = (dp[i][mex[i-1]+1] + 1) % mod;
        dp[i][mex[i-2]+1] = (dp[i][mex[i-2]+1] + 1) % mod;
        while(dp[i][mex[i]])mex[i]++;
    }
    cout << dp[N][0];
}
