#include<iostream>
using namespace std;
int main(void){
	long long int p;
	int N,i;

	cin >> N;
	p=1;
	for (i=1;i<=N;i++){
		p = (p*i)%1000000007;
	}
	cout << p << endl;
return 0;
}
