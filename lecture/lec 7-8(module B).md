Propositional and predicate logic are fundamental concepts in formal logic used to represent and reason about statements.

---

### **1. Propositional Logic**
Also known as **sentential logic**, it deals with propositions (statements) that are either true or false.

#### **Key Features:**
- **Propositions:** Simple declarative statements with a truth value.
  - Examples:
    - "It is raining." (True or False)
    - "2 + 2 = 4." (True)
- **Logical Connectives:** Combine or modify propositions to form complex statements.
  - **AND ( ∧ ):** True if both statements are true.
    - Example: \( P ∧ Q \)
  - **OR ( ∨ ):** True if at least one statement is true.
    - Example: \( P ∨ Q \)
  - **NOT ( ¬ ):** True if the statement is false.
    - Example: \( ¬ P \)
  - **IMPLIES ( → ):** True unless the first statement is true and the second is false.
    - Example: \( P → Q \)
  - **EQUIVALENT ( ↔ ):** True if both statements have the same truth value.
    - Example: \( P ↔ Q \)

#### **Truth Tables:**
Used to determine the truth value of a compound proposition.
- Example:
    For \( P ∧ Q \):
    | P   | Q   | \( P ∧ Q \) |
    |-----|-----|----------------|
    | T   | T   | T              |
    | T   | F   | F              |
    | F   | T   | F              |
    | F   | F   | F              |

---

### **2. Predicate Logic**
Predicate logic (also called first-order logic) extends propositional logic by including **quantifiers** and predicates, enabling more expressive reasoning.

#### **Key Features:**
- **Predicates:** Statements involving variables.
  - Example: P(x): x is a prime number.
- **Quantifiers:** Specify the scope of a variable.
  - **Universal Quantifier ( ∀ ):** "For all."
    - Example: ∀x, P(x): "∀x, P(x) is true."
  - **Existential Quantifier ( ∃ ):** "There exists."
    - Example: ∃x, P(x): "There exists an x such that P(x)  is true."

#### **Domains and Variables:**
- The truth of a predicate depends on the domain (set of possible values for variables).
  - Example: If P(x): x > 0 and domain = { -2, -1, 0, 1, 2 }, then:
    - ∃x, P(x): True (for \( x = 1, 2 \)).
    - ∀x, P(x): False (because \( -2, -1, 0 \) are not \( > 0 \)).

#### **Logical Statements:**
- Combine predicates using logical connectives and quantifiers.
  - Example: \( ∀ x \, (P(x) → Q(x)) \): "For all \( x \), if \( P(x) \) is true, then \( Q(x) \) is true."

---

### **Comparison:**

| Aspect               | Propositional Logic                  | Predicate Logic                       |
|----------------------|--------------------------------------|---------------------------------------|
| **Scope**            | Deals with whole statements.         | Deals with statements involving variables. |
| **Connectives**      | AND, OR, NOT, IMPLIES, etc.          | Same as propositional logic.          |
| **Quantifiers**      | Not used.                            | Uses ∀ (all) and ∃ (exists).          |
| **Expressiveness**   | Less expressive (e.g., "It is raining"). | More expressive (e.g., "Some cities have rain"). |

---

### **Applications:**
- **Propositional Logic:** Circuit design, simple logical systems, truth tables.
- **Predicate Logic:** Database queries, artificial intelligence, theorem proving.

Here are examples demonstrating **propositional logic** and **predicate logic** concepts using Python:

---

### **1. Propositional Logic in Python**

We'll use simple Boolean operations to represent logical connectives.

```python
# Example propositions
P = True  # "It is raining."
Q = False  # "It is snowing."

# Logical connectives
and_result = P and Q  # AND (∧)
or_result = P or Q    # OR (∨)
not_result = not P    # NOT (¬)
implies_result = not P or Q  # IMPLIES (P → Q) is equivalent to (¬P ∨ Q)
equivalent_result = P == Q   # EQUIVALENT (P ↔ Q)

print("P AND Q:", and_result)        # False
print("P OR Q:", or_result)         # True
print("NOT P:", not_result)         # False
print("P → Q:", implies_result)     # False
print("P ↔ Q:", equivalent_result)  # False
```

