class Solution {
public:

    bool isCycle(int src, vector<bool> &vis, vector<int> &stack, vector<vector<int>>& adj){
        stack[src] = true;
        if(!vis[src]){
            vis[src] = true;
            for(auto i: adj[src]){
                if(!vis[i] && isCycle(i,vis,stack,adj)){
                    return true;
                }
                if(stack[i]){
                    return true;
                }
            }
        }
        stack[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        int m = pre.size();
        for(int i=0; i<m; i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vector<int> stack(numCourses,0);
        vector<bool> vis(numCourses,0);
        bool cycle = false;

        for(int i=0; i<numCourses; i++){
            if(!vis[i] && isCycle(i,vis,stack,adj)){
                cycle = true;
            }
        }

        return !cycle;
    }
};