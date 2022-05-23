//Question link --- > https://codeforces.com/contest/1063/problem/B
// 0 - 1 BFS : ) 
// grid bfs where 4 types of movt are possible 
// no distance added when moving up or down therefore there distance = 0 
// and other have respectfully {0,1} or {1,0} distance 
// maintaning a left right movt 2_d array and then finally checking it wiht the given x and y

// COD
#include<bits/stdc++.h>
using namespace std;

#define N 2001
#define INF 1e9 + 10
char grid[N][N];
int lev[N][N];
pair<int,int> steps[N][N];
int n,m,src_x,src_y,x,y;

vector<pair<int,int>> movts = {{1,0},{0,1},{-1,0},{0,-1}};

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}

void bfs(){
    deque<pair<int,int>> q;
    q.push_front({src_x,src_y});
    lev[src_x][src_y] = 0;
    while(!q.empty()){
        auto p = q.front();
        int v_x = p.first , v_y = p.second;
        int st_l = steps[v_x][v_y].first , st_r = steps[v_x][v_y].second;
        q.pop_front();
        for(auto movt : movts){
            int child_x = movt.first + v_x , child_y = movt.second + v_y;
            int wt = movt.second == 0 ? 0 : 1;
            if(!isValid(child_x,child_y)) continue;
            if(grid[child_x][child_y] == '*') continue;
            if(lev[child_x][child_y] > lev[v_x][v_y] + wt){
                lev[child_x][child_y] = lev[v_x][v_y] + wt;
                if(wt == 1){
                    q.push_back({child_x,child_y});
                    if(child_y > v_y)
                        steps[child_x][child_y] = {st_l,st_r+1};
                    else
                        steps[child_x][child_y] = {st_l+1,st_r};
                }
                if(wt == 0){
                    q.push_front({child_x,child_y});
                    steps[child_x][child_y] = {st_l,st_r};
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    cin>>src_x>>src_y;
    src_x -- , src_y --;
    cin>>x>>y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>grid[i][j] , lev[i][j] = INF , steps[i][j] = {0,0};
    }
    bfs();
    int st = src_y - x >=0 ? src_y - x : 0;
    int ed = src_y + y < m ? src_y+y : m-1;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=st;j<=ed;j++){
            int st_l = steps[i][j].first , st_r = steps[i][j].second;
            if(st_l<=x && st_r<=y && lev[i][j] !=INF)
                cnt ++ ;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}