---

### **2. Predicate Logic in Python**

For predicate logic, we use functions to represent predicates and loops or comprehensions for quantifiers.

> [!NOTE]
> `any` looks for at least one true instance.
> `all` requires every instance to be true.

#### **Universal Quantifier ( ∀ ):**
```python
# Define the domain and predicate
domain = [1, 2, 3, 4, 5]
predicate = lambda x: x > 0  # "x > 0"

# Universal quantifier: ∀x P(x)
universal = all(predicate(x) for x in domain)
print("∀x (x > 0):", universal)  # True (all numbers in the domain are > 0)
```

#### **Existential Quantifier ( ∃ ):**
```python
# Existential quantifier: ∃x P(x)
predicate = lambda x: x % 2 == 0  # "x is even"
existential = any(predicate(x) for x in domain)
print("∃x (x is even):", existential)  # True (2, 4 are even)
```

#### **Combining Predicates with Logical Connectives:**
```python
# Multiple predicates
P = lambda x: x > 2  # "x > 2"
Q = lambda x: x % 2 == 0  # "x is even"

# ∀x (P(x) → Q(x))  --> True if for all x, if P(x) is true, then Q(x) is true
implies_all = all(not P(x) or Q(x) for x in domain)
print("∀x (x > 2 → x is even):", implies_all)  # False (e.g., x = 3 is > 2 but not even)
```

---

### **3. Truth Table Generator**
A reusable function to generate truth tables for propositional logic.



```python
from itertools import product

def truth_table(variables, expression):
    """Generate a truth table."""
    headers = variables + [expression.__name__]
    print("\t".join(headers))
    print("-" * (len(headers) * 8))
    
    for values in product([True, False], repeat=len(variables)):
        env = dict(zip(variables, values)) # {'P': True, 'Q': False}.
        result = expression(**env) # env = {'P': True, 'Q': False}, then expression(**env) is equivalent to calling expression(P=True, Q=False).
        print("\t".join(str(env[var]) for var in variables), "\t", result)

# Example usage
def expr(P, Q):
    return (not P or Q)  # P → Q

truth_table(['P', 'Q'], expr)
```
<details>
<summary><h2><i>([True, False], repeat=len(variables))</i></h2></summary>
This code is used to generate all possible combinations of truth values for the given variables.:

### `([True, False], repeat=len(variables))`
- **`[True, False]`**: This is a list containing the two possible truth values, `True` and `False`.
- **`repeat=len(variables)`**: This specifies how many times the list `[True, False]` should be repeated. The `len(variables)` part calculates the number of variables you have.

### Purpose
When you use this in the `product` function from the `itertools` module, it generates the Cartesian product of `[True, False]` repeated as many times as there are variables. This means it will create all possible combinations of `True` and `False` for the given number of variables.

### Example
If you have two variables, `P` and `Q`, `product([True, False], repeat=2)` will generate:
- `(True, True)`
- `(True, False)`
- `(False, True)`
- `(False, False)`

These combinations represent all possible truth values for the variables `P` and `Q`.

### Code Context
In your `truth_table` function, this line:
```python
for values in product([True, False], repeat=len(variables)):
```
iterates over each combination of truth values, allowing you to evaluate the logical expression for each combination and print the results in the truth table.
</details>


Output for \( P → Q \):
```
P	Q	expr
--------------------
True	True	True
True	False	False
False	True	True
False	False	True
```

---
### **Planning**  
Planning in artificial intelligence involves generating a sequence of actions to achieve a specific goal from a given initial state, considering constraints.

