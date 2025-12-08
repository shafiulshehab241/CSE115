#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

// Maximum line and input length
#define MAX_LINE_LENGTH 512
#define MAX_INPUT_LENGTH 512

// High-resolution time in seconds (double)
double get_time_in_seconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

// Generating random lines from txt file
char* read_random_line(const char* filename, char* textLine, size_t maxLen) {
    // Seed the random number generator
    srand(time(0));
    int num = (rand() % 10) + 1; // Random numbers from 1-10;

    FILE *infile = fopen(filename, "r");
    if (infile == NULL) {
        perror("Error opening file");
        textLine[0] = '\0';
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    int lines_read = 1;
    textLine[0] = '\0';

    while (lines_read < 11 && fgets(line, MAX_LINE_LENGTH, infile) != NULL) {
        if (lines_read == num) {
            line[strcspn(line, "\n")] = 0;
            strncpy(textLine, line, maxLen - 1);
            textLine[maxLen - 1] = '\0';
            break;
        }
        lines_read++;
    }

    fclose(infile);
    return (textLine[0] != '\0') ? textLine : NULL;
}

// Counting words;
int count_words(const char* str) {
    if (str == NULL || str[0] == '\0') {
        return 0;
    }

    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            count++;
        }
    }
    return count;
}

// Main function
int main() {
    srand(time(NULL));

    char text[MAX_LINE_LENGTH];
    char userInput[MAX_INPUT_LENGTH];
    double start_time, end_time;

    // INPUT SECTION

    // Read the text prompt from file
    if (read_random_line("sample.txt", text, MAX_LINE_LENGTH) == NULL) {
        fprintf(stderr, "Could not read a line from sample.txt. Exiting.\n");
        return 1;
    }

    // Waiting for user to start
    printf("\n\033[41m\033[1;30m======== Typing Speed Test ========\033[0m\n\n");
    printf("\033[36mType the following sentence:\033[1m\n=> ");
    printf("%s\n\n\033[0mPress Enter when ready...", text);
    getchar();

    // Start the timer and get user input
    printf("\n\033[1;96mStart typing below:\033[0m\n");
    start_time = get_time_in_seconds();

    if (fgets(userInput, MAX_INPUT_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading user input.\n");
        return 1;
    }

    end_time = get_time_in_seconds();

    // Clean up input and remove the newline added by fgets
    userInput[strcspn(userInput, "\n")] = 0;

    // CALCULATION SECTION

    // Calculate time taken
    double seconds = end_time - start_time;

    // Count words typed
    int wordCount = count_words(userInput);

    // Calculate Words Per Minute (WPM)
    double wpm = (wordCount / seconds) * 60.0;

    // Calculate Accuracy
    size_t text_len = strlen(text);
    size_t userInput_len = strlen(userInput);
    int correctChars = 0;
    size_t minLength = (text_len < userInput_len) ? text_len : userInput_len;

    for (size_t i = 0; i < minLength; i++) {
        if (text[i] == userInput[i]) {
            correctChars++;
        }
    }

    double accuracy = (double)correctChars / text_len * 100.0;

    // OUTPUT SECTION

    printf("\n\033[44m\033[1;97m========== Results ==========\033[0m\n\n");

    //Higher WPM
    if (wpm > 60 && accuracy>=90.0){
        printf("\033[39mTime Taken: \033[32m %.2f seconds\033[0m\n",seconds);
        printf("\033[39mWords Typed: \033[32m %d \033[0m\n",wordCount);
        printf("\033[39mSpeed: \033[32m %.2f WPM\033[0m\n",wpm);
        printf("\033[39mAccuracy: \033[32m %.2f %\033[0m\n",accuracy);
    }
    //Normal WPM
    else if(wpm >= 30 && accuracy>=50.0){
        printf("\033[39mTime Taken: \033[33m %.2f seconds\033[0m\n",seconds);
        printf("\033[39mWords Typed: \033[33m %d \033[0m\n",wordCount);
        printf("\033[39mSpeed: \033[33m %.2f WPM\033[0m\n",wpm);
        printf("\033[39mAccuracy: \033[33m %.2f %\033[0m\n",accuracy);
    }
    //Noob
    else{
        printf("\033[39mTime Taken: \033[31m %.2f seconds\033[0m\n",seconds);
        printf("\033[39mWords Typed: \033[31m %d \033[0m\n",wordCount);
        printf("\033[39mSpeed: \033[31m %.2f WPM\033[0m\n",wpm);
        printf("\033[39mAccuracy: \033[31m %.2f %\033[0m\n",accuracy);
    }

    return 0;
}
