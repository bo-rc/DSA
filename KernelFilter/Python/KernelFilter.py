# import modules here
from collections import deque as DQ
from itertools import accumulate
import numpy as np

class KernelFilter:
    def __init__(self, kernel=np.array([0.2,0.2,0.2,0.2,0.2])):
        self._deque = DQ(np.zeros(len(kernel)), maxlen=len(kernel))
        self._kernel = kernel

    def update(self, val):
        self._deque.append(val)
        return np.dot(self._kernel, np.array(self._deque))


if __name__ == "__main__":
    test_array = [1,3,4,5,6,12,6,15,6,9,22,23,34,43,13,54]
    bf = KernelFilter()
    for x in test_array:
        print(bf.update(x))
