int strrindex(char s[], char t[])
{
	int i = 0;
	int j, k;
	int last = -1;
	for(; s[i]!='\0'; i++)
	{
		for(j=0, k=i; t[j]!='\0' && s[k]==t[j]; j++, k++)
		{
			;
		}
		if(t[j]=='\0' && j>0)
		{
			last = i;
		}
	}
	return last;
}
