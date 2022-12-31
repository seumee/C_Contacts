#define _CRT_SECURE_NO_WARNINGS
#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <io.h>

#define GCT_NAME_SIZE		32
#define GCT_PHONENO_SIZE	16
#define GCT_ADDRESS_SIZE	128
#define FILE_NAME_SIZE		128

#define GCT_COLUMN_NUM		50
#define GCT_COLUMN_SIZE		128

#define GCT_COLUMN_NAME_LOC		0
#define GCT_COLUMN_PHONENO_LOC		10
#define GCT_COLUMN_ADDRESS_LOC		30

//출력 항목 지정 / 출력폭 설정
#define USEDCATEGORY		5
#define GIVEN_NAME_COLUMN	1
#define FAMILY_NAME_COLUMN	3
#define GROUP_MEMBERSHIP_COLUMN	28
#define PHONE_VALUE_COLUMN	32
#define GROUP_COLUMN	43

#define MAX_PROFILE_NUM	700

/* 개별 항목 저장형식
typedef structure Tag GCT_Record {
	char	szName[GCT_NAME_SIZE];
	char	szGoogleNo[GCT_PHONENO_SIZE];
	char	szPhoneNo[GCT_PHONENO_SIZE];
	char	szAddress[GCT_ADDRESS_SIZE];
}stCGT_Record;
*/

// 프로필 단위 한줄 저장형식
typedef struct{
	char	szColumn[GCT_COLUMN_NUM][GCT_COLUMN_SIZE];
	char	orgString[GCT_COLUMN_NUM * GCT_COLUMN_SIZE];
	/*
	struct {
		char clen;
		char data[GCT_COLUMN_SIZE];
	}stcolumn[GCT_COLUMN_NUM];
	*/
}stGCT_Record;

typedef struct{
	//char	szFileName[FILE_NAME_SIZE];
	FILE* fp;

	//stGCT_Record	stRecord[];
}stGCT_File;

typedef struct {
	int ifUsed;
	int length;
}ST_USAGE;

//enum enColumnName{
//	GIVEN_NAME_COLMN = 1,
//	FAMILY_NAME_COLMN = 3
//};

// 전역변수 _lineNum, _contacts, _FileName
extern stGCT_Record* _contacts[MAX_PROFILE_NUM];
extern stGCT_Record* _contacts_fav[MAX_PROFILE_NUM];
extern stGCT_Record* _contacts_Database[USEDCATEGORY][MAX_PROFILE_NUM];
extern int _lineNum;
extern int _lineNum_fav;
extern char _FileName[FILE_NAME_SIZE];
extern char _FileName_Favorite[FILE_NAME_SIZE + 10];

#endif
