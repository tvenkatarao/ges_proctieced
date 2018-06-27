#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    main    (void)
{
				static  char    buf1 [] = { "I am to be copied"  };
				char            buf2 [25], *strptr;
				static  int     data1 [5] = { 1, 2, 3, 4, 5  };
				int             data2 [5], i, compare;

				/*      copy characters from buf1 to buf2       */
				(void) memcpy ((void *) buf2, (void *) buf1, sizeof (buf1));
				(void) fprintf (stdout, "%s\n", buf2);

				/*      copy data1 array to data2               */
				(void) memcpy ((void *) data2, (void *) data1, sizeof (data1));
				for (i = 0; i < 5; i++)
								(void) fprintf (stdout, "%d ", data2 [i]);
				(void) fprintf (stdout, "\n");
				
				/*      scan buf1 for charcter 't'              */
				strptr = memchr ((void *) buf1, 't', sizeof (buf1));
				(void) fprintf (stdout, "%s\n", strptr);
				
				/*      compare buf1 to buf2                    */
				compare = memcmp ((void *) buf1, (void *) buf2, sizeof (buf1));
				(void) fprintf (stdout, "%d\n", compare);
				
				/*      set buf2 array to all 'x' characters    */
				(void) memset ((void *) buf2, 'x', sizeof (buf2));
				for (i = 0; i < sizeof (buf2); ++i)
								(void) fprintf (stdout, "%c", buf2 [i]);
				(void) fprintf (stdout, "\n");
				exit (EXIT_SUCCESS);

}
