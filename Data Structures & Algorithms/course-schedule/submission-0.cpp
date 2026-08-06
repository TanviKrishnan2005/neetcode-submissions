class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // n = numcourses
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        // build graph : prereq->course

        for(auto& p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        //add course with no prereq
        queue<int>q;
        for(int i =0;i<n;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        int count =0;
        
        //topological sort;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;

            for(int next :adj[course]){
                indegree[next]--;

                if(indegree[next]==0)
                    q.push(next);
            }
        }
        // all course processws = no cycle
        return count == n;
    }
};
