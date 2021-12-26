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