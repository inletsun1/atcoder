#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	float N, M;
	
	unsigned long ans,i,temp_ans;

	cin >> N >> M;
	ans=0;
	for (i=0;i<=N; i++){
		temp_ans =(unsigned long)(M/4+i/2);
		if(temp_ans>ans) ans = temp_ans;
	}
	cout << ans << endl;

return 0;
}
