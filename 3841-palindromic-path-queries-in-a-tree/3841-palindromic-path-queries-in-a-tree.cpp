class Solution {
public:
    unordered_map <int, vector<int>> adj;  
    int n;
    vector<int> tin, tout, eulerTour;
    int timer;

    vector<int> segmentTree;
    vector<vector<int>> ancestorTable;
    vector<int> depth; 

    int cols;

    // To build the EulerTour array.
    void dfs(int node, int parent, int d, string& s){

        depth[node] = d;
        ancestorTable[node][0] = parent;

        tin[node] = timer;
        eulerTour[timer] =  1 << (s[node] - 'a');   // Entering time: 'a' = 001, 'b' = 010, 'c' = 100 etc..
        timer++;      

        for(int& child: adj[node]){
            if( child == parent ){
                continue;
            }
            dfs(child, node, d+1, s);
        }

        tout[node] = timer;
        eulerTour[timer] =  1 << (s[node] - 'a');   // Leaving time
        timer++;
    }

    // SegmentTree Build for EulerTour array. ( for XOR )
    void buildSegmentTree(int i, int l, int r, vector<int>& nums){
        if(l == r){
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r-l)/2;
        buildSegmentTree(2*i + 1, l, mid, nums);
        buildSegmentTree(2*i + 2, mid + 1, r, nums);
        segmentTree[i] = segmentTree[2*i + 1] ^ segmentTree[2*i + 2];
    }

    // Segment Tree Point Update.
     void updateSegmentTree(int index, int val, int i, int l, int r) {
        if(l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid) {
            updateSegmentTree(index, val, 2*i+1, l, mid);
        } else {
            updateSegmentTree(index, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = segmentTree[2*i+1] ^ segmentTree[2*i+2];
    }

    //Segment Tree : Search Query (Xor)
    int querySegmentTree(int start, int end, int i, int l, int r) {
        if(l > end || r < start) {
            return 0;
        }

        if(l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l,    mid) ^ 
               querySegmentTree(start, end, 2*i+2, mid+1, r);
    }

    // Binary Lifting Code for building ancestorTable
    void buildAncestorTable() {
        for(int j = 1; j < cols; j++) {
            for(int node = 0; node < n; node++) {
                if(ancestorTable[node][j-1] != -1) {
                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j-1] ][j-1];
                }
            }
        }
    }

    //get LCA using Binary Lifting
    int getLCA(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for(int j = 0; j < cols; j++) {
            if(diff & (1 << j)) {
                u = ancestorTable[u][j];
            }
        }

        if(u == v) 
            return u;

        for(int j = cols - 1; j >= 0; j--) {
            if(ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }
    
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;     
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        tout.assign(n,0);
        eulerTour.assign(2*n, 0);           //sees each node at inTime and outTime.
        depth.assign(n, 0);

        // Build the EulerTour Array.
        timer = 0;
        cols = log2(n) + 1;
        ancestorTable.assign(n, vector<int>(cols, -1));
        
        dfs(0, -1, 0, s);                      // intitally root = 0, it's parent = -1;

        // Build Segment Tree for the EulerTour array.
        int N = 2*n;                        // Size of EulerTour array.
        segmentTree.assign(4*N, 0);
        buildSegmentTree( 0, 0, N-1, eulerTour);    // initial Node is root = 0, initially range = 0 to N-1, & the euler array.

        buildAncestorTable();

        vector<bool> result;

        for(string &q: queries){

            stringstream ss(q);
            string type;
            ss >> type;

            if(type == "update"){
                int node;
                char c;

                ss >> node;
                ss >> c;

                int charValue = 1 << (c - 'a');
                s[node] = c;

                updateSegmentTree(tin[node], charValue, 0, 0, 2*n - 1);
                updateSegmentTree(tout[node], charValue, 0, 0, 2*n - 1);
            }
            else{
                int u, v;
                ss >> u >> v;

                int LCAnode = getLCA(u,v);  //get the Lowest Common Ancestor b/w two nodes.
                char c = s[LCAnode];
                int charValue = 1 << (c - 'a');

                int mask = querySegmentTree(0, tin[u], 0, 0, 2*n - 1) ^
                            querySegmentTree(0, tin[v], 0, 0, 2*n - 1) ^ charValue;

                result.push_back((mask & (mask - 1)) == 0);

                
            }
        }
        return result;
    }
};