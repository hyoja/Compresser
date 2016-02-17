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
		printf("select mode 0. compress, 1. decompress");
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
				printf("file readed fail retype your file name : main\n");
				scanf("%s",filename);
			}
			else
			{
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
				if(whileCount > 254)
				{
					fputc(whileCount,writeFilePointer);
					whileCount = 0;
				}
			}
			else
			{
				if(whileCount >0)
				{
					fputc(whileCount,writeFilePointer);
				}
				whileCount = 0;
				fputc(ch,writeFilePointer);
			}
			countt++;
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
				}
			}
			else
			{
				fputc(ch,writeFilePointer);
			}
		}
		fclose(writeFilePointer);
		fclose(writeTextPointer);
		system("chmod 775 doneFile");
	}
	return 0;
}
