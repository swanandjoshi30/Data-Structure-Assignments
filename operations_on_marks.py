def calculate_average(marks):
    total_marks = sum(marks)
    num_students = len(marks)
    
    if num_students == 0:
        return 0  # To avoid division by zero if there are no students
    
    average = total_marks / num_students
    return average

def find_highest_lowest(marks):
    if not marks:
        return None, None  # Return None for both highest and lowest if no marks are provided
    
    highest = max(marks)
    lowest = min(marks)
    return highest, lowest

def count_absent_students(marks):
    return marks.count(0)  # Assuming absent students have a score of 0

def display_highest_frequency(marks):
    if not marks:
        return None
    
    frequency_dict = {}
    
    for mark in marks:
        if mark in frequency_dict:
            frequency_dict[mark] += 1
        else:
            frequency_dict[mark] = 1
    
    max_frequency = max(frequency_dict.values())
    most_frequent_marks = [key for key, value in frequency_dict.items() if value == max_frequency]
    return most_frequent_marks

# Input the number of students
num_students = int(input("Enter the number of students: "))
marks = []

# Input marks for each student
for i in range(num_students):
    mark = int(input("Enter the marks for student {}: ".format(i + 1)))
    marks.append(mark)

flag = 1

while flag == 1:
    print("\nOptions:")
    print("1. Calculate average marks")
    print("2. Find highest and lowest score")
    print("3. Count absent students")
    print("4. Display marks with the highest frequency")

    ch = int(input("Enter your choice (1-4): "))
    
    if ch == 1:
        average_score = calculate_average(marks)
        print("Average marks:", average_score)
        
    elif ch == 2:
        highest, lowest = find_highest_lowest(marks)
        print("Highest score:", highest)
        print("Lowest score:", lowest)
        
    elif ch == 3:
        absent_students = count_absent_students(marks)
        print("Number of absent students:", absent_students)
        
    elif ch == 4:
        most_frequent_marks = display_highest_frequency(marks)
        print("Marks with the highest frequency:", most_frequent_marks)
        
    else:
        print("Invalid choice. Please enter a number between 1 and 4.")

    a = input("Do you want to continue (yes/no): ")
    
    if a.lower() == "yes":
        flag = 1
    elif a.lower() == "no":
        flag = 0
        print("Thanks for using this program!")
    else:
        print("Invalid input. Exiting program.")
        flag = 0
