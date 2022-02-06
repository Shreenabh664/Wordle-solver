#define MAX_WORDS 2315
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void read_words(char *file_name, char **words, int *num_words)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    long read;
    int i = 0;
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp)) != -1)
    {
        words[i] = malloc(sizeof(char) * 6);
        strcpy(words[i], line);
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        words[j][strlen(words[j]) - 1] = '\0';
    }

    *num_words = i;
    fclose(fp);
    if (line)
        free(line);
}

int has_repeated(char *word)
{
    int len = 5;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (word[i] == word[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

int has_char(char *word, char c)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

int has_char_at(char *word, char c, int pos)
{
    if (word[pos] == c)
    {
        return 1;
    }
    return 0;
}

void dealwith(char *feedback, char *first_word, int *num_words, char **words)
{
    for (int i = 0; i < strlen(feedback); i++)
    {
        if (feedback[i] == 'b')
        {
            for (int j = 0; j < *num_words; j++)
            {
                if (has_char(words[j], first_word[i]))
                {
                    for (int k = j; k < *num_words - 1; k++)
                    {
                        words[k] = words[k + 1];
                    }
                    *num_words = *num_words - 1;
                    j--;
                }
            }
        }
        else if (feedback[i] == 'y')
        {
            for (int j = 0; j < *num_words; j++)
            {
                if (has_char(words[j], first_word[i]) == 0)
                {
                    for (int k = j; k < *num_words - 1; k++)
                    {
                        words[k] = words[k + 1];
                    }
                    *num_words = *num_words - 1;
                    j--;
                }
            }
            for (int j = 0; j < *num_words; j++)
            {
                if (has_char_at(words[j], first_word[i], i))
                {
                    for (int k = j; k < *num_words - 1; k++)
                    {
                        words[k] = words[k + 1];
                    }
                    *num_words = *num_words - 1;
                    j--;
                }
            }
        }
        else if (feedback[i] == 'g')
        {
            for (int j = 0; j < *num_words; j++)
            {
                if (has_char(words[j], first_word[i]) == 0)
                {
                    for (int k = j; k < *num_words - 1; k++)
                    {
                        words[k] = words[k + 1];
                    }
                    *num_words = *num_words - 1;
                    j--;
                }
            }
            for (int j = 0; j < *num_words; j++)
            {
                if (has_char_at(words[j], first_word[i], i) == 0)
                {
                    for (int k = j; k < *num_words - 1; k++)
                    {
                        words[k] = words[k + 1];
                    }
                    *num_words = *num_words - 1;
                    j--;
                }
            }
        }
        else
            printf("Invalid feedback\n");
    }
}

int compute_num_words(char *word, char **words, int num_words, char *feedback)
{
    int num_words_after = num_words;
    char **words_copy = malloc(sizeof(char *) * num_words);
    for (int i = 0; i < num_words; i++)
    {
        words_copy[i] = malloc(sizeof(char) * 6);
        strcpy(words_copy[i], words[i]);
    }
    dealwith(feedback, word, &num_words_after, words_copy);
    for (int i = 0; i < num_words; i++)
    {
        free(words_copy[i]);
    }
    free(words_copy);
    return num_words_after;
}

double entropy(char *word, char **words, int num_words)
{
    char possible_chars[] = {'b', 'y', 'g'};
    char feedback[243][6];
    int i;
    for (i = 0; i < 243; i++)
    {
        feedback[i][0] = possible_chars[i / 81 % 3];
        feedback[i][1] = possible_chars[i / 27 % 3];
        feedback[i][2] = possible_chars[i / 9 % 3];
        feedback[i][3] = possible_chars[i / 3 % 3];
        feedback[i][4] = possible_chars[i % 3];
        feedback[i][5] = '\0';
    }
    double num_words_count[243];
    for (i = 0; i < 243; i++)
    {
        num_words_count[i] =
            compute_num_words(word, words, num_words, feedback[i]);
    }
    double sum = 0;
    for (i = 0; i < 243; i++)
    {
        sum += num_words_count[i];
    }
    for (i = 0; i < 243; i++)
    {
        num_words_count[i] /= sum;
    }
    double entropy = 0;
    for (i = 0; i < 243; i++)
    {
        if (num_words_count[i])
        {
            entropy += num_words_count[i] * log2(num_words_count[i]);
        }
    }
    return -entropy;
}

int compare(const void *a, const void *b, char **words, int num_words)
{
    char *word_a = *(char **)a;
    char *word_b = *(char **)b;
    double entropy_a = entropy(word_a, words, num_words);
    double entropy_b = entropy(word_b, words, num_words);
    if (entropy_a > entropy_b)
    {
        return -1;
    }
    else if (entropy_a < entropy_b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void quicksort(char **words, int num_words, int left, int right)
{
    if (left < right)
    {
        int pivot = left + (right - left) / 2;
        int i = left, j = right;
        char *temp = words[pivot];
        while (i <= j)
        {
            while (compare(&words[i], &temp, words, num_words) < 0)
            {
                i++;
            }
            while (compare(&words[j], &temp, words, num_words) > 0)
            {
                j--;
            }
            if (i <= j)
            {
                char *temp2 = words[i];
                words[i] = words[j];
                words[j] = temp2;
                i++;
                j--;
            }
        }
        if (left < j)
        {
            quicksort(words, num_words, left, j);
        }
        if (i < right)
        {
            quicksort(words, num_words, i, right);
        }
    }
}

char *get_word(char **words, int num_words)
{
    quicksort(words, num_words, 0, num_words - 1);
    for (int i = 0; i < num_words; i++)
    {
        if (has_repeated(words[i]) == 0)
        {
            return words[i];
        }
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    char *file_name = malloc(sizeof(char) * 100);
    if (argc != 2)
    {
        file_name = "words.txt";
    }
    else
    {
        file_name = argv[1];
    }
    char **words = (char **)malloc(sizeof(char *) * MAX_WORDS);
    int num_words;
    read_words(file_name, words, &num_words);
    free(file_name);
    char first_word[6] = "soare";
    printf("soare\n");

    char feedback[6];
    scanf("%s", feedback);
    dealwith(feedback, first_word, &num_words, words);
    while (num_words)
    {
        char *word = get_word(words, num_words);
        if (word != NULL)
        {
            printf("%s\n", word);
            scanf("%s", feedback);
            if (strcmp(feedback, "ggggg") == 0)
            {
                break;
            }
            dealwith(feedback, word, &num_words, words);
        }
        else
        {
            for (int i = 0; i < num_words; i++)
            {
                printf("%s\n", words[i]);
                scanf("%s", feedback);
                if (strcmp(feedback, "ggggg") == 0)
                {
                    break;
                }
            }
            break;
        }
    }
    for (int i = 0; i < MAX_WORDS; i++)
    {
        free(words[i]);
    }
    free(words);
    return 0;
}
