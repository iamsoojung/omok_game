#include <stdio.h>		// ル遽 殮轎溘 л熱 餌辨擊 嬪и ④渦だ橾 蹺陛
#include <Windows.h>	// 夔樂璽擊 檜辨ж晦 嬪и ④渦だ橾 蹺陛
#include <conio.h>		// 夔樂 殮轎溘 л熱 餌辨擊 嬪и ④渦だ橾 蹺陛

#define MINT_TEXT textcolor(11, 0);		// 旋濠儀 = 團お & 旋濠寡唳儀 = 匐薑
#define WHITE_TEXT textcolor(15, 0);	// 旋濠儀 = ж曄 & 旋濠寡唳儀 = 匐薑
#define YELLOW_TEXT textcolor(14, 0);	// 旋濠儀 = 喻嫌 & 旋濠寡唳儀 = 匐薑
#define BLACK_STONE 1	// 1 = �瘚�
#define WHITE_STONE 2	// 2 = 寥給
#define BLACK_PRINT printf("∞");	// �瘚� 轎溘
#define WHITE_PRINT printf("≒");	// 寥給 轎溘

int i, j;
int board[19][19] = { 0 };	// 19X19 螃跡っ 寡翮

void title();	// 衛濛�飛� 轎溘л熱
void rule();	// 啪歜寞徹�飛� 轎溘л熱
void load();	// 啪歜 衛濛 瞪 蘋遴お棻遴ж朝 л熱
void after_game();	// 啪歜 部陪 �� 棻擠縑 翕濛й 摹鷗雖�飛� 轎溘л熱
void exit_game();	// 啪歜謙猿�飛� 轎溘л熱

void gotoxy(int x, int y);	// 醴憮 嬪纂 褻薑 л熱
void textcolor(int foreground, int background);	// 旋濠儀, 旋濠寡唳儀 滲唳 л熱

void a();	// 螃跡っ 1ч
void b();	// 螃跡っ 2ч ~ 18ч
void c();	// 螃跡っ 19ч
void omok_board();	// 螃跡っ 斜葬朝 л熱

void stone_move(int stone);	// 給擊 遺霜檜朝 л熱
void press_key(int input, int* x, int* y);	// 酈爾萄 殮溘嫡朝 л熱

int win_check_black();	// �瘚嘛� 蝓葬 っ薑л熱
int win_check_white();	// 寥給曖 蝓葬 っ薑л熱

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 詭檣л熱 衛濛 ---------------------------------------------------------------------------
int main()
{
	// 醴憮 獗梯籀葬
	CONSOLE_CURSOR_INFO cursorInfo = { 0 };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	while (1)
	{
	start:	// 溯檜綰 start (衛濛�飛�)
		title();
		char ch = _getch();	// 滲熱 ch縑 殮溘嫡擎 酈爾萄高 盪濰
		if (ch == 49)	// 1 -> 啪歜 衛濛
		{
		game:	// 溯檜綰 game (啪歜褒ч)
			load();

			// 螃跡っ 蟾晦��
			for (i = 0; i < 19; i++)
			{
				for (j = 0; j < 19; j++)
				{
					board[i][j] = NULL;
				}
			}
			system("cls");	// �飛� 雖辦晦 л熱

			while (1)
			{
				omok_board();
				stone_move(BLACK_STONE);	// �瘚� 衛濛
				if (win_check_black() == 0)	// �瘚嘛� 蝓葬檣 唳辦
				{
					after_game();
					while (1)
					{
						ch = _getch();	// 滲熱 ch縑 殮溘嫡擎 酈爾萄高 盪濰

						if (ch == 49)	// 1
						{
							goto game;	// 溯檜綰 game(啪歜�飛�)戲煎 檜翕
						}
						else if (ch == 27)	// ESC
						{
							exit_game();
							return 0;	// Щ煎斜極檜 薑鼻瞳戲煎 謙猿
						}
						else if (ch == 48)		// 0
						{
							system("cls");	// �飛� 雖辦朝 л熱
							goto start;		// 溯檜綰 start(衛濛�飛�)煎 檜翕
						}
					}
				}

				omok_board();
				stone_move(WHITE_STONE);	// 寥給 衛濛
				if (win_check_white() == 0)	// 寥給檜 蝓葬檣 唳辦 (�瘚嘛� 唳辦諦 翕橾)
				{
					after_game();
					while (1)
					{
						ch = _getch();

						if (ch == 49)
						{
							goto game;
						}
						else if (ch == 27)
						{
							exit_game();
							return 0;
						}
						else if (ch == 48)
						{
							system("cls");
							goto start;
						}
					}
				}
			}
		}
		else if (ch == 50)	// 2 -> 啪歜 撲貲
		{
			rule();
			while (1)
			{
				ch = _getch();	// 滲熱 ch縑 殮溘嫡擎 酈爾萄高 盪濰
				if (ch == 48)	// 0
				{
					system("cls");	// �飛� 雖辦朝 л熱
					goto start;		// 溯檜綰 start(衛濛�飛�)煎 檜翕
				}
			}
		}
		else if (ch == 27)	//esc
		{
			exit_game();
			return 0;	// Щ煎斜極檜 薑鼻瞳戲煎 謙猿
		}
	}
}

