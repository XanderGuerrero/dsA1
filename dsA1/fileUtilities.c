//FileName:		fileUtilities.c
//Project:		ast_assign1
//Author:		Alex Guerrero	
//Date:			January 30, 2014
//Description:	This program takes a user inputted argument containing a directory.  
//				The program processes the string to make it a viable directory path to search for all
//				mp3 files in that directory.  If found, the artist, song title and mp3 extension are 
//				saved to a node in a linked list.  When all mp3 files have been found and linked to a linked list,
//				the list is printed through traversing the list.  After items have been displayed, the program frees
//				memory and exits.



#include"dsA1.h"



//FunctionName:	fileSearchAttachToList(char *fileLocation, char *string, songInfo *head, char *string2, char *string3, char *string4) 
//Project:		dsA1
//Date:			January 30, 2014
//Parameters:	char *fileLocation, char *string, songInfo *head, char *string2, char *string3, char *string4
//Description:	This function searches for files in a directory specified by the user by using FindFirstFile and passing the handle to FindNextFile
//				to locate all the files with an .mp3 file extension.  When a file name is found, it is copied to another string variable to process out any
//				"-"'s or "."'s. Once removed, sscanf is used to scan the artist name, song title and mp3 file extension into memory and then placed into the
//				new node of a linked list.  When the all files have been found, invalid handle value is assigned to h, ptr->next is assigned null and the 
//				function returns the address of head and is exited
songInfo *fileSearchAttachToList(char *fileLocation, char *string, songInfo *head, char *string2, char *string3, char *string4)
{
	//variables initialzed
	WIN32_FIND_DATA fileData = { 0 };
	HANDLE h = INVALID_HANDLE_VALUE;
	songInfo *newBlock = NULL;
	songInfo *ptr = NULL;
	int i = 0;
	int textCount = 0;
	char size = 0;


	//function used to find file information passing handle to h
	h = FindFirstFile(fileLocation, &fileData);

	//While .mp3 file data was found
	while (h != INVALID_HANDLE_VALUE)
	{
		//This section of code allocates space in memory for string and copies the filename found
		//by findFirstFile into string.  The length of string is calculated and the file name is processed
		//to determine if any dashes or dot's appear in the file name.  Id they do, they are replaced with 
		//spaces.  
		//The size of string is determined and assigned to size, which is used to allocate space in memory for 3 three strings
		//to hold the artist name, song title and mp3 file extension
		string = (char *)malloc(sizeof(fileData.cFileName));
		strcpy(string, fileData.cFileName);
		i = strlen(string);
		for (textCount = 0; textCount < i; ++textCount)
		{
			if (string[textCount] == '-')
			{
				string[textCount] = ' ';
			}
			if (string[textCount] == '.')
			{
				string[textCount] = ' ';
			}
		}

		size = sizeof(string);

		string2 = (char *)malloc(sizeof(size));
		string3 = (char *)malloc(sizeof(size));
		string4 = (char *)malloc(sizeof(size));

		//This section of code, sscans the string and places the artist name, song title and .mp3 file extension into
		//the 3 strings found in main.
		sscanf(string, "%s %s %s", string2, string3, string4);

		//Now that the information is ready, allocat enough room in memory for a new block of size
		//songInfo
		newBlock = (songInfo *)malloc(sizeof(songInfo));
		//If no memory is allocated, display message to user
		if (newBlock == NULL)
		{
			printf("Error! No memory!\n");
			break;
		}
		//place information into proper member of structure
		newBlock->artist = string2;
		newBlock->songTitle = string3;
		newBlock->fileExt = string4;
		newBlock->next = NULL;

		//link this record to the current list, if head is NULL,
		//this is an empty chain, so set new block of information to
		//be the head of list
		if (head == NULL)
		{
			head = newBlock;
		}
		else
		{
			//non empty chain, so use head
			// ptr to follow links 'til we reach end of
			// list, where the next field is NULL
			ptr = head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}

			//we are at end since ptr->next is NULL
			//append the new record into ptr->next
			//newBlock is ready for data insertion
			ptr->next = newBlock;
		}
		//if all files have been found, pass invalid_handle_value to 
		//h, set ptr->next as NULL, close handle and exit loop
		if (!FindNextFile(h, &fileData))
		{
			ptr->next = NULL;
			FindClose(h);
			h = INVALID_HANDLE_VALUE;
			break;
		}
	}
	//return head address
	return head;
}



