#include "Func.h"

//----------------------- Not Change Record Value----------------------------//
void sortByNum(stGCT_Record* record[], int Numofrecord, char HowToSort[]) {
	stGCT_Record* recordForSort[MAX_PROFILE_NUM];

    memcpy(recordForSort, record, sizeof(stGCT_Record*) * Numofrecord);
    
    if (strcmp(HowToSort, "ascend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByPN);
    else if (strcmp(HowToSort, "descend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByPN_reverse);
    else return;
    printAll_used(recordForSort, Numofrecord);
    return;
}

void sortByFamilyName(stGCT_Record* record[], int Numofrecord, char HowToSort[]) {
    stGCT_Record* recordForSort[MAX_PROFILE_NUM];

    memcpy(recordForSort, record, sizeof(stGCT_Record*) * Numofrecord);

    if (strcmp(HowToSort, "ascend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByFamilyName);
    else if (strcmp(HowToSort, "descend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByFamilyName_reverse);
    else return;
    printAll_used(recordForSort, Numofrecord);
    return;
}

void sortByName(stGCT_Record* record[], int Numofrecord, char HowToSort[]) {
    stGCT_Record* recordForSort[MAX_PROFILE_NUM];

    memcpy(recordForSort, record, sizeof(stGCT_Record*) * Numofrecord);

    if (strcmp(HowToSort, "ascend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByName);
    else if (strcmp(HowToSort, "descend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByName_reverse);
    else return;
    printAll_used(recordForSort, Numofrecord);
    return;
}

void sortByGroup(stGCT_Record* record[], int Numofrecord, char HowToSort[]) {
    stGCT_Record* recordForSort[MAX_PROFILE_NUM];

    memcpy(recordForSort, record, sizeof(stGCT_Record*) * Numofrecord);
    if (strcmp(HowToSort, "ascend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByGroup);
    else if (strcmp(HowToSort, "descend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByGroup_reverse);
    else return;
    if (strcmp(HowToSort, "ascend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByGroup);
    else if (strcmp(HowToSort, "descend") == 0) qsort(recordForSort + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByGroup_reverse);
    else return;
    printIfGroup(recordForSort, Numofrecord);
    return;
}

//----------------------- Change Record Value----------------------------//
void RecordSort_FamilyName(stGCT_Record* record[], int Numofrecord) {
    qsort(record + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByFamilyName);
    return;
}

void RecordSort_Name(stGCT_Record* record[], int Numofrecord) {
    qsort(record + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByName);
    return;
}

void RecordSort_PN(stGCT_Record* record[], int Numofrecord) {
    qsort(record + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByPN);
    return;
}

void RecordSort_GroupMembership(stGCT_Record* record[], int Numofrecord) {
    qsort(record + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByGroupMembership);
    return;
}

void RecordSort_Group(stGCT_Record* record[], int Numofrecord) {
    qsort(record + 1, Numofrecord - 1, sizeof(stGCT_Record*), compareByGroup);
    return;
}

int compareByPN(const void* a, const void* b) {
    stGCT_Record** pa = (stGCT_Record**)a;
    stGCT_Record** pb = (stGCT_Record**)b;
    return strcmp((*pa)->szColumn[PHONE_VALUE_COLUMN], (*pb)->szColumn[PHONE_VALUE_COLUMN]);
}

int compareByPN_reverse(const void* b, const void* a) {
    stGCT_Record** pa = (stGCT_Record**)a;
    stGCT_Record** pb = (stGCT_Record**)b;
    return strcmp((*pa)->szColumn[PHONE_VALUE_COLUMN], (*pb)->szColumn[PHONE_VALUE_COLUMN]);
}

int compareByFamilyName(const void* a, const void* b) {
    stGCT_Record** pa = (stGCT_Record**)a;
    stGCT_Record** pb = (stGCT_Record**)b;
    return strcmp((*pa)->szColumn[FAMILY_NAME_COLUMN], (*pb)->szColumn[FAMILY_NAME_COLUMN]);
}

int compareByFamilyName_reverse(const void* b, const void* a) {
    stGCT_Record** pa = (stGCT_Record**)a;
    stGCT_Record** pb = (stGCT_Record**)b;
    return strcmp((*pa)->szColumn[FAMILY_NAME_COLUMN], (*pb)->szColumn[FAMILY_NAME_COLUMN]);
}

int compareByName(const void* a, const void* b) {
    stGCT_Record** pa = (stGCT_Record**)a;
    stGCT_Record** pb = (stGCT_Record**)b;
    return strcmp((*pa)->szColumn[GIVEN_NAME_COLUMN], (*pb)->szColumn[GIVEN_NAME_COLUMN]);
}

int compareByName_reverse(const void* b, const void* a) {
    stGCT_Record** pa = (stGCT_Record**)a;
    stGCT_Record** pb = (stGCT_Record**)b;
    return strcmp((*pa)->szColumn[GIVEN_NAME_COLUMN], (*pb)->szColumn[GIVEN_NAME_COLUMN]);
}

int compareByGroup(const void* a, const void* b) {
    stGCT_Record** pa = (stGCT_Record**)a;
    stGCT_Record** pb = (stGCT_Record**)b;
    return strcmp((*pa)->szColumn[GROUP_COLUMN], (*pb)->szColumn[GROUP_COLUMN]);
}

int compareByGroup_reverse(const void* b, const void* a) {
    stGCT_Record** pa = (stGCT_Record**)a;
    stGCT_Record** pb = (stGCT_Record**)b;
    return strcmp((*pa)->szColumn[GROUP_COLUMN], (*pb)->szColumn[GROUP_COLUMN]);
}

int compareByGroupMembership(const void* a, const void* b) {
    stGCT_Record** pa = (stGCT_Record**)a;
    stGCT_Record** pb = (stGCT_Record**)b;
    return strcmp((*pa)->szColumn[GROUP_MEMBERSHIP_COLUMN], (*pb)->szColumn[GROUP_MEMBERSHIP_COLUMN]);
}