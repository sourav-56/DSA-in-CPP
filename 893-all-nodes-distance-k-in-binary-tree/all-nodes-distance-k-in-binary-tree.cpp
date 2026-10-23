/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *   TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
private:
    void buildParentTrack(
        TreeNode* root,
        unordered_map<TreeNode*, TreeNode*>& parentTrack
    ) {
        queue<TreeNode*>nodesQueue;
        nodesQueue.push(root);
        parentTrack[root] = nullptr;
        while (!nodesQueue.empty()){
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            if (node->left != nullptr){
                parentTrack[node->left] = node;
                nodesQueue.push(node->left);
            }

            if (node->right != nullptr){
                parentTrack[node->right] = node;
                nodesQueue.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(
        TreeNode* root,
        TreeNode* target,
        int K
    ) {
        vector<int> ans;

        if (root == nullptr){
            return ans;
        }

        unordered_map<TreeNode*, TreeNode*> parentTrack;

        buildParentTrack(root, parentTrack);

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(target);

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int currLevel = 0;

        while (!nodesQueue.empty()){
            if (currLevel == K){
                break;
            }

            int levelSize = nodesQueue.size();

            for (int i = 0; i < levelSize; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                if (
                    node->left != nullptr &&
                    visited.find(node->left) == visited.end()
                ){
                    visited.insert(node->left);
                    nodesQueue.push(node->left);
                }

                if (
                    node->right != nullptr &&
                    visited.find(node->right) == visited.end()
                ){
                    visited.insert(node->right);
                    nodesQueue.push(node->right);
                }

                TreeNode* parent = parentTrack[node];

                if (
                    parent != nullptr &&
                    visited.find(parent) == visited.end()
                ){
                    visited.insert(parent);
                    nodesQueue.push(parent);
                }
            }

            currLevel++;
        }

        while (!nodesQueue.empty()){
            ans.push_back(nodesQueue.front()->val);
            nodesQueue.pop();
        }

        return ans;
    }
};