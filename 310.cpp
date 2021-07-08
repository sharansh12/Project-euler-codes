#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N= 100000,K= 1<<7;
int a[N+1],cnt[K][3];

int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int ans=0;
    for(int i=0;i<=N;i++){
        unordered_set <int> s;
        for(int j=1;j*j<=i;j++){
            s.insert(a[i-j*j]);
        }
        while(s.count(a[i]))a[i]++;
        ans = max(ans,a[i]);
        cnt[a[i]][0]++;
    }
    // cout << ans << '\n';
    ans =0;
    int sum=0;
    for(int i=0;i<K;i++){
        sum+=cnt[i][0];
        for(int j=0;j<K;j++){
            cnt[i][1] += cnt[j][0]*cnt[i^j][0];
        }
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            cnt[i][2] += cnt[j][1]*cnt[i^j][0];
        }
    }
    ans = cnt[0][2];
    int r =cnt[0][0];
    ans -= r;
    ans -= r*(r-1)*3;
    int s = sum-r;
    ans -= r*s*3;
    ans/=6;
    ans += r*s;
    ans+=r;
    ans+= r*(r-1);
    cout << ans << '\n';
    ans=0;
    // for(int i=0;i<=N;i++){
    //     for(int j=0;j<=i;j++){
    //         for(int k=0;k<=j;k++)
    //             if((a[i]^a[j]^a[k]) == 0)
    //                 ans++;
    //     }
    // }
    cout << ans;
}
