#Recursive:
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val;
}
#iterative:
void postorder(Node *root)
{
    stack<Node *> s1, s2;
    s1.push(root);
    while (s1.size() > 0)
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left != NULL)
            s1.push(temp->left);
        if (temp->right != NULL)
            s1.push(temp->right);
    }
    while (s2.size() > 0)
    {
        cout << s2.top()->val << endl;
        s2.pop()
    }
}

#Recursive:
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val;
    preorder(root->left);
    preorder(root->right);
}
#Iterative:

void preorder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (s.size() > 0)
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->val;
        if (temp->right != NULL)
            s.push(temp->right);
        if (temp->left != NULL)
            s.push(temp->left);
    }
}

#Recursive:
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
}
#Iterative:
void inorder(Node *root)
{
    vector<int> ans;

    stack<TreeNode *> s;
    while (root || !s.empty())
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
    }
    return ans;
}

void levelordertraversal(Node *root)
{
    queue<Node *> q;
    if (root != NULL)
        q.push(root);
    while (q.size() > 0)
    {
        Node *temp = q.front();
        cout << temp->val;
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
         if(root==NULL)
            return ans;
        queue<TreeNode *>q;
        if(root!=NULL)
        q.push(root);
        q.push(NULL);
        vector<int>level;
       
        while(q.size()>1)
        {        
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                q.push(NULL);
                ans.push_back(level);
                level.clear();              
            }
            else
            {
            level.push_back(temp->val);
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
            }
            
        }
        ans.push_back(level);
        return ans;
        
    }
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>res;
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            vector<int>level;
            for(int i=0;i<sz;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right!= NULL) q.push(node->right);
                level.push_back(node->val);
            }
            res.push_back(level);
        }
        return res;
}
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL and q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    return (p->val == q->val) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}
int maxnode(TreeNode *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->val, max(maxnode(root->left), maxnode(root->right)));
}



vector<string> ans;
void printall(TreeNode *root, vector<int> &path, int path_len)
{
    if (root == NULL)
        return;
    path[path_len] = root->val;
    path_len++;
    if (root->left == NULL and root->right == NULL)
        addpath(path, path_len);
    else
    {
        printall(root->left, path, path_len);
        printall(root->right, path, path_len);
    }
}
void addpath(vector<int> path, int n)
{
    string s = "";
    for (int i = 0; i < n - 1; i++)
    {
        s += to_string(path[i]);
        s += "->";
    }
    s += to_string(path[n - 1]);
    ans.push_back(s);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<int> path(100);
    printall(root, path, 0);
    return ans;
}
Q)
Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 int c=0;
    void pathsumtoleaf(TreeNode * root,int sum)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL and root->right==NULL)
        {
            sum=sum*10+root->val;
           c+=sum;
            return;
        }
        int k=sum*10+root->val;
       pathsumtoleaf(root->left,k);
       pathsumtoleaf(root->right,k);
        
    }
public:
    int sumNumbers(TreeNode* root) {
       pathsumtoleaf(root,0);
       
        return c;
    }


Q)

bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        if(root->left==NULL and root->right==NULL)
        {
            targetSum-=root->val;
            if(targetSum==0)
                return true;
            return false;
        }
        return hasPathSum(root->left,targetSum-root->val) or hasPathSum(root->right,targetSum-root->val); 
    }

bool printAncestors(TreeNode * root,TreeNode *key)
{
    if(root==NULL)
    return false;
    if(root==key)
    {
        cout<<root->val<<endl;
        return true;
    }
    if(printAncestors(root->left,key)|| printAncestors(root->right,key))
    {
        cout<<root->val;
        return true;
    }
    return false;
}