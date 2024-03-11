#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t file_open(const char* filename) 
{
    	FILE *file = fopen(filename, "rb");
	
	uint32_t number;
    	if (fread(&number, sizeof(number), 1, file) != 1) 
    	{
		fprintf(stderr, "Error reading file '%s'\n", filename);
		fclose(file);
	}

    	fclose(file);

	return number;
}

int main(int argc, char* argv[]) 
{
	uint32_t file1 = file_open(argv[1]);
	uint32_t file2 = file_open(argv[2]);

	uint32_t num1 = ntohl(file1);
	uint32_t num2 = ntohl(file2);

	uint32_t sum = num1 + num2;
    	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1,num1, num2,num2, sum,sum);

	//reutrn 0;
}

