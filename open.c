#include "Func.h"

//char Num

int Bystrsep(char* line, stGCT_Record* record) {
	int category = 0;
	char* tmp;
	char* ptr = NULL;
	tmp = line;

	while ((ptr = strsep(&tmp, ",")) != NULL) {
		if (category < 50) {
			strcpy(record->szColumn[category], ptr);
			category++;
		}
		else break;
	}
	return 1;
}

char* strsep(char** stringp, const char* delim) {
	char* ptr = *stringp;
	if (ptr == NULL) {
		return NULL;
	}

	while (**stringp) {
		if (strchr(delim, **stringp) != NULL) {
			**stringp = 0x00;
			(*stringp)++; return ptr;
		} (*stringp)++;
	}
	*stringp = NULL;
	return ptr;
}

//int readNsave(FILE* fp, stGCT_Record* record[], int NumOfRecord) {
//	char oneline[GCT_COLUMN_NUM * GCT_COLUMN_SIZE];
//	/*----------		read csv & save to struct				---------------*/
//	char* pszStr = fgets(oneline, GCT_COLUMN_NUM * GCT_COLUMN_SIZE, fp);
//	while (pszStr != NULL) {
//		if ((_contacts[_lineNum] = (stGCT_Record*)malloc(sizeof(stGCT_Record))) != NULL) {
//			memset(_contacts[_lineNum], 0, sizeof(stGCT_Record));
//			Bystrsep(oneline, _contacts[_lineNum]);
//			_lineNum++;
//			pszStr = fgets(oneline, GCT_COLUMN_NUM * GCT_COLUMN_SIZE, fp);
//		}
//		else
//		{
//			printf("malloc fail!\n");
//			fclose(fp);
//			return 0;
//		}
//	}
//	fclose(fp);
//	return 1;
//}

int readNsave(FILE* fp, stGCT_Record* record[], int* NumOfRecord) {
	char oneline[GCT_COLUMN_NUM * GCT_COLUMN_SIZE];
	/*----------		read csv & save to struct				---------------*/
	char* pszStr = fgets(oneline, GCT_COLUMN_NUM * GCT_COLUMN_SIZE, fp);
	while (pszStr != NULL) {
		if ((record[*NumOfRecord] = (stGCT_Record*)malloc(sizeof(stGCT_Record))) != NULL) {
			memset(record[*NumOfRecord], 0, sizeof(stGCT_Record));
			strcpy(record[*NumOfRecord]->orgString, oneline);
			Bystrsep(oneline, record[*NumOfRecord]);
			*NumOfRecord = *NumOfRecord + 1;
			pszStr = fgets(oneline, GCT_COLUMN_NUM * GCT_COLUMN_SIZE, fp);
		}
		else
		{
			printf("malloc fail!\n");
			fclose(fp);
			return 0;
		}	
	}
	fclose(fp);
	return 1;
}

void CreateFavFile() {
	FILE* favFp = NULL;

	int isFile;
	char FileExt[10];

	char* ptr = strtok(_FileName, ".");
	strcpy(_FileName_Favorite, ptr);
	strcat(_FileName_Favorite, "_Favorite");
	ptr = strtok(NULL, ".");
	strcpy(FileExt, ".");
	strcat(FileExt, ptr);
	strcat(_FileName_Favorite, FileExt);

	isFile = _access(_FileName_Favorite, 0);

	if (isFile == -1)
	{
		if ((favFp = fopen(_FileName_Favorite, "w+")) != NULL)
		{
			//printf("Favorite File open Success\n");
		}
		else
		{
			printf("Favorite File open Error\n");
			return;
		}

		SetTitle();
		Contacts_saveas(favFp, _contacts_fav, _lineNum_fav);

	}
	else if (isFile == 0) {
		if ((favFp = fopen(_FileName_Favorite, "r+")) != NULL)
		{
			//printf("Favorite File open Success\n");
		}
		else
		{
			printf("Favorite File open Error\n");
			return;
		}
		if (readNsave(favFp, _contacts_fav, &_lineNum_fav) == 0)	return;
	}
	fclose(favFp);

	printf("Favorite File Name \"%s\" is Opened.\n", _FileName_Favorite);

	return;
}

	void SetTitle() {
		if ((_contacts_fav[_lineNum_fav] = (stGCT_Record*)malloc(sizeof(stGCT_Record))) != NULL) {
			memset(_contacts_fav[_lineNum_fav], 0, sizeof(stGCT_Record));
			RecordCopy(_contacts_fav, _contacts, 1);
			_lineNum_fav++;
		}
		else
		{
			printf("malloc fail!\n");
		}
		return;
	}