// Practice Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/* The idea is to firstly correctly collect all the leaf. When the first leaf is encountered
   store that in the set or actually you need that just take two variable similarly store the
   last leaf node. 
   Then print the first node and then do it for the left subtree then for the right subtree.
   In the left node start printing until you firstly encountered the start leaf node.
   In the right subtree start going until you find the last encountered leaf node then print.
   
   CAUTION :: print the root first and then left subtree and then right subtree otherwise you get WA.
              just think carefully. Don't pass the root node to the left function and right function.
*/

/* A Binary Tree node
class Node
{
    int data;
    Node left, right;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}*/
class GfG
{
    static ArrayList<Integer> al = new ArrayList<Integer>(); // for collecting the leaf node
    static Set<Node> set = new HashSet<Node>(); // for storing the visited node
    static boolean flag1, flag2; 
    static void preOrder(Node head) {
    // function to collect the leaf node
        if(head!= null) {
            preOrder(head.left);
            if(head.left==null && head.right == null) {
                al.add(head.data);
                set.add(head);
            }
            preOrder(head.right);
        }
    }
    
    static void goLeft(Node root) 
    // function to print the left node
        if(root == null || flag2) return;
        if(set.contains(root)) {flag2 = true; return;}
        System.out.print(root.data+" ");
        goLeft(root.left);
        goLeft(root.right);
    }
    
    static void goRight(Node root) {
    // function to print the right node
        if(root == null || flag1) return;
        if(set.contains(root)) { flag1 = true; return;}
        goRight(root.right);
        goRight(root.left);
        System.out.print(root.data+" ");
        //System.out.print(root.data+ " ");
    }
    
	void printBoundary(Node node)
	{
	    flag1 = false; flag2 = false;
		preOrder(node);
    // Remember the CAUTION above
		System.out.print(node.data+" ");
		goLeft(node.left);
		set.add(node);
		for(int i = 0; i < al.size(); i++) {
		    System.out.print(al.get(i)+" ");
		}
		goRight(node.right);
		set.clear();
		al.clear();
	}
}
