int Hash(char name[])
{
    return name[0]-65;
}

void initDictionary(Dictionary *D)
{
	int idx;
	for(idx = 0; idx < SIZE; idx++)
	{
		D[idx] = NULL;
    }
}

D = (Dictionary *)malloc(sizeof(Dictionary));
if (D != NULL){
    initDictionary(*D);
}