#include<bits/stdc++.h>
using namespace std;
vector<int> DFS(int index, vector<vector<int>>& dis, vector<int>& w){ // return the farthest node and its distance with the index node
    vector<bool> visit(w.size(), false);
    visit[index] = true;
    vector<int> distance(w.size(), 0);
    queue<int> q;
    q.push(index); 
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        for(int i = 0; i < w.size(); i++){
            if(!visit[i] && dis[idx][i] != 0){
                distance[i] = distance[idx] + dis[idx][i];
                visit[i] = true;
                q.push(i);
            }
        }
    }
    int max_distance = 0, max_idx;
    for(int i = 0; i < w.size(); i++){
        if(i != index && distance[i] + w[i]> max_distance){
            max_idx = i;
            max_distance = distance[i] + w[i];
        }
    }
    return vector<int>{max_idx, max_distance};
}
int main(){
    int n;
    cin>>n;
    vector<int> w;
    int weight;
    for(int i = 0; i < n; i++){
        cin>>weight;
        w.push_back(weight);
    }
    int a, b, c;
    vector<vector<int>> dis(n, vector<int>(n, 0));
    for(int i = 1; i < n; i++){
        cin>>a>>b>>c;
        dis[a-1][b-1] = c;
        dis[b-1][a-1] = c; 
    }
    vector<int> res1, res2;
    // The extension of Tree's Diameter problem
    // link to Tree's Diameter problem
    // URL: https://zhuanlan.zhihu.com/p/349814050
    // link to the original problem
    // URL: https://www.nowcoder.com/discuss/1078566 (第五题--修公路)
    res1 = DFS(0, dis, w);
    res2 = DFS(res1[0], dis, w);
    cout<<res2[1] + w[res1[0]]<<endl;
    return 0;
}