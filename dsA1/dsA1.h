//FileName:		dsA1.h
//Project:		dsA1
//Author:		Alex Guerrero	
//Date:			January 30, 2014
//Description:	This program takes a user inputted argument containing a directory.  
//				The program processes the string to make it a viable directory path to search for all
//				mp3 files in that directory.  If found, the artist, song title and mp3 extension are 
//				saved to a node in a linked list.  When all mp3 files have been found and linked to a linked list,
//				the list is printed through traversing the list.  After items have been displayed, the program frees
//				memory and exits.


//Include files
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>

//disables a warning to allow the use of depreciated functions
#pragma warning(disable: 4996)


//Constants
#define kOne 1
#define kTrue 1
#define kFalse 0

//structure
typedef struct songInfo {
	char *artist;
	char *songTitle;
	char *fileExt;
	struct songInfo *next;
} songInfo;



//prototypes
songInfo *fileSearchAttachToList(char *fileLocation, char *string, songInfo *head, char *string2, char *string3, char *string4);
void copyContents(char *buffer, char* finalString);
void addFileExtension(char* addressOfLastCharacter, char *p, char* buffer, char* finalString);
void list_info(songInfo *head);
void delete_info(songInfo *head);



