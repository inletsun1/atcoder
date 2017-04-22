#include<iostream>
using namespace std;

int main(void){
	int res;
	long long int ns,x;

	cin >> x;
	ns=x/11;
	res=x-11*ns;
	if(res==0){
		ns=ns*2;
	}else if(res<7){
		ns=ns*2+1;
	}else{
		ns=(ns+1)*2;
	}
	cout << ns << endl;
	return 0;
}
