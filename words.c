#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"words.h"

char *get_random_word(int category){
    char words[100][50];
    static char selected_word[50];
    FILE *fin;
    int count=0;
    int random_index;

    if(category==1){
        fin=fopen("animals.txt","r");
    }
    else if(category==2){
        fin=fopen("countries.txt","r");
    }
    else if(category==3){
        fin=fopen("fruits.txt","r");
    }
    else {
        printf("Please enter a valid category (1, 2, or 3)\n");
        return NULL;
    }

    if(fin==NULL){
        printf("Error in opening the file\n");
        return NULL;

    }

    while(fgets(words[count],sizeof(words[count]),fin)!=NULL){
        words[count][strcspn(words[count], "\n")] = '\0';
        count++;
    }

    fclose(fin);

    random_index=rand() % count;
    strcpy(selected_word,words[random_index]);

    return selected_word;

}