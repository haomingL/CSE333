public class BinarySearchTree {
	private class TreeNode {
		public char val;
		public TreeNode left;
		public TreeNode right;

		public TreeNode(char ch) {
			this.val = ch;
		}
	}

	private TreeNode root;

	public boolean search(char target) {
		return search(target, root);
	}

	private boolean search(char target, TreeNode node) {
		if (node != null) {
			if (node.val == target) {
				return true;
			} else if (node.val > target) {
				return search(target, node.left);
			} else {
				return search(target, node.right);
			}
		}
		return false;
	}

	public void insert(char ch) {
		root = insert(ch, root);
	}

	private TreeNode insert(char ch, TreeNode node) {
		if (node == null) {
			return new TreeNode(ch);
		} else if (node.val > ch) {
			node.left = insert(ch, node.left);
		} else if (node.val < ch) {
			node.right = insert(ch, node.right);
		}
		return node;
	}
}