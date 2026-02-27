/* Function: display : This function displays the entire inverted index database stored inside the hash table.
It prints:
    - Hash index
    - File count (number of files containing the word)
    - Word
    - Word count in each file
    - File name
 Structure Traversal:
    1. Loop through all 27 hash buckets
    2. Traverse main node (unique words)
    3. Traverse sub node (file details)
*/
#include "inverter.h"

void display(hash_t arr[])
{
    int index;
    //loop for hash structure
    for(index=0;index<27;index++)
    {
        if(arr[index].link != NULL)
        break;
    }
    /*if all index link parts are NULL*/
    if(index == 27)
    {
        printf(BOLD_RED "No database exist\n\n" RESET);
        return;
    }
    printf(BOLD_GREEN "\t\t::::::Created database::::::\n" RESET);
    printf("+-------+---------+----------------+---------+----------------------+\n");
    printf("| Index | FileCnt | Word           | WordCnt | Filename             |\n");
    printf("+-------+---------+----------------+---------+----------------------+\n");

    for(index=0;index<27;index++)
    {
        /*traversing hash index*/
        if(arr[index].link != NULL)
        {
            /*traversing main node*/
            main_node_t* temp_main_node = arr[index].link;
            while(temp_main_node != NULL)
            {
                /*traversing sub node*/
                sub_node_t* temp_sub_node = temp_main_node->sub_link;
                while(temp_sub_node != NULL)
                {
                    /*printing the details*/
                    printf("| %-5d | %-7d | %-14s | %-7d | %-20s |\n",index,temp_main_node->file_count,temp_main_node->word,temp_sub_node->word_count,temp_sub_node->filename);
                    temp_sub_node = temp_sub_node->link;
                }
                temp_main_node = temp_main_node->link;
            }
        }
    }
    printf("+-------+---------+----------------+---------+----------------------+\n\n");
}
