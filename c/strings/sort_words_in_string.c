
// C Program to Sort Word in String


#include <stdio.h>
#include <string.h>
void main()
{
    int i,c,j = 0, k, space = 0;
    char str[100], p[50][100],  cmp[50];



    printf("Enter the string\n");
    scanf(" %[^\n]s", str);
//no of spaces in a string for sorting the string 
    for (i = 0;i < strlen(str);i++)
    {
        if ((str[i] == ' ')||(str[i] == "\n"))
        {
            space++;
        }
    }

// copy the each word into 2d array
    for (i = 0, j = 0, k = 0;j < strlen(str);j++)
    {
        if ((str[j] == ' ')||(str[j] == "\n"))  
        {    
            p[i][k] = '\0';
            i++;
            k = 0;
        }        
        else
            p[i][k++] = str[j];
    }

//sorting the array
    for (i = 0;i < space;i++)    
    {
        for (j = i + 1;j <= space;j++)
        {
            if((strlen(p[i])) > (strlen(p[j])))    
            {
                strcpy(cmp, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], cmp);
            }
            if((strlen(p[i])) == (strlen(p[j])))    
            {
                    if(strcmp(p[i] , p[j]) > 0)
                    {
                        strcpy(cmp, p[i]);
                        strcpy(p[i], p[j]);
                        strcpy(p[j], cmp);
                    }
            }
        }
    }
    printf("After sorting string is \n");
    for (i = 0;i <= space;i++)
    {
        printf("%s ", p[i]);
    }
}
