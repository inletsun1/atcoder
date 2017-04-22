#include<iostream>
#include<algorithm>
using namespace std;

long long  solve(long long n);

int main(void){
    long long N,i,ans;

    cin >> N;
    ans = 0;
    for(i=0;i<N;i++){
        ans = ans + solve(i+1)%1000000007;
    }

    cout << ans;
    return 0;
}

long long solve(long long n){
    long long i,ans;
    ans = 0;
    for (i=1;i<=n;i++){
        if(n%i==0){
            ans+=1;
        }
    }
    return ans;
}
