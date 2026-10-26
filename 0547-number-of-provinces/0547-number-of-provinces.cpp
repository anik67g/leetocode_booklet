class Solution {
void dfs(int node, vector<vector<int>>& isConnected, vector<int>&vis) {
vis[node] = 1;  // Mark the current node as visited

    for (int it = 0; it < isConnected.size(); it++) {
        // If a connection exists and the node is not visited
        if (isConnected[node][it] == 1 && !vis[it]) {
            dfs(it, isConnected, vis);
        }
    }
}


public:
int findCircleNum(vector<vector<int>>& isConnected) {
int n = isConnected.size();
vector<int> vis(n, 0);


    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;  // Found a new province
            dfs(i, isConnected, vis);
        }
    }

    return cnt;
}


};
