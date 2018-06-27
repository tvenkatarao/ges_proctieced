#include<stdio.h>
#include<stdlib.h>

struct invent_record
{
	char   name[10];
	int    number;
	float  price;
	int    quantity;
};

void main()
{
	struct invent_record item;
	char  filename[10];
	int   response;
	FILE  *fp;
	long  n;
	void append (struct invent_record *x, FILE *y);
	printf("Type filename:");
	scanf("%s", filename);

	fp = fopen(filename, "a+");
	do
	{
		append(&item, fp);
		printf("\nItem %s appended.\n",item.name);
		printf("\nDo you want to add another item\ (1 for YES /0 for NO)?");
		scanf("%d", &response);
	}  while (response == 1);

	fseek(fp,0,SEEK_END); /*Set the file pointer at the end of file*/
	n=ftell(fp);      /* Position of last character  */
	fclose(fp);

	fp = fopen(filename, "r");

	while(ftell(fp) < n)
	{
		fscanf(fp,"%s %d %f %d",item.name, &item.number, &item.price, &item.quantity);
		fprintf(stdout,"%-8s %7d %8.2f %8d\n",item.name, item.number, item.price, item.quantity);
	}
	fclose(fp);
}
void append(struct invent_record *product, FILE *ptr)
{
	printf("Item name:");                                        
	scanf("%s", product->name);                                  
	printf("Item number:");                                      
	scanf("%d", &product->number);                               
	printf("Item price:");                                       
	scanf("%f", &product->price);                                
	printf("Quantity:");                                         
	scanf("%d", &product->quantity);                             
	fprintf(ptr, "%s %d %.2f %d",                                
			product->name,                                 
			product->number,                               
			product->price,                                
			product->quantity);                            
}  
