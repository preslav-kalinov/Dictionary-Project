#ifndef DICTIONARYCOURSEWORK_H_INCLUDED
#define DICTIONARYCOURSEWORK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wList(char language[], char dict[3][256][256], int Len[]);
void sortW(char dict[][256], int len);
void addW(char dict[][256], int *len, char word[]);
void delW(char dict[][256], int *len, char word[]);


#endif // DICTIONARYCOURSEWORK_H_INCLUDED
