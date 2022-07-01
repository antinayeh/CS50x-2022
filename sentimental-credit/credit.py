# TODO
from cs50 import get_int


h = get_int("Number: ")

sum = 0
counter = 0

while (h > 0):
    counter += 1
    if (h < 99 and h > 9):
        dd = h
    d = h % 10
    if (counter % 2 != 0):
        sum = sum + d
    else:
        double_d = d * 2
        if (double_d > 9):
            double_d = double_d % 10
            double_d += 1
        sum = sum + double_d
    h = int(h / 10)

if (sum % 10 != 0):
    print("INVALID\n")
else:
    if (d == 4 and (counter == 13 or counter == 16)):
        print("VISA\n")
    elif (d == 3 and (dd == 34 or dd == 37) and counter == 15):
        print("AMEX\n")
    elif (d == 5 and counter == 16):
        if (dd == 51 or dd == 52 or dd == 53 or dd == 54 or dd == 55):
            print("MASTERCARD\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")