//FunctionName:	copyContents(char *buffer, char* finalString)
//Project:		dsA1	
//Date:			January 30, 2014
//Parameters:	char *buffer, char* finalString
//Description:	This function copies the contents of one buffer into another
//				through the use of a for loop.  During the transfer of characters, 
//				if the buffer containing the information being transfered encounters a 
//				"\", an extra backslash is appended and copied into finalString.
void copyContents(char *buffer, char *finalString)
{
	//while loop to control function flow
	while (kOne)
	{
		//variables used in program
		int i = 0;
		int r = 0;
		int c = 0;


		//find the number of characters and place into c variable
		c = strlen(buffer);

		//This loop copies the characters found in buffer to finalString one variable 
		//at a time.  If buffer contains a "\", place into finalString and place an extra "\" 
		//into finalString to prepare string for correct file path format. once finished, exit the loop
		for (i = 0; i <= (c); ++i)
		{
			finalString[r] = buffer[i];
			if (buffer[i] == '\\')
			{
				++r;
				finalString[r] = '\\';
			}
			r++;
		}
		break;
	}
}



//FunctionName:	addFileExtension(char* addressOfLastCharacter, char *p, char* buffer, char* finalString)
//Project:		dsA1	
//Date:			January 30, 2014
//Parameters:	char* addressOfLastCharacter, char *p, char* buffer, char* finalString
//Description:	This function uses pointers to locate the addres of the last character in buffer.
//				Once found, if the last character is a ".", "\*.mp3" is added to the string.
//				If "\" is found as the last character, "*.mp3" is added and if a regular letter or 
//				any other character is found, "\\*.mp3" is appended to the end of the string
void addFileExtension(char* addressOfLastCharacter, char *p, char* buffer, char* finalString)
{
	//variables initialized
	int c = 0;


	//string length determined and placed into c
	c = strlen(buffer);

	while (kOne)
	{
		//This section of code assigns the address of buffer to p
		//and is then used in an expression to calculate the address 
		//of the last character. Once found,  a series of if statements
		//will append the proper file extension to the matching case.
		p = buffer;
		addressOfLastCharacter = p + (c - 1);
		if (*addressOfLastCharacter == '.')
		{
			strcat(finalString, "\\\\*.mp3");
			break;
		}
		if (*addressOfLastCharacter == '\\')
		{
			strcat(finalString, "*.mp3");
			break;
		}
		if (*addressOfLastCharacter != '\\')
		{
			strcat(finalString, "\\\\*.mp3");
			break;
		}
	}
}



//FunctionName: list_info(songInfo *head)
//Project:		dsA1
//Date:			January 30, 2014
//Parameters:	songInfo *head
//Description:	This function traverses the linked list through the use of a while loop to print
//				to the screen the contents of each node of the list until ptr->next is NULL.
//				The function prints out 20 files at a time and requires the user to press any key to display 
//				the next 20 files.  If only 40 files are found in total, getch() is only called once.
void list_info(songInfo *head)
{
	//variables initialized
	int count = 0;
	int numberOfNodes = 0;
	songInfo *ptr = head;


	while (kOne)
	{
		//follow the chain until the pointer is null.
		//count how many nodes are in the list.
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			++numberOfNodes;
		}
		//set the address of head to ptr
		ptr = head;

		//If the number of entries is exactly 40, print the first 20 entries and call getch()
		//to prompt the user in viewing the next 20 files
		//when printing is done, break out of the main loop
		if (numberOfNodes == 40)
		{
			//follow the chain until the pointer is null.
			while (ptr != NULL)
			{
				printf("\n");
				//print file info to the screen
				printf("%s %s %s\n", ptr->artist, ptr->songTitle, ptr->fileExt);
				ptr = ptr->next;
				++count;
				if (count == 19)
				{
					printf("\n");
					printf("Press any key to continue\n");
					getch();
				}
			}
			break;
		}
		//follow the chain until the pointer is null.
		//when printing is done, break out of the main loop
		while (ptr != NULL)
		{
			//if 20 files have been displayed, prompt user to enter any key to display next 20
			//list entries
			if (count > 19)
			{
				printf("\n");
				printf("Press any key to continue\n");
				count = 0;
				getch();
			}
			printf("\n");
			//print file info to the screen
			printf("%s %s %s\n", ptr->artist, ptr->songTitle, ptr->fileExt);
			ptr = ptr->next;
			++count;
		}
		break;
	}
	printf("\n\nNo more file to display\n\n");
}



//FunctionName: delete_info(songInfo *head)
//Project:		dsA1
//Author:		Carlo sgro
//Date:			January 30, 2014
//Parameters:	songInfo *head
//Description:	This function traverses the linked list deleting each node to free memory
//				before exiting the program
void delete_info(songInfo *head)
{
	//variables initialized
	songInfo *curr = NULL;
	songInfo *ptr = NULL;

	//address of head is assigned to ptr
	ptr = head;

	//follow the chain until the pointer is null
	while (ptr != NULL)
	{
		//save the current cell
		curr = ptr;
		// next, move to the next cell
		ptr = ptr->next;
		//free current node
		free(curr);
	}
}