#### Components of a Planning Problem:
1. **Initial State (\( S_0 \)):** The starting point of the system.
2. **Goal State (\( G \)):** A description of the desired outcome.
3. **Actions:** Possible transformations that can move the system from one state to another.
   - Each action has:
     - **Preconditions:** Conditions that must be true for the action to be executed.
     - **Effects:** Changes to the state caused by the action.

#### Planning Approaches:
1. **State-Space Planning:** Searches through all possible states to find a sequence that achieves the goal.
   - Forward Planning: Starts at \( S_0 \) and progresses towards \( G \).
   - Backward Planning: Starts at \( G \) and works backward to \( S_0 \).

2. **Partial-Order Planning:** Constructs plans with unordered steps, resolving conflicts dynamically as needed.

3. **Hierarchical Task Network (HTN):** Breaks tasks into subtasks for more structured planning.

4. **Graph-Based Planning:** Uses structures like planning graphs for efficient reasoning (e.g., GraphPlan).

#### Example:
- Initial State: Robot is at location \( A \).
- Goal: Robot is at location \( C \).
- Actions:
  1. Move from \( A \) to \( B \) (Precondition: Robot at \( A \)).
  2. Move from \( B \) to \( C \) (Precondition: Robot at \( B \)).
- Plan: Move \( A → B → C \). 

Python provides libraries like **PDDL (Planning Domain Definition Language) libraries** and frameworks such as **Pyomo** and **AI-specific libraries** like **`pyplanning`** to implement planning problems. A common and simple example involves coding a **state-space planner** using basic Python.

Here’s a Python example to solve a **basic robot path-planning problem**:

---

### **Example: Robot Moving Between Locations**

#### Problem Description:
The robot starts at **Location A** and must move to **Location C** by following specific actions.

---

### **Code Implementation:**

```python
# Define the initial state, goal state, and actions
initial_state = "A"
goal_state = "C"

# Define actions with their preconditions and effects
actions = {
    "Move_A_to_B": {"precondition": "A", "effect": "B"},
    "Move_B_to_C": {"precondition": "B", "effect": "C"},
    "Move_A_to_C": {"precondition": "A", "effect": "C"},  # Optional shortcut
}

# Planner function to find the sequence of actions
def plan(initial_state, goal_state, actions):
    current_state = initial_state
    plan_sequence = []
    
    # Iteratively find actions to achieve the goal
    while current_state != goal_state:
        for action, details in actions.items():
            if details["precondition"] == current_state:
                plan_sequence.append(action)  # Add action to plan
                current_state = details["effect"]  # Update current state
                break
        else:
            print("No valid plan found!")
            return None
    
    return plan_sequence

# Call the planner
plan_sequence = plan(initial_state, goal_state, actions)

# Print the plan
if plan_sequence:
    print("Plan to achieve the goal:")
    for step in plan_sequence:
        print(f"- {step}")
else:
    print("No plan could be generated.")
```

---

### **Output**:
If you run the above code, it will output:
```
Plan to achieve the goal:
- Move_A_to_B
- Move_B_to_C
```

---

### **How it Works**:
1. **Initial State**: The robot starts at location `A`.
2. **Goal State**: The robot needs to reach location `C`.
3. **Actions**: Each action has:
   - A precondition (where the robot must currently be to perform the action).
   - An effect (where the robot will be after performing the action).
4. **Planner**: Iteratively checks the actions whose preconditions match the current state, applies them, and updates the state until the goal is reached.


---

The **"Fame problem"** (or **celebrity problem**) is a common coding and logic problem that asks to determine if there is a "celebrity" in a group of people. A **celebrity** is defined as:

1. Everyone in the group knows the celebrity.
2. The celebrity knows no one in the group.

---

### **Problem Statement**
Given \( n \) people, determine if there is a celebrity among them using the following function:
- \( knows(A, B) \): Returns `True` if person \( A \) knows person \( B \), otherwise `False`.

### **Input:**
- \( n \): Number of people.
- A function \( knows(A, B) \).

