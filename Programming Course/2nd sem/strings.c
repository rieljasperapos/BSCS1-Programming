#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* strlwr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = tolower((unsigned char) *tmp);
    }

    return s;
}

char* strupr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = toupper((unsigned char) *tmp);
    }

    return s;
}

int main(void)
{
	char string[200][30];
	int i,num,ret, length, count = 0, len = 0, len1;
	char text[4000];
	
	ret = 1; num = 0;
	do{
		ret = scanf("%s",string[num]);	
		num++;
		
	}while (ret != EOF);

	num--;

	for(i=0;i<num;i++){
        length = strlen(string[i]);
		printf ("str[%d]=%s len=%d\n",i,string[i], length);
        strcat(text, string[i]);
        if(i == num-1)
        break;
        strcat(text, " ");
        //count++;
        
	}
    len = strlen(text);
    printf("##########\n");
    printf("%s len=%d\n", text, len);
    printf("##########\n");
    printf("%s", strupr(text));
    printf("\n##########\n");
    printf("%s", strlwr(text));

    return 0;



}