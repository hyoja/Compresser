#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{

	FILE *readFilePointer = NULL;
	FILE *writeFilePointer = NULL;
	FILE *writeTextPointer = NULL;
	int ch;

	
	int menuSelectValue = 0;
	while(true)
	{
		printf("select tpy 0. compact, 1. decompact");
		scanf("%d",&menuSelectValue);
		if(menuSelectValue == 0 || menuSelectValue ==1)
		{
			break;
		}
	}
	int i = 0;
	int countt = 0;
	if(menuSelectValue == 0)
	{	
		char filename[100];
		while(true)
		{
			readFilePointer = fopen(filename, "rb");
			if (readFilePointer  == NULL) 
			{
				printf("file readed fail retype your file name : main");
				scanf("%s",filename);
			}
			else
			{
				readFilePointer = fopen(filename,"rb");
				break;
			}
		}
		int whileCount = 0;
		writeFilePointer = fopen("newFile","wb");
		while  ((ch = fgetc(readFilePointer)) != EOF) 
		{
			if(ch == 0)
			{
				if(whileCount == 0)
				{
					fputc(ch,writeFilePointer);
				}
				whileCount = whileCount +1;
				if(whileCount > 250)
				{
					printf("save 0, count is %d \n",whileCount);
					fputc(whileCount,writeFilePointer);
					whileCount = 0;
				}
			}
			else
			{
				if(whileCount >0)
				{
					//printf("saved 0, count is %d \n",whileCount);
					fputc(whileCount,writeFilePointer);
				}
				//printf("readed value is %d \n",ch);
				whileCount = 0;
				fputc(ch,writeFilePointer);
			}
			countt++;
			//if(countt ==150) break;
		}
		fclose(writeFilePointer);
		fclose(readFilePointer);
	}
	else if(menuSelectValue == 1)
	{
		writeTextPointer = fopen("newFile","rb");
		writeFilePointer = fopen("doneFile","wb");
		int complitionValue = 0;
		while ( (ch = fgetc(writeTextPointer)) != EOF ) 
		{
			if(ch == 0)
			{
				int whileCount = fgetc(writeTextPointer);
				for( i = 0 ; i< whileCount;i++)
				{
					int zero = 0;
					fputc(zero,writeFilePointer);
					printf("count is %d ,",whileCount);
				}
			}
			else
			{
				fputc(ch,writeFilePointer);
			}
			printf("ch is %d \n",ch);
		}
		fclose(writeFilePointer);
		fclose(writeTextPointer);
	}
	printf("\n");
	return 0;
}
