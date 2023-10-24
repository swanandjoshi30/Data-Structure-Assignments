def linear_search(arr,ele):
    i=0
    while i<len(arr):
        if arr[i]==ele:
            return i
        i = i + 1
    return -1

arr=[]
n=int(input("Enter no. of students who attended the training program : "))

def read():
  for i in range(n):
    roll_no=int(input("Enter roll number of students: "))
    arr.append(roll_no)

read()

ele=int(input("Enter the roll no. you want to search : "))
index = linear_search(arr, ele)

if index != -1:
    print(f"Found the Roll No at index {index}")
else:
    print("Roll No. not found.")
