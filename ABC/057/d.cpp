#include<iostream>
#include<algorithm>
#include<functional>
#include<cstdio>

using namespace std;

long long int Pascal_triangle(long long int n, long long int i, long long int* memo){
    if(n<=1|i==0|i==n) return memo[n][i] = 1;
    if(memo[n][i] == 0) return memo[n][i] = Pascal_triangle(n-1, i-1, *memo) + Pascal_triangle(n-1, i, *memo);
    return memo[n][i];
}

int main(){
    long long int N, A, B;
    cin >> N >> A >> B;

    double v[N];

    for(long long int i=0; i<N; i++){
        cin >> v[i];
    }
    sort(v, v + N, greater<long long int>());



    double ans_sum = 0;
    double ans_mean = 0;
    long long int ans_num = 1;
    long long int vA_num = 0;

    for(long long int i=0; i<A; i++){
        ans_sum += v[i];
        if(v[i] == v[A-1]) vA_num += 1;
    }

    ans_mean = ans_sum/((double)A);
    long long int tmp = 0;
    for(long long int i=0; i<N; i++){
        if(v[i] == v[A-1]) {
            tmp += 1;
        }else if(v[i]<v[A-1]) break;
    }

    if(v[0] == v[A-1]) {
        long long int finish = min(B, tmp);
        long long int memo[tmp][finish+1];
        for(int i=0; i<tmp; i++){
            for(int j=0; j<finish+1; j++){
                memo[i][j] = 0;
            }
        }
        long long int ans = Pascal_triangle(tmp, A, *memo);
        long long int start = ans;
        for(long long int i=A; i<finish; i++){
            start = (start * (tmp-i))/(i+1);
            ans = ans + start;
        }
        printf("%.6lf\n", ans_mean);
        cout << ans << "\n";
        return 0;
    }else{
        long long int memo[tmp][vA_num+1];
        for(int i=0; i<tmp; i++){
            for(int j=0; j<vA_num+1; j++){
                memo[i][j] = 0;
            }
        }
        printf("%.6lf\n", ans_mean);
        cout << Pascal_triangle(tmp, vA_num, *memo) << "\n";
    }
}
