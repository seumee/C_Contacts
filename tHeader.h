/*
fgets(oneline, sizeof(char) * GCT_COLUMN_NUM * GCT_COLUMN_SIZE, fp);
while (oneline[i] != '\n') {
	if (oneline[i] != ',') {
		contacts.szColumn[category][j+1] = oneline[i];
		i++;
		j++;
	}
	else {
		contacts.szColumn[category][0] = j;
		category++;
		i++;
		j = 0;
	}
}
// 50번째 항목 길이 저장을 위해 while문 바깥에사 j값 1회 대입
contacts.szColumn[category][0] = j;
printf("%s", oneline);
while (oneline[tmp] != '\n') {
	putchar(oneline[tmp]);
	tmp++;
}
*/

/*
for (tmp2 = 0; tmp2 < GCT_COLUMN_NUM; tmp2++) {
	for (i = 0; i <= contacts.szColumn[tmp2][0]-1; i++) {
		printf("%c", contacts.szColumn[tmp2][i+1]);
	}
	printf("\ncategory %d end-- tmp2 is %d\n", tmp2+1, tmp2);
}
*/