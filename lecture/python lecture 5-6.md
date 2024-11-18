## Different Types of Loops, List and Dictionary

### "for" Loops
A `for` loop is used for iterating over a sequence (like a list, tuple, dictionary, set, or string).

**Syntax:**
```python
for element in sequence:
    # code block to execute
```

**Example:**
```python
# Iterate over a list
numbers = [1, 2, 3, 4, 5]
for number in numbers:
    print(number)
```

**Practice Problem:**

<details>
<summary>Write a `for` loop to print the squares of numbers from 1 to 10.</summary>

```python
for number in range(1, 11):
    print(number ** 2)

```

</details>

---

### "while" Loops
A `while` loop repeatedly executes a block of code as long as a condition is true.

**Syntax:**
```python
while condition:
    # code block to execute
```

**Example:**
```python
n = 10
sum_of_numbers = 0
counter = 1
while counter <= n:
    sum_of_numbers += counter
    counter += 1
print(sum_of_numbers)
```

**Practice Problem:**
<details>
<summary>Write a `while` loop to print the first 10 even numbers.</summary>

```python
count = 1
even_number = 2

while count <= 10:
    print(even_number)
    even_number += 2
    count += 1

```

</details>

<details>
<summary>Write a `while` loop that calculates the factorial of a given number `n`.</summary>

```python

n = 5  # You can change this value to any positive integer
factorial = 1
i = 1

while i <= n:
    factorial *= i
    i += 1

print(f"The factorial of {n} is {factorial}")

```

</details>

---

## Advanced Data Storage Techniques in Python

### List
Indexing allows you to access individual elements in a list or dictionary.

```python
fruits = ['apple', 'banana', 'cherry']
print(fruits[0])  # Output: apple
```
#### List comprehensions
List comprehensions provide a concise way to create lists in Python. They are often more readable and faster than traditional for-loops.
**Basic Syntax**
The basic syntax of a list comprehension is:
```python
[expression for item in iterable if condition]
```
- **expression**: The value to add to the list.
- **item**: The current item from the iterable.
- **iterable**: A collection of items (like a list or range).
- **condition** (optional): A filter that only includes items that meet the condition.


1. **Simple List Comprehension:**
   Create a list of squares of numbers from 1 to 10.
   ```python
   squares = [x**2 for x in range(1, 11)]
   print(squares)  # Output: [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
   ```

2. **List Comprehension with Condition:**
   Create a list of even numbers from 1 to 10.
   ```python
   evens = [x for x in range(1, 11) if x % 2 == 0]
   print(evens)  # Output: [2, 4, 6, 8, 10]
   ```

3. **Nested List Comprehension:**
   Create a list of tuples (x, y) where x is from 1 to 3 and y is from 1 to 2.
   ```python
   pairs = [(x, y) for x in range(1, 4) for y in range(1, 3)]
   print(pairs)  # Output: [(1, 1), (1, 2), (2, 1), (2, 2), (3, 1), (3, 2)]
   ```

**Practice Problem**

<details>
<summary> Try creating a list of the first 10 multiples of 3 using a list comprehension. </summary>

```python

multiples_of_3 = [3 * i for i in range(1, 11)]
print(multiples_of_3)

```

</details>

---

### Dictionary
```python
student = {'name': 'John', 'age': 25}
print(student['name'])  # Output: John
```
#### Dictionary comprehensions
Dictionary comprehensions in Python provide a concise way to create dictionaries. They are similar to list comprehensions but are used to generate dictionary key-value pairs.

#### Basic Syntax
The basic syntax of a dictionary comprehension is:
```python
{key: value for item in iterable if condition}
```
- **key**: The key for the dictionary entry.
- **value**: The value for the dictionary entry.
- **item**: The current item from the iterable.
- **iterable**: A collection of items (like a list or range).
- **condition** (optional): A filter that only includes items that meet the condition.

#### Examples

1. **Simple Dictionary Comprehension:**
   Create a dictionary where the keys are numbers from 1 to 5 and the values are their squares.
   ```python
   squares = {x: x**2 for x in range(1, 6)}
   print(squares)  # Output: {1: 1, 2: 4, 3: 9, 4: 16, 5: 25}
   ```

2. **Dictionary Comprehension with Condition:**
   Create a dictionary of even numbers from 1 to 10 and their squares.
   ```python
   even_squares = {x: x**2 for x in range(1, 11) if x % 2 == 0}
   print(even_squares)  # Output: {2: 4, 4: 16, 6: 36, 8: 64, 10: 100}
   ```

