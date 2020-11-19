#include "DictionaryCourseWork.h"

//Languages:
//EN-English
//DE-German
//FI-Finnish

int main()
{
    char dictionary[3][256][256] = {{"run", "pirate", "gym", "aunt", "money", "snow", "entertainment", "flat", "university"},
                                    {"Lauf", "Pirat", "Fitnessstudio", "Tante", "Geld", "Schnee", "Unterhaltung", "Wohnung", "Universitaet"},
                                    {"juosta", "merirosvo", "kuntosali", "taeti", "raha", "lumi", "viihde", "tasainen", "yliopisto"}}, option1[15], option2[15];
    int Length[3] = {9, 9, 9};

    printf("\tDICTIONARY PROGRAM\n");

    do
    {
            printf("\n\n\t\t1. List of words\n");
            printf("\t\t2. Sort words\n");
            printf("\t\t3. Add a word\n");
            printf("\t\t4. Delete a word\n");
            printf("\t\t5. Exit the dictionary\n");

            gets(option1);

            if(strcmp(option1, "1") == 0)
        {
            printf("\n|1.Info| Words from which languages to be shown? (2 or all): ");

            gets(option1);

            if(strcmp(option1, "2") == 0)
            {
                printf("|1.Info| Words from which language to be shown first? (EN/DE/FI): ");

                gets(option1);

                if(strcmp(option1, "EN") == 0)
                {
                    printf("|1.Info| Words from which language to be shown second? (DE/FI): ");

                    gets(option2);

                    if(strcmp(option2, "DE") != 0 && strcmp(option2, "FI") != 0)
                        printf("\n|1.Info| Invalid second language, try again.");
                    else
                    {
                        printf("\n|1.Info|");
                        wList(option1, dictionary, Length);
                        printf("\n|1.Info|");
                        wList(option2, dictionary, Length);
                    }
                }
                else if(strcmp(option1, "DE") == 0)
                {
                    printf("|1.Info| Words from which language to be shown second? (EN/FI): ");

                    gets(option2);

                    if(strcmp(option2, "EN") != 0 && strcmp(option2, "FI") != 0)
                        printf("\n|1.Info| Invalid second language, try again.");
                    else
                    {
                        printf("\n|1.Info| ");
                        wList(option1, dictionary, Length);
                        printf("\n|1.Info| ");
                        wList(option2, dictionary, Length);
                    }
                }
                else if(strcmp(option1, "FI") == 0)
                {
                    printf("|1.Info| Words from which language to be shown second? (EN/DE): ");

                    gets(option2);

                    if(strcmp(option2, "EN") != 0 && strcmp(option2, "DE") != 0)
                        printf("\n |1.Info|Invalid second language, try again.");
                    else
                    {
                        printf("\n|1.Info| ");
                        wList(option1, dictionary, Length);
                        printf("\n|1.Info| ");
                        wList(option2, dictionary, Length);
                    }
                }
            }
            else if(strcmp(option1, "all") == 0)
            {
                printf("\n|1.Info| ");
                wList("EN", dictionary, Length);
                printf("\n|1.Info| ");
                wList("DE", dictionary, Length);
                printf("\n|1.Info| ");
                wList("FI", dictionary, Length);
            }

            else printf("\n|1.Info| ERROR.");
        }

        else if(strcmp(option1, "2") == 0)
        {
            printf("\n|2.Info| In which language you'd like to sort the words? (EN/DE/FI): ");

            gets(option1);

            if(strcmp(option1, "EN") != 0 && strcmp(option1, "DE") != 0 && strcmp(option1, "FI") != 0)
                printf("|2.Info| ERROR.");
            else
            {
                if(strcmp(option1, "EN") == 0)
                    sortW(dictionary[0], Length[0]);
                else if(strcmp(option1, "DE") == 0)
                    sortW(dictionary[1], Length[1]);
                else if(strcmp(option1, "FI") == 0)
                    sortW(dictionary[2], Length[2]);
                printf("\n|2.Info| ");

                wList(option1, dictionary, Length);
            }
        }
        else if(strcmp(option1, "3") == 0)
        {
            {
                int i;
                for(i=0;i<3;i++)
                {
                    if(i == 0)
                    {
                         printf("|3.Info| The word you want to add in EN: ");
                         gets(option2);
                         addW(dictionary[0], &Length[0], option2);
                    }

                else if(i == 1)
                {
                  printf("|3.Info| The word you want to add in DE: ");
                    gets(option2);
                    addW(dictionary[1], &Length[1], option2);
                }
                else if(i == 2)
                {
                  printf("|3.Info| The word you want to add in FI: ");
                  gets(option2);
                addW(dictionary[2], &Length[2], option2);
                }

            }
                printf("\n|3.Info|");
                wList("EN", dictionary, Length);
                printf("\n|3.Info| ");
                wList("DE", dictionary, Length);
                printf("\n|3.Info| ");
                wList("FI", dictionary, Length);

        }
    }

        else if(strcmp(option1, "4") == 0)
        {
                int i;
                for(i=0;i<3;i++)
                {
                    if(i == 0)
                    {
                        printf("\n|4.Info| Which word you want to remove from EN: ");
                        gets(option2);
                        delW(dictionary[0], &Length[0], option2);
                    }
                    else if(i == 1)
                    {
                        printf("\n|4.Info| Which word you want to remove from DE: ");
                        gets(option2);
                        delW(dictionary[1], &Length[1], option2);
                    }
                    else if(i == 2)
                    {
                        printf("\n|4.Info| Which word you want to remove from FI: ");
                        gets(option2);
                        delW(dictionary[2], &Length[2], option2);
                    }
                }
                   printf("\n\n|4.Info|");
                wList("EN", dictionary, Length);
                printf("\n|4.Info| ");
                wList("DE", dictionary, Length);
                printf("\n|4.Info| ");
                wList("FI", dictionary, Length);

        }

        else if(strcmp(option1, "5") != 0)
            printf("\nInvalid command.\n");
    }
    while(strcmp(option1, "5") != 0);

    return 0;
    }


