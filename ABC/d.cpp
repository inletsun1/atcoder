#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector< int> a, b;
    int tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i=0; i<N; i++){
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int k;
    k = 0;
    while(2**k<=a[N-1]){
        for(int i=0; i<N; i++){
            vector< int>::iterator iter;
            iter = lower_bound(b.begin(), b.end(), a[i]+2**k);
        }
    }
}
