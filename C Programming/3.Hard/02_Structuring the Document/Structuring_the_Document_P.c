#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

/**
	Old Version
*/

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document DOCS;
struct document get_document(char* text)
{
    int buff = 0;
    int i, j, k, m, paragraph_count = 1;
    int words_buff = 0, char_index = 0;
    char * token[1000];
    int token_index = 0;
    DOCS.paragraph_count= 1;

    for(i = 0; i < strlen(text); i++)
    {
        if(text[i] == '\n')
        {
            DOCS.paragraph_count++;
        }
    }
    DOCS.data = malloc(sizeof(struct paragraph) * DOCS.paragraph_count);
    /*sentences in paragraph count*/
    for(i = 0; i < DOCS.paragraph_count; i++)
    {
        DOCS.data[i].sentence_count = 0;
        for(j = buff; j < strlen(text); j++)
        {
            if(text[j] == '\n')
            {
                buff = j+1;
                break;
            }
            if(text[j] == '.')
            {
                DOCS.data[i].sentence_count++;
            }
        }
    }
    buff = 0;
    /*words in sentence of paragraph count*/
    for(i = 0; i < DOCS.paragraph_count; i++)
    {
        DOCS.data[i].data = malloc(sizeof(struct sentence) * DOCS.data[i].sentence_count);
        for(j = 0; j < DOCS.data[i].sentence_count; j++)
        {
            DOCS.data[i].data[j].word_count = 0;
            for(k = buff; k < strlen(text); k++)
            {
                if(text[k] == '.' && text[k+1] == '\n')
                {
                    DOCS.data[i].data[j].word_count++;
                    buff = k+2;
                    break;
                }
                else if(text[k] == '.')
                {
                    DOCS.data[i].data[j].word_count++;
                    buff = k+1;
                    break;
                }
                else if(text[k] == ' ' )
                {
                    DOCS.data[i].data[j].word_count++;
                }
            }
        }
    }
    buff = 0;
    /*characters in words in sentence of paragraph count*/
    for(i = 0; i < DOCS.paragraph_count; i++)
    {
        for(j = 0; j < DOCS.data[i].sentence_count; j++)
        {
            DOCS.data[i].data[j].data = malloc(sizeof(struct word) * DOCS.data[i].data[j].word_count);
            for(k = 0; k < DOCS.data[i].data[j].word_count; k++)
            {
                for(m = buff; m < strlen(text); m++)
                {
                    if(text[m] == '.' && text[m+1] == '\n')
                    {
                        buff = m+2;
                        break;
                    }
                    else if(text[m] == '.' || text[m] == ' ')
                    {
                        buff = m+1;
                        break;
                    }
                    else
                    {
                        words_buff++;
                    }
                }
                DOCS.data[i].data[j].data[k].data = (char*) malloc(sizeof(char) * words_buff);
                words_buff = 0;
            }
        }
    }
    buff = 0;

    /*Writing words of sentence of paragraph in array*/
    token[0] = strtok(text, "\n");

    for(i = 1; i < DOCS.paragraph_count; i++)
    {
        token[i] = strtok(NULL, "\n");
    }
    token_index = 0;

    int para_sentence_count = 0;
    for(i = token_index; i < DOCS.paragraph_count; i++)
    {
        token[para_sentence_count + DOCS.paragraph_count] = strtok(token[i], ".");
        for(j = 1; j < DOCS.data[i].sentence_count; j++)
        {
            token[para_sentence_count + j + DOCS.paragraph_count] = strtok(NULL, ".");
        }
        para_sentence_count += DOCS.data[i].sentence_count;
    }

    token_index = 0;
    int para_sentence_word_count = 0;
    int para_sentence_count_increment = 0;

    for(i = token_index; i < DOCS.paragraph_count; i++)
    {
        for(j = 0; j < DOCS.data[i].sentence_count; j++)
        {
            token[para_sentence_word_count + DOCS.paragraph_count + para_sentence_count] = strtok(token[j + para_sentence_count_increment + DOCS.paragraph_count], " ");
            for(k = 1; k < DOCS.data[i].data[j].word_count; k++)
            {
                token[k + para_sentence_word_count + DOCS.paragraph_count + para_sentence_count] = strtok(NULL, " ");
            }
            para_sentence_word_count += DOCS.data[i].data[j].word_count;
        }
        para_sentence_count_increment += DOCS.data[i].sentence_count;
    }
    /*Writing words of sentence of paragraph in array*/

    int word_first_index = DOCS.paragraph_count + para_sentence_count;
    for(i = 0; i < DOCS.paragraph_count; i++)
    {
        for(j = 0; j < DOCS.data[i].sentence_count; j++)
        {
            for(k = 0; k < DOCS.data[i].data[j].word_count; k++)
            {
                DOCS.data[i].data[j].data[k].data = token[word_first_index++];

            }
        }
    }
    return DOCS;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n)
{
    struct word WORD;
    WORD = Doc.data[n-1].data[m-1].data[k-1];
    return WORD;
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m)
{
    struct sentence SENTENCE;
    SENTENCE = Doc.data[m-1].data[k-1];
    return SENTENCE;
}

struct paragraph kth_paragraph(struct document Doc, int k)
{
    struct paragraph PARAGRAPH;
    PARAGRAPH = Doc.data[k-1];
    return PARAGRAPH;
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main()
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
}
