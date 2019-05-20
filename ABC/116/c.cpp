#include<iostream>
using namespace std;

int a[101];
int N;

bool water(){
    int s,g;
    s = -1; 
    g = -1;
    for(int i = 0; i < N; i++){
        if((s < 0) && a[i] > 0){
            s = i;  
        }
        if((s >= 0) && (a[i] == 0) && (g < 0)){
            g = i - 1;
            break;
        }
        if(s >= 0 && i == N - 1){
            g = i;
        }
    }
    //cout << "s:" << s << ", g:" << g << endl;
    bool flag = false;
    for(int i = s; i <= g && s >= 0; i++){
        flag = true;
        a[i] -= 1;
    }
    /*
    for(int i = 0; i < N; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    */
    return flag;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int ans = 0;
    while(water()){
        ans += 1;
    }
    cout << ans << endl;
}
