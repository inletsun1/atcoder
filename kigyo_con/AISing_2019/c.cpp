#include<iostream>
#include<vector>

using namespace std;

const bool BLACK = false;
const bool WHITE = true;


int H, W;
char s[401][401];
bool isReached[401][401];
bool mat[401][401];

void init_isReached(){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            isReached[i][j] = false;
        }
    }
}

int search_root(int h, int w){

    cout << "first roots" << endl;
    cout << "start:" << "(" << h << ", "<< w << " )" << endl;
    int ans = 0;
    
    init_isReached();
    isReached[h][w] = true;

    vector<pair<int, int > > v;
    vector<bool > color;
    int ud[4] = {1, 0, -1, 0};
    int rl[4] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++){
        if((h + ud[i] >= 0) && (h + ud[i] < H) && (w + rl[i] >= 0) && (w + rl[i] < W)){
            if(isReached[h+ud[i]][w+rl[i]]){
                continue;
            }else if(s[h+ud[i]][w+rl[i]] == '.'){
                v.push_back(make_pair(h + ud[i], w + rl[i]));
                color.push_back(WHITE);
                ans += 1;
                cout << "add:" << "(" << h + ud[i] << ", "<< w + rl[i] << " ), ";
            }
            isReached[h+ud[i]][w+rl[i]] = true;
        }
    }
    cout << endl;

    cout << "second roots" << endl;
    pair<int, int > pos;
    bool tmp_color;
    while(v.size() > 0){
        pos = v[0];
        v.erase(v.begin());
        tmp_color = color[0];
        color.erase(color.begin());
        
        h = pos.first;
        w = pos.second;

        cout << "start:" << "(" << h << ", "<< w << " )" << endl;
        for(int i = 0; i < 4; i++){
            if((h + ud[i] >= 0) && (h + ud[i] < H) && (w + rl[i] >= 0) && (w + rl[i] < W)){
                if(isReached[h+ud[i]][w+rl[i]]){
                    continue;
                }else if(((s[h+ud[i]][w+rl[i]] == '.') && tmp_color) || (((s[h+ud[i]][w+rl[i]] == '#') && !tmp_color))){
                    v.push_back(make_pair(h + ud[i], w + rl[i]));
                    color.push_back(!tmp_color);
                    cout << "add:" << "(" << h + ud[i] << ", "<< w + rl[i] << " ), ";
                    if(tmp_color){
                        ans += 1;
                    }
                }
                isReached[h+ud[i]][w+rl[i]] = true;
            }
        }
        cout << endl;
    }
    return ans;
}

int main(){
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> s[i][j];
            mat[i][j] = false;
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(s[i][j] == '#'){
                ans = ans + search_root(i, j);
            }
        }
    }

    cout << ans << endl;
}
