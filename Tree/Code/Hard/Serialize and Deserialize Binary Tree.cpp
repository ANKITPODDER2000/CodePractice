/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (!node)
                s += "n";
            else
            {
                s += to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }

            if (!q.empty())
                s += ',';
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        char del = ',';
        stringstream ss(data);
        string word = "";
        queue<TreeNode *> q;
        TreeNode *root = NULL;
        while (!ss.eof())
        {
            if (!root)
            {
                getline(ss, word, del);
                if (word != "n")
                {
                    root = new TreeNode(stoi(word));
                    q.push(root);
                    q.push(root);
                }
            }
            else
            {
                getline(ss, word, del);
                TreeNode *node1 = q.front();
                q.pop();
                if (word != "n")
                {
                    TreeNode *n = new TreeNode(stoi(word));
                    node1->left = n;
                    q.push(n);
                    q.push(n);
                }

                getline(ss, word, del);
                TreeNode *node2 = q.front();
                q.pop();
                if (word != "n")
                {
                    TreeNode *n = new TreeNode(stoi(word));
                    node2->right = n;
                    q.push(n);
                    q.push(n);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));