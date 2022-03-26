"""Python script to generate test cases for binary search algorithm"""

import argparse
import random

parser = argparse.ArgumentParser()
parser.add_argument("-t", "--testcases", help="Number of test cases to generate", type=int, default=5)
parser.add_argument("-l", "--minLength", help="Min length of array to generate", type=int, default=10)
parser.add_argument("-L", "--maxLength", help="Max length of array to generate", type=int, default=25)
parser.add_argument("-m", "--min", help="Min array element value", type=int, default=0)
parser.add_argument("-M", "--max", help="Max array element value", type=int, default=100)


if __name__ == "__main__":
    args = parser.parse_args()
    print(args.testcases)
    for _ in range(args.testcases):
        array = []
        arrayLength = random.randint(args.minLength, args.maxLength)
        for _ in range(arrayLength):
            array.append(random.randint(args.min, args.max))
        target = array[random.randint(0, len(array) - 1)]
        array.sort()

        print(arrayLength, target)
        for i in range(len(array)):
            print(array[i], end=" ")
        print()
