typedef struct node
{
	node* child[26];
	int we;
	int pe;
	bool ok;
} node;

node* createNode()
{
	node* tmp = new node;
	for(int i = 0; i < 26; i++) tmp->child[i] = 0;
	tmp->we = 0;
	tmp->pe = 0;
}

node* root = new node;

void insert(char word[], int s)
{
	node* tmp = root;
	for(int i = 0; i < s; i++)
	{
		if(tmp->child[word[i]-'a'] == NULL)
		{
			node* nnode = createNode();
			tmp->child[word[i]-'a'] = nnode;	
		}
		tmp = tmp->child[word[i]-'a'];
		tmp->pe++;
	}
	tmp->we++;
	tmp->ok = true;
}

bool search(char word[], int s)
{
	node* tmp = root;
	for(int i = 0; i < s; i++)
	{
		if(tmp->child[word[i]-'a'] == NULL)
			return false;
		tmp = tmp->child[word[i]-'a'];
	}
	return tmp->ok;
}

void print(node* root, char res[], int len)
{
	if(root == NULL ) return;

	if(root->ok)
	{
		res[len] = '\0';
		printf("%s\n", res);
	}

	for(int i = 0; i < 26; i++)
	{
		if(root->child[i])
		{
			res[len] = 'a' + i;
			print(root->child[i], res, len+1);
		}
	}
}

