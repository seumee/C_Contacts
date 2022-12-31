///////////////////////////////////////////////////////////////////////////////
/// @date           2020.12
/// @brief          Address Book Management Function
/// @author
///////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include "Func.h"


/*
    This function can have at least 2 and maximum 3 argments!
*/
void
UT_Sample(char** pszWords, int nWCnt)
{
    int     i, nIntVal;

    // Second argument is integer !
    nIntVal = atoi(pszWords[1]);

    for (i = 0; i < nWCnt; i++) printf("User Input: arg[%d]=%s\n", i, pszWords[i]);
    if (nWCnt == 2) printf("User Input: %s %d\n", pszWords[0], nIntVal);
    else if (nWCnt == 3) printf("User Input: %s %d %s\n", pszWords[0], nIntVal, pszWords[2]);
}

void
UT_Test(char** pszWords, int nWCnt)
{
	printf("%s\n", _contacts[1]->orgString);
}

void
UT_File_Google(char** pszWords, int nWCnt)
{
}

void
UT_File_Open(char** pszWords, int nWCnt)
{
	FILE* fp = NULL;

	system("cls");

	strcpy(_FileName, pszWords[0]);

	if ((fp = fopen(_FileName, L"r+,ccs=UNICODE")) != NULL)
	{
		printf("File Open Success\n");
	}
	else
	{
		printf("File open Error\n");
		return;
	}

	if (readNsave(fp, _contacts, &_lineNum) == 0)	return;
	SetDB(_contacts_Database, _contacts, _lineNum);
	CreateFavFile();
	printf("\n");
	/*---------------------------------------
				print contacts
	---------------------------------------*/
	/////////////////////////////////////////
	printAll_used(_contacts, _lineNum);
	/////////////////////////////////////////
}

void
UT_File_Save(char** pszWords, int nWCnt)
{
	system("cls");
	RecordSort_FamilyName(_contacts, _lineNum);
	FILE* fp = NULL;

	if ((fp = fopen(_FileName, "w+")) != NULL)
	{
		printAll_used(_contacts, _lineNum);
		if (Contacts_saveas(fp, _contacts, _lineNum) == 0)	return;
		else 	printf("File Save Success\n");
	}
	else
	{
		printf("File open Error\n");
		return;
	}
}

void
UT_File_SaveAs(char** pszWords, int nWCnt)
{
	system("cls");
	RecordSort_FamilyName(_contacts, _lineNum);
	FILE* fp = NULL;

	if ((fp = fopen(pszWords[0], "w+")) != NULL)
	{
		printAll_used(_contacts, _lineNum);
		if (Contacts_saveas(fp, _contacts, _lineNum) == 0)	return;
		else 	printf("File Save Success\n");
	}
	else
	{
		printf("File open Error\n");
		return;
	}
}

void
UT_File_Close(char** pszWords, int nWCnt)
{
	for (int i = _lineNum - 1; i >= 0; i--)
	{
		free(_contacts[i]);
	}
	DeleteDB(_contacts_Database, _lineNum);
	_lineNum = 0;
	for (int j = _lineNum_fav - 1; j >= 0; j--)
	{
		free(_contacts_fav[j]);
	}
	rewind(stdin);
	system("cls");

	Help();

	return;
}

void
UT_Record_Show(char** pszWords, int nWCnt)
{
	system("cls");
	printAll_used(_contacts, _lineNum);
}

void
UT_Record_Add(char** pszWords, int nWCnt)
{
	system("cls");
	if (addProfile(_contacts, _lineNum) == 0)	return;
	else {
		DeleteDB(_contacts_Database, _lineNum);
		_lineNum++;
		SetDB(_contacts_Database, _contacts, _lineNum);
	}
	printAll_used(_contacts, _lineNum);
}

void
UT_Record_Delete(char** pszWords, int nWCnt)
{
	int ProfileNum;
	int ResultNum = 1;
	int Num = 0;
	int isprofile = 0;
	char ox;

	system("cls");
	UT_Record_Ksearch_Numbered(pszWords, nWCnt);
	if ((seqSearch(_contacts, 0, _lineNum, pszWords[0])) == -1) {
		printf("키워드에 해당하는 항목이 없습니다.\n");
	}
	else {
		printf("삭제할 프로필의 번호를 입력하세요 >> ");
		rewind(stdin);
		scanf_s("%d", &ProfileNum);
		while (isprofile != -1 && Num < _lineNum) {
			if ((Num = seqSearch(_contacts, Num + 1, _lineNum, pszWords[0])) != -1) {
				if (ProfileNum == ResultNum) {
					printOne(_contacts, Num);
					printf("삭제 : O, 취소 : X >> ");
					rewind(stdin);
					scanf_s("%c", &ox, sizeof(ox));
					if (ox == 'o' || ox == 'O') {
						for (int i = 0; i < _lineNum_fav; i++) {
							if (strncmp(_contacts[Num]->orgString, _contacts_fav[i]->orgString, sizeof(_contacts[i]->orgString)) == 0) {
								delete(_contacts_fav, _lineNum_fav, i);
								_lineNum_fav--;
								SaveToFile_fav();
							}
						}
						delete(_contacts, _lineNum, Num);
						DeleteDB(_contacts_Database, _lineNum);
						_lineNum--;
						SetDB(_contacts_Database, _contacts, _lineNum);
						printf("삭제되었습니다.\n");
						break;
					}
				}
				ResultNum++;
			}
			else {
				printf("검색결과가 더이상 없습니다.\n");
				isprofile = -1;
			}
		}
	}
}

