//https://leetcode-cn.com/problems/is-graph-bipartite/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int vNum = graph.size();
        vector<int> visited(vNum,0);
        for(int i=0;i<vNum;i++){
            if(visited[i] == 0){
                int r = dfs(graph,visited,i,1);
                if(r == 0)
                    return false;
            }
        }
        return true;
    }
    int dfs(vector<vector<int>>& graph, vector<int>& visited, int vertex, int whichpart){
        if(visited[vertex]){
            return visited[vertex] == whichpart?1:0;
        }
        visited[vertex] =  whichpart;
        for(int c:graph[vertex]){
            int r = dfs(graph, visited, c, (whichpart % 2) + 1);
            if(r == 0)
                return 0;
        }
        return 1;
    }
};
