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
		char filename[100] = {0,};
		while(true)
		{
			readFilePointer = fopen(filename, "rb");
			if (readFilePointer  == NULL) 
			{
				printf("file readed fail retype your file name : main \n");
				scanf("%s",filename);
			}
			else
			{
				break;
			}
		}
		int whileCount = 0;
		int strateCheckArray[3];
		for( i = 0 ; i<3;i++)
		{
			strateCheckArray[i] = -1;
		}
		writeFilePointer = fopen("newFile","wb");
		while  ((ch = fgetc(readFilePointer)) != EOF) 
		{
			printf("readed %d ",ch);
			if(whileCount<3 && (whileCount == 0 || strateCheckArray[whileCount -1] == ch))
			{
				strateCheckArray[whileCount] = ch;
				whileCount++;
			}
			else if(strateCheckArray[2] == ch)
			{
				whileCount++;
				if(whileCount == 255)
				{
					for( i = 0 ; i< 3;i++)
					{
						fputc(strateCheckArray[0],writeFilePointer);
					}
					fputc(whileCount,writeFilePointer);
					whileCount = 0;
					for( i = 0 ; i<3;i++)
					{
						strateCheckArray[i] = -1;
					}
				}
			}
			else
			{
				if(whileCount<3)
				{
					for(i = 0; i< whileCount; i++)
					{
						printf("nomal save %d \n",strateCheckArray[i]);
						fputc(strateCheckArray[i],writeFilePointer);
					}
				}
				else
				{
					printf("compact save %d \n",whileCount);
					for( i = 0 ; i< 3;i++)
					{
						fputc(strateCheckArray[0],writeFilePointer);
					}
					fputc(whileCount,writeFilePointer);
				}
				for( i = 0 ; i<3;i++)
				{
					strateCheckArray[i] = -1;
				}
				whileCount = 1;
				strateCheckArray[0] = ch;

			}
			countt++;
		}
		if(whileCount > 0)
		{
			for( i = 0 ; i< whileCount;i++)
			{
				fputc(strateCheckArray[i],writeFilePointer);
			}
		}
		fputc(ch,writeFilePointer);
		fclose(writeFilePointer);
		fclose(readFilePointer);
	}
	else if(menuSelectValue == 1)
	{
		/*	writeTextPointer = fopen("newFile","rb");
			writeFilePointer = fopen("doneFile","wb");
			int complitionValue = 0;
			int strateCheckArray[3];
			for( i = 0 ; i<3;i++)
			{
			strateCheckArray[i] = -1;
			}
			while  ((ch = fgetc(readFilePointer)) != EOF) 
			{
			if(whileCount<3 && (whileCount == 0 || strateCheckArray[whileCount -1] == ch))
			{
			strateCheckArray[whileCount] = ch;
			whileCount++;
			}
			else if(strateCheckArray[2] == ch)
			{
			whileCount++;
			if(whileCount == 255)
			{
			for( i = 0 ; i< 3;i++)
			{
			fputc(strateCheckArray[0],writeFilePointer);
			}
			fputc(whileCount,writeFilePointer);
			whileCount = 0;
			for( i = 0 ; i<3;i++)
			{
			strateCheckArray[i] = -1;
			}
			}
			}
			else
			{
			if(whileCount<3)
			{
		//printf("nomal save \n");
		for(i = 0; i< whileCount; i++)
		{
		fputc(strateCheckArray[i],writeFilePointer);
		}
		}
		else
		{
		//printf("compact save %d",whileCount);
		for( i = 0 ; i< 3;i++)
		{
		fputc(strateCheckArray[0],writeFilePointer);
		}
		fputc(whileCount,writeFilePointer);
		//printf(" and differ value %d is nomal saved \n",ch);
		fputc(ch,writeFilePointer);
		}
		for( i = 0 ; i<3;i++)
		{
		strateCheckArray[i] = -1;
		}
		whileCount = 0;
		}
		countt++;


		}
		fclose(writeFilePointer);
		fclose(writeTextPointer);
		}*/
	printf("\n");
	return 0;
}
}
