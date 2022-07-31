#include <iostream>
using namespace std;
class node{
	public:
	int data;
	node* right;
	node* left;
	node(int x){
		data = x;
		right = NULL;
		left = NULL;
	}
};
node* minValueNode(node* root)
{
    node* current = root;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

void deleteNode(struct node* &root, int key)
{
    if (root == NULL) return;
    if (key < root->data) deleteNode(root->left, key);
    else if (key > root->data) deleteNode(root->right, key);
    else {
    	
        if (root->left==NULL and root->right==NULL){
        	delete root;
            root = NULL;
            return;
   		}
   		
        else if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            root = temp;
            return;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            root = temp;
            return;
        }
        node* temp = minValueNode(root->right);
        root->data = temp->data;
        deleteNode(root->right, temp->data);
    }
    return;
}

void preorder(node* root){
			if (root == NULL) return;
			cout << root->data <<" ";
			preorder(root->left);
			preorder(root->right);
			
		}
void inorder(node* root){
			if (root == NULL) return;
			inorder(root->left);
			cout << root->data <<" ";
			inorder(root->right);
			
		}
void postorder(node* root){
			if (root==NULL) return;
			postorder(root->left);
			postorder(root->right);
			cout <<root->data <<" ";
			
		}
void insertBST(node* &root, int val){
			node* temp = root;
			node* n = new node(val);
			if (temp == NULL){
				root = n;
				return;
			}
			
			if(val < temp->data){
				insertBST(temp->left , val);
			}else{
				insertBST(temp->right, val);
			}
			return;
		}
int search(node* root, int key){
			if(root->data==key) return 1;
			if (root->data < key ) search(root->right , key);
			if (root->data > key) search (root->left , key);
			return 0;
		}
int main(){
		node* root = NULL;
		
		insertBST(root,1);
		insertBST(root,9);
		insertBST(root,5);
		insertBST(root,2);
		insertBST(root,8);
		insertBST(root,15);
		insertBST(root,12);
		insertBST(root,19);
		insertBST(root,45);
		insertBST(root,23);
		insertBST(root,81);
		insertBST(root,90);
		insertBST(root,92);
		insertBST(root,89);
		insertBST(root,47);
		insertBST(root,72);
		insertBST(root,84);
		insertBST(root,145);
		
		deleteNode(root,5);
		deleteNode(root,72);
		deleteNode(root,145);
		
		inorder(root);
	}
