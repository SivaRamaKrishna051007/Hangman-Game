#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include "words.h"
#include "game.h"

int main(){

srand(time(NULL));
printf("================================================================\n\n");

printf("██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███╗   ███╗ █████╗ ███╗   ██╗\n");

printf("██║  ██║██╔══██╗████╗  ██║██╔════╝ ████╗ ████║██╔══██╗████╗  ██║\n");

printf("███████║███████║██╔██╗ ██║██║  ███╗██╔████╔██║███████║██╔██╗ ██║\n");

printf("██╔══██║██╔══██║██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██║██║╚██╗██║\n");

printf("██║  ██║██║  ██║██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║\n");

printf("╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝\n\n");

printf("================================================================\n\n\n");

printf("=====================================================\n");
printf("                 GAME INSTRUCTIONS                  \n");
printf("=====================================================\n\n");

printf("1. The number of blanks shows the number of letters \n");
printf("   in the hidden word.\n\n");

printf("2. Enter only one alphabet at a time.\n");
printf("   You may use uppercase or lowercase letters.\n\n");

printf("3. Each turn, enter only a single letter guess.\n\n");

printf("4. You will get chances based on selected difficulty level.\n\n");

printf("5. For every wrong guess, stickman body parts will be\n");
printf("   removed depending on difficulty level.\n\n");

printf("6. There are 3 categories available:\n");
printf("   1. Animals\n");
printf("   2. Countries\n");
printf("   3. Fruits\n");
printf("   Select a category using its serial number.\n\n");

printf("7. The database text files store one word per line.\n");
printf("   All words are written in lowercase letters.\n");
printf("   No spaces are used in any word.\n\n");

printf("8. Difficulty Levels:\n");
printf("   Easy       - 7 chances and choose any 3 vowels at start\n");
printf("   Moderate   - 5 chances and choose any 2 vowels at start\n");
printf("   Difficult  - 3 chances and choose any 1 vowel at start\n\n");

printf("=====================================================\n");
printf("           Save the Stickman if you can! 😏         \n");
printf("=====================================================\n\n");

int category;
int difficulty;
char *selected_word;
char replay;

do{

printf("Choose your preferred category:\n");
printf("1. Animals\n");
printf("2. Countries\n");
printf("3. Fruits\n");
printf("Enter your choice (1-3): ");
scanf("%d",&category);

printf("\n\n");

printf("Choose your preferred difficulty level:\n");
printf("1. Easy\n");
printf("2. Moderate\n");
printf("3. Difficult\n");
printf("Enter your preferred difficulty level: ");
scanf("%d",&difficulty);

printf("\n\n");

if((category<1 || category>3) || (difficulty<1 || difficulty>3)){

    if(category<1 || category>3){
        printf("Invalid category. Even the stickman looks confused 😏\n");
        printf("Please enter 1, 2, or 3 only.\n");
    }

    printf("\n");

    if(difficulty<1 || difficulty>3){
        printf("Invalid difficulty level. Nice try though 😏\n");
        printf("Please enter 1, 2, or 3 only.\n");
    }

    printf("\n");
    continue;
}

if(category==1){
    printf("Selected Category: Animals\n");
    printf("Guess the animal name");
}
else if(category==2){
    printf("Selected Category: Countries\n");
    printf("Guess the country name");
}
else if(category==3){
    printf("Selected Category: Fruits\n");
    printf("Guess the fruit name");
}

if(difficulty==1){
    printf("\n\n");
    printf("You have chosen Easy level.\n");
    printf("You can make at most 7 wrong attempts.\n");
}
else if(difficulty==2){
    printf("\n\n");
    printf("You have chosen Moderate level.\n");
    printf("You can make at most 5 wrong attempts.\n");
}
else if(difficulty==3){
    printf("\n\n");
    printf("You have chosen Difficult level.\n");
    printf("You can make at most 3 wrong attempts.\n");
}

printf("\n\n");

selected_word=get_random_word(category);

int check=play_game(selected_word,difficulty);

if(check==0){
    printf("Want to try once more? (y/n): ");
    scanf(" %c",&replay);
}
else if(check==1){
    printf("Ready for another round? (y/n): ");
    scanf(" %c",&replay);
}

printf("\n");

}
while(replay=='y' || replay=='Y');

}