#define HS 100003
#define MAX_DB_SIZE 100000
//max word lenght is 5(0/1)
void mystrcpy(char* s, char* d)
{
	for(int i = 0; i < 51; i++)

		d[i] = s[i];
}

bool mystrcmp(char* a, char* b)
{
	int i = 0;
	while(a[i] && b[i] && (a[i] == b[i]) && i < 50)
		i++;
	return (a[i] == b[i]);
} 

typedef struct node
{
	char word[51];
	bool ok;
	int next;
} node;

node db[MAX_DB_SIZE];
int table[HS];
int counter = 0;

int HashFun(char word[], int s)
{
	int hash = 5381;
	for(int i = 0; i < s; i++)
	{
		hash = (33*hash + (word[i]-'0'))%HS;
	}
	return hash;
}

void insert(char word[], int s)
{
	int hash = HashFun(word,s);
	if(table[hash] == -1)
	{
		table[hash] = counter;
		mystrcpy(word,(db[counter]).word);
		(db[counter]).ok = true;
		counter++;
		return;
	}

	(db[counter]).next = table[hash];
	table[hash] = counter;
	mystrcpy(word,(db[counter]).word);
	(db[counter].ok) = true;
	counter++;
}

bool search(char word[], int s)
{
	int hash = HashFun(word,s);
	if(table[hash] == -1) return false;

	int tmp = table[hash];
	while(tmp != -1)
	{
		if(mystrcmp(db[tmp].word,word) && db[tmp].ok) return true;
		tmp = db[tmp].next;
	}
	return false;
}

void remove(char word[], int s)
{
	int hash = HashFun(word,s);
	if(table[hash] == -1) return;

	int tmp = table[hash];
	while(tmp != -1)
	{
		if(mystrcmp(db[tmp].word,word)) db[tmp].ok = false;
		tmp = db[tmp].next;
	}	
}

void reset()
{
	for(int i = 0; i < MAX_DB_SIZE; i++) db[i].next = -1;
	for(int i = 0; i < HS; i++) table[i] = -1;
}