void title()
{
	// Sleep(100); 
	// : 0.1蟾噶 衛除離蒂 舒堅 轎溘
	gotoxy(5, 2); printf("忙收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收忖");
	Sleep(100);
	MINT_TEXT;
	gotoxy(5, 4); printf("      ﹥﹥﹥         ﹥﹥﹥﹥                                   ﹥    ");
	Sleep(100);
	gotoxy(5, 5); printf("     ﹥    ﹥        ﹥    ﹥     ﹥﹥﹥﹥   ﹥ ﹥     ﹥﹥﹥   ﹥    ");
	Sleep(100);
	gotoxy(5, 6); printf("      ﹥﹥﹥         ﹥﹥﹥﹥          ﹥    ﹥ ﹥    ﹥    ﹥  ﹥    ");
	Sleep(100);
	gotoxy(5, 7); printf("        ﹥              ﹥            ﹥   ﹥﹥ ﹥     ﹥﹥﹥   ﹥    ");
	Sleep(100);
	gotoxy(5, 8); printf("        ﹥              ﹥           ﹥      ﹥ ﹥                    ");
	Sleep(100);
	gotoxy(5, 9); printf("        ﹥        ﹥﹥﹥﹥﹥﹥﹥    ﹥       ﹥ ﹥      ﹥﹥﹥﹥﹥    ");
	Sleep(100);
	gotoxy(5, 10); printf("   ﹥﹥﹥﹥﹥﹥                    ﹥        ﹥ ﹥      ﹥      ﹥    ");
	Sleep(100);
	gotoxy(5, 11); printf("                    ﹥﹥﹥﹥﹥               ﹥ ﹥      ﹥﹥﹥﹥﹥    ");
	Sleep(100);
	gotoxy(5, 12); printf("                            ﹥                                        ");
	Sleep(100);
	gotoxy(5, 13); printf("                            ﹥                                        ");
	Sleep(100);
	WHITE_TEXT;
	gotoxy(5, 15); printf("戌收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收戎"); Sleep(100);
	gotoxy(30, 18); printf("啪歜 衛濛 >>  1");
	gotoxy(30, 20); printf("啪歜 撲貲 >>  2");
	gotoxy(30, 22); printf("啪歜 謙猿 >> ESC");
}

void rule()
{
	system("cls");
	gotoxy(5, 3); printf("忙收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收忖");
	MINT_TEXT;
	gotoxy(5, 5); printf("                 ≧≠≧≠≧≠ 啪歜寞徹 ≠≧≠≧≠≧");
	gotoxy(5, 7); printf("                 寞щ酈蒂 檜辨ж罹 夥舜給擊 遺霜檜堅");
	gotoxy(5, 8); printf("                試盪 5偃曖 夥舜給擊 翱殖嬴 檜戲賊 蝓葬!");
	gotoxy(5, 9); printf("                        ��(��)檜 摹(鉬)殮棲棻");
	gotoxy(5, 11); printf("                    ∠∟⊿⊥ 寞щ酈 : 夥舜給 檜翕");
	gotoxy(5, 12); printf("                 space bar : 夥舜給 場晦 (渦綰 贗葛)");
	gotoxy(5, 14); printf("                   衛濛�飛橉虞� 給嬴陛溥賊 >>> 0");
	WHITE_TEXT;
	gotoxy(5, 16); printf("戌收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收戎");
}

