#include<stdio.h>
#include<string.h>

void checkFile(FILE* fp, char fileName);
int countCharacter(FILE* fp);
int countWord(FILE* fp);

int main(int argc, char* argv[]) {
	int characterCount;
	int wordCount;
	FILE* fp = fopen(argv[2], "r");

	if (!strcmp(argv[1], "-c")) {
		printf("�ַ�����%d", countCharacter(fp));
	}
	else if (!strcmp(argv[1], "-w")) {
		printf("��������%d", countWord(fp));
	}
	fclose(fp);
	return 0;
}

void checkFile(FILE* fp, char fileName) {
	if (fp == NULL) {
		printf("�ļ�%s�����ڻ��޷��ɹ��򿪣�\n", fileName);
	}
}

int countCharacter(FILE* fp) {
	int count = 0;
	while (!feof(fp)) {
		if (fgetc(fp) != NULL) {
			count++;
		}
	}

	return count-1;
}

int countWord(FILE* fp) {
	int count = 1;
	char ch;
	while (!feof(fp)) {
		ch = fgetc(fp);

		if (ch == ' ' || ch == ',') {
			count++;
		}
		else if (ch == NULL) {
			count = 0;
		}
	}

	return count;
}