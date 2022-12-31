#include "Func.h"

int delete(stGCT_Record* record[], int NumOfRecord , int index) {
	for (int i = index; i < NumOfRecord -1; i++) {
		memcpy(record[i], record[i+1], sizeof(stGCT_Record));
	}
	free(record[NumOfRecord-1]);
	
	return 1;
}