void load()
{
	system("cls");
	gotoxy(30, 8);
	printf("忙收收收收收收收收收收收收收收收收收收收收收收收忖");
	gotoxy(30, 14);
	printf("戌收收收收收收收收收收收收收收收收收收收收收收收戎");
	Sleep(100);
	gotoxy(30, 10);
	printf("\t 啪歜擊 衛濛м棲棻!!");
	gotoxy(42, 12);
	printf("3");	Sleep(1000);	// 3蟾 蘋遴お棻遴 衛濛
	gotoxy(42, 12);
	printf("2");	Sleep(1000);
	gotoxy(42, 12);
	printf("1");	Sleep(1000);
}

void after_game()
{
	puts("\n  旨收收收  ≦ иっ 渦 ж衛啊蝗棲梱?  收收收旬\n");
	puts("            иっ 渦!! >>> 1          ");
	puts("          寰ж堅 謙猿й楚蹂 >>> ESC    ");
	puts("\n       衛濛�飛橉虞� 給嬴陛溥賊 >>> 0     \n");
	printf("   曲收收收收收收收收收收收收收收收收");
	puts("收收收收收收收收收收收收收收收收收旭\n");
}

void exit_game()
{
	system("cls");
	printf("\n\n      收收收收收收收收收收收收收收收收收收收收收收收收");
	puts("收收收收收收收收收收收收收收收收收收收收收收收收");
	MINT_TEXT;
	puts("\n\n              ⅥⅤⅥⅤⅥⅤ 謙 猿 ⅤⅥⅤⅥⅤⅥ\n\n");
	WHITE_TEXT;
	printf("      收收收收收收收收收收收收收收收收收收收收收收收收");
	puts("收收收收收收收收收收收收收收收收收收收收收收收收\n\n\n");
}


void a()
{
	// 1翮
	if (board[0][0] == 0)	printf("忙 ");		// 螃跡っ 寡翮曖 錳模陛 0 檜賊 -> 螃跡っ 賅曄 轎溘
	else if (board[0][0] == BLACK_STONE)	BLACK_PRINT		// 螃跡っ 寡翮曖 錳模陛 �瘚� 檜賊 -> �瘚� 轎溘
	else if (board[0][0] == WHITE_STONE)	WHITE_PRINT		// 螃跡っ 寡翮曖 錳模陛 寥給 檜賊 -> 寥給 轎溘

	// 2翮 ~ 18翮
		for (i = 1; i < 18; i++)
		{
			if (board[0][i] == 0)	printf("成 ");
			else if (board[0][i] == BLACK_STONE)	BLACK_PRINT
			else if (board[0][i] == WHITE_STONE)	WHITE_PRINT
		}

	// 19翮
	if (board[0][18] == 0)	printf("忖 ");
	else if (board[0][18] == BLACK_STONE)	BLACK_PRINT
	else if (board[0][18] == WHITE_STONE)	WHITE_PRINT

		printf("\n");
}

void b()
{
	for (i = 1; i < 18; i++)
	{
		// 1翮
		if (board[i][0] == 0)	printf("戍 ");
		else if (board[i][0] == BLACK_STONE)	BLACK_PRINT
		else if (board[i][0] == WHITE_STONE)	WHITE_PRINT

			// 2翮 ~ 18翮
			for (j = 1; j < 18; j++)
			{
				if (board[i][j] == 0)	printf("托 ");
				else if (board[i][j] == BLACK_STONE)	BLACK_PRINT
				else if (board[i][j] == WHITE_STONE)	WHITE_PRINT
			}

		// 19翮
		if (board[i][18] == 0)	printf("扣 ");
		else if (board[i][18] == BLACK_STONE)		BLACK_PRINT
		else if (board[i][18] == WHITE_STONE)		WHITE_PRINT

			printf("\n");
	}
}

