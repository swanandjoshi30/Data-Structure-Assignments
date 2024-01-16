# Initialize an empty list to store roll numbers
arr = []

# Get the number of students from the user
n = int(input("Enter the number of students: "))

# Function to read roll numbers from the user and populate the list
def read():
    for i in range(n):
        roll_no = int(input("Enter the Roll No. of student: "))
        arr.append(roll_no)
        
# Call the read function to input roll numbers
read()

# Function to perform bubble sort on the list of roll numbers
def bubble_sort():
    for i in range(0, n-1):
        for j in range(n-1-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    print("Sorted Roll Numbers:", arr)

# Call the bubble_sort function
bubble_sort()

# Binary search function to find the index of a roll number in the sorted list
def binary_search(arr, low, high, ele):
    if high >= low:
        mid = (low + high) // 2
        
        if arr[mid] == ele:
            return mid
        elif arr[mid] > ele:
            return binary_search(arr, low, mid-1, ele)
        else:
            return binary_search(arr, mid+1, high, ele)
    else:
        return -1

# Linear search function to find the index of a roll number in the unsorted list
def linear_search(arr, ele):
    i = 0
    while i < len(arr):
        if arr[i] == ele:
            return i
        i = i + 1
    return -1

# Main menu loop
while True:
    print("****************** MENU *******************")
    print("1. Binary Search (Sorted List)")
    print("2. Linear Search (Unsorted List)")
    print("3. Exit")
    
    # Get user choice
    ch = int(input("Please enter your choice: "))
    
    # Binary Search option
    if ch == 1:
        ele = int(input("Enter the roll no. you want to search: "))
        index = binary_search(arr, 0, len(arr)-1, ele)
        
        if index != -1:
            print(f"Found the Roll No at index {index}")
        else:
            print("Roll No. not found.")
    
    # Linear Search option
    elif ch == 2:
        ele = int(input("Enter the roll no. you want to search: "))
        index = linear_search(arr, ele)
        
        if index != -1:
            print(f"Found the Roll No at index {index}")
        else:
            print("Roll No. not found.")
    
    # Exit option
    elif ch == 3:
        print("Exiting the program.")
        break
    
    # Invalid option
    else:
        print("Invalid choice. Please enter a valid option.")
