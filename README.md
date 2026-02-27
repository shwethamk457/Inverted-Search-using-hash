# Inverted-Search-using-hash
📌 **Project Overview**
This project implements an Inverted Search System in C using a Hash Table with 27 buckets (a–z + special characters).

An Inverted Index maps:
Word → List of files containing the word + frequency count
The system indexes multiple text files and enables fast word searching using hashing and linked list–based collision handling.

🎯 **Objectives**
Build an efficient word indexing system
Implement hashing with collision resolution
Enable fast search operations
Practice file handling in C
Use dynamic memory allocation effectively

▶️ **Program Execution (Command Line Arguments)**
The program accepts input file names as Command Line Arguments (CLA).
🔹 Execution Format
        ./a.out file1.txt file2.txt file3.txt
🔹 Example
        ./a.out data1.txt data2.txt
🔹 Meaning
        ./a.out → Executable file
        file1.txt file2.txt → Input files for indexing

🚀 **Features**
✅ Create Database : Builds inverted index from input files
📄 Display Database : Shows indexed words with file & frequency count
🔎 Search Database :	Displays files containing the searched word
💾 Save Database :	Saves database to a file
🔄 Update Database :	Reloads saved database without rebuilding

🧠 **Data Structures Used**
🔹 Hash Table (27 Buckets)
  Index	Purpose
    0–25	Words starting with a–z
    26	Special characters & digits
🔹 Hash Function
  if (isalpha(word[0]))
    index = tolower(word[0]) - 'a';
  else
    index = 26;
🔹 Collision Handling
  Separate Chaining
  Implemented using Linked Lists

🗂 **Database Storage Format**
When saved to a file:
index filecount word wordcount filename
🔹 Example : 3 2 data 1 file1.txt
              3 2 data 1 file2.txt
              0 1 algorithm 1 file1.txt
🔹 Meaning
data stored in index 3
Appears in 2 files
Appears once in each file

🏗 **Working Principle**
Read file names from command line
Open each file
Extract words
Compute hash index
Insert word into bucket
Update counts if word exists
Handle collisions using linked lists

📂 **Project Structure**
Inverted-Search
 ├── main.c
 ├── create_database.c
 ├── display_database.c
 ├── search_database.c
 ├── save_database.c
 ├── update_database.c
 ├── header.h
 └── README.md
 
📊 Example
file1.txt
data structure and algorithm
file2.txt
data mining and machine learning

🔎 Searching: data
Output:
Word: data
File Count: 2
file1.txt -> 1 time
file2.txt -> 1 time

🛠 **Concepts Covered**
Hashing
Collision Resolution
Linked Lists
File Handling
Structures
Pointers
Dynamic Memory Allocation
Command Line Arguments

🌍 **Applications**
Search Engines
Document Indexing Systems
Digital Libraries
Text Analysis Tools
Information Retrieval Systems

🔮 **Future Enhancements**
Stop-word removal
Case-insensitive advanced search
Sorting by frequency
GUI version
Large file optimization
Memory usage improvements
