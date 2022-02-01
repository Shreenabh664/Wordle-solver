#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void read_words(char **words, int *num_words)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    long read;
    int i = 0;

    fp = fopen("words.txt", "r");
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

int main()
{
    char **words = (char **)malloc(sizeof(char *) * 2315);
    int num_words;
    read_words(words, &num_words);
    printf("%d words read\n", num_words);
    printf("saute\n"); // first word printed

    char first_word[5] = "saute";
    char *feedback1 = (char *)malloc(sizeof(char) * 5);
    scanf("%s", feedback1);
    if (strcmp(feedback1, "ggggg") == 0)
    {
        free(feedback1);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    dealwith(feedback1, first_word, &num_words, words);
    free(feedback1);
    if (num_words == 1)
    {
        printf("%s\n", words[0]);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    int rand_num = rand() % num_words;
    int rand_num_count = 0;
    while (has_repeated(words[rand_num]) && rand_num_count < 2000)
    {
        rand_num = rand() % num_words;
        rand_num_count++;
    }
    if (rand_num_count == 2000)
    {
        if (num_words == 1)
        {
            printf("%s\n", words[0]);
            for (int i = 0; i < num_words; i++)
            {
                free(words[i]);
            }
            free(words);
            return 0;
        }
        else
        {
            printf("The remaining word(s) are:\n");
            for (int i = 0; i < num_words; i++)
            {
                printf("%s\n", words[i]);
            }
            for (int i = 0; i < num_words; i++)
            {
                free(words[i]);
            }
            free(words);
            return 0;
        }
    }
    printf("%s\n", words[rand_num]); // second word printed

    char *feedback2 = (char *)malloc(sizeof(char) * 5);
    scanf("%s", feedback2);
    if (strcmp(feedback2, "ggggg") == 0)
    {
        free(feedback2);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    dealwith(feedback2, words[rand_num], &num_words, words);
    free(feedback2);
    if (num_words == 1)
    {
        printf("%s\n", words[0]);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    int rand_num2 = rand() % num_words;
    rand_num_count = 0;
    while (has_repeated(words[rand_num2]) && rand_num_count < 2000)
    {
        rand_num2 = rand() % num_words;
        rand_num_count++;
    }
    if (rand_num_count == 2000)
    {
        if (num_words == 1)
        {
            printf("%s\n", words[0]);
            for (int i = 0; i < num_words; i++)
            {
                free(words[i]);
            }
            free(words);
            return 0;
        }
        else
        {
            printf("The remaining word(s) are:\n");
            for (int i = 0; i < num_words; i++)
            {
                printf("%s\n", words[i]);
            }
            for (int i = 0; i < num_words; i++)
            {
                free(words[i]);
            }
            free(words);
            return 0;
        }
    }
    printf("%s\n", words[rand_num2]); // third word printed

    char *feedback3 = (char *)malloc(sizeof(char) * 5);
    scanf("%s", feedback3);
    if (strcmp(feedback3, "ggggg") == 0)
    {
        free(feedback3);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    dealwith(feedback3, words[rand_num2], &num_words, words);
    free(feedback3);
    if (num_words == 1)
    {
        printf("%s\n", words[0]);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    int rand_num3 = rand() % num_words;
    rand_num_count = 0;
    while (has_repeated(words[rand_num3]) && rand_num_count < 2000)
    {
        rand_num3 = rand() % num_words;
        rand_num_count++;
    }
    if (rand_num_count == 2000)
    {
        if (num_words == 1)
        {
            printf("%s\n", words[0]);
            for (int i = 0; i < num_words; i++)
            {
                free(words[i]);
            }
            free(words);
            return 0;
        }
        else
        {
            printf("The remaining word(s) are:\n");
            for (int i = 0; i < num_words; i++)
            {
                printf("%s\n", words[i]);
            }
            for (int i = 0; i < num_words; i++)
            {
                free(words[i]);
            }
            free(words);
            return 0;
        }
    }
    printf("%s\n", words[rand_num3]); // fourth word printed

    char *feedback4 = (char *)malloc(sizeof(char) * 5);
    scanf("%s", feedback4);
    if (strcmp(feedback4, "ggggg") == 0)
    {
        free(feedback4);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    dealwith(feedback4, words[rand_num3], &num_words, words);
    free(feedback4);
    if (num_words == 1)
    {
        printf("%s\n", words[0]);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    int rand_num4 = rand() % num_words;
    rand_num_count = 0;
    while (has_repeated(words[rand_num4]) && rand_num_count < 2000)
    {
        rand_num4 = rand() % num_words;
        rand_num_count++;
    }
    if (rand_num_count == 2000)
    {
        if (num_words == 1)
        {
            printf("%s\n", words[0]);
            for (int i = 0; i < num_words; i++)
            {
                free(words[i]);
            }
            free(words);
            return 0;
        }
        else
        {
            printf("The remaining word(s) are:\n");
            for (int i = 0; i < num_words; i++)
            {
                printf("%s\n", words[i]);
            }
            for (int i = 0; i < num_words; i++)
            {
                free(words[i]);
            }
            free(words);
            return 0;
        }
    }
    printf("%s\n", words[rand_num4]); // fifth word printed

    char *feedback5 = (char *)malloc(sizeof(char) * 5);
    scanf("%s", feedback5);
    if (strcmp(feedback5, "ggggg") == 0)
    {
        free(feedback5);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    dealwith(feedback5, words[rand_num4], &num_words, words);
    free(feedback5);

    if (num_words == 1)
    {
        printf("%s\n", words[0]);
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
    else
    {
        printf("The remaining word(s) are:\n");
        for (int i = 0; i < num_words; i++)
        {
            printf("%s\n", words[i]);
        }
        for (int i = 0; i < num_words; i++)
        {
            free(words[i]);
        }
        free(words);
        return 0;
    }
}
