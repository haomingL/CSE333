#include <stdlib.h>
#include <stdio.h>

#define FALSE 0;
#define TRUE 1;

typedef struct TreeNode_st {
	char val;
	struct TreeNode_st* left;
	struct TreeNode_st* right;
} TreeNode, *TreeNodePtr;

typedef struct BinarySearchTree_st {
	TreeNodePtr root;
} BinarySearchTree, *BinarySearchTreePtr;

int Search_BST(TreeNodePtr node_ptr, char ch);

TreeNodePtr Insert_BST(TreeNodePtr node_ptr, char ch);

TreeNodePtr Construct_TreeNode(char ch) {
	TreeNodePtr res = (TreeNodePtr)malloc(sizeof(*res));
	return res;
}

BinarySearchTreePtr Construct_BST() {
	BinarySearchTreePtr res = (BinarySearchTreePtr)malloc(sizeof(*res));
	return res;
}

int Search(BinarySearchTreePtr bst_ptr, char ch) {
	int result = Search_BST(bst_ptr->root, ch);
	return result;
}

int Search_BST(TreeNodePtr node_ptr, char ch) {
	if (node_ptr == NULL) {
		return FALSE;
	} else {
		if (node_ptr->val > ch) {
			Search_BST(node_ptr->left, ch);
		} else if (node_ptr->val < ch) {
			Search_BST(node_ptr->right, ch);
		} else {
			return TRUE;
		}
		return FALSE;
	}
}

void Insert(BinarySearchTreePtr bst_ptr, char ch) {
	bst_ptr->root = Insert_BST(bst_ptr->root, ch);
}

TreeNodePtr Insert_BST(TreeNodePtr node_ptr, char ch) {
	if (node_ptr == NULL) {
		return Construct_TreeNode(ch);
	} else if (node_ptr->val > ch) {
		node_ptr->left = Insert_BST(node_ptr->left, ch);
	} else if (node_ptr->val < ch) {
		node_ptr->right = Insert_BST(node_ptr->right, ch);
	}
	return node_ptr;
}

void FreeBST(TreeNodePtr node_ptr) {
	if (node_ptr != NULL) {
		FreeBST(node_ptr->left);
		FreeBST(node_ptr->right);
		free(node_ptr);
	}
}

void FreeBinarySearchTree(BinarySearchTreePtr bst_ptr) {
	FreeBST(bst_ptr->root);
}

int main(int args, char** argv) {
	BinarySearchTreePtr bst_ptr = Construct_BST();
	printf("Successfully construct\n");
	Insert(bst_ptr, 'm');
	printf("Successfully insert\n");
	Insert(bst_ptr, 'h');
	Insert(bst_ptr, 'r');
	Insert(bst_ptr, 'c');
	Insert(bst_ptr, 'p');
	FreeBinarySearchTree(bst_ptr);
}