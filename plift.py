from math import*

pass_fail_graph = []

lift1 = (float(input("Max Lift: ")) * .8000)
lift_graph1 = [lift1]
lift_graph2 = []

yN_counter = []

def pass_fail():
    passFail = (input("Did you get it? Y/N "))
    if "Y" in passFail:
        yN_counter.append("Yes")
    else:
        yN_counter.append("No")


def L1():
    print(lift1)
    while "No" not in yN_counter:
        pass_fail()
        user = (float(input("Actual Lift: ")))
        lift_graph2.append(user)
        lift_graph2.append(float(lift_graph2[-1]) + 5)
        print(lift_graph2)
    else:
        print("Time for a new program!")