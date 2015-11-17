public class BinarySearchTreeMain {
	public static void main(String[] args) {
		BinarySearchTree bst = new BinarySearchTree();
		bst.insert('m');
		bst.insert('h');
		bst.insert('r');
		bst.insert('c');
		bst.insert('p');
		assert(bst.search('r'));
		assert(!bst.search('b'));
	}
}