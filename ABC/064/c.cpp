#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    bool color[8];
    for(int i=0; i<8; i++){
        color[i] = true;
    }
    int ans, c;
    int rate;
    int tuyoihito;
    tuyoihito = 0;
    for(int i=0; i<N; i++){
        cin >> rate;
        if(rate>=1 && rate<=399){
            c = 0;
        }else if(rate>=400 && rate<=799){
            c = 1;
        }else if(rate>=800 && rate<=1199){
            c = 2;
        }else if(rate>=1200 && rate<=1599){
            c = 3;
        }else if(rate>=1600 && rate<=1999){
            c = 4;
        }else if(rate>=2000 && rate<=2399){
            c = 5;
        }else if(rate>=2400 && rate<=2799){
            c = 6;
        }else if(rate>=2800 && rate<=3199){
            c = 7;
        }else{
            c = 8;
            tuyoihito += 1;
        }
        if(c<8 && color[c]){
            ans += 1;
            color[c] = false;
        }

    }
    cout << ans << endl;
    cout << ans << " ";
    if(ans+tuyoihito<8){
        cout << ans+tuyoihito << endl;
    }else{
        cout << 8 << endl;
    }

}
