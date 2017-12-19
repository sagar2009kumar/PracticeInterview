// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/?ref=self

/* Node is defined as
class TreeNode {
    int data; //node data
    TreeNode left, right; //left and right child's reference
    // Tree node constructor
    public TreeNode(int data) {
        this.data = data;
         left = right = null;
    }
}*/

class GfG {
     public void diagonalPrint(TreeNode root){
         TreeNode temp = root;
           Queue<TreeNode> queue = new LinkedList<TreeNode> ();
           queue.add(root);
           while(!queue.isEmpty()) {
               temp = queue.peek();
               queue.remove();
               while(temp!= null) {
                   System.out.print(temp.data+" ");
                   if(temp.left != null) queue.add(temp.left);
                   temp = temp.right;
               }
           }
      }
}
