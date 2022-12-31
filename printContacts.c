#include "Func.h"

/*----------		print all contacts						---------------*/
void printAll(stGCT_Record* record[], int Numofrecord) {
	for (int i = 0; i < Numofrecord; i++) {
		for (int category = 0; category < GCT_COLUMN_NUM; category++) {
			printf("%16s\t", record[i]->szColumn[category]);
		}
	}
	printf("\n");
}

/*----------		print all contacts(used category)		---------------*/
void printAll_used(stGCT_Record* record[], int Numofrecord) {
	//for (int i = 0; i < _lineNum; i++) {
	//	//for (int category = 0; category < GCT_COLUMN_NUM; category++) {
	//	for (int category = 0; category < GCT_COLUMN_NUM; category++) {
	//		if (used(category).ifUsed) {
	//			printf("%*s|", use[1][used(category).which], _contacts[i]->szColumn[category]);
	//		}
	//	}
	int	nColumnLoc;
	for (int i = 0; i < Numofrecord; i++) {
		printf("   | ");
		for (int category = 0; category < USEDCATEGORY; category++) {
			nColumnLoc = _stUsage[category].ifUsed;
			printf("%-*s | ", _stUsage[category].length, record[i]->szColumn[nColumnLoc]);
		}
		printf("\n");
	}
}

/*----------		print certain contact(used category)	---------------*/
void printOne(stGCT_Record* record[], int Num) {
	int	nColumnLoc;
	printf("   | ");
	for (int category = 0; category < USEDCATEGORY; category++) {
		nColumnLoc = _stUsage[category].ifUsed;
		printf("%-*s | ", _stUsage[category].length, record[Num]->szColumn[nColumnLoc]);
	}
	printf("\n");
}

/*----------		print certain contact(used category)	---------------*/
void printOne_All(stGCT_Record* record[], int index) {
	for (int category = 0; category < GCT_COLUMN_NUM; category++) {
		printf("%16s\t", record[index]->szColumn[category]);
	}
	printf("\n");
}

/*----------		print certain contact No blank(used category)	---------------*/
void printOne_NoBlank(stGCT_Record* record[], int Num) {
	int	nColumnLoc;
	printf("| ");
	for (int category = 0; category < USEDCATEGORY; category++) {
		nColumnLoc = _stUsage[category].ifUsed;
		printf("%-*s | ", _stUsage[category].length, record[Num]->szColumn[nColumnLoc]);
	}
	printf("\n");
}

/*----------		print if group exist(used category)	---------------*/
void printIfGroup(stGCT_Record* record[], int Numofrecord) {
	int	nColumnLoc;
	for (int i = 0; i < Numofrecord; i++) {
		if (strlen(record[i]->szColumn[GROUP_COLUMN]) != 0) {
			printf("   | ");
			for (int category = 0; category < USEDCATEGORY; category++) {
				nColumnLoc = _stUsage[category].ifUsed;
				printf("%-*s | ", _stUsage[category].length, record[i]->szColumn[nColumnLoc]);
			}
		printf("\n");
		}
	}
}

/*----------		print contacts in array(used category)	---------------*/
void printInArray(stGCT_Record* record[], int array[], int arraysize) {
	int	nColumnLoc;

	for (int i = 0; i < arraysize; i++) {
		printf("   | ");
		for (int category = 0; category < USEDCATEGORY; category++) {
			nColumnLoc = _stUsage[category].ifUsed;
			printf("%-*s | ", _stUsage[category].length, record[array[i]]->szColumn[nColumnLoc]);
		}
		printf("\n");
	}
}

/*----------		print contacts which are not pointer(used category)	---------------*/
void printContacts(stGCT_Record record) {
	int nColumnLoc;
	printf("   | ");
	for (int category = 0; category < USEDCATEGORY; category++) {
		nColumnLoc = _stUsage[category].ifUsed;
		printf("%-*s | ", _stUsage[category].length, record.szColumn[nColumnLoc]);
	}
	printf("\n");
}

/*----------		print LineNum							---------------*/
//printf("\n!!!---LineNum = %d--!!!", lineNum);

//int numberForm()
//contacts[i]->szColumn[category][3]