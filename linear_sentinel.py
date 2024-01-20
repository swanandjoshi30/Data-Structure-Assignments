def linear_search(roll_numbers, target):
    # Linear search function
    for roll_number in roll_numbers:
        if roll_number == target:
            return True
    return False

def sentinel_search(roll_numbers, target):
    # Sentinel search function
    roll_numbers.append(target)
    i = 0
    while roll_numbers[i] != target:
        i += 1
    roll_numbers.pop()
    return i < len(roll_numbers)

def main():
    # Main function for user interaction
    n = int(input("Enter the number of students: "))
    roll_numbers = []

    # Loop to take roll number inputs
    for i in range(n):
        roll_number = int(input(f"Enter roll number for student {i + 1}: "))
        roll_numbers.append(roll_number)

    target_student = int(input("Enter the roll number to search: "))

    # Search
    linear_result = linear_search(roll_numbers, target_student)
    sentinel_result = sentinel_search(roll_numbers, target_student)

    # Display results
    print("\nRoll Numbers:", roll_numbers)
    print("Linear Search Result:", "Found" if linear_result else "Not Found")
    print("Sentinel Search Result:", "Found" if sentinel_result else "Not Found")

if __name__ == "__main__":
    main()
