class Solution{
    public:
    void connect(Node *root) {
         if(!root) return;
         queue<Node *> q;
         q.push(root);
         while(!q.empty()) {
             int s = q.size();
             while(s--){
                 Node *t = q.front();
                 q.pop();
                 t->nextRight = (s == 0 ? NULL : q.front());
                 if(t->left) q.push(t->left);
                 if(t->right) q.push(t->right);
             }
         }
    }    
};
