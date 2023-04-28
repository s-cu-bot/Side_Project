#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define WHT SetConsoleTextAttribute( col,0x000F); // 하얀색
#define VIO SetConsoleTextAttribute( col,0x0001 | 0x0008 |0x000c); //보라
#define YEL SetConsoleTextAttribute( col, 0x000e); //노란색
#define HIGH SetConsoleTextAttribute( col,0x00a); // 연두
#define SKY SetConsoleTextAttribute( col, 0x000b); //하늘색
int b, c, d, e;
int main()
{
	srand((unsigned)time(NULL));
	int i, j, k, l, a[10][10][10][10]; //a는 0~9999까지
	int count = 5040;
	int strike, ball, number = 0;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			for (k = 0; k < 10; k++)
				for (l = 0; l < 10; l++)
				{
					a[i][j][k][l] = i * 1000 + j * 100 + k * 10 + l;
					if (i == j || i == k || i == l || j == k || j == l || k == l)
						a[i][j][k][l] = -1;
				}
	HIGH; printf("\t*중복되는숫자XX 맨첫자리 0가능*\n");
	while (1)
	{
		HIGH; printf("\n남은 경우의수 : %d\n", count);
		YEL; printf("\n\t%d번째, 흠... 추측해보겠습니다!", number + 1);
		printf("\n가능한 수가 없을때는, 무한루프가 생성됩니다.\n");
		do
		{
			b = rand() % 10;
			c = rand() % 10;
			d = rand() % 10;
			e = rand() % 10;
		} while (a[b][c][d][e] == -1 || a[b][c][d][e] == 0);
		SKY; if (b == 0)
			printf("0");
		printf("%d", a[b][c][d][e]);
		WHT; printf("\n\nStrike, Ball\n ");
		scanf("%d %d", &strike, &ball);
		a[b][c][d][e] = 0;
		count--;
		if (strike == 4 && ball == 0)
		{
			SKY;	printf("\n맞췄습니다!");
			break;
		}
		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++)
				for (k = 0; k < 10; k++)
					for (l = 0; l < 10; l++)
					{
						if (strike == 3 && ball == 0)
						{
							{
								if ((i == b && j == c&& k == d) || (i == b && j == c && l == e) || (i == b&&k == d&&l == e) || (j == c&&k == d&&l == e))
									;
								else
									if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
									{
										count--;
										a[i][j][k][l] = 0;
									}
							}
						}
						else if (strike == 2 && ball == 0)
						{
							for (l = 0; l < 10; l++)
							{
								if ((i == b && j == c && k != d&&k != e&&l != d&&l != e) || (i == b && k == d&& j != c&&j != e&&l != c&&l != e) || (i == b && l == e&& j != c&&j != d&&k != c&&k != d)
									|| (j == c && k == d&& i != b&&i != e&&l != b&&l != e) || (j == c&&l == e&& i != b&&i != d&&k != b&&k != d) || (k == d && l == e&& i != b&&i != c&&j != b&&j != c))
									;
								else
									if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
									{
										count--;
										a[i][j][k][l] = 0;
									}
							}
						}
						else if (strike == 2 && ball == 1)
						{
							{
								if ((i == b && j == c && ((k == e && l != d) || (k == d && l != e)))
									|| (i == b && k == d && ((j == e && l != c) || (l == c && j != e)))
									|| (i == b && l == e && ((j == d && k != c) || (k == c && j != d)))
									|| (j == c && k == d && ((i == e && l != b) || (l == b && i != e)))
									|| (j == c && l == e && ((i == d && k != b) || (k == b && i != d)))
									|| (k == d && l == e && ((i == c && j != b) || (j == b && i != c))))
									;
								else
									if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
									{
										count--;
										a[i][j][k][l] = 0;
									}
							}
						}
						else if (strike == 2 && ball == 2)
						{
							{
								if ((i == b && j == c && k == e && l == d) || (i == b && k == d &&  j == e && l == c)
									|| (i == b && l == e && j == d && k == c) || (j == c && k == d && i == e && l == b)
									|| (j == c && l == e && i == d && k == b) || (k == d && l == e && i == c && j == b))
									;
								else
									if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
									{
										count--;
										a[i][j][k][l] = 0;
									}
							}
						}
						else if (strike == 1 && ball == 0)
						{
							{
								if (((i == b) && (j != c && j != d&& j != e &&k != c&&k != d&&k != e&&l != c&&l != d&&l != e))
									|| ((j == c) && (i != b && i != d&& i != e && k != b&&k != d&&k != e&&l != b&&l != d&&l != e))
									|| ((k == d) && (i != b && i != c && i != e && j != b && j != c && j != e && l != b&&l != c&&l != e))
									|| ((l == e) && (i != b && i != c && i != d && j != b && j != c && j != d&&  k != b&&k != c&&k != d)))
									;
								else
									if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
									{
										count--;
										a[i][j][k][l] = 0;
									}
							}
						}
						else if (strike == 1 && ball == 1)
						{
							{
								if ((i == b && (j == d || j == e || k == c || k == e || l == c || l == d) && ((k != c&&k != d&&k != e&&l != c&&l != d&&l != e) || (j != c&&j != d&&j != e&&l != c&&l != d&&l != e) || (j != c&&j != d&&j != e&&k != c&&k != d&&k != e)))
									|| (j == c && (i == d || i == e || k == b || k == e || l == b || l == d) && ((i != b&&i != d&&i != e&&k != b&&k != d&&k != e) || (i != b&&i != d&&i != e&&l != b&&l != d&&l != e) || (k != b&&k != d&&k != e&&l != b&&l != d&&l != e)))
									|| (k == d && (i == c || i == e || j == b || j == e || l == b || l == c) && ((i != b&&i != c&&i != e&&j != b&&j != c&&j != e) || (i != b&&i != c&&i != e&&l != b&&l != c&&l != e) || (j != b&&j != c&&j != e&&l != b&&l != c&&l != e)))
									|| (l == e && (i == c || i == d || j == b || j == d || k == b || k == c) && ((i != b&&i != c&&i != d&&j != b&&j != c&&j != d) || (i != b&&i != c&&i != d&&k != b&&k != c&&k != d) || (j != b&&j != c&&j != d&&k != b&&k != c&&k != d))))
									;
								else
									if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
									{
										count--;
										a[i][j][k][l] = 0;
									}
							}
						}
						else if (strike == 1 && ball == 2)
						{
							{
								if ((i == b && (((j == d || j == e) && (k == c || k == e)) || ((j == d || j == e) && (l == c || l == d)) || ((k == c || k == e) && (l == c || l == d))) && ((j != c&&j != d&&j != e) || (k != c&&k != d&&k != e) || (l != c&&l != d&&l != e)))
									|| (j == c && (((i == d || i == e) && (k == b || k == e)) || ((i == d || i == e) && (l == b || l == d)) || ((k == b || k == e) && (l == b || l == d))) && ((i != b&&i != d&&i != e) || (k != b&&k != d&&k != e) || (l != b&&l != d&&l != e)))
									|| (k == d && (((i == c || i == e) && (j == b || j == e)) || ((i == c || i == e) && (l == b || l == c)) || ((j == b || j == e) && (l == b || l == c))) && ((i != b&&i != c&&i != e) || (j != b&&j != c&&j != e) || (l != b&&l != c&&l != e)))
									|| (l == e && (((i == c || i == d) && (j == b || j == d)) || ((i == c || i == d) && (k == b || k == c)) || ((j == b || j == d) && (k == b || k == c))) && ((i != b&&i != c&&i != d) || (j != b&&j != c&&j != d) || (k != b&&k != c&&k != d))))
									;
								else if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
								{
									count--;
									a[i][j][k][l] = 0;
								}
							}
						}
						else if (strike == 1 && ball == 3)
						{
							{
								if ((i == b && ((j == d || j == e) && (k == c || k == e) && (l == c || l == d)))
									|| (j == c && (i == d || i == e) && (k == b || k == e) && (l == b || l == d))
									|| (k == d && ((j == b || j == e) && (i == c || i == e) && (l == b || l == c)))
									|| (l == e && ((j == b || j == d) && (k == b || k == c) && (i == c || i == d))))
									;
								else
									if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
									{
										count--;
										a[i][j][k][l] = 0;
									}
							}
						}
						else if (strike == 0 && ball == 0)
						{
							if ((i != b && i != c && i != d && i != e) && (j != b && j != c && j != d && j != e) && (k != b && k != c && k != d && k != e) && (l != b && l != c && l != d && l != e))
								;
							else if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
							{
								count--;
								a[i][j][k][l] = 0;
							}
						}
						else if (strike == 0 && ball == 1)
						{
							{
								if (((i == c || i == d || i == e) && (j != b && j != c&&j != d&&j != e&&k != b && k != c&&k != d&&k != e&&l != b && l != c&&l != d&&l != e))
									|| ((j == b || j == d || j == e) && (i != b && i != c&&i != d&&i != e&&k != b && k != c&&k != d&&k != e&&l != b && l != c&&l != d&&l != e))
									|| ((k == b || k == c || k == e) && (j != b && j != c&&j != d&&j != e&&i != b && i != c&&i != d&&i != e&&l != b && l != c&&l != d&&l != e))
									|| ((l == b || l == c || l == d) && (j != b && j != c&&j != d&&j != e&&k != b && k != c&&k != d&&k != e&&i != b && i != c&&i != d&&i != e))
									)
									;
								else if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
								{
									count--;
									a[i][j][k][l] = 0;
								}
							}
						}
						else if (strike == 0 && ball == 2)
						{
							{
								if (((i == c || i == d || i == e) && (j == b || j == d || j == e) && (k != b && k != c &&k != d&& k != e) && (l != b && l != c &&l != d&& l != e)) || ((i == c || i == d || i == e) && (k == b || k == c || k == e) && (j != b && j != c &&j != d&& j != e) && (l != b && l != c &&l != d&& l != e))
									|| ((i == c || i == d || i == e) && (l == b || l == c || l == d) && (k != b && k != c &&k != d&& k != e) && (j != b && j != c &&j != d&& j != e)) || ((j == b || j == d || j == e) && (k == b || k == c || k == e) && (i != b && i != c &&i != d&& i != e) && (l != b && l != c &&l != d&& l != e))
									|| ((j == b || j == d || j == e) && (l == b || l == c || l == d) && (i != b && i != c &&i != d&& i != e) && (k != b && k != c &&k != d&& k != e)) || ((k == b || k == c || k == e) && (l == b || l == c || l == d) && (i != b && i != c &&i != d&& i != e) && (j != b && j != c &&j != d&& j != e)))
									;
								else if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
								{
									count--;
									a[i][j][k][l] = 0;
								}
							}
						}
						else if (strike == 0 && ball == 3)
						{

							{
								if (((i == c || i == d || i == e) && (j == b || j == d || j == e) && (k == b || k == c || k == e) && (l != b && l != c && l != d && l != e))
									|| ((l == b || l == c || l == d) && (j == b || j == d || j == e) && (k == b || k == c || k == e) && (i != b && i != c && i != d && i != e))
									|| ((i == c || i == d || i == e) && (l == b || l == c || l == d) && (k == b || k == c || k == e) && (j != b && j != c && j != d && j != e))
									|| ((i == c || i == d || i == e) && (j == b || j == d || j == e) && (l == b || l == c || l == d) && (k != b && k != c && k != d && k != e))
									)
									;
								else
									if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
									{
										count--;
										a[i][j][k][l] = 0;
									}
							}
						}
						else if (strike == 0 && ball == 4)
						{
							{
								if ((i == c || i == d || i == e) && (j == b || j == d || j == e) && (k == b || k == c || k == e) && (l == b || l == c || l == d))
									;
								else if (a[i][j][k][l] != -1 && a[i][j][k][l] != 0)
								{
									count--;
									a[i][j][k][l] = 0;
								}
							}
						}
						else
						{
							printf("\nball과 strike는 0부터4까지만\n");
							return 0;
						}
					}
		number++;
	}
}