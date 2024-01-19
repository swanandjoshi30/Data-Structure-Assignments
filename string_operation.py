#Write a Python program to compute following operations on String:
#a) To display word with the longest length
#b) To determines the frequency of occurrence of particular character in the string
#c) To check whether given string is palindrome or not 
#d) To display index of first appearance of the substring
#e) To count the occurrences of each word in a given string


sentence = input("Enter sentence: ")

# Finding the longest word
longest = max(sentence.split(), key=len)
print("Longest word is: ", longest)
print("And its length is: ", len(longest))

# Count of all characters in the sentence
all_freq = {}
for char in sentence:
    if char in all_freq:
        all_freq[char] += 1
    else:
        all_freq[char] = 1
print("Count of all characters in the sentence is:\n" + str(all_freq))

# Palindrome check
text = input("Enter text to check for palindrome: ")
print("Given text is " + text)
rev = ''.join(reversed(text))  # Convert reversed iterator to a string
if text == rev:
    print("It's a palindrome")
else:
    print("It's not a palindrome")

# Substring search
sub_str1 = str(input("Enter word: "))
print("Index of the first appearance of the substring", sub_str1, "is:", sentence.find(sub_str1))
if sub_str1 in sentence:
    print("Substring found")
else:
    print("Substring not found")

# Frequency of each word in the sentence
print("Following are the counts of the frequency of each word in the given string")

def freq(sentence):
    sentence = sentence.split()
    unique_words = set(sentence)
    for word in unique_words:
        print('Count of frequency of', word, 'is:', sentence.count(word))

def main():
    freq(sentence)

main()
