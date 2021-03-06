//Created By Philip Keroff

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "parser.h"
#include "statSem.h"

//main function
int main(int argc, char *argv[])
{
	struct node *root = malloc(sizeof(struct node));
	char *inFileName = NULL, *outFileName;
	char tempWords[200];
	FILE *input, *tempfile, *outFile;
	int fileCheck = 0;

	//Error more than three arguments
	if(argc >= 3)
	{
		printf("Error: two many arguments\n");

		return -1;
	}

	//If there is an argument for a file
	else if(argc == 2)
	{
		inFileName = malloc(sizeof(char) * (strlen(argv[1]) + 6));
		outFileName = malloc(sizeof(char) * (strlen(argv[1]) + 4));

		strcpy(inFileName, argv[1]);
		strcpy(outFileName, argv[1]);

		strcat(inFileName, ".fs182");
		strcat(outFileName, ".asm");
		
		input = fopen(inFileName, "r");
		
		if(input == NULL)
		{
			printf("Error: That file doesn't Exist\n");
			return 1;
		}
	}

	//If it is standard Input
	else
	{	
		fileCheck = 1;

		outFileName = "out.asm";

		//Opens a tempfile to write stdin
		tempfile = fopen("tempfile", "w");

		//Scans stdin until EOF
		while(scanf("%s", tempWords) != EOF)
		{
			fprintf(tempfile, "%s ", tempWords);
		}
		
		//Closes the writable tempfile
		fclose(tempfile);

		tempfile = fopen("tempfile", "r");

		//If tempfile failed to be created
		if(tempfile == NULL)
		{
			printf("Error: tempfile was not created");
			return 1;
		}	
		
		//Sets input to tempfile
		input = tempfile;
	}

	//Starts the driver for the scanner
	root = startParser(input);

	outFile = fopen(outFileName, "w");

	statSem(root, outFile);

	//closes the files
	fclose(input);
	fclose(outFile);

	//deletes the tempfile
	if(fileCheck == 1)
	{
		remove("tempfile");
	}

	return 0;
}