### **Output:**
- The index of the celebrity if one exists.
- If no celebrity exists, return `-1`.

---

### **Constraints:**
1. \( knows(A, B) \) is predefined and operates in \( O(1) \) time.
2. Solve the problem in \( O(n) \) time complexity.

---

### **Solution:**
We use a two-step process:
1. Identify a **potential celebrity** using elimination.
2. Verify if the candidate satisfies the celebrity conditions.

---

### **Python Implementation**
```python
def findCelebrity(n, knows):
    # Step 1: Identify a potential celebrity
    celebrity = 0
    for i in range(1, n):
        if knows(celebrity, i):
            # If the current candidate knows someone, they cannot be the celebrity
            celebrity = i

    # Step 2: Verify the candidate
    for i in range(n):
        if i != celebrity and (knows(celebrity, i) or not knows(i, celebrity)):
            # If the candidate knows someone OR someone doesn't know the candidate
            return -1

    return celebrity
```

---

### **Example Usage**

#### **Input Example 1:**
Let’s define a `knows` function for a test case:

```python
# Matrix representation of "knows" relationships
# Row i: person i, Column j: True if i knows j
knows_matrix = [
    [False, True, False],  # Person 0 knows 1
    [False, False, False], # Person 1 knows nobody (Celebrity)
    [True, True, False]    # Person 2 knows 0 and 1
]

def knows(A, B):
    return knows_matrix[A][B]

n = 3
print("Celebrity:", findCelebrity(n, knows))  # Output: 1
```

---

#### **Input Example 2 (No Celebrity):**
```python
knows_matrix = [
    [False, True, False],
    [True, False, False],
    [False, True, False]
]

print("Celebrity:", findCelebrity(n, knows))  # Output: -1
```

---

### **Explanation of the Algorithm**
1. **Identify a Candidate:** 
   - Start with person 0 as the candidate.
   - If the candidate knows \( i \), eliminate the candidate and set \( i \) as the new candidate.
   - This ensures that at most \( n-1 \) comparisons are made.

2. **Verify the Candidate:**
   - Check if everyone knows the candidate.
   - Ensure the candidate knows no one else.

This approach works in \( O(n) \) time. 

---

### Introduction to NLP
Natural Language Processing (NLP) is a field of artificial intelligence that focuses on the interaction between computers and humans through natural language. The goal is to enable computers to understand, interpret, and generate human language in a way that is both meaningful and useful.

### Key Concepts in NLP
1. **Tokenization**: Breaking down text into smaller units, such as words or sentences.
2. **Stop Words**: Common words (e.g., "and", "the", "is") that are often removed from text to focus on more meaningful words.
3. **Stemming and Lemmatization**: Reducing words to their base or root form.
4. **Part-of-Speech Tagging**: Identifying the grammatical parts of speech (e.g., nouns, verbs) in a sentence.
5. **Named Entity Recognition (NER)**: Identifying and classifying entities (e.g., names, dates) in text.
6. **Sentiment Analysis**: Determining the sentiment or emotion expressed in text.

### Getting Started with NLP in Python
We'll use the `nltk` library, a powerful toolkit for NLP in Python.

#### Step 1: Install NLTK
First, you need to install the `nltk` library. You can do this using pip:
```bash
pip install nltk
```

#### Step 2: Import NLTK and Download Data
```python
import nltk
nltk.download('all')  # Download all NLTK data (you can download specific datasets as needed)
```

#### Step 3: Tokenization
```python
from nltk.tokenize import word_tokenize, sent_tokenize

text = "Natural Language Processing is fascinating. Let's learn more about it!"
word_tokens = word_tokenize(text)
sent_tokens = sent_tokenize(text)

print("Word Tokens:", word_tokens)
print("Sentence Tokens:", sent_tokens)
```

