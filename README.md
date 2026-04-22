# Hangman Game

A simple and different Hangman game developed in C language.

## Files
- main.c
- game.c
- words.c
- game.h
- words.h
- Makefile

## Categories
- Animals
- Countries
- Fruits

## Difficulty Levels
- Easy
- Moderate
- Difficult

## How to Run
- First of all run "make clean" command
- After that Compile the project using the "make" command.
- After that, run the game using "./hangman."

## Features
- Random word selection
- Multiple categories
- Vowel hints
- Replay option
- Multiple difficulty levels

## Rules related to gameplay

- The number of blanks shows the number of letters in the hidden word
- 
- Based on the selected category ,the game takes random word belongs to that category and you should guess that word
- 
- first of all select category after that select difficulty level
- 
- Some vowels in the word will revealed at the start.
- 
- For Example , you selected moderate level , so you can choose any two vowels to reveal in the hidden word at the start of the game
- 
- Number of vowels to reveal depends on the difficulty level
- 
- Enter only one alphabet at a time .Make sure that you enter only alphabets that can be either uppercase or lowercase
- 
- Each turn , enter only a single letter guess
- 
- The number of wrong guesses that you can do depends upon the selected difficulty level
- 
- For every wrong guess , the body parts of hanging stickman will be cut based on the difficulty level
- 
- The database text files store one word per line.All words are written in lowercase letters.No spaces are used in any word.
- 
- At the end of the game either you lose or win,if you want to replay enter either 'Y' or 'y' and if you want to exit enter 'n'