#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int N;
int s[100];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s[i];
    }
    sort(s, s+N);
    int cum[N];
    cum[0] = s[0];
    for(int i=1; i<N; i++){
        cum[i] = cum[i-1] + s[i];
    }
    int ans = cum[N-1];
    for(int i=0; i<N; i++){
        if(ans%10==0){
            if(s[i]%10!=0){
                cout << ans - s[i] << endl;;
                return 0;
            }
        }else{
            cout << ans << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
    
}
