'''
To create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set ,
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection,
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection,
e. Intersection of two sets ,
f. Union of two sets,
g. Difference between two sets,
h. Subset
'''


def createSet(mySet, name):
    n = int(input("Enter Number of Elements in Set" + name + ": "))
    for i in range(n):
        e = int(input("Enter the element to add to Set : "))
        mySet.add(e)
    print(mySet)
    print()

# insert an element to Set


def insertElement(mySet):
    e = int(input("Enter the Number to add to set : "))
    mySet.add(e)
    print(mySet)

# Remove an element from Set


def removeElement(mySet):
    e = int(input("Enter the Number to remove fom set : "))
    mySet.remove(e)
    print(mySet)

# search for element in Set


def searchElement(mySet):
    e = int(input("Enter the Number to search : "))
    if e in mySet:
        print("Element is present in the Set")
    else:
        print("Element is not present in the Set")

# get size of set


def getSize(mySet):
    print("Length of set is : ", end=" ")
    print(len(mySet))

# union of two set using python function


def union(setA, setB):
    setC = setA.union(setB)
    print("Union of two set A & B is : ", setC)


def intersection(setA, setB):
    # Intersection of two set using python function
    setC = setA.intersection(setB)
    print("Intersection of set A & B is : ", setC)

# Difference of two set using python


def difference(setA, setB):
    setC = setA.difference(setB)
    print("Difference of set A & B is : ", setC)

# Checking of subset using python


def isSubset(setA, setB):
    print("SetA is subset of SetB : ", setA.issubset(setB))


def menu():
    flag = 'y'
    while flag == 'y':
        print("**************Welcome to the program!!**************")
        print("1. Add new Element ")
        print("2. Remove element  ")
        print("3. Search for an element ")
        print("4. Return the size of set")
        print("5. Intersection of two set ")
        print("6. Union of two set ")
        print("7. Difference of two set ")
        print("8. Check for subset condition ")
        print()
        ch = int(input("Enter your choice : "))
        match ch:
            case 1:
                insertElement(mySet)
            case 2:
                removeElement(mySet)
            case 3:
                searchElement(mySet)
            case 4:
                getSize(mySet)
            case 5:
                intersection(setA, setB)
            case 6:
                union(setA, setB)
            case 7:
                difference(setA, setB)
            case 8:
                isSubset(setA, setB)
        flag = (input("Do you want to continue y/n?? : "))


setA = set()
setB = set()
createSet(setA, "A")
createSet(setB, "B")
setChoice = input("Which set do you want to perform the operatios on? : ")
if setChoice == 'A' or setChoice == 'a':
    mySet = setA
elif setChoice == 'B' or setChoice == 'b':
    mySet = setB
else:
    mySet = setA

menu()
