#include "Func.h"

int Contacts_save(FILE* fp, stGCT_Record* record[], int NumOfRecord) {
	for (int i = 0; i < NumOfRecord; i++) {
		for (int j = 0; j < GCT_COLUMN_NUM-1; j++) {
			fprintf(fp, "%s,", record[i]->szColumn[j]);
		}
		fprintf(fp, "\n");
	}
	printf("File Save Success\n");
	fclose(fp);
	return 1;
}

int Contacts_saveas(FILE* fp, stGCT_Record* record[], int NumOfRecord) {
	for (int i = 0; i < NumOfRecord; i++) {
		for (int j = 0; j < GCT_COLUMN_NUM; j++) {
			fprintf(fp, "%s,", record[i]->szColumn[j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return 1;
}