// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/?ref=self

// FUNCTION CODE
/* A Binary Tree node
class Node
{
    int data;
    Node left, right;
   Node(int item)    {
        data = item;
        left = right = null;
    }
} */
/* Should print vertical order such that each vertical line
    is separated by $ */
class GfG {
    static ArrayList<ArrayList<Integer>> al;
    static void preOrder(Node root, int level) {
        if(root != null) {
            al.get(level).add(root.data);
            // for the left subtree the level should be decreased.
            preOrder(root.left, level-1);
            // for the right sbutree the level should be increased.
            preOrder(root.right, level+1);
        }
    }
    static void print() {
        for(int i = 0; i < 42; i++) {
            if(al.get(i).size() > 0) {
                for(int j = 0; j < al.get(i).size(); j++) {
                    System.out.print(al.get(i).get(j)+ " ");
                }
                System.out.print("$");
            }
        }
    }
    @SuppressWarnings("fallthrough")
    void verticalOrder(Node node) {
        al = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < 42; i++) {
            al.add(new ArrayList<Integer> ());
        }
        preOrder(node, 20);
        print();
    }
}
