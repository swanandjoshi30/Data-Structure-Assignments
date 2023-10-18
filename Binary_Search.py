arr = []
n = int(input("Enter the number of students: "))

def read():
    for i in range(n):
        roll_no = int(input("Enter the Roll No. of student: ")) 
        arr.append(roll_no)
      
read()

def bubble_sort():
    for i in range(0, n-1):
        for j in range(n-1-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    print(arr)

bubble_sort()
      
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
        
ele = int(input("Enter Roll No. you want to check: "))        
result = binary_search(arr, 0, len(arr)-1, ele)
 
if result != -1:
    print("Roll No. is present at index", str(result))
else:
    print("Roll No. is not present in array")
