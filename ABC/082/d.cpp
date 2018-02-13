#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int > f, t;
bool isF[9000][17000], isT[9000][17000];

int main(){
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    bool flag = true;
    int tmp = 0;
    int sum_f, sum_t;
    sum_f = 0;
    sum_t = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='T' || i==s.size()-1){
            if(s[i]=='F' && i==s.size()-1){
                tmp += 1;
            }
            if(flag){
                f.push_back(tmp);
                sum_f += tmp;
                //cout << "add to F: " << tmp << endl;
            }else{
                t.push_back(tmp);
                sum_t += tmp;
                //cout << "add to T: " << tmp << endl;
            }
            flag = !flag;
            tmp = 0;
        }else{
            tmp += 1;
        }

    }

    //cout << "f_size: " << f.size() << " t_size: " << t.size() << endl;
    //cout << "sum_f: " << sum_f << " sum_t: " << sum_t << endl;

    if((x<-sum_f && x>sum_f) || (y<-sum_t && y>sum_t)){
        cout << "No" << endl;
        return 0;
    }
    for(int i=0; i<f.size(); i++){
        for(int j=0; j<=2*sum_f + 1; j++){
            isF[i][j] = false;
        }
    }
    isF[0][sum_f] = true;

    for(int i=0; i<t.size(); i++){
        for(int j=0; j<=2*sum_t + 1; j++){
            isT[i][j] = false;
        }
    }
    isT[0][sum_t] = true;
    

    for(int i=1; i<=f.size(); i++){
        for(int j=0; j<=2*sum_f+1; j++){
            if(j-f[i-1]<0 && j+f[i-1]>2*sum_f+1){
                //cout << "-: " << j-f[i-1] << " +:" << j+f[i-1] << endl;
                isF[i][j] = false;
            }else{
                isF[i][j] = isF[i-1][j-f[i-1]] || isF[i-1][j+f[i-1]];
            }
            /*
            if(isF[i][j]){
                cout << "i= " << i << " x: " << j-sum_f << endl;
            }
            */

        }
    }

    if(!isF[f.size()][x+sum_f]){
        cout << "No" << endl;
        return 0;
    }

    for(int i=1; i<=t.size(); i++){
        for(int j=0; j<=2*sum_t+1; j++){
            if(j-t[i-1]<0 && j+t[i-1]>2*sum_t+1){
                //cout << "-: " << j-t[i-1] << " +:" << j+t[i-1] << endl;
                isT[i][j] = false;
            }else{
                isT[i][j] = isT[i-1][j-t[i-1]] || isT[i-1][j+t[i-1]];
            }
            /*
            if(isT[i][j]){
                cout << "i = " << i << " y: " << j-sum_t << endl;
            }
            */

        }
    }
    
    if(!isT[t.size()][y+sum_t]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}
