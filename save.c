/* Function: save : This function saves the current inverted index database into a backup file provided by the user.
It:
    1. Checks whether database exists
    2. Takes file name from user
    3. Validates ".txt" extension
    4. Traverses entire hash table
    5. Writes data in structured format
File Format Structure:
    #index;file_count;word;word_count;filename;word_count;filename;#
*/
#include "inverter.h"

void save(hash_t arr[])
{
    char save_file[25];
    int i;
    for(i = 0;i < 27;i++)
    {
        if(arr[i].link != NULL)
        break;
    }
    if(i == 27)
    {
        printf(BOLD_RED "ERROR : Database is empty\n\n" RESET);
        return;
    }
    /*reading file name from user*/
    printf("Enter the file name where you want to save : ");
    scanf(" %[^\n]", save_file);

    /*checking file extension*/
    char* substr1 = strstr(save_file, ".txt");

    if(substr1 != NULL && strcmp(substr1, ".txt") == 0)
    {
        FILE* fptr = fopen(save_file, "w");
        if(fptr == NULL)
        {
            printf(BOLD_RED "ERROR : Unable to open file\n\n" RESET);
            return;
        }

        /*traversing hash table*/
        for(int index = 0; index < 27; index++)
        {
            main_node_t* temp_main = arr[index].link;
            /*traversing main node*/
            while(temp_main != NULL)
            {
                /*printing main node details into file*/
                /* Print index, file_count, word */
                fprintf(fptr, "#%d;%d;%s;",index,temp_main->file_count,temp_main->word);

                /* Print all sub nodes in same line */
                sub_node_t* temp_sub = temp_main->sub_link;
                /*traversing sub node*/
                while(temp_sub != NULL)
                {
                    /*printing word count, file name*/
                    fprintf(fptr, "%d;%s;",temp_sub->word_count,temp_sub->filename);

                    /*updating temp sub node*/
                    temp_sub = temp_sub->link;
                }
                /* Close the line */
                fprintf(fptr, "#\n");
                /*updating temp main node*/
                temp_main = temp_main->link;
            }
        }
        fclose(fptr);
        printf(BOLD_GREEN "Database saved successfully into %s\n\n" RESET, save_file);
    }
    else
    {
        printf(BOLD_RED "ERROR : %s invalid file name extension\n\n" RESET, save_file);
        printf(BOLD_RED "Example : (filename.txt)\n" RESET);
    }
}

