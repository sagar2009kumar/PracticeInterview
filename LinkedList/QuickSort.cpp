// Link to the description of the problem
// https://practice.geeksforgeeks.org/problems/quicksort-on-doubly-linked-list/1


/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* a Node of the doubly linked list */
/*struct Node
{
    int data;
    Node *next;
    Node *prev;
};
   struct Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
void _quickSort(Node* l, Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
void quickSort(Node *head)
{
    // Find last Node
    struct Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}*/
Node* partition(Node *l, Node *h){
    //Your code goes here
    int pivot_data = h->data;
    Node* temp = l;
    Node* temp1 = l;
    while(temp!= h) {
        if(temp->data < pivot_data ) {
            int u = temp->data;
            temp->data = temp1->data;
            temp1->data = u;
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    h->data = temp1->data;
    temp1->data = pivot_data;
    //cout << temp1->data << "\n";
    return temp1;
    
}
