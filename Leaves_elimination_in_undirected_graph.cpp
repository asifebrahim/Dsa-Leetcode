class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n,0);
        for(auto it:edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
            inDegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==1){
                q.push(i);
            }
        }
        int remain=n;
        while(remain>2){
            int leavesCount=q.size();
            remain-=leavesCount;
            for(int i=0;i<leavesCount;i++){
                int x=q.front();
                q.pop();
                for(int it:adjList[x]){
                    inDegree[it]--;
                    if(inDegree[it]==1){
                        q.push(it);
                    }
                }
            }

        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};