#include <stdio.h>
unsigned int LitToBigEndian(unsigned int x);
int main( )
{
	int Little_Endian = 0xABCDEF98;
	printf("\n Little_Endian = 0x%X\n",Little_Endian);
	printf("\n Big_Endian = 0x%X\n",LitToBigEndian(Little_Endian));
}
unsigned int LitToBigEndian(unsigned int x)
{
	int res1,res2,res3,res4;
	 res1 = ((x>>24) & 0x000000ff); 
	res2 = ((x>>8) & 0x0000ff00) ; 
	res3 = ((x<<8) & 0x00ff0000); 
	res4 =  ((x<<24) & 0xff000000);

	printf("\n Big_Endian = 0x%X\n , 0x%X\n ,0x%X\n, 0x%X\n",res1,res2,res3,res4);

	return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) | ((x<<8) &
				0x00ff0000) | ((x<<24) & 0xff000000));
}
