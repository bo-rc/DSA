# Box Filter
This project is to implement a box filter in Python and C++.

Box filter is one the simplest but most widely-used smoothing algorithm. Basically, we determine the filtered values by taking an average of a surrounding neighbors of each value point. This algorithm is also called sliding-window (box) smoothing. In this project, there is only one parameter to initialize the filter: size, which says how many neighboring values we want to take into the averaging computation.

Inputs are real numbers: they can be integers or floats.

e.g. for this array: 
* `[1,3,4,5,6,12,6,15,6,9,22,23,34,43,13,54]`, after filtering with a box filter of size 5, it should be: 
* `[1.0, 2.0, 2.6666666666666665, 3.25, 3.8, 6.0, 6.6, 8.8, 9.0, 9.6, 11.6, 15.0, 18.8, 26.2, 27.0, 33.4]`

If we plot the original and the filtered values in a figure:

![simpleBoxFilter](files/boxfilter_simple.png)


Here is another example of a noisy sinusoidal curve using a boxfilter of size 10:

![simpleBoxFilter](files/box_filter_sin.png)

# Assignment
* write a python class `BoxFilter(size=5)`, which takes one argument to initialize the box filter size.
* write python test script to use your `BoxFilter` class and make some plots in python to show results.
* write a C++ class and tests.
* write `cmake` files for the C++ version, build and test it.
