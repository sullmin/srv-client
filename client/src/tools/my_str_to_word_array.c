/*
** EPITECH PROJECT, 2019
** new str to word array
** File description:
** new str to word array
*/

#include <stdbool.h>
#include <stdlib.h>

static bool were_parth(const char c, const char *char_list, const bool stat)
{
    if (c == '\0' || c == '\n')
        return true;
    if (c <= 32 && stat)
        return true;
    for (int i = 0; char_list[i]; i++) {
        if (c == char_list[i])
            return true;
    }
    return false;
}

static int cnt_word(const char *str, const char *char_list, const bool stat)
{
    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (!were_parth(str[i], char_list, stat) &&
            were_parth(str[i + 1], char_list, stat))
            cnt++;
    return cnt;
}

static int *char_per_word(const char *str, int size, const char *charlist,
    const bool stat)
{
    int cnt = 1;
    int move = 0;
    int *word = malloc(sizeof(int) * (size + 1));

    if (!word)
        return NULL;
    word[size] = -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!were_parth(str[i], charlist, stat) &&
            were_parth(str[i + 1], charlist, stat)) {
            word[move] = cnt;
            cnt = 0;
            move++;
        }
        if (!were_parth(str[i], charlist, stat))
            cnt++;
    }
    return word;
}

static void tab_filler(const char *str, char **tab, const char *charlist,
    const bool stat)
{
    int move = 0;
    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!were_parth(str[i], charlist, stat)) {
            tab[move][cnt] = str[i];
            tab[move][cnt + 1] = '\0';
            cnt++;
        }
        if (!were_parth(str[i], charlist, stat) && were_parth(str[i + 1],
            charlist, stat)) {
            move++;
            cnt = 0;
        }
    }
}

char **my_str_to_word_array(const char *str, const char *char_list,
    const bool stat)
{
    int size = cnt_word(str, char_list, stat);
    char **tab = malloc(sizeof(char *) * (size + 1));
    int *word = char_per_word(str, size, char_list, stat);

    if (!tab || !word)
        return NULL;
    tab[size] = NULL;
    for (int i = 0; i < size; i++) {
        tab[i] = malloc(sizeof(char) * (word[i] + 1));
        if (!tab[i])
            return NULL;
        tab[i][word[i]] = '\0';
    }
    tab_filler(str, tab, char_list, stat);
    free(word);
    return tab;
}