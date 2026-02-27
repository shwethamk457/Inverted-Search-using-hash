/* Function: update : This function rebuilds (updates) the inverted index database from a previously saved backup file.
It:
    1. Takes backup file name from user
    2. Validates ".txt" extension
    3. Opens backup file
    4. Reads each stored record
    5. Reconstructs main nodes and sub nodes
    6. Inserts them back into hash table
Backup File Format:
    #index;file_count;word;word_count;filename;word_count;filename;#
*/
#include "inverter.h"

int update(hash_t arr[], FILE_NAME* head)
{
    char backup_file[30];

    printf("Enter backup file name : ");
    scanf("%s", backup_file);

    /* Check .txt extension */
    char *ext = strstr(backup_file, ".txt");
    if(ext == NULL || strcmp(ext, ".txt") != 0)
    {
        printf(BOLD_RED "ERROR : Invalid file extension\n\n" RESET);
        return 0;
    }

    FILE *fptr = fopen(backup_file, "r");
    if(fptr == NULL)
    {
        printf(BOLD_RED "ERROR : Backup file not found\n\n" RESET);
        return 0;
    }

    char line[200];

    while(fscanf(fptr, "%s", line) != EOF)
    {
        int len = strlen(line);

        // Validate format 
        if(line[0] != '#' || line[len - 1] != '#')
        {
            printf(BOLD_RED "ERROR : Invalid backup file format\n\n" RESET);
            fclose(fptr);
            return 0;
        }

        //Remove last '#' 
        line[len - 1] = '\0';

        //Skip first '#' 
        char *token = strtok(&line[1], ";");

        //Index 
        int index = atoi(token);

        //File count 
        token = strtok(NULL, ";");
        int file_count = atoi(token);

        //Word 
        token = strtok(NULL, ";");

        main_node_t *new_main = malloc(sizeof(main_node_t));
        new_main->file_count = file_count;
        strcpy(new_main->word, token);
        new_main->sub_link = NULL;
        new_main->link = NULL;

        //Insert main node 
        new_main->link = arr[index].link;
        arr[index].link = new_main;

        sub_node_t *last_sub = NULL;

        //Loop file_count times to create sub nodes 
        for(int i = 0; i < file_count; i++)
        {
            //Word count
            token = strtok(NULL, ";");
            int word_count = atoi(token);

            //Filename
            token = strtok(NULL, ";");

            sub_node_t *new_sub = malloc(sizeof(sub_node_t));
            new_sub->word_count = word_count;
            strcpy(new_sub->filename, token);
            new_sub->link = NULL;

            if(new_main->sub_link == NULL)
            {
                new_main->sub_link = new_sub;
                last_sub = new_sub;
            }
            else
            {
                last_sub->link = new_sub;
                last_sub = new_sub;
            }
        }
    }

    fclose(fptr);
    printf(BOLD_GREEN "Database updated from file successfully from backup\n\n" RESET);
    return 1;
}
