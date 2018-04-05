#include <stdio.h>
#include <string.h>

struct student {
	int stt;
	char id[8], name[100];
};

int main()
{
	student a[100];
	int count = 0;
	FILE *f = fopen("17APCS1-Students.csv", "r");
	FILE *g = fopen("anotherFile.csv", "w");

	char tmp[100];
	fgets(tmp, 99, f);
	fprintf(g, "%s", tmp);
	fgets(tmp, 99, f);
	fprintf(g, "%s", tmp);

	for (; count < sizeof(a) / sizeof(a[0]); count++) {
		int got = fscanf(f, "%d,%[^,],%[^\n]\n", &a[count].stt, &a[count].id, &a[count].name);
		if (got != 3) break;
		fprintf(g, "%d,%s,%s\n", a[count].stt, a[count].id, a[count].name);
		printf("%d,%s,%s\n", a[count].stt, a[count].id, a[count].name);
	}

	fclose(f);
	fclose(g);
	printf("Da xong !");
	getchar();
	return 0;
}