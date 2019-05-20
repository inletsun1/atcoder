#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 1e9 + 1;
int N, K;

int main(){
    cin >> N;
    cin >> K;
    int h[N];

    for(int i = 0; i < N; i++){
        cin >> h[i];
    }

    sort(h, h + N);

    int ans = INF;


    for(int i = 0; i <= N - K; i++){
        if((h[i+K-1] - h[i]) < ans){
            ans = h[i+K-1] - h[i];
        }
    }

    cout << ans << endl;
}

