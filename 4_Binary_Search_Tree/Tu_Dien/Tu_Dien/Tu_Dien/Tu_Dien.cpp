#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;
struct WORD {
	char Name[256];
	char Pronounce[256];
	char Meaning[512];
	char Vidu[1024];
};
int traTuDienBinarySearch(WORD* words, int n, char* wordX);
int traTuDienLinearSearch(WORD* words, int n, char* wordX);
int ReadWordsFromFileToArray(WORD* words, int& n, char* fileName);
void XuatTu(WORD word);
int main() {
	int n;
	WORD words[1000];
	char tuCanTra[256];
	char* fileName = "words.txt";
	ReadWordsFromFileToArray(words, n, fileName);
	cout << "***** TU DIEN ANH - VIET *****" << endl;
	while (true) {
		cout << "Nhap tu can tra: ";
		cin >> tuCanTra;
		int indexRes = traTuDienLinearSearch(words, n, tuCanTra);
		if (indexRes != -1) {
			XuatTu(words[indexRes]);
		}
		else {
			cout << "Tu dien hien chua co tu nay. Ung dung se cap nhat som nhat!" << endl;
			cout << "--------------------------------------------------------------" << endl;
		}
	}
	return 0;
}

int traTuDienLinearSearch(WORD* words, int n, char* wordX) {
	WORD w;
	strcpy(w.Name, wordX);
	words[n] = w;
	int i = 0;
	while (strcmp(words[i].Name, wordX) != 0) {
		i++;
	}
	if (i < n)
		return i;
	return -1;
}
int traTuDienBinarySearch(WORD* words, int n, char* wordX) {
	int l = 0, r = n - 1, m;
	while (l <= r) {
		m = (l + r) / 2;
		if (strcmp(wordX, words[m].Name) == 0) {
			return m;
		}
		else if (strcmp(wordX, words[m].Name) < 0) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return -1;
}

int ReadWordsFromFileToArray(WORD* words, int& n, char* fileName) {
	FILE* f = fopen(fileName, "r");
	if (!f)
		return 0;
	int i = 0;
	while (!feof(f)) {

		char* token;
		char str[255];
		fgets(str, 255, f);

		token = strtok(str, "\t");
		strcpy(words[i].Name, token);

		token = strtok(NULL, "\t");
		strcpy(words[i].Pronounce, token);

		token = strtok(NULL, "\t");
		strcpy(words[i].Meaning, token);

		token = strtok(NULL, "\t");
		strcpy(words[i].Vidu, token);

		i++;
	}
	n = i;
}

void XuatTu(WORD word) {
	cout << word.Name << " " << word.Pronounce << endl;
	cout << "Nghia: " << word.Meaning << endl;
	cout << "Vi du: " << word.Vidu << endl;
	cout << "--------------------------------------------------------------" << endl;
}
