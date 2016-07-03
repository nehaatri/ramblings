/*
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *       1            <---
 *     /   \
 *     2    3         <---
 *      \    \
 *        5   4       <---
 * You should return [1, 3, 4].
 *
 * Author: Neha Atri <neha.atri@gmail.com>
 * https://leetcode.com/problems/binary-tree-right-side-view/
 */

class Solution {
       public:
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> array;
		if (root == NULL) return array;

		q.push(root);
		q.push(NULL);

		while (!q.empty()) {
			TreeNode* node_1 = q.front();
			q.pop();

			if (node_1 == NULL) {
				if (q.empty()) break;
				q.push(NULL);
			} else {
				if (node_1->left) q.push(node_1->left);
				if (node_1->right) q.push(node_1->right);
			}

			TreeNode* node_2 = q.front();
			if (node_2 == NULL) array.push_back(node_1->val);
		}
		return array;
	}
};
