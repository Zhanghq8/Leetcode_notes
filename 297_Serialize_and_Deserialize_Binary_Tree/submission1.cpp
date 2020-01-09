#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serhelper(out, root);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserhelper(in);
    }
private:
    void serhelper(ostringstream& out, TreeNode* root) {
        if (!root) {
            out << "# ";
            return;
        }
        out << root->val << " ";
        serhelper(out, root->left);
        serhelper(out, root->right);
    }
    TreeNode* deserhelper(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserhelper(in);
        root->right = deserhelper(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));