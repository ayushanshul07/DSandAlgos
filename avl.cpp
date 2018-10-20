#include <iostream>

using namespace std;

typedef struct node{
	int val;
	node* left;
	node* right;
	int height;
} node;


class AVL{
private:
	node* root;
public:
	AVL(){
		root= NULL;
	}

	node* createNode(int val){
	node* tmp = new node;
	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->height = 1;
	return tmp;
	}

	int height(node* n = root){
		if(!n) return 0;
		return n->height;
	}

	int getBalance(node* root){
		if(!root) return 0;
		return height(root->left) - height(root->right);
	}

	node* rightRotate(node* z){
		node* y = z->left;
		node* T3 = y->right;
		y->right = z;
		z->left = T3;

		//update height
		z->height = max(height(z->left), height(z->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;
		//return new root
		return y;
	}


	node* leftRotate(node* z){
		node* y = z->right;
		node* T3 = y->left;
		y->left = z;
		z->right = T3;

		//update height
		z->height = max(height(z->left), height(z->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;
		//return new root
		return y;
	}


	node* insert(node* root, int val){
		if(!root){
			node* tmp = createNode(val);
			root = tmp;
			return root;
		}

		if(val < root->val){
			root->left = insert(root->left, val)
		}
		else if(val > root->val){
			root->right = insert(root->right, val);
		}
		else return root;

		root->height = max(height(root->left), height(root->right)) + 1;
		int balance = getBalance(root);

		if (balance > 1 && key < root->left->key) 
	       return rightRotate(root);  

	   	if (balance > 1 && key > root->left->key){ 
	        node->left =  leftRotate(root->left); 
	        return rightRotate(root); 
	    } 
	  
	    if (balance < -1 && key > root->right->key) 
	        return leftRotate(root); 
	     
	    if (balance < -1 && key < nroot>right->key) { 
	        node->right = rightRotate(root->right); 
	        return leftRotate(root); 
	    } 
	  
	    return root;
	}


	node* del(node* root, int val){

		if(!root) return root;

		if(val < root->val)
			root->left = del(root->left, val);
		else if(val > root-> val)
			root->right = del(root->right, val);
		else{

			if( (!(root->left)) || (!(root->right)) ){
				node* tmp = root->left ? root->left : root->right;

				if(!tmp){
					tmp = root;
					root = NULL;
				}
				else{
					*root = *tmp;
				}
				free(tmp); 
			}
			else{
				node* tmp = successor(root->right);
				root->val = tmp->val;
				root->right = del(root->right, tmp->val);
			}
		}

		if(!root){
			return root;
		}

		root->height = max(height(root->left), height(root->right)) + 1;
		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0) 
	       return rightRotate(root);  

	   	if (balance > 1 && getBalance(root->left) < 0){ 
	        node->left =  leftRotate(root->left); 
	        return rightRotate(root); 
	    } 
	  
	    if (balance < -1 && getBalance(root->left) <= 0) 
	        return leftRotate(root); 
	     
	    if (balance < -1 && getBalance(root->left) > 0) { 
	        node->right = rightRotate(root->right); 
	        return leftRotate(root); 
	    } 
	  
	    return root;

	}

};


int main(){

	return 0;
}