#include<iostream>

using namespace std;

int main(){
    int n, T;
    cin >> n >> T;
    int t[n];
    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    int x = T;
    for(int i=1; i<n; i++){
        if(t[i]>=t[i-1]+T){
            x += T;
        }else{
            x += t[i] - t[i-1];
        }
    }
    cout << x << "\n";
}
