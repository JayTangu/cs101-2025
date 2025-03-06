#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* fp;
	int awrite[] = {0,1,2};
	char bwrite[] = "ABC";
	float cwrite[] = {1.1,1.2,.13};
	int aread[3]; 
	char bread[3];
	float cread[3];
	fp = fopen("a.bin","wb+");
	fwrite(awrite , sizeof(awrite),1,fp);
	fwrite(bwrite , sizeof(bwrite),1,fp);
	fwrite(cwrite , sizeof(cwrite),1,fp);
	fseek(fp,0,SEEK_SET);
	fread(aread, sizeof(awrite),1,fp);
	fread(bread, sizeof(bwrite),1,fp);
	fread(cread, sizeof(cwrite),1,fp);
	
	for(int i = 0 ; i < 3 ; i++) {
		printf("%d ",aread[i]);
	}
	printf("\n");
	for(int i = 0 ; i < 3 ; i++) {
		printf("%c ",bread[i]);
	}
	printf("\n");
	for(int i = 0 ; i < 3 ; i++) {
		printf("%f ",cread[i]);
	}
	return 0;
}
