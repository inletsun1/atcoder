#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int temp_max,x, N, i;
    cin >> N;
    x = 0;temp_max=0;
    char s[N];
    for (i=0; i<N; i++){
        cin >> s[i];
        if (s[i]=='I') x+=1;
        if (s[i]=='D') x-=1;
        temp_max=max(temp_max,x);
    } 
    cout << temp_max << endl;

    return 0;
}