void wList(char language[], char dict[3][256][256], int Len[])
{
    int i;
    printf("Words in ");

    if(strcmp(language, "EN") == 0)
    {
        printf("EN: ");
        for(i=0; i<Len[0]; i++)
            printf("%s ", dict[0][i]);
    }

    else if(strcmp(language, "DE") == 0)
    {
        printf("DE: ");
        for(i=0; i<Len[1]; i++)
            printf("%s ", dict[1][i]);
    }

    else if(strcmp(language, "FI") == 0)
    {
        printf("FI: ");
        for(i=0; i<Len[2]; i++)
            printf("%s ", dict[2][i]);
    }
}
//da raboti sus vsichki masivi i da gi sortira na edno
void sortW(char dict[][256], int len)
{
    int i, j;
    for (i=0; i<len-1; i++)
    {
        for (j=i+1; j<len; j++)
        {
            if (strcmp(dict[i], dict[j]) > 0)
            {
                //swap da go napravq vuv funkcii za da go izpolzvam 3 puti
                char temp[256];
                strcpy(temp, dict[i]);
                strcpy(dict[i], dict[j]);
                strcpy(dict[j], temp);
            }
        }
    }
}
//da raboti s 3te masiva
void addW(char dict[][256], int *len, char word[])
{
    int i;
    if(*len < 256)
    {
        for(i=0; i<*len; i++)
        {
            if(strcmp(dict[i], word) == 0)
            {
                printf("|3.Info| Cannot add word: it's already in the dictionary.");
                return;
            }
        }
        strcpy(dict[*len], word);
        (*len)++;
    }
    else printf("|3.Info| Cannot add word: dictionary is full.");
}

void delW(char dict[][256], int *len, char word[])
{
    int i, j;
    for(i=0; i<*len; i++)
    {
        if(strcmp(dict[i], word) == 0)
        {
            for(j=i; j<*len; j++)
            {
                char temp[256];
                strcpy(temp, dict[j]);
                strcpy(dict[j], dict[j + 1]);
                strcpy(dict[j + 1], temp);
            }
            strcpy(dict[*len], "");
            (*len)--;
            return;
        }
    }
    printf("|4.Info| Cannot remove word: the word is not in the dictionary.");
}
