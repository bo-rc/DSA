# import modules here
from collections import deque as DQ
from itertools import accumulate

class BoxFilter:
    def __init__(self, size=5):
        self._deque = DQ(maxlen=size)

    def update(self, val):
        self._deque.append(val)
        sum = max(accumulate(self._deque))
        return sum / len(self._deque)


if __name__ == "__main__":
    test_array = [1,3,4,5,6,12,6,15,6,9,22,23,34,43,13,54]
    bf = BoxFilter(5)
    for x in test_array:
        print(bf.update(x))
