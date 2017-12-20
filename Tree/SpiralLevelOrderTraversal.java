// https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1/?ref=self

/*
// A Binary Tree node
class Node
{
    int data;
    Node left, right;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
*/

class GfG {
    static Stack<Node> stack1 = new Stack<Node>();
    static Stack<Node> stack2 = new Stack<Node>();
    static int cnt = 1;
      void printSpiral(Node node)  {
          cnt = 1;
          Node temp;
          stack1.push(node);
           while(!stack1.isEmpty() || !stack2.isEmpty()) {
               if(cnt == 1) {
                   while(!stack1.isEmpty()) {
                       temp = stack1.peek();
                       System.out.print(temp.data+" ");
                       stack1.pop();
                       if(temp.right!=null)
                            stack2.push(temp.right);
                        if(temp.left!= null)
                            stack2.push(temp.left);
                   }
                   cnt = 0;
               }else {
                   while(!stack2.isEmpty()) {
                       temp = stack2.peek();
                       System.out.print(temp.data+" ");
                       stack2.pop();
                       if(temp.left!= null) 
                            stack1.push(temp.left);
                       if(temp.right!= null) 
                            stack1.push(temp.right);
                   }
                   cnt = 1;
               }
           }
      }
}
