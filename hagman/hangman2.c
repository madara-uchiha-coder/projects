#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Structure to store each word and its details
struct WordData {
    char word[30];
    char category[30];
    char difficulty[10];
    char hint[100];
};

// Function to display hangman stages
void showHangman(int attempts) {
    switch (attempts) {
        case 0:
            printf("\n  _____\n  |   |\n      |\n      |\n      |\n______|_\n");
            break;
        case 1:
            printf("\n  _____\n  |   |\n  O   |\n      |\n      |\n______|_\n");
            break;
        case 2:
            printf("\n  _____\n  |   |\n  O   |\n  |   |\n      |\n______|_\n");
            break;
        case 3:
            printf("\n  _____\n  |   |\n  O   |\n /|   |\n      |\n______|_\n");
            break;
        case 4:
            printf("\n  _____\n  |   |\n  O   |\n /|\\  |\n      |\n______|_\n");
            break;
        case 5:
            printf("\n  _____\n  |   |\n  O   |\n /|\\  |\n /    |\n______|_\n");
            break;
        case 6:
            printf("\n  _____\n  |   |\n  O   |\n /|\\  |\n / \\  |\n______|_\n");
            break;
    }
}

int main() {
    // Word bank with all details
    struct WordData words[] = {
        {"PROGRAMMING", "Technology", "Medium", "Creating software"},
        {"ELEPHANT", "Animals", "Easy", "Largest land mammal"},
        {"CRYPTOCURRENCY", "Technology", "Hard", "Digital currency"},
        {"COMPUTER", "Technology", "Easy", "Used for processing data"},
        {"COUNTRY", "General", "Easy", "A nation with its own government"}
    };

    int totalWords = 5;
     srand(time(0));

    char word[50], masked[50], guess;
    int lives = 7, wrong = 0, i, found, len, win = 0;
    int index = rand() % totalWords;

    // Select a random word
    strcpy(word, words[index].word);
    len = strlen(word);

    // Initialize masked word
    for (i = 0; i < len; i++)
        masked[i] = '_';
    masked[len] = '\0';

    // Display initial info
    printf("===== HANGMAN WORD GUESSING GAME =====\n");
    printf("Category: %s\n", words[index].category);
    printf("Difficulty: %s\n", words[index].difficulty);
    printf("Hint: %s\n", words[index].hint);
    printf("The word has %d letters.\n", len);

    // Game loop
    while (wrong < lives && !win) {
        showHangman(wrong);
        printf("\nWord: %s\n", masked);
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        found = 0;
        for (i = 0; i < len; i++) {
            if (word[i] == guess && masked[i] == '_') {
                masked[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            printf("Wrong guess!\n");
            wrong++;
        } else {
            printf("Good guess!\n");
        }

        if (strcmp(word, masked) == 0)
            win = 1;
    }

    // Final results
    if (win) {
        printf("\n%s\n", masked);
        printf("🎉 Congratulations! You guessed the word correctly.\n");
    } else {
        showHangman(6);
        printf("\nYou lost! The correct word was: %s\n", word);
    }

    printf("\nGame Over.\n");
    return 0;
}
