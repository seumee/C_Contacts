#include "Func.h"

int search(stGCT_Record* record[], int Numofrecord, char keyWord[], int categoryndx) {
	int numOfResult = 0;
	int index, low = 1, high = Numofrecord-1;
	
	while (low <= high) {
		// high�� low�� Ȧ���� ���� index�� ���� ó���� �� �߰���!
		index = (low + high) / 2;

		if (strncmp(keyWord, record[index]->szColumn[categoryndx], strlen(keyWord)) == 0) {
			return index;
		}
		else {
			if (strncmp(keyWord, record[index]->szColumn[categoryndx], strlen(keyWord)) < 0) {
				if (high == index)
				{
					if (low == high)	break;
					else high = index -1;
				}
				high = index;
			}
			else {
				//  high�� low�� ���̰� 1�� ���� index==low�� ��� �߻�
				if (low == index)
				{
					if (low == high)	break;
					else low = index + 1;
				}
				else low = index;
			}
		}
	}
	return -1;
}

int seqSearch(stGCT_Record* record[], int fromwhere, int Numofrecord, char keyWord[]) {
	char* combined;
	char* ptr;
	int combSize = GCT_COLUMN_SIZE * 3;
	for (int i = fromwhere; i < Numofrecord; i++) {
		if ((combined = malloc(sizeof(char) * combSize)) != NULL) {
			memset(combined, 0, sizeof(char) * combSize);
			strcat(combined, record[i]->szColumn[FAMILY_NAME_COLUMN]);
			strcat(combined, record[i]->szColumn[GIVEN_NAME_COLUMN]);
			strcat(combined, record[i]->szColumn[PHONE_VALUE_COLUMN]);

			ptr = strstr(combined, keyWord);
			if (ptr != NULL) return i;
		}
		else printf("malloc Failed!!\n");
	}
	return -1;
}