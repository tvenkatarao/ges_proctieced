#include <stdio.h>


int main()
{
const char *mytext = "The quick brown fox jumps over the lazy dog";   
FILE *bfp= fopen("test.txt", "wb");   
if (bfp) 
{     
    fwrite(mytext, sizeof(char), strlen(mytext), bfp);     
    fclose(bfp);   
}
				

				return 0;

}