3. **Using a Dictionary Comprehension to Transform Data:**
   Suppose you have a dictionary of student names and their grades, and you want to create a new dictionary with the grades converted to a 4.0 scale.
   ```python
   grades = {'Alice': 85, 'Bob': 92, 'Charlie': 78}
   scaled_grades = {student: grade / 25 for student, grade in grades.items()}
   print(scaled_grades)  # Output: {'Alice': 3.4, 'Bob': 3.68, 'Charlie': 3.12}
   ```

**Practice Problem based on dictionary comprehension**

<details>
<summary>Try creating a dictionary where the keys are the first 5 letters of the alphabet and the values are their positions in the alphabet (e.g., {'a': 1, 'b': 2, ...}). </summary>

```python

# Create the dictionary
alphabet_positions = {chr(97 + i): i + 1 for i in range(5)}

# Print the dictionary
print(alphabet_positions)

```

</details>

---

#### Create, Update, and Delete List and Dictionary Elements

**Creating Lists and Dictionaries:**
```python
# List
fruits = ['apple', 'banana', 'cherry']

# Dictionary
student = {'name': 'John', 'age': 25}
```

**Updating Elements:**
```python
# List
fruits[1] = 'blueberry'

# Dictionary
student['age'] = 26
```

**Deleting Elements:**
```python
# List
del fruits[2]

# Dictionary
del student['age']
```
**Problem:**

<details>
<summary>Create a list of 5 numbers. Write a function to double the value of each number and return the updated list.</summary>

```python
# Create a list of 5 numbers
numbers = [1, 2, 3, 4, 5]

# Function to double the values
def double_values(numbers_list):
    doubled_list = [number * 2 for number in numbers_list]
    return doubled_list

# Call the function and print the updated list
doubled_numbers = double_values(numbers)
print(doubled_numbers)

```

</details>

<details>
<summary>Create a dictionary with information about a book (title, author, year). Add a key for "publisher," then delete the "year" key.</summary>

```python

# Create a dictionary with book information
book = {
    'title': 'To Kill a Mockingbird',
    'author': 'Harper Lee',
    'year': 1960
}

# Add a key for "publisher"
book['publisher'] = 'J.B. Lippincott & Co.'

# Delete the "year" key
del book['year']

# Print the updated dictionary
print(book)

```

</details>

### Perform Basic Operations on List and Dictionary Elements

**List Operations:**
```python
# Append an element
fruits.append('orange')

# Remove an element
fruits.remove('banana')

# Length of the list
print(len(fruits))
```

**Dictionary Operations:**
```python
# Add a new key-value pair
student['grade'] = 'A'

# Get all keys
print(student.keys())

# Get all values
print(student.values())
```



**Problem:**


<details>
<summary> Given a list of strings, write a program to count the frequency of each string. </summary>

```python

# Sample list of strings
strings = ['apple', 'banana', 'apple', 'orange', 'banana', 'apple']

# Function to count the frequency of each string
def count_frequencies(strings_list):
    frequency_dict = {}
    for string in strings_list:
        if string in frequency_dict:
            frequency_dict[string] += 1
        else:
            frequency_dict[string] = 1
    return frequency_dict

# Call the function and print the result
frequencies = count_frequencies(strings)
print(frequencies)

```

</details>

<details>
<summary> Given a dictionary of student names and scores, write a program to calculate the average score and identify the top scorer. </summary>

```python

# Sample dictionary of student names and scores
students_scores = {
    'Alice': 85,
    'Bob': 92,
    'Charlie': 78,
    'David': 90,
    'Eva': 88
}

# Function to calculate the average score and identify the top scorer
def analyze_scores(scores_dict):
    total_score = 0
    top_scorer = None
    highest_score = 0
    
    for student, score in scores_dict.items():
        total_score += score
        if score > highest_score:
            highest_score = score
            top_scorer = student
    
    average_score = total_score / len(scores_dict)
    
    return average_score, top_scorer, highest_score

# Call the function and print the results
average, top_student, top_score = analyze_scores(students_scores)
print(f"Average Score: {average}")
print(f"Top Scorer: {top_student} with a score of {top_score}")

```

</details>




### **Exercises for Practice**
1. Write a `for` loop to generate the first 10 terms of the Fibonacci sequence.
2. Write a `while` loop that keeps asking the user for input until they type "exit."
3. Create a dictionary of employee names and salaries. Increase the salary of every employee by 10% and print the updated dictionary.
4. Write a function to remove duplicate elements from a list and return the cleaned list.
5. Create a list of dictionaries, where each dictionary contains information about a student (name, grade, age). Use a `for` loop to calculate and print the average age of students.