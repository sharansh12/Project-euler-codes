#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N= 1000000;

int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int a[N+1],ans=0;
    a[0] = a[1] = 0;
    for(int i=2;i<101;i++){
        set <int> s;
        for(int j=0;j<i-1;j++){
            s.insert(a[j]^a[i-2-j]);
        }
        a[i] =0;
        while(s.count(a[i]))a[i]++;
        if(a[i])ans++;
        // if(i>36){
        //     if(a[i] != a[i-34]){
        //         cout << i << ' ' << a[i] << ' ' << a[i-34] << '\n';
        //     }
        // }
    }
    for(int i=101;i<=1000000;i++){
        a[i]= a[i-34];
        if(a[i])ans++;
    }
    cout << ans;
}
