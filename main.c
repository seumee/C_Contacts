#include "Structure.h"
#include "menu.h"
#include "Func.h"

stGCT_Record* _contacts[MAX_PROFILE_NUM];

stGCT_Record* _contacts_Database[USEDCATEGORY][MAX_PROFILE_NUM];
/*	{
		FamilyName(_contacts_Database[0]);
		Name(_contacts_Database[1]);
		GroupMembership(_contacts_Database[2]);
		PN(_contacts_Database[3]);
		Group(_contacts_Database[4]);
	} */

stGCT_Record* _contacts_fav[MAX_PROFILE_NUM];

// 총 항목의 개수(_contacts[0] ~ _contacts[299] -> _lineNum = 300)
int _lineNum = 0;
int _lineNum_fav = 0;
char _FileName[FILE_NAME_SIZE];
char _FileName_Favorite[FILE_NAME_SIZE + 10];

ST_USAGE _stUsage[USEDCATEGORY] = {
	{FAMILY_NAME_COLUMN, 14},
	{GIVEN_NAME_COLUMN, 16},
	{GROUP_MEMBERSHIP_COLUMN, 30},
	{PHONE_VALUE_COLUMN, 16},
	{GROUP_COLUMN, 22}
};

int main(int argc, char **argv) {

	SetDir();
	
	system("title CONTACTS");
	MainMenu();
	return 0;
}