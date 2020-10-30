class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        queue<int> leaves;
        //array to hold the leaves of the graph 
        
        vector<int> ans;
        
        unordered_map<int, unordered_set<int>> adj;
        //the adjacency list
        
        vector<int> degree(n, 0);
        //this array holds the degree of each node
        
        for(int i= 0 ; i< edges.size(); i++){
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
            
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        
        for(int i=0;i<n;i++){
            if(degree[i] == 1){
                leaves.push(i);
                ans.push_back(i);
            }
        }
        
        
        if(n==1) return {0};
        if(n<=2) return ans;
        
        vector<int> newleaves;        
        
        while(n>2){
            n-=leaves.size();
            int size = leaves.size();
            
            for(int i=0;i<size;i++){
                int cur = leaves.front();
                leaves.pop();
                degree[cur]--;
                
                for(int nei : adj[cur]){
                    degree[nei]--;
                    adj[nei].erase(cur);
                    if(degree[nei]==1) leaves.push(nei);
                }
                
                adj.erase(cur);
            }

        }
        
        ans.clear();
        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();            
        }
        
        return ans;
        
    }
};