void
UT_Record_Change(char** pszWords, int nWCnt)
{
	int ProfileNum;
	int ResultNum = 1;
	int Num = 0;
	int isprofile = 0;
	UT_Record_Ksearch_Numbered(pszWords, nWCnt);
	if ((seqSearch(_contacts, 0, _lineNum, pszWords[0])) == -1) {
		printf("키워드에 해당하는 항목이 없습니다.\n");
	}
	else {
		printf("수정할 프로필의 번호를 입력하세요 >> ");
		rewind(stdin);
		scanf_s("%d", &ProfileNum);
		while (isprofile != -1 && Num < _lineNum) {
			if ((Num = seqSearch(_contacts, Num + 1, _lineNum, pszWords[0])) != -1) {
				if (ProfileNum == ResultNum) {
					change(_contacts, Num);

					break;
				}
				ResultNum++;
			}
			else {
				printf("검색결과가 더이상 없습니다.\n");
				isprofile = -1;
			}
		}
	}
}

void
UT_Record_Search(char** pszWords, int nWCnt)
{
	int num;
	int isResult = 0;
	system("cls");
	printf("'%s'에 대한 검색결과 >>\n", pszWords[0]);

	for (int i = 0; i < USEDCATEGORY; i++) {
		
		num = search(_contacts_Database[i], _lineNum, pszWords[0], _stUsage[i].ifUsed);
		if (num != -1) {
			isResult++;
			printOne(_contacts_Database[i], num);
		}
	}
	if (isResult == 0) {
		printf("'%s'에 해당하는 항목이 존재하지 않습니다.\n", pszWords[0]);
	}
}

void
UT_Record_Ksearch(char** pszWords, int nWCnt)
{
	int Num = 0;
	int isprofile = 0;
	system("cls");
	printf("'%s'에 대한 검색결과 >>\n", pszWords[0]);
	if ((seqSearch(_contacts, 0, _lineNum, pszWords[0])) == -1) {
	printf("키워드에 해당하는 항목이 없습니다.\n");
	}
	else {
		while (isprofile != -1 && Num < _lineNum) {
			if ((Num = seqSearch(_contacts, Num + 1, _lineNum, pszWords[0])) != -1) {
				printOne(_contacts, Num);
			}
			else {
				printf("검색결과가 더이상 없습니다.\n");
				isprofile = -1;
			}
		}
	}
}

void
UT_Record_Ksearch_Numbered(char** pszWords, int nWCnt)
{
	int Num = 0;
	int index = 1;
	int isprofile = 0;

	system("cls");
	if ((seqSearch(_contacts, 0, _lineNum, pszWords[0])) == -1) {
		printf("키워드에 해당하는 항목이 없습니다.\n");
	}
	else {
		while (isprofile != -1) {
			if (Num >= _lineNum) break;
			if ((Num = seqSearch(_contacts, Num + 1, _lineNum, pszWords[0])) != -1) {
				printf("%3d", index);
				index++;
				printOne_NoBlank(_contacts, Num);
			}
			else {
				printf("검색결과가 더이상 없습니다.\n");
				isprofile = -1;
			}
		}
	}
}

void
UT_Record_Ksearch_Numbered_fav(char** pszWords, int nWCnt)
{
	int Num = 0;
	int index = 1;
	int isprofile = 0;

	system("cls");
	if ((seqSearch(_contacts_fav, 0, _lineNum_fav, pszWords[0])) == -1) {
		printf("키워드에 해당하는 항목이 없습니다.\n");
	}
	else {
		while (isprofile != -1) {
			if (Num >= _lineNum_fav) break;
			if ((Num = seqSearch(_contacts_fav, Num + 1, _lineNum_fav, pszWords[0])) != -1) {
				printf("%3d", index);
				index++;
				printOne_NoBlank(_contacts_fav, Num);
			}
			else {
				printf("검색결과가 더이상 없습니다.\n");
				isprofile = -1;
			}
		}
	}
}

void
UT_Record_Rsearch(char** pszWords, int nWCnt)
{
}

void
UT_Sort_Name(char** pszWords, int nWCnt)
{
	if (nWCnt == 0) {
		sortByFamilyName(_contacts, _lineNum, "ascend");
	}
	else if (nWCnt == 1) {
		sortByFamilyName(_contacts, _lineNum, pszWords[0]);
	}
}

