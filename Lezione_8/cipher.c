#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define LEN 100
#define KEY_LEN 5

unsigned int read_string(char* phrase);
void generate_random_key(char* key);
void generate_mask(char* key, unsigned int phrase_length, char* mask);
void cypher_string(char* phrase, unsigned int phrase_length, char* mask, char* cypher);
void decypher_string(char* phrase, unsigned int phrase_length, char* mask, char* cypher);

int main(int argc, char** argv)
{
    srand48(time(NULL));

    char phrase[LEN] = {0};
    char mask[LEN + 1] = {0};
    char key[KEY_LEN + 1] = {0};
    char output[LEN] = {0};
    unsigned int phrase_length = read_string(phrase);
    unsigned int choice;

    do
    {
        printf("Choose an option:\n");
        printf("1. Random key\n");
        printf("2. Enter a custom key\n");

        scanf("%u", &choice);
        printf("\n\n");

    } while (choice - 1 > 1);
    
    if(choice == 1)
    {
        generate_random_key(key);
    }
    else
    {
        while (strlen(key) != 5)
        {
            printf("WARNING: Any key exceeding %d characters will be stripped.\n", KEY_LEN);
            scanf("%s", key);
            key[KEY_LEN] = 0;
        }
    }

    do
    {
        printf("Choose an option:\n");
        printf("1. Cipher\n");
        printf("2. Decipher\n");

        scanf("%u", &choice);
        printf("\n");

    } while (choice - 1 > 1);

    generate_mask(key, phrase_length, mask);
    if(choice == 1)
    {
        cypher_string(phrase, phrase_length, mask, output);
    }
    else
    {
        decypher_string(phrase, phrase_length, mask, output);
    }

    printf("\n=== Result ===\n");
    printf("Input: \t\t%s\n", phrase);
    printf("Key: \t\t%s\n", mask);
    printf("Output: \t%s\n", output);

    return 0;
}

unsigned int read_string(char* phrase)
{
    printf("Enter a string (Upper case only)\n");
    gets(phrase);

    if(strlen(phrase) > LEN)
    {
        fprintf(stderr, "Invalid input entered!\n");
        exit(1);
    }

    return strlen(phrase);
}

void generate_random_key(char* key)
{
    for(int i = 0; i < KEY_LEN; i++)
        key[i] = (char)((lrand48() % 26) + (int)('A'));
}

void generate_mask(char* key, unsigned int phrase_length, char* mask)
{
    for(int i = 0; i < phrase_length; i++) mask[i] = key[i % 5];
}

void cypher_string(char* phrase, unsigned int phrase_length, char* mask, char* cypher)
{
    for(int i = 0; i < phrase_length; i++) 
    {
        if(phrase[i] != ' ')
        {
            cypher[i] = (char)((phrase[i] + mask[i]) % 26 + (int)('A'));
        }
        else
        {
            cypher[i] = ' ';
        }
    }
}


void decypher_string(char* phrase, unsigned int phrase_length, char* mask, char* cypher)
{
    for(int i = 0; i < phrase_length; i++) 
    {
        if(phrase[i] != ' ')
        {
            cypher[i] = (char)((26 + phrase[i] - mask[i]) % 26 + (int)('A'));
        }
        else
        {
            cypher[i] = ' ';
        }
    }
}
