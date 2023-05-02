import sys
import os
import random
import time

b, c, d, e = 0, 0, 0, 0

def main():
    random.seed(time.time())
    i, j, k, l = 0, 0, 0, 0
    a = [[[[-1 for _ in range(10)] for _ in range(10)] for _ in range(10)] for _ in range(10)]  # a ranges from 0 to 9999
    count = 5040
    strike, ball, number = 0, 0, 0
    for i in range(10):
        for j in range(10):
            for k in range(10):
                for l in range(10):
                    a[i][j][k][l] = i * 1000 + j * 100 + k * 10 + l
                    if i == j or i == k or i == l or j == k or j == l or k == l:
                        a[i][j][k][l] = -1
    print("\n\n\t*중복되는숫자XX 맨첫자리 0가능*\n")

    while True:
        print(f"\n\t***남은 경우의수 : {count}***\n")
        while True:
            b = random.randint(0, 9)
            c = random.randint(0, 9)
            d = random.randint(0, 9)
            e = random.randint(0, 9)
            if a[b][c][d][e] != -1 and a[b][c][d][e] != 0:
                break
        if b == 0:
            print("0", end='')
        print(f"\n\t{number+1}번째 추측 : " + str(a[b][c][d][e]))
        print("\n\nStrike, Ball\n ")
        strike, ball = map(int, input().split())
        a[b][c][d][e] = 0	
        count -= 1
        if strike == 4 and ball == 0:
            print("\n맞췄습니다!")	
            break

        for i in range(10):
            for j in range(10):
                for k in range(10):
                    for l in range(10):
                        if strike == 3 and ball == 0:
                            if (i == b and j == c and k == d) or (i == b and j == c and l == e) or (i == b and k == d and l == e) or (j == c and k == d and l == e):
                                pass
                            else:
                                if a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                    count -= 1
                                    a[i][j][k][l] = 0
                        elif strike == 2 and ball == 0:
                            for l in range(10):
                                if ((i == b and j == c and k != d and k != e and l != d and l != e) or (i == b and k == d and j != c and j != e and l != c and l != e) or (i == b and l == e and j != c and j != d and k != c and k != d)
                                    or (j == c and k == d and i != b and i != e and l != b and l != e) or (j == c and l == e and i != b and i != d and k != b and k != d) or (k == d and l == e and i != b and i != c and j != b and j != c)):
                                    pass
                                else:
                                    if a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                        count -= 1
                                        a[i][j][k][l] = 0
                        elif strike == 2 and ball == 1:
                            if ((i == b and j == c and ((k == e and l != d) or (k == d and l != e)))
                                or (i == b and k == d and ((j == e and l != c) or (l == c and j != e)))
                                or (i == b and l == e and ((j == d and k != c) or (k == c and j != d)))
                                or (j == c and k == d and ((i == e and l != b) or (l == b and i != e)))
                                or (j == c and l == e and ((i == d and k != b) or (k == b and i != d)))
                                or (k == d and l == e and ((i == c and j != b) or (j == b and i != c)))):
                                pass
                            else:
                                if a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                    count -= 1
                                    a[i][j][k][l] = 0
                        elif strike == 2 and ball == 2:
                            if ((i == b and j == c and k == e and l == d) or (i == b and k == d and  j == e and l == c)
                                or (i == b and l == e and j == d and k == c) or (j == c and k == d and i == e and l == b)
                                or (j == c and l == e and i == d and k == b) or (k == d and l == e and i == c and j == b)):
                                pass
                            else:
                                if a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                    count -= 1
                                    a[i][j][k][l] = 0
                        elif strike == 1 and ball == 0:
                            if (((i == b) and (j != c and j != d and j != e and k != c and k != d and k != e and l != c and l != d and l != e))
                                or ((j == c) and (i != b and i != d and i != e and k != b and k != d and k != e and l != b and l != d and l != e))
                                or ((k == d) and (i != b and i != c and i != e and j != b and j != c and j != e and l != b and l != c and l != e))
                                or ((l == e) and (i != b and i != c and i != d and j != b and j != c and j != d and  k != b and k != c and k != d))):
                                pass
                            else:
                                if a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                    count -= 1
                                    a[i][j][k][l] = 0
                        elif strike == 1 and ball == 1:
                            if ((i == b and (j == d or j == e or k == c or k == e or l == c or l == d) and ((k != c and k != d and k != e and l != c and l != d and l != e) or (j != c and j != d and j != e and l != c and l != d and l != e) or (j != c and j != d and j != e and k != c and k != d and k != e)))
                                or (j == c and (i == d or i == e or k == b or k == e or l == b or l == d) and ((i != b and i != d and i != e and k != b and k != d and k != e) or (i != b and i != d and i != e and l != b and l != d and l != e) or (k != b and k != d and k != e and l != b and l != d and l != e)))
                                or (k == d and (i == c or i == e or j == b or j == e or l == b or l == c) and ((i != b and i != c and i != e and j != b and j != c and j != e) or (i != b and i != c and i != e and l != b and l != c and l != e) or (j != b and j != c and j != e and l != b and l != c and l != e)))
                                or (l == e and (i == c or i == d or j == b or j == d or k == b or k == c) and ((i != b and i != c and i != d and j != b and j != c and j != d) or (i != b and i != c and i != d and k != b and k != c and k != d) or (j != b and j != c and j != d and k != b and k != c and k != d)))):
                                pass
                            else:
                                if a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                    count -= 1
                                    a[i][j][k][l] = 0
                        elif strike == 1 and ball == 2:
                            if ((i == b and (((j == d or j == e) and (k == c or k == e)) or ((j == d or j == e) and (l == c or l == d)) or ((k == c or k == e) and (l == c or l == d))) and ((j != c and j != d and j != e) or (k != c and k != d and k != e) or (l != c and l != d and l != e)))
                                or (j == c and (((i == d or i == e) and (k == b or k == e)) or ((i == d or i == e) and (l == b or l == d)) or ((k == b or k == e) and (l == b or l == d))) and ((i != b and i != d and i != e) or (k != b and k != d and k != e) or (l != b and l != d and l != e)))
                                or (k == d and (((i == c or i == e) and (j == b or j == e)) or ((i == c or i == e) and (l == b or l == c)) or ((j == b or j == e) and (l == b or l == c))) and ((i != b and i != c and i != e) or (j != b and j != c and j != e) or (l != b and l != c and l != e)))
                                or (l == e and (((i == c or i == d) and (j == b or j == d)) or ((i == c or i == d) and (k == b or k == c)) or ((j == b or j == d) and (k == b or k == c))) and ((i != b and i != c and i != d) or (j != b and j != c and j != d) or (k != b and k != c and k != d)))):
                                pass
                            else:
                                if a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                    count -= 1
                                    a[i][j][k][l] = 0
                        elif strike == 1 and ball == 3:
                            if ((i == b and ((j == d or j == e) and (k == c or k == e) and (l == c or l == d)))
                                or (j == c and (i == d or i == e) and (k == b or k == e) and (l == b or l == d))
                                or (k == d and ((j == b or j == e) and (i == c or i == e) and (l == b or l == c)))
                                or (l == e and ((j == b or j == d) and (k == b or k == c) and (i == c or i == d)))):
                                pass
                            else:
                                if a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                    count -= 1
                                    a[i][j][k][l] = 0
                        elif strike == 0 and ball == 0:
                            if ((i != b and i != c and i != d and i != e) and (j != b and j != c and j != d and j != e) and (k != b and k != c and k != d and k != e) and (l != b and l != c and l != d and l != e)):
                                pass
                            elif a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                count -= 1
                                a[i][j][k][l] = 0
                        elif strike == 0 and ball == 1:
                            if (((i == c or i == d or i == e) and (j != b and j != c and j != d and j != e and k != b and k != c and k != d and k != e and l != b and l != c and l != d and l != e))
                                or ((j == b or j == d or j == e) and (i != b and i != c and i != d and i != e and k != b and k != c and k != d and k != e and l != b and l != c and l != d and l != e))
                                or ((k == b or k == c or k == e) and (j != b and j != c and j != d and j != e and i != b and i != c and i != d and i != e and l != b and l != c and l != d and l != e))
                                or ((l == b or l == c or l == d) and (j != b and j != c and j != d and j != e and k != b and k != c and k != d and k != e and i != b and i != c and i != d and i != e))
                                ):
                                pass
                            elif a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                count -= 1
                                a[i][j][k][l] = 0
                        elif strike == 0 and ball == 2:
                            if (((i == c or i == d or i == e) and (j == b or j == d or j == e) and (k != b and k != c and k != d and k != e) and (l != b and l != c and l != d and l != e)) or ((i == c or i == d or i == e) and (k == b or k == c or k == e) and (j != b and j != c and j != d and j != e) and (l != b and l != c and l != d and l != e))
                                or ((i == c or i == d or i == e) and (l == b or l == c or l == d) and (k != b and k != c and k != d and k != e) and (j != b and j != c and j != d and j != e)) or ((j == b or j == d or j == e) and (k == b or k == c or k == e) and (i != b and i != c and i != d and i != e) and (l != b and l != c and l != d and l != e))
                                or ((j == b or j == d or j == e) and (l == b or l == c or l == d) and (i != b and i != c and i != d and i != e) and (k != b and k != c and k != d and k != e)) or ((k == b or k == c or k == e) and (l == b or l == c or l == d) and (i != b and i != c and i != d and i != e) and (j != b and j != c and j != d and j != e))):
                                pass
                            elif a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                count -= 1
                                a[i][j][k][l] = 0
                        elif strike == 0 and ball == 3:
                            if (((i == c or i == d or i == e) and (j == b or j == d or j == e) and (k == b or k == c or k == e) and (l != b and l != c and l != d and l != e))
                                or ((l == b or l == c or l == d) and (j == b or j == d or j == e) and (k == b or k == c or k == e) and (i != b and i != c and i != d and i != e))
                                or ((i == c or i == d or i == e) and (l == b or l == c or l == d) and (k == b or k == c or k == e) and (j != b and j != c and j != d and j != e))
                                or ((i == c or i == d or i == e) and (j == b or j == d or j == e) and (l == b or l == c or l == d) and (k != b and k != c and k != d and k != e))):
                                pass
                            elif a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                count -= 1
                                a[i][j][k][l] = 0
                        elif strike == 0 and ball == 4:
                            if (i == c or i == d or i == e) and (j == b or j == d or j == e) and (k == b or k == c or k == e) and (l == b or l == c or l == d):
                                pass
                            elif a[i][j][k][l] != -1 and a[i][j][k][l] != 0:
                                count -= 1
                                a[i][j][k][l] = 0
                        else:
                            print("\nball and strike should be between 0 and 4\n")
                            return 0
        number += 1

#파이썬 실행
if __name__ == "__main__":
    main()