void
UT_Sort_Tel(char** pszWords, int nWCnt)
{
	if (nWCnt == 0) {
		sortByNum(_contacts, _lineNum, "ascend");
	}
	else if (nWCnt == 1) {
		sortByNum(_contacts, _lineNum, pszWords[0]);
	}
}

void
UT_Sort_Group(char** pszWords, int nWCnt)
{
	if (nWCnt == 0) {
		sortByGroup(_contacts, _lineNum, "ascend");
	}
	else if (nWCnt == 1) {
		sortByGroup(_contacts, _lineNum, pszWords[0]);
	}
}

void
UT_Favorite_Show(char** pszWords, int nWCnt)
{
	system("cls");
	printAll_used(_contacts_fav, _lineNum_fav);
}

void
UT_Favorite_Add(char** pszWords, int nWCnt)
{
	int ProfileNum;
	int ResultNum = 1;
	int Num = 0;
	int isprofile = 0;

	system("cls");
	UT_Record_Ksearch_Numbered(pszWords, nWCnt);
	if ((seqSearch(_contacts, 0, _lineNum, pszWords[0])) == -1) {
		printf("키워드에 해당하는 항목이 없습니다.\n");
	}
	else {
		printf("즐겨찾기에 추가할 프로필의 번호를 입력하세요 >> ");
		rewind(stdin);
		scanf_s("%d", &ProfileNum);
		while (isprofile != -1 && Num < _lineNum) {
			if ((Num = seqSearch(_contacts, Num + 1, _lineNum, pszWords[0])) != -1) {
				if (ProfileNum == ResultNum) {
					if (seqSearch(_contacts_fav, 0, _lineNum_fav, pszWords[0]) == -1) {
						RecordCopy_One(_contacts_fav, _contacts, Num);
						system("cls");
						printf("즐겨찾기에 추가되었습니다.\n");
						_lineNum_fav++;
						RecordSort_FamilyName(_contacts_fav, _lineNum_fav);
						SaveToFile_fav();
						printAll_used(_contacts_fav, _lineNum_fav);
						break;
					}
					else
					{
						printf("이미 즐겨찾기에 존재하는 항목입니다.\n");
						break;
					}
				}
				ResultNum++;
			}
			else {
				printf("검색결과가 더이상 없습니다.\n");
				isprofile = -1;
			}
		}
	}
}

void
UT_Favorite_Delete(char** pszWords, int nWCnt)
{
	int ProfileNum;
	int ResultNum = 1;
	int Num = 0;
	int isprofile = 0;

	system("cls");
	UT_Record_Ksearch_Numbered_fav(pszWords, nWCnt);
	if ((seqSearch(_contacts_fav, 0, _lineNum_fav, pszWords[0])) == -1) {
		printf("키워드에 해당하는 항목이 없습니다.\n");
	}
	else {
		printf("즐겨찾기에서 삭제할 프로필의 번호를 입력하세요 >> ");
		rewind(stdin);
		scanf_s("%d", &ProfileNum);
		while (isprofile != -1 && Num < _lineNum_fav) {
			if ((Num = seqSearch(_contacts_fav, Num + 1, _lineNum_fav, pszWords[0])) != -1) {
				if (ProfileNum == ResultNum) {
					delete(_contacts_fav, _lineNum_fav, Num);
					system("cls");
					printf("즐겨찾기에서 삭제되었습니다.\n");
					_lineNum_fav--;
					SaveToFile_fav();
					printAll_used(_contacts_fav, _lineNum_fav);
					break;
				}
				ResultNum++;
			}
			else {
				printf("검색결과가 더이상 없습니다.\n");
				isprofile = -1;
			}
		}
	}
}

void
UT_Favorite_Sort(char** pszWords, int nWCnt)
{
	if (_strcmpi(pszWords[0], "name") == 0) {
		printf("%s", "name");
		if (nWCnt == 1) {
			sortByFamilyName(_contacts_fav, _lineNum_fav, "ascend");
		}
		else if (nWCnt == 2) {
			sortByFamilyName(_contacts_fav, _lineNum_fav, pszWords[1]);
		}
	}
	else if (_strcmpi(pszWords[0], "tel") == 0) {
		printf("%s", "tel");
		if (nWCnt == 1) {
			sortByNum(_contacts_fav, _lineNum_fav, "ascend");
		}
		else if (nWCnt == 2) {
			sortByNum(_contacts_fav, _lineNum_fav, pszWords[1]);
		}
	}
	else if (_strcmpi(pszWords[0], "group") == 0) {
		printf("%s", "group");
		if (nWCnt == 1) {
			sortByGroup(_contacts_fav, _lineNum_fav, "ascend");
		}
		else if (nWCnt == 2) {
			sortByGroup(_contacts_fav, _lineNum_fav, pszWords[1]);
		}
	}

	else printf("Invalid Argument :: Usage name/tel/group [ascend/descend]\n");
}