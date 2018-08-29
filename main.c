#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	FILE *fin, *fout;
	uint8_t b[4];

	if (argc != 2) {
		printf("Usage: %s <binary-file>\n"
		       "Note: the output will be out.txt\n", argv[0]);
		return 0;
	}

	fin = fopen(argv[1], "rb");
	if (!fin) {
		printf("error: can't open %s\n", argv[1]);
		goto error1;
	}

	fout = fopen("out.txt", "w");
	if (!fout) {
		printf("error: can't open out.txt\n");
		goto error2;
	}

	while (fread(b, sizeof(b), 1, fin) == 1)
		fprintf(fout, "%02x%02x%02x%02x\n", b[3], b[2], b[1], b[0]);

	fclose(fout);
error2:
	fclose(fin);
error1:
	return 0;
}

