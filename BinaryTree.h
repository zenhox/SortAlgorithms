#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
struct TreeNode
{
	int  val;
	TreeNode * left;
	TreeNode * right;
};

class BinaryTree {
public:
	BinaryTree(std::vector<int> preorder, std::vector<int> inorder) 
	{
		root = new TreeNode();
		buildTree(this->root, preorder, inorder);
	}
	void inorder_traversal() {
		if (root != nullptr) {
			inorder_traversal(root);
		}
	}
	void inorder_traversal(TreeNode * root) {
		if (root != nullptr) {
			inorder_traversal(root->left);
			std::cout << root->val<<" ";
			inorder_traversal(root->right);
		}
	}
	void preorder_traversal(TreeNode * root) {
		if (root != nullptr) {
			std::cout << root->val << " ";
			inorder_traversal(root->left);
			inorder_traversal(root->right);
		}
	}
	void postorder_traversal(TreeNode * root) {
		if (root != nullptr) {
			inorder_traversal(root->left);
			inorder_traversal(root->right);
			std::cout << root->val << " ";
		}
	}


private:
	TreeNode * root;
	void  buildTree(TreeNode * current_root,
		std::vector<int> preorder,std::vector<int> inorder) 
	{
		current_root->val = preorder[0];
		int root_index = -1;
		for (int i = 0; i < inorder.size(); ++i) {
			if (inorder[i] == current_root->val) {
				root_index = i;
				break;
			}
		}
		if (root_index != -1) {
			if (root_index != 0) {
				//std::vector<int> preorder_left(preorder.begin(), preorder.begin() + root_index);
				std::vector<int> inorder_left(inorder.begin(), inorder.begin() + root_index);
				std::vector<int> preorder_left(preorder.begin()+1, preorder.begin()+inorder_left.size()+1);
				current_root->left = new TreeNode();
				buildTree(current_root->left, preorder_left, inorder_left);
			}
			if (root_index != inorder.size() - 1) {
				//std::vector<int> preorder_right(inorder.begin() + root_index + 2, inorder.end());
				std::vector<int> inorder_left(inorder.begin(), inorder.begin() + root_index);
				std::vector<int> inorder_right(inorder.begin() + root_index + 1, inorder.end());
				std::vector<int> preorder_right(preorder.begin()+inorder_left.size()+1, preorder.end());
				current_root->right = new TreeNode();
				buildTree(current_root->right, preorder_right, inorder_right);
			}
		}

	}
};
