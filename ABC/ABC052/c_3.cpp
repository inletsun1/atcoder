#include<iostream>
#include<algorithm>
using namespace std;

bool isPrime(int j);

int main(void){
    long long ans;
    int N;
    cin >> N;
    ans = 1;

    //割る素数
    for(int i=2;i<=N;i++){
        int tmp;//割れる回数
        tmp = 0;
        if(isPrime(i)==true){
            //cout << i << endl;
            //2~Nにおいてiで割れる回数の総和
            for(int j=i;j<=N;j++){
               int tmpj=j;
               while(tmpj%i==0){
                tmp+=1;
                tmpj=tmpj/i;
               //cout << "i=" << i << "j=" << j << "j per i="<< j%i  <<"tmp=" << tmp << endl;
               } 
            }
            ans = (tmp+1)*ans%1000000007;
        }
    }
    cout << ans;
    return 0;
}

bool isPrime(int j){
    bool flag;
    flag = true;
    if(j==2) {
        flag = true;
    }else{
        for(int i=2; i<=j-1; i++){
            if(j%i==0){
                flag = false;
                break;
            }
        }
    }
    return flag;
}
