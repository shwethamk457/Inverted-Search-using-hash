#ifndef INVERTER_H
#define INVERTER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* =========================================================
   ANSI COLOR CODES
   These macros are used to print colored output in terminal
   for better readability and user interaction.
   ========================================================= */
#define RESET "\033[0m"

/* Regular Colors */
#define RED         "\033[31m"
#define GREEN       "\033[32m" 
#define BLUE        "\033[34m"

/* Bold */
#define BOLD_BLACK      "\033[1;30m"
#define BOLD_RED        "\033[1;31m"
#define BOLD_GREEN      "\033[1;32m"
#define BOLD_BLUE       "\033[1;34m"

/* Underline */
#define UNDERLINE_RED       "\033[4;31m"
#define UNDERLINE_WHITE     "\033[4;37m"

/*for storing the file name*/
typedef struct node
{
    char file_name[30];
    struct node* link;
}FILE_NAME;

/*Sub node*/
typedef struct node1
{
    int word_count;
    char filename[25];
    struct node1 *link;
}sub_node_t;

/*Main node*/
typedef struct node2
{
    int file_count;
    char word[50];
    sub_node_t* sub_link;
    struct node2* link;
}main_node_t;

/*hash table */
typedef struct node3
{
    int index;
    main_node_t* link;
}hash_t;

int validate_arguments(char [],FILE_NAME **);

int insert_at_last(char [],FILE_NAME **);

int print_filename(FILE_NAME* );

//create database
void create(hash_t [],FILE_NAME* );

main_node_t* create_main_node(char* word);

sub_node_t* create_sub_node(char *filename);

//display database
void display(hash_t []);

//save database
void save(hash_t []);

//search database
void search(hash_t []);

//update database
int update(hash_t [],FILE_NAME* );

int is_file_present(hash_t [], char* );

//destroying the memories
void destroy_hash(hash_t []);

#endif