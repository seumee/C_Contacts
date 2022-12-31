#include "Func.h"

int change(stGCT_Record* record[], int index) {
	int	nColumnLoc;
	char ox;
	char newData[GCT_COLUMN_SIZE];
	stGCT_Record tmpRecord;
	memcpy(&tmpRecord, record[index], sizeof(stGCT_Record));
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printContacts(tmpRecord);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	for (int category = 0; category < USEDCATEGORY; category++) {
		nColumnLoc = _stUsage[category].ifUsed;
		if (strcmp(tmpRecord.szColumn[nColumnLoc], "") != 0) printf("%s : %s\n", _contacts[0]->szColumn[nColumnLoc], tmpRecord.szColumn[nColumnLoc]);
		else printf("%s : %s\n", _contacts[0]->szColumn[nColumnLoc], "\"No record\"");
		printf("수정 : O, 다음 항목 : X >> ");
		rewind(stdin);
		scanf_s("%c", &ox, sizeof(ox));
		rewind(stdin);
		if (ox == 'o' || ox == 'O') {
			strcpy(newData, "");
			scanf_s("%s", newData, sizeof(newData));
			rewind(stdin);
			strcpy(tmpRecord.szColumn[nColumnLoc], newData);
		}
	}
	printf("\n수정 결과 >>\n");
	printContacts(tmpRecord);
	printf("저장 : O, 취소 : X >> ");
	rewind(stdin);
	scanf_s("%c", &ox, sizeof(ox));
	if (ox == 'o' || ox == 'O') {
		for (int i = 0; i < _lineNum_fav; i++) {
			if (strncmp(_contacts[index]->orgString, _contacts_fav[i]->orgString, sizeof(_contacts[i]->orgString)) == 0) {
				memcpy(_contacts_fav[i], &tmpRecord, sizeof(stGCT_Record));
			}
			RecordSort_FamilyName(_contacts_fav, _lineNum_fav);
			SaveToFile_fav();
		}
		memcpy(record[index], &tmpRecord, sizeof(stGCT_Record));
		printf("저장되었습니다.\n");

		RecordSort_FamilyName(record, _lineNum);
	}
	else printf("저장하지 않았습니다.\n");

	return 1;
}