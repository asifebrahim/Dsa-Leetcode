class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n,0);
        for(auto it:edges){
            adjList[it[0]].push_back(it[1]);   // Creating the adjacency List
            adjList[it[1]].push_back(it[0]);
            inDegree[it[0]]++;   // Creating the degree List of each node
            inDegree[it[1]]++;
        }
        queue<int> q;               //Creating a queue to push every node with a degree of 1
        for(int i=0;i<n;i++){
            if(inDegree[i]==1){
                q.push(i);
            }
        }
        int remain=n;           //haven't remoeved the leaves yet so remaining is n
        while(remain>2){          //Ususally a grapg has 2 or 1 MHT
            int leavesCount=q.size();   //Total node with inDegree 1
            remain-=leavesCount;    //After removing the leaves we gonna have this much remaining nodes
            for(int i=0;i<leavesCount;i++){            // For the leaves size we do operations on each of them
                int x=q.front();
                q.pop();                      //Pop the leaf node
                for(int it:adjList[x]){
                    inDegree[it]--;       //Since we are removing the leaf node we decrease the degree of the nodes connected to it
                    if(inDegree[it]==1){  //If the degree of the node becomes 1 we push it to the queue as it becomes a leaf node
                        q.push(it);
                    }
                }
            }

        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()); //We add the remaining nodes to the answer vector
            q.pop();
        }
        return ans;
    }
};