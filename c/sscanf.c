#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{

    char n[] = "hellonworld!";

    char s[13];

    sscanf(n, "%s", s);

    printf("%s\n", s);


    int day, year;
    char weekday[20], month[20], dtm[100];

    strcpy( dtm, "Saturday March 25 1989 fjs" );
    sscanf( dtm, "%s %s %d  %d", weekday, month, &day, &year );

    printf("%s %d, %d = %s\n", month, day, year, weekday );

    return 0;

}
