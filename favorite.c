#include "Func.h"

void RecordCopy_One(stGCT_Record* SortedRecord[], stGCT_Record* OriginalRecord[], int index) {
	if ((SortedRecord[_lineNum_fav] = (stGCT_Record*)malloc(sizeof(stGCT_Record))) != NULL) {
		memset(SortedRecord[_lineNum_fav], 0, sizeof(stGCT_Record));
		memcpy(SortedRecord[_lineNum_fav], OriginalRecord[index], sizeof(stGCT_Record));
	}
	else
	{
		printf("malloc fail!\n");
		return;
	}
	return;
}

void SaveToFile_fav() {
	FILE* favFp = fopen(_FileName_Favorite, "w+");
	for (int i = 0; i < _lineNum_fav; i++) {
		for (int j = 0; j < GCT_COLUMN_NUM; j++) {
			fprintf(favFp, "%s,", _contacts_fav[i]->szColumn[j]);
		}
		fprintf(favFp, "\n");
	}
	fclose(favFp);
}