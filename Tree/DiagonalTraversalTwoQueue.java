// This is the inefficient way of doing that You can do it by
// only one traversal.

// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/?ref=self

/* Node is defined as
class TreeNode
{
    int data; //node data
    TreeNode left, right; //left and right child's reference
    // Tree node constructor
    public TreeNode(int data)
    {
        this.data = data;
         left = right = null;
    }
}*/

class GfG {
    static ArrayList<TreeNode> al1 = new ArrayList<TreeNode> ();
    static ArrayList<TreeNode> al2 = new ArrayList<TreeNode> ();
    static void printRight(TreeNode root) {
        while(root!= null) {
            System.out.print(root.data+" ");
            if(root.left!= null) {
                al2.add(root.left);
            }
            root = root.right;
        }
    }
    public void diagonalPrint(TreeNode root) {
        printRight(root);
        while(al2.size() > 0) {
            al1 = al2;
            al2 = new ArrayList<TreeNode>();
            for(int i = 0; i < al1.size(); i++) {
                printRight(al1.get(i));
            }
        }
        al1.clear();
        al2.clear();
    }
}
