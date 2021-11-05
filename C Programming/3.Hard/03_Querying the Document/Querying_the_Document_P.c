#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5


char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n)
{
    char* word_k;
    word_k = document[n - 1][m - 1][k - 1];
    return word_k;
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m)
{
    char** sentence_k;
    sentence_k = document[m - 1][k - 1];
    return sentence_k;
}

char*** kth_paragraph(char**** document, int k)
{
    char*** paragraph_k;
    paragraph_k = document[k - 1];
    return paragraph_k;
}
char * sent_No;
char ** word_No;
char**** Doc_DOC;
char**** get_document(char* text)
{
    static int i, k, P_index = 0, S_index = 0, W_index = 0;
    char C_Text = 0;
    char Temp_char[10] = {0};
    char* Buff_char = (char *) malloc(sizeof(int) * 100);
    strcpy(Buff_char, "");

    for(i = 0; i < strlen(text); i++)
    {
        C_Text = text[i+1];
        Temp_char[0] = text[i];
        /*
            So, the first condition is when we are at the first character ever of the
            plain text, and if that character is not a null character '\0' then we
            set the number of paragraphs of the document (that we already created before
            the function) to be 1 so the current number of paragraphs of the document is 1
            and now we want to create a paragraph pointer (A pointer that points to a
            paragraph data-type) with the size of the current number of paragraphs which
            is currently 1.
            So, now let's understand the most important function of this challenge!
            So, the first thing is that we created a for loop, that loop loops for all
            characters of the input plain text (character by character), and we made
            five cases in that for loop and we will go with them one by one.
            After we initialize the number of paragraphs to be 1 and created a paragraph
            pointer with the size of 1 single paragraph, then it is time to set the number
            of sentences in that single paragraph, and we will initialize it with one, and
            of course we create a sentence pointer with the size of one single sentence,
            and again it is time to set the number of words in that sentences, and we will
            initialize it with one word, and of course we create a word pointer with the
            size of one single word.
        */
        if(i == 0 && text[i] != '\0')
        {
            P_index = 1;
            Doc_DOC = (char****) malloc(sizeof(char***) * P_index);

            sent_No = (char*) malloc(sizeof(char) * P_index);
            sent_No[P_index - 1] = 1;
            Doc_DOC[P_index - 1] = malloc(sizeof(char**) * sent_No[P_index - 1]);

            word_No = (char**) malloc(sizeof(char*) * P_index);
            word_No[P_index] = (char*) malloc(sizeof(char) * sent_No[P_index - 1]);
            word_No[P_index - 1][sent_No[P_index - 1] - 1] = 1;
            Doc_DOC[P_index - 1][sent_No[P_index - 1] - 1] = malloc(sizeof(char*) * word_No[P_index - 1][sent_No[P_index - 1] - 1]);
        }
        if(text[i] == ' ')
        {
            int i;
            Doc_DOC[P_index - 1][sent_No[P_index - 1] - 1][word_No[P_index - 1][sent_No[P_index - 1] - 1] - 1] = malloc(sizeof(char) * (strlen(Buff_char) + 1));
            strcpy(Doc_DOC[P_index - 1][sent_No[P_index - 1] - 1][word_No[P_index - 1][sent_No[P_index - 1] - 1] - 1], Buff_char);

            word_No[P_index - 1][sent_No[P_index - 1] - 1]++;
            Doc_DOC[P_index - 1][sent_No[P_index - 1] - 1] =
            realloc(Doc_DOC[P_index - 1][sent_No[P_index - 1] - 1], sizeof(char*) * word_No[P_index - 1][sent_No[P_index - 1] - 1]);

            for(i = 0; i < strlen(Buff_char); i++)
            {
                Buff_char[i] = 0;
            }
        }
        else if (text[i-1] != '\0' && text[i] == '.')
        {
            int i;
            Doc_DOC[P_index - 1][sent_No[P_index - 1] - 1][word_No[P_index - 1][sent_No[P_index - 1] - 1] - 1] = malloc(sizeof(char) * (strlen(Buff_char) + 1));
            strcpy(Doc_DOC[P_index - 1][sent_No[P_index - 1] - 1][word_No[P_index - 1][sent_No[P_index - 1] - 1] - 1], Buff_char);

            if((C_Text != '\0') && (C_Text != '\n'))
            {
                sent_No[P_index - 1]++;
                Doc_DOC[P_index - 1] = realloc(Doc_DOC[P_index - 1], sizeof(char**) * sent_No[P_index - 1]);

                word_No[P_index - 1][sent_No[P_index - 1] - 1] = 1;
                Doc_DOC[P_index - 1][sent_No[P_index - 1] - 1] = malloc(sizeof(char*) * word_No[P_index - 1][sent_No[P_index - 1] - 1]);
            }

            for(i = 0; i < strlen(Buff_char); i++)
            {
                Buff_char[i] = 0;
            }
        }
        // increase the number of paragraphs by 1
         else if (text[i-1] != '\0' && text[i] == '\n')
        {
            int i;
            P_index++;
            Doc_DOC = realloc(Doc_DOC, sizeof(char***) * P_index);

            sent_No[P_index - 1] = 1;
            Doc_DOC[P_index - 1] = malloc(sizeof(char**) * sent_No[P_index - 1]);

            word_No[P_index - 1][sent_No[P_index - 1] - 1] = 1;
            Doc_DOC[P_index - 1][sent_No[P_index - 1] - 1] = malloc(sizeof(char*) * word_No[P_index - 1][sent_No[P_index - 1] - 1]);
        }
        else
        {
            strcat(Buff_char, Temp_char);
        }
    }
    return Doc_DOC;
}




char* get_input_text() {
    int paragraph_count, i;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count, i;
    scanf("%d", &word_count);
    for(i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char*** paragraph) {
    int sentence_count, i;
    scanf("%d", &sentence_count);
    for (i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main()
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }
}
