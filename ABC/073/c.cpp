#include<iostream>
#include<set>

using namespace std;

int N;
int main(){
    cin >> N;
    int a;
    set<int > S;
    set<int >::iterator iter;
    for(int i=0; i<N; i++){
        cin >> a;
        iter = S.find(a);
        if(iter==S.end()){
            S.insert(a);
        }else{
            S.erase(a);
        }
    }
    cout << S.size() << endl;
}
