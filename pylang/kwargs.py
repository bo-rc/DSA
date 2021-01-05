def func(param_0, param_1, param_2=[1,2,3], *args):
    print("positional arg 0 is: ", param_0)
    print("positional arg 1 is: ", param_1)
    print("arg with default is:", param_2)
    print(args)


a = "test"
b = 1024
c = 3.14
mydictionary = {"val1": 10, "val2": 12}
myTuple = (1,3,4,5)
func(a,b,c, *myTuple, 6,7) # 1024, 3.14, test



