#include<iostream>
using namespace std;

int main(void){
	string s;
	
	cin >> s;

	int slen;
	slen = s.length();
	int start_indx;
	for(int i=0;i<slen;i++){
		if(s.substr(i,1)=="A") {
			start_indx=i+1;
			break;
		}
		
	}
	int goal_indx;
	for(int i=slen-1; i>=0; i--){
		if(s.substr(i,1)=="Z") {
			goal_indx=i+1;
			break;
		}
	}
	cout << (goal_indx-start_indx+1) << endl;
	return 0;
}
