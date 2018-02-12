#include<iostream>
using namespace std;

int A, B, C, D, E, F;
int main(){
    cin >> A >> B >> C >> D >> E >> F;
    int water, sugar, total;
    water = 0;
    sugar = 0;
    for(int a=0; 100*A*a<=F; a++){
        for(int b=0; 100*A*a+100*B*b<=F; b++){
            for(int c=0; 100*A*a+100*B*b+C*c<=F; c++){
                for(int d=0; 100*A*a+100*B*b+C*c+D*d<=F; d++){
                    total = 100*A*a+100*B*b+C*c+D*d;
                    if(((C*c+D*d)<=E*(A*a+B*b)) && (total*sugar<=(C*c+D*d)*(water+sugar))){
                        water = 100*(A*a + B*b);
                        sugar = C*c + D*d;
                    }
                }
            }
        }
    }
    cout << water+sugar << " " << sugar << endl;
}
