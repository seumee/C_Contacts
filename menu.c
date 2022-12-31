///////////////////////////////////////////////////////////////////////////////
/// @date           2020.12
/// @brief          Address Book Management Menu
/// @author
///////////////////////////////////////////////////////////////////////////////
#include "menu.h"


/*-----------------------------------------------------------------
    Sub Menu List
-----------------------------------------------------------------*/
_SUBMENU    stFileMenu[] = {
    {   "sample",   UT_Sample,          2,  3,  "string integer [string]"  },
    {   "google",   UT_File_Google,     2,  2,  "id pwd"  },
    {   "open",     UT_File_Open,       1,  1,  "file"  },
    {   "save",     UT_File_Save,       0,  0,  ""  },
    {   "saveas",   UT_File_SaveAs,     1,  1,  "file"  },
    {   "close",    UT_File_Close,      0,  0,  ""  },
    {   "test",     UT_Test,            0,  0,  ""   },
    {   NULL,  NULL, 0,  0,  ""  },
};

_SUBMENU    stRecordMenu[] = {
    {   "show",     UT_Record_Show,     0,  0,  ""  },
    {   "add",      UT_Record_Add,      0,  0,  ""  },
    {   "delete",   UT_Record_Delete,   1,  1,  "keyWord"  },
    {   "change",   UT_Record_Change,   1,  1,  "keyWord"  },
    {   "search",   UT_Record_Search,   0,  1,  "keyWord"  },
    {   "keywordSearch",   UT_Record_Ksearch,   0,  1,  "keyWord"  },
    {   "rsearch",  UT_Record_Rsearch,  0,  0,  ""  },
    {   NULL,  NULL, 0,  0,  ""  },
};

_SUBMENU    stSortMenu[] = {
    {   "name",     UT_Sort_Name,       0,  1,  "[ascend/descend]"  },
    {   "tel",      UT_Sort_Tel,        0,  1,  "[ascend/descend]"  },
    {   "group",    UT_Sort_Group,      0,  1,  "[ascend/descend]"  },
    {   NULL,  NULL, 0,  0,  ""  },
};

_SUBMENU    stFavoriteMenu[] = {
    {   "show",     UT_Favorite_Show,   0 , 0,  ""  },
    {   "add",      UT_Favorite_Add,    1,  1,  "keyWord"  },
    {   "delete",   UT_Favorite_Delete, 1,  1,  "keyWord" },
    {   "sort",     UT_Favorite_Sort,   1,  2,  "name/tel/group [ascend/descend]"  },
    {   NULL,  NULL, 0,  0,  ""  },
};

/*-----------------------------------------------------------------
    Main Menu List
-----------------------------------------------------------------*/
_MAINMENU   stMainMenu[] = {
    {   "file",         stFileMenu   },
    {   "record",       stRecordMenu   },
    {   "sort",         stSortMenu   },
    {   "Favorite",     stFavoriteMenu   },

    {   NULL,       NULL    },
};

void
Help()
{
    int         i, j;
    _SUBMENU* pstSubMenu;

    printf("--------------  [ HELP ]  ------------------------\n");
    printf("    help : Help\n");
    printf("    exit/quit : quit\n");
    //    printf("    history : history\n");

    for (i = 0; stMainMenu[i].pszCmd; i++)
    {
        printf("    %s (", stMainMenu[i].pszCmd);

        pstSubMenu = stMainMenu[i].pstSubMenu;
        for (j = 0; pstSubMenu[j].pszCmd; j++) printf("%s/", pstSubMenu[j].pszCmd);
        printf(")\n");

        //            printf("        %s %s %s\n", stMainMenu[i].pszCmd, pstSubMenu[j].pszCmd, pstSubMenu[j].pszHelp);
    }

    printf("--------------------------------------------------\n");
}

int
MainMenu()
{
    int     i;
    int     nWCnt;
    char    szCmd[256];
    char* pszWords[16];

    Help();

    while (1)
    {
        rewind(stdin);
        printf("> ");
        fgets(szCmd, sizeof(szCmd), stdin);
        if (szCmd[0] == 0)      continue;

        if ((nWCnt = C_WordsInLine(szCmd, pszWords, 16)) > 0)
        {
            if (!_strnicmp("help", pszWords[0], strlen(pszWords[0]))) { Help(); continue; }
            else if (!_strnicmp("quit", pszWords[0], strlen(pszWords[0])))  return -1;
            else if (!_strnicmp("exit", pszWords[0], strlen(pszWords[0])))  return -1;
            else if (nWCnt >= 2)
            {
                for (i = 0; stMainMenu[i].pszCmd; i++)
                    if (!_strnicmp(stMainMenu[i].pszCmd, pszWords[0], strlen(pszWords[0])))
                    {
                        SubMenu(stMainMenu[i].pszCmd, stMainMenu[i].pstSubMenu, pszWords + 1, nWCnt - 1);
                        break;
                    }
                if (!stMainMenu[i].pszCmd)        printf("\t\tUnknown Command [%s]\n", pszWords[0]);
            }
            else    printf("\t\tInvalid Command [%s]\n", pszWords[0]);
        }
    }
}

void
SubMenu(char* pszMainCmd, _SUBMENU* pstMenu, char** pszWords, int nWCnt)
{
    int     i;

    for (i = 0; pstMenu[i].pszCmd; i++)
        if (!_strnicmp(pstMenu[i].pszCmd, pszWords[0], strlen(pszWords[0])))
        {
            if ((nWCnt - 1) < pstMenu[i].nNoMinArg || (nWCnt - 1) > pstMenu[i].nNoMaxArg)
                printf("Invalid Argument :: Usage [%s %s %s]\n", pszMainCmd, pstMenu[i].pszCmd, pstMenu[i].pszHelp);
            else (*pstMenu[i].func)(pszWords + 1, nWCnt - 1);

            return;
        }

    printf("\t\tUnknown Submenu [%s %s]\n", pszMainCmd, pszWords[0]);

}

int
C_WordsInLine(char* pszLine, char* pszWords[], int nMaxCnt)
{
    int nCntT = 0;

    while (nCntT < nMaxCnt) {
        while (isspace((unsigned char)*pszLine)) ++pszLine;
        if (*pszLine == 0x00) return nCntT;

        pszWords[nCntT++] = pszLine;

        while (!isspace((unsigned char)*pszLine) && *pszLine != 0x00) ++pszLine;
        if (*pszLine == 0x00) return nCntT;

        *pszLine = 0x00;
        ++pszLine;
    }

    return nCntT;
}