//FileName:		dsA1.c
//Project:		dsA1
//Author:		Alex Guerrero	
//Date:			January 30, 2014
//Description:	This program takes a user inputted argument containing a directory.  
//				The program processes the string to make it a viable directory path to search for all
//				mp3 files in that directory.  If found, the artist, song title and mp3 extension are 
//				saved to a node in a linked list.  When all mp3 files have been found and linked to a linked list,
//				the list is printed through traversing the list.  After items have been displayed, the program frees
//				memory and exits.


#include"dsA1.h"

int main(int argc, char* argv[])
{
	//variables for use in the program initialized
	int count = 1;
	char* finalString;
	char* buffer;
	char *addressOfLastCharacter = NULL;
	char *p = NULL;
	songInfo *head = NULL;
	char *string = NULL;
	char *string2 = NULL;
	char *string3 = NULL;
	char *string4 = NULL;
	int noArgs = kTrue;


	//if agrument count is only 1 or no argument is detected
	//display error message
	if (argc == 1 || argc == 0)
	{
		printf("Error: Usage dsAssignment1<directory...>\n");
		noArgs = kFalse;
	}

	//While loop to control program flow
	while (kOne && noArgs == kTrue)
	{
		//While loop to control program flow
		while (kOne)
		{
			//This section of code allocates memory for buffer, string and finalString variables.
			//These variables will hold the directory entered by the user. 
			buffer = (char*)malloc(strlen(argv[count]) + 50);
			//if memory not allocated, display message to user.
			//program breaks and tries again
			if (buffer == NULL)
			{
				printf("Memory not allocated\n");
				break;
			}
			finalString = (char*)malloc(strlen(argv[count]) + 50);
			//if memory not allocated, display message to user.
			//program breaks and tries again
			if (finalString == NULL)
			{
				printf("Memory not allocated\n");
				break;
			}
			string = (char*)malloc(strlen(argv[count]) + 50);//MADE a CHANGE - added this line
															 //if memory not allocated, display message to user.
															 //program breaks and tries again
			if (string == NULL)
			{
				printf("Memory not allocated\n");
				break;
			}
			//copy argument string into buffer
			strcpy(buffer, argv[count]);
			//if the buffer is empty, display message to the user
			//break out of the loop and try next directory
			if (buffer == NULL)
			{
				printf("String not copied\n");
				break;
			}
			//copy buffer contents to final string using the copyContents
			copyContents(buffer, finalString);

			//String has been copied and passed to addFileExtension to add the .mp3
			//extension
			addFileExtension(addressOfLastCharacter, p, buffer, finalString);

			//Once the string has been prepared for file searching, it is passed to fileSearchAttachToList()
			head = fileSearchAttachToList(finalString, string, head, string2, string3, string4);

			//Increment the argument count and proceed to find next directories mp3 files
			argv[++count];
			break;
		}
		//If there are no more arguments on the command line, list the linked list
		//information, free allocated memory and break out of final loop
		//to exit the program
		if (argv[count] == NULL)
		{
			list_info(head);
			delete_info(head);
			break;
		}
	}
	return 0;
}