void c()
{
	// 1翮
	if (board[18][0] == 0)	printf("戌 ");
	else if (board[18][0] == BLACK_STONE)	BLACK_PRINT
	else if (board[18][0] == WHITE_STONE)	WHITE_PRINT

		// 2翮 ~ 18翮
		for (i = 1; i < 18; i++)
		{
			if (board[18][i] == 0)	printf("扛 ");
			else if (board[18][i] == BLACK_STONE)	BLACK_PRINT
			else if (board[18][i] == WHITE_STONE)	WHITE_PRINT
		}

	// 19翮
	if (board[18][18] == 0)	printf("戎 ");
	else if (board[18][18] == BLACK_STONE)	BLACK_PRINT
	else if (board[18][18] == WHITE_STONE)	WHITE_PRINT

		printf("\n");
}

void omok_board()
{
	a();	// 1ч
	b();	// 2ч ~ 18ч
	c();	// 19ч
}

int win_check_black()
{
	for (i = 0; i < 18; i++)
	{
		for (j = 0; j < 18; j++)
		{
			// 陛煎 5翱樓 (⊥)
			if (board[i][j] == BLACK_STONE && board[i][j + 1] == BLACK_STONE && board[i][j + 2] == BLACK_STONE && board[i][j + 3] == BLACK_STONE && board[i][j + 4] == BLACK_STONE)
			{
				omok_board();
				YELLOW_TEXT;
				puts("\n\t      BLACK 蝓 !!!");
				WHITE_TEXT;
				return 0;
			}

			// 撮煎 5翱樓 (⊿)
			if (board[i][j] == BLACK_STONE && board[i + 1][j] == BLACK_STONE && board[i + 2][j] == BLACK_STONE && board[i + 3][j] == BLACK_STONE && board[i + 4][j] == BLACK_STONE)
			{
				omok_board();
				YELLOW_TEXT;
				puts("\n\t      BLACK 蝓 !!!");
				WHITE_TEXT;
				return 0;
			}

			// 嬴楚 渠陝摹 5翱樓 (Ｋ)
			if (board[i][j] == BLACK_STONE && board[i + 1][j + 1] == BLACK_STONE && board[i + 2][j + 2] == BLACK_STONE && board[i + 3][j + 3] == BLACK_STONE && board[i + 4][j + 4] == BLACK_STONE)
			{
				omok_board();
				YELLOW_TEXT;
				puts("\n\t      BLACK 蝓 !!!");
				WHITE_TEXT;
				return 0;
			}

			// 嬪 渠陝摹 5翱樓 (Ｈ)
			if (i >= 4)
			{
				if (board[i][j] == BLACK_STONE && board[i - 1][j + 1] == BLACK_STONE && board[i - 2][j + 2] == BLACK_STONE && board[i - 3][j + 3] == BLACK_STONE && board[i - 4][j + 4] == BLACK_STONE)
				{
					omok_board();
					YELLOW_TEXT;
					puts("\n\t      BLACK 蝓 !!!");
					WHITE_TEXT;
					return 0;
				}
			}
		}
	}
}

