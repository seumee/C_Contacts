#define _CRT_SECURE_NO_WARNINGS
#ifndef _FUNC_H_
#define _FUNC_H_

#include "Structure.h"
#include "windows.h"

//main.c
void SetDir();

//open.c
int Bystrsep(char* line, stGCT_Record* record);
char* strsep(char** stringp, const char* delim);
int readNsave(FILE* fp, stGCT_Record* record[], int* NumOfRecord);
void CreateFavFile();
void SetTitle();

//sort.c
	// Num
void sortByNum(stGCT_Record* record[], int Numofrecord, char HowToSort[]);
int compareByPN(const void* a, const void* b);
int compareByPN_reverse(const void* b, const void* a);
	// FamilyName
void sortByFamilyName(stGCT_Record* record[], int Numofrecord, char HowToSort[]);
int compareByFamilyName(const void* a, const void* b);
int compareByFamilyName_reverse(const void* b, const void* a);
	// Name
void sortByName(stGCT_Record* record[], int Numofrecord, char HowToSort[]);
int compareByName(const void* a, const void* b);
int compareByName_reverse(const void* b, const void* a);
	// Group
void sortByGroup(stGCT_Record* record[], int Numofrecord, char HowToSort[]);
int compareByGroup(const void* a, const void* b);
int compareByGroup_reverse(const void* b, const void* a);
	// GroupMembership
int compareByGroupMembership(const void* a, const void* b);
	// Sort_changeRecord
void RecordSort_Name(stGCT_Record* record[], int Numofrecord);
void RecordSort_FamilyName(stGCT_Record* record[], int Numofrecord);
void RecordSort_PN(stGCT_Record* record[], int Numofrecord);
void RecordSort_GroupMembership(stGCT_Record* record[], int Numofrecord);
void RecordSort_Group(stGCT_Record* record[], int Numofrecord);

//search.c
typedef struct {
	int* array[MAX_PROFILE_NUM];
}ResultForSearch;
int search(stGCT_Record* record[], int Numofrecord, char keyWord[], int categoryndx);
int seqSearch(stGCT_Record* record[], int fromwhere, int Numofrecord, char keyWord[]);


//add.c
int addProfile(stGCT_Record* record[], int Numofrecord);

//printContacts.c
void printAll(stGCT_Record* record[], int Numofrecord);
void printAll_used(stGCT_Record* record[], int Numofrecord);
void printOne(stGCT_Record* record[], int Num);
void printOne_NoBlank(stGCT_Record* record[], int Num);
void printIfGroup(stGCT_Record* record[], int Numofrecord);
void printInArray(stGCT_Record* record[], int array[], int arraysize);
void printContacts(stGCT_Record record);
void printOne_All(stGCT_Record* record[], int index);

//change.c
int change(stGCT_Record* record[], int index);

//delete.c
int delete(stGCT_Record* record[], int NumOfRecord, int index);

//save.c
int Contacts_save(FILE* fp, stGCT_Record* record[], int NumOfRecord);
int Contacts_saveas(FILE* fp, stGCT_Record* record[], int NumOfRecord);

//setDatabase.c
void RecordCopy(stGCT_Record* SortedRecord[], stGCT_Record* OriginalRecord[], int NumOfRecord);
void SetDB(stGCT_Record* record[USEDCATEGORY][MAX_PROFILE_NUM], stGCT_Record* OriginalRecord[], int NumOfRecord);
void DeleteDB(stGCT_Record* record[USEDCATEGORY][MAX_PROFILE_NUM], int NumOfRecord);

//favorite.c
void RecordCopy_One(stGCT_Record* SortedRecord[], stGCT_Record* OriginalRecord[], int index);
void SaveToFile_fav();

extern ST_USAGE _stUsage[USEDCATEGORY];

#endif