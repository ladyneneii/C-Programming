#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define sentenceSIZE 50
#define wordSIZE 20
#define lexiconSIZE 50
#define dictionarySIZE 26
#define glossarySIZE 26

typedef char Wordtype[wordSIZE];
typedef Wordtype Lexicon[lexiconSIZE];
typedef struct cell {
	Wordtype word;
	struct cell *connect;
} *LLNode;
typedef LLNode Dictionary[dictionarySIZE];
typedef struct {
	Wordtype wordCB;
	int link;
} CBNode;
typedef struct {
	CBNode wordlink[glossarySIZE];
	int avail;
} Glossary;
typedef int Sentence;

Dictionary *createDictionary();
void initDictionary(Dictionary D);
Glossary createGlossary();
void populateGlossary(Glossary *gloss, Sentence *list, char sentence[]);
void displayGlossary(Glossary gloss, Sentence list);

int main()
{
	Dictionary *dict = createDictionary();
	Glossary virtualSpace = createGlossary();
	char str[sentenceSIZE];

	printf("Enter a sentence: \n");
	fgets(str, sentenceSIZE, stdin);

	Sentence sentence1 = -1;
	populateGlossary(&virtualSpace, &sentence1, str);
	displayGlossary(virtualSpace, sentence1);

	return 0;
}

Dictionary *createDictionary()
{
	Dictionary *head = (Dictionary *)malloc(sizeof(Dictionary));

	if (head != NULL){
		initDictionary(*head);
	}

	return head;
}

void initDictionary(Dictionary D)
{
	int idx;

	for (idx = 0; idx < dictionarySIZE; idx++){
		D[idx] = NULL;
	}
}

Glossary createGlossary()
{
	Glossary glossary;
	int idx; 

	glossary.avail = glossarySIZE-1;
	for (idx = glossarySIZE-1; idx > -1; idx--){
		glossary.wordlink[idx].link = idx-1;
	}
	
	return glossary;
}

void populateGlossary(Glossary *gloss, Sentence *list, char sentence[])
{
	int idx, temp, count;

	for (idx = count = 0; sentence[idx] != '\0'; idx++){
		if (sentence[idx] == ' '){
			*list = gloss->avail;
			if (*list != -1){
				gloss->avail = gloss->wordlink[*list].link;
				memcpy(gloss->wordlink[*list].wordCB, sentence + idx - count, count * sizeof(char));
				gloss->wordlink[*list].wordCB[count] = '\0';
				count = 0;
				list = &gloss->wordlink[*list].link;
			}
		} else {
			count++;
		}
	}
	*list = gloss->avail;
	if (*list != -1){
		gloss->avail = gloss->wordlink[*list].link;
		memcpy(gloss->wordlink[*list].wordCB, sentence + idx - count, count * sizeof(char));
		gloss->wordlink[*list].wordCB[count] = '\0';
		count = 0;
		list = &gloss->wordlink[*list].link;
		*list = -1;
	}
}

void displayGlossary(Glossary gloss, Sentence list)
{
    printf("%d", list);
	for ( ; list != -1; list = gloss.wordlink[list].link){
		printf("%s ", gloss.wordlink[list].wordCB);
	}
}