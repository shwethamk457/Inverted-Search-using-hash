/*Function: search : This function searches for a given word in the inverted index database.
It:
    1. Takes a word from user
    2. Calculates hash index based on first character
    3. Traverses main node list at that index
    4. If word found:
        - Displays number of files containing the word
        - Displays frequency in each file
    5. If word not found:
        - Prints error message
*/
#include "inverter.h"

void search(hash_t arr[])
{
    /*reading word from user*/
    char word_search[25];
    printf("Enter the word : ");
    scanf(" %s",word_search);
    int index;
    if(word_search[0] >= 'a' && word_search[0] <= 'z')
    {
        index = word_search[0] - 'a';
    }
    else if(word_search[0] >= 'A' && word_search[0] <= 'Z')
    {
        index = word_search[0] - 'A';
    }
    else
    {
        index = 26;
    }
        if(arr[index].link != NULL)
        {
            main_node_t* temp_main = arr[index].link;
            while(temp_main != NULL)
            {
                if(strcmp(temp_main->word,word_search) == 0)
                {
                    printf("----------------------------------------------------------------------------\n\n");
                    printf(BOLD_GREEN "Word %s present in %d files\n" RESET,temp_main->word,temp_main->file_count);
                    sub_node_t* temp_sub = temp_main->sub_link;
                    while(temp_sub != NULL)
                    {
                        printf(BOLD_GREEN "In %s, the word present %d times\n" RESET,temp_sub->filename,temp_sub->word_count);
                        temp_sub = temp_sub->link; //updating sub node
                    }
                    printf("\n----------------------------------------------------------------------------\n");
                    return;
                }
                temp_main = temp_main->link; //updating main node
            }
            if(temp_main == NULL)
            {
                printf(BOLD_RED "ERROR : Word is not found\n\n" RESET);
                return;
            }
        }
        else
        {
            printf(BOLD_RED "ERROR : Word is not found\n\n" RESET);
            return;
        }
    printf("---------------------------------------------------\n");
}