# import modules here
from collections import deque as DQ
import numpy as np

class KernelFilter:
    def __init__(self, kernel=np.array([0.1, 0.25, 0.3, 0.25, 0.1])):
        self._deque = DQ(np.zeros(len(kernel)), maxlen=len(kernel))
        self._kernel = kernel

    def update(self, val):
        self._deque.append(val)
        return np.dot(self._kernel, np.array(self._deque))


if __name__ == "__main__":
    test_array = [1,1,1,1,1,1,1]
    k = KernelFilter()
    for x in test_array:
        print(k.update(x), end=",")

