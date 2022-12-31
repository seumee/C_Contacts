#include "Func.h"

int addProfile(stGCT_Record* record[], int Numofrecord) {
	char NewData[GCT_COLUMN_SIZE];
	int nColumnLoc;
	char ox;
	stGCT_Record NewRecord;
	memset(&NewRecord, 0, sizeof(stGCT_Record));

	for (int category = 0; category < USEDCATEGORY; category++) {
		nColumnLoc = _stUsage[category].ifUsed;
		printf("%s >> ", _contacts[0]->szColumn[nColumnLoc]);
		fgets(NewData, sizeof(NewData), stdin);
		NewData[strlen(NewData) - 1] = '\0';

		strcpy(NewRecord.szColumn[nColumnLoc], NewData);
	}

	printContacts(NewRecord);
	printf("저장 : O, 취소 : X >> ");
	rewind(stdin);
	scanf_s("%c", &ox, sizeof(ox));
	if (ox == 'o' || ox == 'O') {
		if ((record[Numofrecord] = malloc(sizeof(stGCT_Record))) != NULL) {
			memcpy(record[Numofrecord], &NewRecord, sizeof(stGCT_Record));
		}
		else
		{
			printf("malloc fail!\n");
			return 0;
		}
	}
	else return 0;
	system("cls");
	RecordSort_FamilyName(record, Numofrecord+1);
	return 1;
}

//void printIfGroup(stGCT_Record* record[], int Numofrecord) {
//	int	nColumnLoc;
//	for (int i = 0; i < Numofrecord; i++) {
//		if (strlen(record[i]->szColumn[GROUP_COLUMN]) != 0) {
//			printf("   | ");
//			for (int category = 0; category < USEDCATEGORY; category++) {
//				nColumnLoc = _stUsage[category].ifUsed;
//				printf("%-*s | ", _stUsage[category].length, record[i]->szColumn[nColumnLoc]);
//			}
//			printf("\n");
//		}
//	}
//}