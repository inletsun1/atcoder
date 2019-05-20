#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int N;
vector<pair<pair<int, int>, int> > v;

int main(){
    cin >> N;

    int x, y, h;
    int xt, yt, ht;
    for(int i = 0; i < N; i++){
        cin >> x;
        cin >> y;
        cin >> h;
        v.push_back(make_pair(make_pair(x, y), h));
        if(h!=0){
            xt = x;
            yt = y;
            ht = h;
        }
    }

    int H;
    bool flag = true;
    for(int i = 0; i <= 100 && flag; i++){
        for(int j = 0; j <= 100 && flag; j++){
            H = abs(i - xt) + abs(j - yt) + ht;
            for(int k = 0; k < N && flag; k++){
                h = max(H - abs(i - v[k].first.first) - 
                    abs(j - v[k].first.second), 0); 
                if(h == v[k].second){
                    if((k == N - 1) && (H > 0)){
                        flag = false;
                        x = i;
                        y = j;
                    }
                }else{
                    break;
                }
            }
        }
    }

    cout << x << " " << y << " " << H << endl;
}
