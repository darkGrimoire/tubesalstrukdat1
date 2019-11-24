/* File : driver_mesinload.c */
/* Driver dari ADT Mesin Load */

#include <stdio.h>
#include "lib/mesinload.h"
#include "lib/mesinkarfile.h"
#include "lib/boolean.h"

static FILE * src;
static FILE * src2;
static FILE * src3;

#define BUFSIZE 1024
 
int main() {
	/* Untuk Load */
    char line[512];
    int sum;
    sum = 0;
	src = fopen ("sample.txt", "rt");
	fgets(line, 512, src);
	printf("%s", line);
	src3 = fopen("pitakar.txt", "wt");
	fprintf(src3, "%s", line);
	fclose(src3);
	STARTDATA();
	while (!EndLData) {
		if (CLData.Index == 'N') {
			sum = sum + CLData.Value;
		}
		else {
			printf("%c ", CLData.Index);
		}
		ADVDATA();
	}
	printf("%d\n", sum);
	while (!feof(src)) {
		sum = 0;
		fgets(line, 512, src);
		printf("%s", line);
		src3 = fopen("pitakar.txt", "wt");
		fprintf(src3, "%s", line);
		fclose(src3);
		STARTDATA();
		while (!EndLData) {
			if (CLData.Index == 'N') {
				sum = sum + CLData.Value;
			}
			else {
				printf("%c ", CLData.Index);
			}
			ADVDATA();
		}
		printf("%d\n", sum);
		fclose(src3);
	}
	fclose(src);
	/* Untuk save */
	src2 = fopen("another.txt", "wt");
	src = fopen("sample.txt", "rt");
	fgets(line, 512, src);
	fprintf(src2, "%s", line);
	while (!feof(src)) {
		fgets(line, 512, src);
		fprintf(src2, "%s", line);
	}
	printf("Done saving!\n");
    return 0;
}
