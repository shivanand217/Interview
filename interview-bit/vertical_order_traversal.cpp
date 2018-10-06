
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector< vector<int> > ans;
    
    // base case
    if(A == NULL){
        return ans;
    }
       
    map<int,vector<int> > mpp;
    queue<pair<TreeNode *, int> > q;
    q.push(make_pair(A, 0));
    
    pair<TreeNode *,int> p;
    
    while(!q.empty()) {
        p = q.front();
        q.pop();
        
        mpp[p.second].push_back(p.first->val);
        
        if(p.first->left != NULL){
            q.push(make_pair(p.first->left, p.second-1));
        }
        if(p.first->right != NULL){
            q.push(make_pair(p.first->right, p.second+1));
        }
    }
    
    for(map<int,vector<int> > :: iterator it = mpp.begin(); it!= mpp.end(); it++) {
        ans.push_back(it->second);   
    }
    
    return ans;
}