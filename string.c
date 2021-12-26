#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
/**
 *
 * @param w
 * @return
 */
int gametric(char* w){
    int sum =0;
    for (int i = 0; i < strlen(w); i++)
    {
         char ch = w[i];
    if (ch >= 'A' && ch <= 'Z')
    {
        sum += ch - 'A' + 1;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        sum += ch - 'a' + 1;
    }
    }
    return sum;
}




void Q1(char *word, char *text){
    int wLen = gametric(word);
    int tLen = strlen(text) - 1;
    char check[TXT] = {'\0'};
    int l = 0;
    int first = 1;

    for (int i = 0; i < tLen; i++)
    {
        int wordlen = strlen(word);
        for (int j = i; j<tLen+1; j++)
        {
            if(gametric(&text[j])==0){
                wordlen++;
                check[l]=text[j];
                l++;
                break;
            }
            check[l] = text[j];
            int temp = gametric(check);
            if(temp==0){
                memset(check, 0, strlen(check));
                l = 0;
                break;
            }
            if (temp == wLen)
            {
                if(first ==0){printf("~");}
                first=0;
                printf("%s", check);
                memset(check, 0, strlen(check));
                l = 0;
                break;
            }
            if (temp > wLen)
            {
                memset(check, 0, strlen(check));
                l = 0;
                break;
            }
            if (temp <wLen)
            {
                l++;
                continue;
            }
        }
    }
}
    /**
 * function to put the load string in the txt string
 * @param txt dest
 * @param load
 */
void rewrite(char *txt, char *load)

{
    for (int i = 0; i < strlen(load); i++)
    {
        txt[i] = load[i];
    }
}
/**
 * function to check if char c is in string w
 * @param w string
 * @param c char
 * @return 1 if contain, 0 if not
 */
int contains(char *w, char c)
{
    for (int i = 0; i < strlen(w); i++)
    {
        if (w[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * function to remove char 'to remove' from string 'str'
 * @param str
 * @param toRemove
 */
void removechar(char *str, const char toRemove){
    int i = 0;
    int len = strlen(str);

    /* Run loop till the first occurrence of the character is not found */
    while(i<len && str[i]!=toRemove)
        i++;

    /* Shift all characters right to the position found above, to one place left */
    while(i < len){
        str[i] = str[i+1];
        i++;
    }
}

void Q3(char *w, char *t)
{
    char check[TXT] = {'\0'};  // add to this as we go along
    char edit[WORD] = {'\0'}; // from original - remove what we've already taken
    int length = strlen(t);
    rewrite(edit, w);
    int l = 0;
    int editLen = strlen(w);
    int first = 1;


    for (int j = 0; j < length; j++)
    {
        if(t[j]==32){
            continue;
        }
        int wordlen = strlen(w);
        if (contains(edit, t[j]))
        {
            check[l] = t[j];
            removechar(edit, t[j]);
            editLen--;
            l++;
        }
        else
        {
            continue;
        }
        for (int i = j + 1; i<length && i < i+wordlen; i++)
        {
            // printf("hold: %s\n",hold);
            // printf("len: %d\n",editLen);
            if (t[i] == 32 || contains(edit, t[i]))
            {
                if(contains(edit, t[i])){
                    editLen--;
                }
                check[l] = t[i];
                removechar(edit, t[i]);
                l++;
                if(t[i] == 32){
                    wordlen++;
                }
            }
            else{
                memset(check, 0, TXT);
                rewrite(edit, w);
                l = 0;
                editLen = strlen(w);
                break;
            }
            if (editLen == 0)
            {
                if(first ==0){printf("~");}
                first=0;
                check[l]='\0';
                printf("%s", check);
                memset(check, 0, TXT);
                rewrite(edit, w);
                editLen = strlen(w);
                l = 0;
                break;
            }
        }
    }
}

  

//    for (int i = 0; i < TXT; ++i) {
//        printf("%s~", ans[i]);
//    }





char atbash(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 'z' + 'a' - c;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return 'Z' + 'A' - c;
    }
    return c;
}

int isSame(char* a, char* b){
    int ans = 1;
    if(strlen(a)==strlen(b)){
        for (int i = 0; i < strlen(a); i++){
            if (a[i] != b[i]){
                ans = 0;
            }
        }
    }
    else{
        ans = 0;
    }
    return ans;
}

void Q2(char *w, char *t)
{
    char word[WORD] = {'\0'};
    char reverse[WORD] = {'\0'};
    char check[TXT] = {'\0'};
    int l = 0;
    int first = 1;

    for (int i = 0; i < strlen(w); i++)
    {
        word[i] = atbash(w[i]);
        reverse[strlen(w) - i - 1] = atbash(w[i]);
    }

    for (int i = 0; i < strlen(t); i++)
    {
        for (int j = i; j < strlen(t); j++)
        {
            check[l] = t[j];
            if (strlen(check) < strlen(w))
            {
                l++;
                continue;
            }
            if (isSame(check, word) == 1 || isSame(check, reverse) == 1)
            {
                if(first ==0){printf("~");}
                first=0;
                printf("%s", check);
                memset(check, 0, TXT);
                l = 0;
                break;
            }
            if (strlen(check) >= strlen(w))
            {
                memset(check, 0, TXT);
                l = 0;
                break;
            }
        }
    }
}
int main()
{

    char word[WORD] = {'\0'};
    char txt[TXT] = {'\0'};
    char chword;
    char chtext;

    // to get the word
    int i = 0;
    do
    {
        scanf("%c", &chword);
        word[i] = chword;
        i++;
    } while (chword != '\t' && chword != '\n' && chword != ' ');
    word[i-1]='\0';

    // to get the txt
    i = 0;
    do
    {
        scanf("%c", &chtext);
        txt[i] = chtext;
        i++;
    } while (chtext != '~');
    txt[i-1]='\0';


    printf("Gematria Sequences: ");
    Q1(word,txt); //to add what the function gets
    printf("\n");
    printf("Atbash Sequences: ");
    Q2(word,txt); //to add what the function gets
    printf("\n");
    printf("Anagram Sequences: ");
    Q3(word,txt); //to add what the function gets

}
