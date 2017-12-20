#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int e = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar();}
    while('0' <= ch && ch <= '9'){ e = e*10+(ch-'0'); ch = getchar();}
    return e*f;
}

int a[1001], n;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

void preOrder(Node* node) {
    if(node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

Node* construct(int left, int right) {
    //printf("%d %d \n",left, right);
    if(left > right) {
        // If right is greater than the left then
        // just return
        return NULL;
    }
    if(left == right) {
        // if left is equal to the right then it is
        // leaf node
        Node* res = new Node(a[left]);
        res->left = res->right = NULL;
        return res;
    }
    int mid = (left+right)>>1;
    Node* res = new Node(a[mid]);
    // mid-1 and mid+1 should be used
    res->left = construct(left, mid-1);
    res->right = construct(mid+1, right);
    return res;
}

int main() {
	int t = read();
	while(t-->0) {
	    n = read();
	    for(int i = 0; i < n; i++) a[i] = read();
	    Node* temp = construct(0, n-1);
	    preOrder(temp);
	    printf("\n");
	}
	return 0;
}
