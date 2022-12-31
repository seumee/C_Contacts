///////////////////////////////////////////////////////////////////////////////
/// @date           2020.12
/// @brief          Address Book Management Menu
/// @author
///////////////////////////////////////////////////////////////////////////////
#ifndef __OAM_SIMM4LM_INC_H__
#define __OAM_SIMM4LM_INC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>


#define MAX_LINE_NUM        128
#define MAX_LINE_LEN        256
#define MAX_WORD_NUM        64
#define MAX_WORD_LEN        64

typedef struct TagSubMenuMng {
    char* pszCmd;
    void        (*func)();
    int    nNoMinArg;
    int    nNoMaxArg;
    char* pszHelp;
}_SUBMENU;

typedef struct TagMainMenuMng {
    char* pszCmd;
    _SUBMENU* pstSubMenu;
}_MAINMENU;


// menu.c
void Help();
void SubMenu(char* pszMainCmd, _SUBMENU* pstMenu, char** pszWords, int nWCnt);
int MainMenu();
int C_WordsInLine(char* pszLine, char* pszWords[], int nMaxCnt);

// menu_func.c
void UT_File_Google(char** pszWords, int nWCnt);
void UT_File_Open(char** pszWords, int nWCnt);
void UT_File_Save(char** pszWords, int nWCnt);
void UT_File_SaveAs(char** pszWords, int nWCnt);
void UT_File_Close(char** pszWords, int nWCnt);
void UT_Record_Show(char** pszWords, int nWCnt);
void UT_Record_Add(char** pszWords, int nWCnt);
void UT_Record_Delete(char** pszWords, int nWCnt);
void UT_Record_Change(char** pszWords, int nWCnt);
void UT_Record_Search(char** pszWords, int nWCnt);
void UT_Record_Ksearch(char** pszWords, int nWCnt);
void UT_Record_Ksearch_Numbered(char** pszWords, int nWCnt);
void UT_Record_Ksearch_Numbered_fav(char** pszWords, int nWCnt);
void UT_Record_Rsearch(char** pszWords, int nWCnt);
void UT_Sort_Name(char** pszWords, int nWCnt);
void UT_Sort_Tel(char** pszWords, int nWCnt);
void UT_Sort_Group(char** pszWords, int nWCnt);
void UT_Favorite_Show(char** pszWords, int nWCnt);
void UT_Favorite_Add(char** pszWords, int nWCnt);
void UT_Favorite_Delete(char** pszWords, int nWCnt);
void UT_Favorite_Sort(char** pszWords, int nWCnt);


void UT_Sample(char** pszWords, int nWCnt);
void UT_Test(char** pszWords, int nWCnt);



#endif