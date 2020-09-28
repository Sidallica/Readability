#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
//    printf("%i letter(s)\n", letters);

    int words = count_words(text);
//    printf("%i word(s)\n", words);

    int sentences = count_sentences(text);
//    printf("%i sentence(s)\n", sentences);

    //L is the average number of letters per 100 words in the text
    float L = ((float)letters / words) * 100;

    //S is the average number of sentences per 100 words in the text.
    float S = ((float)sentences / words) * 100;

    //Calculating grade using Coleman-Liau index
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

//Helper function to count number of letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

//Helper function to count number of words
int count_words(string text)
{
    int words = 1;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}


//Helper function to count number of sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}