class Solution {
public:
    bool isCyclic(vector<vector<int>>& graph, int curr, vector<int>& visited) {
        if(visited[curr] == 1) {
            return true;
        }
        
        visited[curr] = 1;
        for(int i=0; i<graph[curr].size(); i++) {
            if(visited[graph[curr][i]] != 2 && isCyclic(graph, graph[curr][i], visited)) {
                return true;
            }
        }
        visited[curr] = 2;
        return false;
    }
    bool canFinish(int nC, vector<vector<int>>& prereq) {
        vector<vector<int>> graph(nC);
        for(int i=0; i<prereq.size(); i++){
            graph[prereq[i][0]].push_back(prereq[i][1]);  
        }
        vector<int> visited(nC, 0);
        for(int i=0; i<nC; i++){
            if(!visited[i] && isCyclic(graph, i, visited)){
                return false;
            }
        }
        return true;
    }
};