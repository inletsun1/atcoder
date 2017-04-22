#include<iostream>
using namespace std;

char sheep(char tb, char j);
char wolf(char tb, char j);

int main(void){
	int i,N,ans;
	
	ans = 0;

	cin >> N;
	
	char animal[N+1];

	for(i=0;i<N;i++){
		cin << animal[i];
	}
	animal[N]=animal[0];

	char judge[N];
	for(i=1;i<=N;i++){
		judge[i]=sheep(judge[i-1], animal[i]);
	}
	if (judge[0]==judge[1]){
		ans = ans+1;
	}

	

	char judge[N];
	for(i=1;i<=N;i++){
		judge[i]=sheep(judge[i-1], animal[i]);
	}
	if (judge[0]==judge[1]){
		ans = ans+1;
	}



	char judge[N];
	for(i=1;i<=N;i++){
		judge[i]=sheep(judge[i-1], animal[i]);
	}
	if (judge[0]==judge[1]){
		ans = ans+1;
	}


	char judge[N];
	for(i=1;i<=N;i++){
		judge[i]=sheep(judge[i-1], animal[i]);
	}
	if (judge[0]==judge[1]){
		ans = ans+1;
	}
return 0;
}

char sheep(char tb, char j){
	if(tb=='S'){
		if(j=='o'){
			j='o';
		}else if(j=='x'){
			j='x';
		}
	}else if(tb=='W'){
		if(j=='o'){
			j='x';
		}else if(j=='x'){
			j='o';
		}
	return j;
}
char wolf(char tb, char j){
	if(tb=='W'){
		if(j=='o'){
			j='o';
		}else if(j=='x'){
			j='x';
		}
	}else if(tb=='S'){
		if(j=='o'){
			j='x';
		}else if(j=='x'){
			j='o';
		}
	return j;
}
