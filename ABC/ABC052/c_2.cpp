#include<iostream>
#include<algorithm>
using namespace std;

long long  solve(long long n);

int main(void){
    long long N,i,ans;

    cin >> N;

    int p[N-1];

    ans = 1;

    for(i=2;i<=N;i++){
        p[i-2]=0;
        for(int j=2; j<=i; j++){
            bool flag;
            flag = true;
            for(int k=2;k<j;k++){
                if(j%k==0) flag=false;
                break;
            }
            if(flag==true){
                while(i%j==0){
                    p[i-2]+=1;
                    i/=j; 
                }
            }
            ans*=(p[i-2]+1)/(1e9+7);
        }
    }


    cout << ans;

    return 0;
}

