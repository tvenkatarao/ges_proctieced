#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fp;
	char *string="This is testing for fwrite.\n";
	char buff[255];
	int n=0;
	/* File Write Operations */
	fp = fopen("test.txt", "w+");
	/* Access control flags */
	/*
	   "r" -> Open for reading.
	   "w" -> Open for writing.
	   "a" -> Open for appending.
	   "r+" -> Both reading and writing.
	   "w+" -> Both reading and writing, create new file if it exists,
	   "a+" -> Open for both reading and appending.
	 */
	fprintf(fp, "This is testing for fprintf.\n");
	fputs("This is testing for fputs.\n", fp);
	fwrite(string, strlen(string),5,fp);
	fclose(fp);
	memset(buff,0x00,sizeof(buff));
	/* File Reading Operations */
	fp = fopen("test.txt", "r");
	fread(&buff,sizeof(buff),1,fp);
	printf(" fread < Read in Blocks of Array OR Structure > : ");
	printf(" \n\n test.txt \n===============================");
	printf(" \n%s===============================\n", buff );
	rewind(fp); //Reset the cursor position in file at first character
	printf("\n\n fgetc <Fetch single character> : %c\n\n", fgetc(fp) );
	fscanf(fp, "%s", buff);
	printf(" fscanf <Fetch single word starting from current position> : %s\n\n",buff );fgets(buff, 255, (FILE*)fp);
	printf(" fgets <Fetch whole line from current position> : %s\n", buff );
	/* Counting number of characters in file */
	fseek(fp,0L,0); // Same as rewind.
	/*
	   fseek(fp, offset, position);
	   Position can be
	   0->start of file
	   1->current position
	   2->end of file
	   fseek(fp,0L,1); // Stay at current position.
	   fseek(fp,0L,2); // Past end of file.
	   fseek(fp,m,0); // Move to (m+1) byte.
	   fseek(fp,m,1) // Go forward m bytes.
	   fseek(fp,-m,1); // Go backward m bytes from current position.
	   fseek(fp,-m,2); // Go backward from end of file.
	 */
	while (fgetc(fp) != EOF)
		++n;
	if (feof(fp))
		printf (" feof() < Total characters > : %d\n\n",n);
	fclose(fp);
	return 0;
}
