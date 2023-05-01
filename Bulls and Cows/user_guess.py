import sys
import os
import random
import time

def unique_digits(number) :
    digits = set()
    if number < 1000 :
        digits.add('0')
    for digit in str(number) :
        if digit in digits :
            return False
        digits.add(digit)
    return True

def compare_digits(guess_number, answer_number) :
    strike_number = 0
    ball_number = 0
    guess_list = [digit for digit in str(guess_number)]
    answer_list = [digit for digit in str(answer_number)]

    #strike 구하기
    for index in range(len(guess_list)) :
        if guess_list[index] == answer_list[index] :
            strike_number += 1

    #ball 구하기
    ball_number = len(list(set(guess_list) & set(answer_list))) - strike_number

    return strike_number, ball_number

def main():
    #시도횟수 
    number = 0
    
    #랜덤 4자리 수
    random.seed(time.time())
    while True :
        answer = random.randint(0, 10000)
        if unique_digits(answer) == True :
            break
    print(answer)

    while True:
        print(f"\n\t{number+1}번째, 추측한 수 입력")
        guess = int(input())
        strike, ball = compare_digits(guess, answer)
        if strike == 4 :
            print(f"\n\t{number+1}번째 시도에 성공!\n")
            os._exit(1)
        print(f"\n\tStrike = {strike}, Ball = {ball}\n")
        number += 1
        

#파이썬 실행
if __name__ == "__main__":
    main()
