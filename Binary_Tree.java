public class Binary_Tree extends BinaryTree{
	node root;
	
	void printSpiral(node root){
		int h = height(root);
		boolean ltr=false;
		for(int i=1;i<=h;i++){
			spiralUtil(root,i,ltr);
			ltr=!ltr;
		}
	}
	
	void spiralUtil(node root,int level,boolean ltr){
		if(root==null)
			return;
		if(level==1)
			System.out.print(root.data+" ");
		else{
			if(ltr){
				spiralUtil(root.left,level-1,ltr);
				spiralUtil(root.right,level-1,ltr);
			} else {
				spiralUtil(root.right,level-1,ltr);
				spiralUtil(root.left,level-1,ltr);
			}
		}
	}
	
	
	
	public static void main(String args[]){
		Binary_Tree tree = new Binary_Tree();
		tree.root = new node(1);
        tree.root.left = new node(2);
        tree.root.right = new node(3);
        tree.root.left.left = new node(7);
        tree.root.left.right = new node(6);
        tree.root.right.left = new node(5);
        tree.root.right.right = new node(4);
        tree.printSpiral(tree.root);
	}
}
