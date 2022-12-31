#include "Func.h"

void RecordCopy(stGCT_Record* SortedRecord[], stGCT_Record* OriginalRecord[], int NumOfRecord) {
	for (int i = 0; i < NumOfRecord; i++) {
		if ((SortedRecord[i] = (stGCT_Record*)malloc(sizeof(stGCT_Record))) != NULL) {

			memset(SortedRecord[i], 0, sizeof(stGCT_Record));
			memcpy(SortedRecord[i], OriginalRecord[i], sizeof(stGCT_Record));
		}
		else
		{
			printf("malloc fail!\n");
			return;
		}
	}
	return;
}
//stGCT_Record* _contacts_Database[USEDCATEGORY][MAX_PROFILE_NUM];
void SetDB(stGCT_Record * record[USEDCATEGORY][MAX_PROFILE_NUM], stGCT_Record* OriginalRecord[], int NumOfRecord) {
	for (int i = 0; i < USEDCATEGORY; i++) {
		RecordCopy(record[i], OriginalRecord, NumOfRecord);
	}
	RecordSort_FamilyName		(record[0], NumOfRecord);
	RecordSort_Name				(record[1], NumOfRecord);
	RecordSort_GroupMembership	(record[2], NumOfRecord);
	RecordSort_PN				(record[3], NumOfRecord);
	RecordSort_Group			(record[4], NumOfRecord);

	printf("Set Database success!\n");
	return;
}

void DeleteDB(stGCT_Record* record[USEDCATEGORY][MAX_PROFILE_NUM], int NumOfRecord) {
	for (int i = NumOfRecord - 1; i >= 0; i--)
	{
		for (int j = 0; j < USEDCATEGORY; j++) {
			free(record[j][i]);
		}
	}
}
