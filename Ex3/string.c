#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
// מחשב את הגימטריה של המילה, עובר בלולאה על הטקסט. אם באיזשהו צ'אר הערך של הגימטריה יהיה שווה לגימטריה של האות- נחזיר את המילה. אם הערך יהיה גדול יותר- נמשיך ללולאה הבאה.
//this function conculate the gametric of the word
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


char* gametrical(char* text){
    char* ans;
    char* check;
    int sum = 0;
    for (int i = 0; i < strlen(text); i++)
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

    if (/* condition */)
    {
        /* code */
    }
    
    



        }
    


}









int main(int argc, char const *argv[])
{
    int a = gametric("ab-cd,");
    printf("%d",a);
    return 0;
}
