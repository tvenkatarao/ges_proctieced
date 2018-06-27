#include <stdio.h>
#include <string.h>

union Data {
				int i;
				float f;
				char str[20];

};

int main(  ) {

				union Data data;        

				data.i = 10;
printf("%d\n",sizeof(float));
data.f = 5;
				printf( "data.i : %d-%f\n", data.i,data.f );

				data.f = 220.5;
				printf( "data.f : %f\n", data.f );

				strcpy( data.str, "C Programming" );
				printf( "data.str : %s\n", data.str );

				return 0;

}

