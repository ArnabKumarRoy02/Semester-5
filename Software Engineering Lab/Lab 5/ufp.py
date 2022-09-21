low = [3, 4, 3, 7, 5]
average = [4, 5, 4, 10, 7]
high = [6, 7, 6, 15, 10]

ei = int(input("Enter the value of EI: "))
print("\nPress 1 for low\nPress 2 for average\nPress 3 for high")
type1 = int(input("Enter the type of EI: "))

if type1 == 1:
    res1 = ei * low[0]
elif type1 == 2:
    res1 = ei * average[0]
else:
    res1 = ei * high[0]

eo = int(input("\nEnter the value of EO: "))
print("\nPress 1 for low\nPress 2 for average\nPress 3 for high")
type2 = int(input("Enter the type of EO: "))

if type2 == 1:
    res2 = eo * low[1]
elif type2 == 2:
    res2 = eo * average[1]
else:
    res2 = eo * high[1]

print("UFP = ", res1 + res2)