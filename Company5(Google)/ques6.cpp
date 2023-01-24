class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto i:times){
            adj[i[0]-1].push_back({i[1]-1,i[2]});
        }

        vector<int> dist(n,INT_MAX);
        k--;

        queue<pair<int,int>> q;
        q.push({k,0});
        dist[k] = 0;

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            int src = p.first;
            int d = p.second;

            for(auto i:adj[src]){
                int node = i.first;
                int dis = i.second;

                if(d+dis<dist[node]){
                    dist[node] = dis+d;
                    q.push({node,dis+d});
                }
            }
        }

        for(auto i:dist){
            if(i==INT_MAX){
                return -1;
            }
        }

        return *max_element(dist.begin(),dist.end());
    }
};