#### Step 4: Removing Stop Words
```python
from nltk.corpus import stopwords

stop_words = set(stopwords.words('english'))
filtered_words = [word for word in word_tokens if word.lower() not in stop_words]

print("Filtered Words:", filtered_words)
```

#### Step 5: Stemming and Lemmatization
```python
from nltk.stem import PorterStemmer, WordNetLemmatizer

stemmer = PorterStemmer()
lemmatizer = WordNetLemmatizer()

stemmed_words = [stemmer.stem(word) for word in filtered_words]
lemmatized_words = [lemmatizer.lemmatize(word) for word in filtered_words]

print("Stemmed Words:", stemmed_words)
print("Lemmatized Words:", lemmatized_words)
```

#### Step 6: Part-of-Speech Tagging
```python
pos_tags = nltk.pos_tag(word_tokens)
print("Part-of-Speech Tags:", pos_tags)
```

#### Step 7: Named Entity Recognition (NER)
```python
from nltk import ne_chunk

ner_tree = ne_chunk(pos_tags)
print("Named Entities:", ner_tree)
```

#### Step 8: Sentiment Analysis
For sentiment analysis, you can use libraries like `TextBlob` or `VADER`:
```python
from textblob import TextBlob

blob = TextBlob(text)
print("Sentiment:", blob.sentiment)
```

## You can use the transformers library from Hugging Face for various NLP tasks:

### 1. Sentiment Analysis
```python
from transformers import pipeline

# Load the sentiment-analysis pipeline
classifier = pipeline('sentiment-analysis')

# Analyze sentiment
result = classifier("I love using the transformers library!")
print(result)
```
This will output:
```
[{'label': 'POSITIVE', 'score': 0.9998}]
```

### 2. Named Entity Recognition (NER)
```python
from transformers import pipeline

# Load the NER pipeline
ner = pipeline('ner', grouped_entities=True)

# Perform NER
result = ner("Hugging Face Inc. is a company based in New York City.")
print(result)
```
This will output:
```
[{'entity_group': 'ORG', 'score': 0.998, 'word': 'Hugging Face Inc.'},
 {'entity_group': 'LOC', 'score': 0.999, 'word': 'New York City'}]
```

### 3. Text Generation
```python
from transformers import pipeline

# Load the text generation pipeline
generator = pipeline('text-generation', model='gpt2')

# Generate text
result = generator("Once upon a time", max_length=50, num_return_sequences=1)
print(result)
```
This will output a continuation of the given text.

### 4. Question Answering
```python
from transformers import pipeline

# Load the question-answering pipeline
qa = pipeline('question-answering')

# Answer a question
result = qa(question="What is the capital of France?", context="Paris is the capital of France.")
print(result)
```
This will output:
```
{'score': 0.99, 'start': 0, 'end': 5, 'answer': 'Paris'}
```

### 5. Text Summarization
```python
from transformers import pipeline

# Load the summarization pipeline
summarizer = pipeline('summarization')

# Summarize text
text = """
The transformers library by Hugging Face provides thousands of pretrained models to perform tasks on different modalities such as text, vision, and audio.
These models can be applied on: text, for tasks like text classification, information extraction, question answering, summarization, translation, and text generation.
"""
result = summarizer(text, max_length=50, min_length=25, do_sample=False)
print(result)
```
This will output a summarized version of the given text.

### 6. Translation
```python
from transformers import pipeline

# Load the translation pipeline
translator = pipeline('translation_en_to_fr')

# Translate text
result = translator("Hello, how are you?")
print(result)
```
This will output:
```
[{'translation_text': 'Bonjour, comment ça va ?'}]
```

These examples demonstrate the versatility of the `transformers` library for various NLP tasks. You can explore more models and tasks on the [Hugging Face Transformers GitHub page](https://github.com/huggingface/transformers)(https://github.com/huggingface/transformers).


### Conclusion
There are many more advanced techniques and libraries (like `spaCy` and `transformers`) that you can explore as you dive deeper into NLP.

