#include<iostream>
#include<string>
using namespace std;
string s;

string search(string s){
    string raw_s;
    char tmp_str, next_str, memo;
    raw_s = s;
    tmp_str='5';
    next_str='2';
    int del_ind = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]==next_str){
            memo = next_str;
            next_str = tmp_str;
            tmp_str = memo;
            raw_s.erase(raw_s.begin()+i-del_ind);
            del_ind += 1;
        }
    }
    return raw_s;

}
int main(){
    cin >> s;

    if(s[0]=='2' && s[s.size()-1]=='5' && s.size()%2==0){
        int counter = 0;
        while(s.size()>0){
            s = search(s);
            counter += 1;
        }
        cout << counter << endl;
    }else{
        cout << -1 << endl;
    }

}
