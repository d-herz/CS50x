// Program to calculate approximate grade level for inputted text
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    // Prompt user for a piece of text:
    string text = get_string("Text: ");

    float L = (count_letters(text) / (float) count_words(text)) * 100;
    // printf("L = %f\n", L);

    float S = (count_sentences(text) / (float) count_words(text)) * 100;
    // printf("S = %f\n", S);

    // Calculating the Coleman-Liau index:
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Rounding and assigning index to grade
    int grade = round(index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Function for counting alphabetical characters:
int count_letters(string text)
{
    int letterCount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }
    }
    // printf("%i letters\n", letterCount);

    return letterCount;
}

// Function for counting words
int count_words(string text)
{
    int wordCount = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isblank(text[i]))
        {
            wordCount++;
        }
    }
    // printf("%i words\n", wordCount);

    return wordCount;
}

// Function for counting sentences
int count_sentences(string text)
{
    int sentenceCount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCount++;
        }
    }

    // printf("%i sentences\n", sentenceCount);
    return sentenceCount;
}