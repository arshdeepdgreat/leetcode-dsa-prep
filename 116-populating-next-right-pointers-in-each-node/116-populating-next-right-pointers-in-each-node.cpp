/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        
        Node *r = root;
        while(r->left){
            Node *leftPart = r;
            while(r){
                r->left->next=r->right;
                if(r->next)
                    r->right->next=r->next->left;
                else
                    r->right->next = NULL;
                
                r=r->next;
             }
            r = leftPart->left;
        } 
        return root;
    }
    
};