int win_check_white()
{
	for (i = 0; i < 18; i++)
	{
		for (j = 0; j < 18; j++)
		{
			// 陛煎 5翱樓 (⊥)
			if (board[i][j] == WHITE_STONE && board[i][j + 1] == WHITE_STONE && board[i][j + 2] == WHITE_STONE && board[i][j + 3] == WHITE_STONE && board[i][j + 4] == WHITE_STONE)
			{
				omok_board();
				YELLOW_TEXT;
				puts("\n\t      WHITE 蝓 !!!");
				WHITE_TEXT;
				return 0;
			}

			// 撮煎 5翱樓 (⊿)
			if (board[i][j] == WHITE_STONE && board[i + 1][j] == WHITE_STONE && board[i + 2][j] == WHITE_STONE && board[i + 3][j] == WHITE_STONE && board[i + 4][j] == WHITE_STONE)
			{
				omok_board();
				YELLOW_TEXT;
				puts("\n\t      WHITE 蝓 !!!");
				WHITE_TEXT;
				return 0;
			}

			// 嬴楚 渠陝摹 5翱樓 (Ｋ)
			if (board[i][j] == WHITE_STONE && board[i + 1][j + 1] == WHITE_STONE && board[i + 2][j + 2] == WHITE_STONE && board[i + 3][j + 3] == WHITE_STONE && board[i + 4][j + 4] == WHITE_STONE)
			{
				omok_board();
				YELLOW_TEXT;
				puts("\n\t      WHITE 蝓 !!!");
				WHITE_TEXT;
				return 0;
			}

			// 嬪 渠陝摹 5翱樓 (Ｈ)
			if (i >= 4)
			{
				if (board[i][j] == WHITE_STONE && board[i - 1][j + 1] == WHITE_STONE && board[i - 2][j + 2] == WHITE_STONE && board[i - 3][j + 3] == WHITE_STONE && board[i - 4][j + 4] == WHITE_STONE)
				{
					omok_board();
					YELLOW_TEXT;
					puts("\n\t      WHITE 蝓 !!!");
					WHITE_TEXT;
					return 0;
				}
			}
		}
	}
}

void stone_move(int stone)
{
	static int x = 19;		// 夥舜憲 嬪纂謝ル蒂 嬪и 薑瞳滲熱 x, y
	static int y = 10;
	int input;
	gotoxy(x, y);
	while (1)
	{
	retry:		// 溯檜綰 retry(啪歜 營衛濛)
		input = _getch();
		if (_kbhit())	//酈爾萄 殮溘檜 氈戲賊
		{
			gotoxy(x, y);
			system("cls");
			omok_board();
			input = _getch();
			press_key(input, &x, &y);
			gotoxy(x, y);
			if (stone == BLACK_STONE)	BLACK_PRINT
			else WHITE_PRINT
		}
		else if (_getch() == 32)	// 殮溘檜 spacebar檣 唳辦
		{
			if (board[y - 1][x / 2] == BLACK_STONE || board[y - 1][x / 2] == WHITE_STONE)	// 摹鷗и 謝ル陛 檜嘐 給檜 襄營ж朝 謝ル檣 唳辦
			{
				system("cls");
				omok_board();
				puts("\n\t≦ 檜嘐 摹鷗脹 蘊殮棲棻. ≦");
				puts("\n\t  ≦ 棻衛 摹鷗п輿撮蹂 ≦");
				goto retry;		// 溯檜綰 retry(啪歜 營衛濛)煎 檜翕
			}

			// 斜 諼 唳辦 給 轎溘
			else
			{
				if (stone == BLACK_STONE)	board[y - 1][x / 2] = BLACK_STONE;
				else board[y - 1][x / 2] = WHITE_STONE;
				system("cls");
				break;
			}
		}
	}
}

void press_key(int input, int* x, int* y)	// input = 酈爾萄 殮溘, x謝ル諦 y謝ル朝 ん檣攪煎 嫡擠
{
	if (input == 72)	// 酈爾萄 殮溘 = 鼻
	{
		(*y)--;			// y謝ル 嬪薹 檜翕
		if (*y < 1)	*y = 1;		// 渦 檜鼻 檜翕й 蘊檜 橈朝 唳辦 -> 薯濠葬
		return y;		// y謝ル 奩��
	}
	else if (input == 80)	// 酈爾萄 殮溘 = ж
	{
		(*y)++;			// y謝ル 嬴楚薹 檜翕
		if (*y > 19)	*y = 19;
		return y;
	}
	else if (input == 75)	// 酈爾萄 殮溘 = 謝
	{
		*x -= 2;		// x謝ル 豭薹 檜翕
		if (*x < 1)	*x = 1;
		return x;		// x謝ル 奩��
	}
	else if (input == 77)	// 酈爾萄 殮溘 = 辦
	{
		*x += 2;		// x謝ル 螃艇薹 檜翕
		if (*x > 37)	*x = 37;
		return x;		// x謝ル 奩��
	}
}