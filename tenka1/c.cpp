#include<iostream>
using namespace std;

int main(){
    long long int N;
    cin >> N;
    int flag = 1;
    for(long long int h = 1; h<=3500; h++){
        if (flag == 0){
            break;
        }
        for(long long int n = h; n<=3500; n++){
            if(flag == 0){
                break;
            }
            if(((4*h*n - n*N - h*N) > 0) and ((h*n*N)%(4*h*n - n*N - h*N))==0){
                long long int w = (h*n*N)/(4*h*n - n*N - h*N);
                cout << h << ' ' << n << ' ' << w << endl;
                flag = 0;
                break;
            }
        }
    }

}
