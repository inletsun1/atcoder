#include<iostream>
#include<map>
using namespace std;

int N;
int main(){
    cin >> N;
    map<int, int > T;
    int a;
    for(int i=0; i<N; i++){
        cin >> a;
        T[a-1] += 1;
        T[a] += 1;
        T[a+1] += 1;
    }
    map<int, int >::iterator iter;
    int ans;
    ans = 0;
    for(iter=T.begin(); iter!=T.end(); iter++){
        pair<int, int > item = *iter;
        if(item.second >= ans){
            ans = item.second;
        }
    }
    cout << ans << endl;
}
