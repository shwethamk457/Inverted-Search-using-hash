/*Function: validate_arguments : This function validates the file names passed through command line arguments.
It checks:
    1. Whether the file has ".txt" extension
    2. Whether the file exists
    3. Whether the file is not empty
    4. Whether the file is not already added (duplicate check)
Returns:
    1 → Valid file
    0 → Invalid file
*/
#include "inverter.h"

/*validating the file name which are passed in CLA*/
int validate_arguments(char argv[],FILE_NAME** head)
{
    /*checking .txt file extension*/
    char* substr1=strstr(argv,".txt");
    if(substr1 != NULL)
    { 
        if((strcmp(substr1,".txt"))!=0)
        {
            printf(RED "ERROR : %s invalid file name extension\n" RESET,argv);
            return 0;
        }
        else
        {
            /*checking if file is exist or not*/
            FILE* fptr = fopen(argv,"r");
            if(fptr == NULL)
            {
                printf(RED "ERROR : %s file is not present\n" RESET,argv);
                return 0;
            }
            else
            {
                /*checking content is present or not*/
                fseek(fptr,0,SEEK_END);
                long size = ftell(fptr);
                fclose(fptr);
                if(size == 0)
                {
                    printf(RED "ERROR : %s in file content is not present\n"RESET ,argv);
                    return 0;
                }
                else
                {
                    /*checking if the file name is duplicate or not*/
                    if(*head == NULL)
                        return 1;
                    
                    FILE_NAME* temp = *head;
                    /*traverse*/
                    while(temp != NULL)
                    {
                        if((strcmp(argv,temp->file_name)) == 0)
                        {
                            printf(RED "ERROR : %s file is already copied\n" RESET,argv);
                            return 0;
                        }
                        /*updating the temp value*/
                        temp = temp->link;
                    }
                    return 1;
                }
            }
        }
    }
    else
    {
        /*if file extension is invalid*/
        printf(RED "ERROR : %s invalid file name extension\n" RESET,argv);
        return 0;
    }
}

/*Insert at last for adding file name into hash table*/
int insert_at_last(char argv[],FILE_NAME** head)
{
    FILE_NAME* new = malloc(sizeof(FILE_NAME));
    if(new == NULL)
        return 0;

    strcpy(new->file_name,argv);
    new->link = NULL;
    if(*head == NULL)
    {
        *head = new;
        return 1;
    }
    else
    {
        FILE_NAME *temp=*head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new;
        return 1;
    }
}

/*printing which are files are valid for database*/
int print_filename(FILE_NAME* head)
{
    //printf("File names : ");
    if(head == NULL)
    {
        printf(RED "ERROR : In node file is not present\n" RESET);
        return 0;
    }
    while (head)		
	{
		printf(" %s -> ", head -> file_name);
		head = head -> link;
    }
	printf(" NULL\n");
    return 1;
}

/*to free the memories*/
void destroy_hash(hash_t arr[])
{
    for(int i = 0; i < 27; i++)
    {
        main_node_t *temp_main = arr[i].link;
        while(temp_main != NULL)
        {
            sub_node_t *temp_sub = temp_main->sub_link;
            /* Free sub nodes */
            while(temp_sub != NULL)
            {
                sub_node_t *sub_next = temp_sub->link;
                free(temp_sub);
                temp_sub = sub_next;
            }
            main_node_t *main_next = temp_main->link;
            free(temp_main);
            temp_main = main_next;
        }
        arr[i].link = NULL;
    }
}