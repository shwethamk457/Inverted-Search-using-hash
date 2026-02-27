/******************************************************************************************
 *  Project Name     : Inverted Search using Hash Table
 *  Student Name     : Shwetha M K
 *  Submission Date  : 27th February 2026
 *  Description      :
 *  This project implements an Inverted Search using a Hash Table.
 *  The program accepts multiple text files through command line arguments, validates them, and creates a database of words.
 *  Each word is stored in a hash table (27 buckets: a–z and special characters) along with the list of files in which the word appears and its frequency.
 
 *  The program provides the following operations:
 *      1. Create Database
 *      2. Display Database
 *      3. Save Database
 *      4. Search Word
 *      5. Update Database from Backup
 *      6. Exit
 
 *  Data Structures Used:
 *      - Linked List
 *      - Hash Table
 *      - Nested Linked List (for file details)
 ******************************************************************************************/

 #include "inverter.h"
int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        printf(BOLD_RED "ERROR : Invalid command line arguments\n" RESET);
        return 0;
    }
    FILE_NAME* head = NULL;
    /*arguments validation*/
    for(int i=1;i<argc;i++)
    {
        if(validate_arguments(argv[i],&head)==1)
        {
            insert_at_last(argv[i],&head);
        }
    }
    /*printing the file names which are validated*/
    print_filename(head);
    /*creating hash of 26 alphabets and 1 for special characters*/
    hash_t arr[27];
    /*updating index value and link part*/
    for(int i=0;i<27;i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
    int create_flag = 0,update_flag = 0;
    while(1)
    {
        int opt;
        printf("----------------------------------------------------------------------------\n");
        printf(BLUE "\t\t\t::::::Menu::::::\n");
        printf("1.Create database \n2.Display database \n3.Save database \n4.Search database \n5.Update database\n6.Exit\n" RESET);
        printf("-----------------------------------------------------------------------------\n");
        printf("Enter the option : " );
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                /*creating the database*/
                if(create_flag == 1 || update_flag == 1)
                {
                    printf(BOLD_RED "ERROR : Create/Update already completed in this execution\n\n" RESET);
                }
                else
                {
                    create(arr,head);
                    create_flag = 1;
                    printf(BOLD_GREEN "Creating database is completed\n\n" RESET);
                }
                break;

            case 2:
                /*for Display the database*/
                display(arr);
                break;
            
            case 3:
                /*saving the database into one file*/
                save(arr);
                break;
            
            case 4:
                /*for searching the word in database*/
                search(arr);
                break;
            
            case 5:
                /*updating the database from backup file*/
                if(create_flag == 1 || update_flag == 1)
                {
                    printf(BOLD_RED "ERROR : Create/Update already completed in this execution\n\n" RESET);
                }
                else
                {
                    if(update(arr,head))
                    {
                        create(arr,head);
                        update_flag = 1;
                    }
                }
                break;

            case 6:
                /*destroying the created memories*/
                destroy_hash(arr);
                return 0;
                break;

            default:
                /*destroying the created memories*/
                destroy_hash(arr);
                return 0;
                break;
        }
        /*for continuous operations1*/
        printf("Do you want to continue ? (1.yes)(2.No) :");
        scanf("%d",&opt);
        if(opt == 2)
            break;
    }
    return 0;
}