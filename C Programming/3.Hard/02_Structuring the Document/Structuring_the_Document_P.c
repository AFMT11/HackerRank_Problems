#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

/**
    New Version
*/

/**
    A document is represented as a collection paragraphs,
    a paragraph is represented as a collection of sentences,
    a sentence is represented as a collection of words and
    a word is represented as a collection of lower-case ([a-z])
    and upper-case ([A-Z]) English characters.
*/
struct word
{
    char* data;
};

struct sentence
{
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph
{
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document
{
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

/*
    This function its job is to convert plain text into words that
    are part of sentences, sentences that are part of paragraphs
    So, the document consists of a bunch of paragraphs, each paragraph
    consists of a bunch of sentences, each sentence consists of a
    bunch of words
    in this challenge, each document, every paragraph of the document,
    each sentence of each paragraph of the document, each word of each
    sentence of each paragraph of the document are all represented as
    structs, the document is a struct, the paragraph is a struct, the
    sentence is a struct, the word is a struct!
*/

struct document Doc_DOC;
struct document get_document(char* text)
{
    static int i, k;
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
            Doc_DOC.paragraph_count = 1;
            Doc_DOC.data = malloc(sizeof(struct paragraph) * Doc_DOC.paragraph_count);

            Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count = 1;
            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data = malloc(sizeof(struct sentence) * Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count);

            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count = 1;
            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].data = malloc(sizeof(struct word) * Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count);
        }
        if(text[i] == ' ')
        {
            int i;
            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count - 1].data =
            malloc(sizeof(char) * (strlen(Buff_char) + 1));
            strcpy(Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count - 1].data, Buff_char);

            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count++;
            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].data =
            realloc(Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].data,
            sizeof(struct word) * Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count);

            for(i = 0; i < strlen(Buff_char); i++)
            {
                Buff_char[i] = 0;
            }
        }
        else if (text[i-1] != '\0' && text[i] == '.')
        {
            int i;
            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count - 1].data =
            malloc(sizeof(char) * (strlen(Buff_char) + 1));
            strcpy(Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count - 1].data, Buff_char);

            if((C_Text != '\0') && (C_Text != '\n'))
            {
                Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count++;
                Doc_DOC.data[Doc_DOC.paragraph_count - 1].data = realloc(Doc_DOC.data[Doc_DOC.paragraph_count - 1].data, sizeof(struct sentence) * Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count);

                Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count = 1;
                Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].data = malloc(sizeof(struct word) * Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count);
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
            Doc_DOC.paragraph_count++;
            Doc_DOC.data = realloc(Doc_DOC.data, sizeof(struct paragraph) * Doc_DOC.paragraph_count);

            Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count = 1;
            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data = malloc(sizeof(struct sentence) * Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count);

            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count = 1;
            Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].data = malloc(sizeof(struct word) * Doc_DOC.data[Doc_DOC.paragraph_count - 1].data[Doc_DOC.data[Doc_DOC.paragraph_count - 1].sentence_count - 1].word_count);
        }
        else
        {
            strcat(Buff_char, Temp_char);
        }
    }
    return Doc_DOC;
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

void print_sentence(struct sentence sen)
{
    int i;
    for(i = 0; i < sen.word_count; i++)
    {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1)
        {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para)
{
    int i;
    for(i = 0; i < para.sentence_count; i++)
    {
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc)
{
    int i;
    for(i = 0; i < doc.paragraph_count; i++)
    {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text()
{
    int paragraph_count;
    scanf("%d", &paragraph_count);
    int i;
    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (i = 0; i < paragraph_count; i++)
    {
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

    while (q--)
    {
        int type;
        scanf("%d", &type);

        if (type == 3)
        {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2)
        {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else
        {
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
}
