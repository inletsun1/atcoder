#include<iostream>
using namespace std;
int main(void){
	unsigned long N, M, i, ans, temp_ans;
	
	cin >> N >> M;
	
	ans=0;
	for(i=1;i<=N;i++){
		temp_ans = i+(M-2*i)/4;
		if (ans<temp_ans){
			ans = temp_ans;
		}
	}

	cout << ans << endl ;
	return 0;
}
