#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "game.h"

int check_char(char guess,char selected_word[]){
    int length=strlen(selected_word);
    int found=0;

    for(int i=0;i<length;i++){
        if(selected_word[i]==guess){
            found=1;
            return found;
        }
    }

    return found;
}

int play_game(char selected_word[],int difficulty){

    int length=strlen(selected_word);
    int no_of_wrong_attempt=0;
    char guess;
    char guessed[length+1];
    char wrong_guessed[26];
    int wrong_count=0;
    guessed[length]='\0';
    char vowel;
    int reveal_count;
    char used_vowels[5];
    int used_count=0;
    if(difficulty==1){
        reveal_count=3;
    }
    else if(difficulty==2){
        reveal_count=2;
    }
    else if(difficulty==3){
        reveal_count=1;
    }
    for(int i=0;i<length;i++){
        guessed[i]='_';
    }

    printf("\nUse your free vowel hints wisely 😏\n");
    
    for(int k=1;k<=reveal_count;k++){
        printf("Choose vowel %d to reveal (a/e/i/o/u): ",k);
        scanf(" %c",&vowel);
        vowel=tolower(vowel);

        if(vowel!='a' && vowel!='e' && vowel!='i' &&
        vowel!='o' && vowel!='u'){
        printf("That is not a vowel. Try again.\n");
        k--;
        continue;
        }   

        int already_used=0;

        for(int j=0;j<used_count;j++){
            if(used_vowels[j]==vowel){
            already_used=1;
            break;
        }
        }

        if(already_used==1){
        printf("You already selected that vowel. Try using memory too 😏\n");
        k--;
        continue;
        }

        used_vowels[used_count]=vowel;
        used_count++;

        for(int i=0;i<length;i++){
        if(selected_word[i]==vowel){
            guessed[i]=vowel;
            }
        }
    }
    

    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |         (_)\n");
    printf("      |         /|\\\n");
    printf("      |          |\n");
    printf("      |         / \\\n");
    printf("      |\n");
    printf("______|________________\n");

 while(1){
    
    printf("\n");
    for(int i=0;i<length;i++){
        printf("%c ",guessed[i]);
    }

    printf("\n\n");
    printf("Dare to guess? Type a letter: ");
    scanf(" %c",&guess);
    printf("\n\n");
    guess=tolower(guess);
    int already_guessed=0;

    for(int i=0;i<length;i++){
        if(guessed[i]==guess){
            already_guessed=1;
            break;
        }
    }

    for(int i=0;i<wrong_count;i++){
        if(wrong_guessed[i]==guess){
            already_guessed=1;
            break;
        }
    }

    if(already_guessed==1){
        printf("Already guessed that letter. Try using your memory next time.\n\n\n");
        continue;
    }

    int if_there=check_char(guess,selected_word);
    if(if_there==0){
        wrong_guessed[wrong_count]=guess;
        wrong_count++;
        no_of_wrong_attempt++;
    }

    if(if_there==1){

        for(int i=0;i<length;i++){
            if(selected_word[i]==guess){
                guessed[i]=guess;
            }
            
        }

        printf("\n");

        if(strcmp(guessed, selected_word) == 0){
            printf("\n");

            printf("The word is %s\n",selected_word);
            printf("=============================================\n");
            printf("              YOU WON 🎉\n");
            printf("=============================================\n");
            printf(" The stickman survives... somehow because of you.\n");
            printf(" Even luck decided to support you today.\n");
            printf(" Intelligence detected for the first time.\n");
            printf(" Enjoy this rare moment of success 😏\n");
            printf("=============================================\n");
            return 1;
        }

    }

    else if(if_there==0){

        if(difficulty==2){  

            if(no_of_wrong_attempt==1){
                printf("      ____________\n");
                printf("      |          |\n");
                printf("      |         (_)\n");
                printf("      |         /|\\\n");
                printf("      |          |\n");
                printf("      |         /\n");
                printf("      |\n");
                printf("______|________________\n");
                printf("One leg gone already.\n");
                printf("He is hopping because of your guessing skills.\n");
                printf("Strong start... for disaster.\n");
        }

        else if(no_of_wrong_attempt==2){
                printf("      ____________\n");
                printf("      |          |\n");
                printf("      |         (_)\n");
                printf("      |         /|\\\n");
                printf("      |          |\n");
                printf("      |\n");
                printf("      |\n");
                printf("______|________________\n");
                printf("Both legs are gone.\n");
                printf("Now he can't run from your mistakes.\n");
                printf("Standing was overrated anyway.\n");
        }

        else if(no_of_wrong_attempt==3){
                printf("      ____________\n");
                printf("      |          |\n");
                printf("      |         (_)\n");
                printf("      |         /|\n");
                printf("      |          |\n");
                printf("      |\n");
                printf("      |\n");
                printf("______|________________\n");
                printf("Two legs and one hand gone.\n");
                printf("You are dismantling him piece by piece.\n");
                printf("At this rate, confidence is next.\n");
        }

        else if(no_of_wrong_attempt==4){
                printf("      ____________\n");
                printf("      |          |\n");
                printf("      |         (_)\n");
                printf("      |          |\n");
                printf("      |          |\n");
                printf("      |\n");
                printf("      |\n");
                printf("______|________________\n");
                printf("Two legs and two hands gone.\n");
                printf("Only the body remains, just like your hope.\n");
                printf("One more mistake and history will remember this failure.\n");
        }

        else if(no_of_wrong_attempt==5){
                printf("      ____________\n");
                printf("      |          |\n");
                printf("      |          |\n");
                printf("      |\n");
                printf("      |\n");
                printf("      |\n");
                printf("      |\n");
                printf("______|________________\n");
                printf("\n");
                printf("=============================================\n");
                printf("               GAME OVER 💀\n");
                printf("=============================================\n");
                printf("The word was: %s\n\n. Better luck next time.\n", selected_word);
                printf("         O        <- Head rolled away\n");
                printf("        /|\\       <- Arms gave up\n");
                printf("         |        <- Body collapsed\n");
                printf("        / \\       <- Legs ran away\n");
                printf("\n");
                printf("      O           /|\\           / \\\n");
                printf("   Pieces of your hopes are everywhere!\n");
                printf("\n");
                printf("=============================================\n");
                printf(" You couldn't save him this time...\n");
                printf(" Even the stickman lost faith in you.\n");
                printf(" Better luck next round, champion 😏\n");
                printf("=============================================\n\n\n");

            return 0;
        }
     }
     
     else if(difficulty==1){

        if(no_of_wrong_attempt==1){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |         (_)\n");
    printf("      |         /|\\\n");
    printf("      |          |\n");
    printf("      |         /\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("One leg gone.\n");
    printf("Still plenty of chances... somehow.\n");
}

else if(no_of_wrong_attempt==2){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |         (_)\n");
    printf("      |         /|\\\n");
    printf("      |          |\n");
    printf("      |\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("Both legs gone.\n");
    printf("Walking is no longer an option.\n");
}

else if(no_of_wrong_attempt==3){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |         (_)\n");
    printf("      |          |\\\n");
    printf("      |          |\n");
    printf("      |\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("One hand gone too.\n");
    printf("This is getting awkward.\n");
}

else if(no_of_wrong_attempt==4){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |         (_)\n");
    printf("      |          |\n");
    printf("      |          |\n");
    printf("      |\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("Both hands gone.\n");
    printf("Now he can only stare at your mistakes.\n");
}

else if(no_of_wrong_attempt==5){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |         (_)\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("Only the head remains.\n");
    printf("Hope is hanging by a thread.\n");
}

else if(no_of_wrong_attempt==6){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |          o\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("Even the head looks smaller now.\n");
    printf("Confidence has officially left the chat.\n");
}

else if(no_of_wrong_attempt==7){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |          |\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("\n");
    printf("=============================================\n");
    printf("               GAME OVER 💀\n");
    printf("=============================================\n");
    printf("The word was: %s\n", selected_word);
    printf("Easy mode was generous...\n");
    printf("You still found a way to lose 😏\n");
    printf("=============================================\n");

    return 0;
}

     }

     else if(difficulty==3){

        if(no_of_wrong_attempt==1){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |         (_)\n");
    printf("      |         /|\\\n");
    printf("      |          |\n");
    printf("      |\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("Both legs gone instantly.\n");
    printf("Brutal mode wasted no time.\n");
    printf("Running from failure was never possible.\n");
}

else if(no_of_wrong_attempt==2){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |         (_)\n");
    printf("      |          |\n");
    printf("      |          |\n");
    printf("      |\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("Both hands gone too.\n");
    printf("Now he can only watch your downfall.\n");
    printf("Confidence level: missing.\n");
}

else if(no_of_wrong_attempt==3){
    printf("      ____________\n");
    printf("      |          |\n");
    printf("      |          |\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("      |\n");
    printf("______|________________\n");

    printf("\n");
    printf("=============================================\n");
    printf("               GAME OVER 💀\n");
    printf("=============================================\n");
    printf("The word was: %s\n", selected_word);
    printf("Tough mode gave you only 3 chances.\n");
    printf("You used all of them beautifully... on failure 😏\n");
    printf("=============================================\n");

    return 0;
}

     }

    }
}
    return 0;
}