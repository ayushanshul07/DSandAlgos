
int count (node* root) {
    return root ? root->size : 0;
}

void update_count (node* root) {
    if (root)
        root->size = 1 + count(root->left) + count(root->right);
}


void split(node* root, node* (&l), node* (&r), int key){

	if(!root){
		l = r = NULL;
		return;
	}

	if(key >= root->val){
		split(root->right, root->right , r , key)
		l = root;
	}
	else{
		split(root->left, l, root->left, key);
		r = root;
	}

	update_count(root);
}

void merge(node* (&root), node* l, node* r){

	if((!l) || (!r)){
		root = l?l:r;
		return;
	}

	if(r->priority > l->priority){
		merge(r->left, l, r->left);
		root = r;
	}
	else{
		merge(l->right, l->right, r);
		root = l;
	}

	update_count(root);
}


void insert(node* (&root), node* nnode){

	if(!root){
		root = nnode;
		return;
	}
	
	if(nnode->priority > root->priority){
		split(root, nnode->left, nnode->right, nnode->val);
		root = nnode;
	}
	else{
		insert( (nnode->val < root->key) ? root->left : root->right, nnode);
	}

	update_count(root);
}

void erase(node* (&root), int key){
	if(root->val == key){
		merge(root, root->left, root->right);
		return;
	}

	erase( (root->val > key ? root->left : root->right), key);
	update_count(root);
}

