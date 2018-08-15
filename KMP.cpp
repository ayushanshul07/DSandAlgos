void LPS(char word[], int len, int* lps)
{
	lps[0] = 0;
	int j = 0;
	for(int i = 1; i < len; i++)
	{
		while(j > 0 && word[i] != word[j])
			j = lps[j-1];
		if(word[i] == word[j])
			j++;
		lps[i] = j;
	}
}

void KMP(char text[], int n, char pat[], int m)
{
	int* lps = new int[m];
	LPS(pat,m,lps);
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		while(j > 0 && text[i] != pat[j])
			j = lps[j-1];
		if(text[i] == pat[j])
			j++;
		if(j == m)
		{
			cout << "Match: " << i+1-m << endl;
			j = lps[j-1];
		}
	}
}