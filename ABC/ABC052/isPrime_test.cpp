#include<iostream>
#include<algorithm>
using namespace std;

bool isPrime(int j);

int main(void){
    int i;
    bool bl;
    cin >> i;
    bl=isPrime(i);
    if(bl){
        cout << "true" <<endl;
    }else{
    cout << "false" << endl;
    }
    return 0;
}

bool isPrime(int j){
    bool flag;
    flag = true;
    if(j==2) {
        flag = true;
    }else if(j==1){
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
