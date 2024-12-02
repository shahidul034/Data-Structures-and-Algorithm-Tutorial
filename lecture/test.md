### **Propositional Logic**  
Propositional logic (also called propositional calculus or statement logic) is a branch of logic that deals with **propositions**—statements that are either true or false. It is the foundation of logical reasoning in computer science, artificial intelligence, and mathematics.

#### Key Features:
- **Propositions:** Simple declarative statements like "It is raining" (denoted by variables like \( p, q, r \)).
- **Logical Connectives:**
  - **AND (\( \land \))**: \( p \land q \) is true if both \( p \) and \( q \) are true.
  - **OR (\( \lor \))**: \( p \lor q \) is true if at least one of \( p \) or \( q \) is true.
  - **NOT (\( \neg \))**: \( \neg p \) is true if \( p \) is false.
  - **IMPLIES (\( \rightarrow \))**: \( p \rightarrow q \) is true unless \( p \) is true and \( q \) is false.
  - **EQUIVALENCE (\( \leftrightarrow \))**: \( p \leftrightarrow q \) is true if \( p \) and \( q \) have the same truth value.
- **Truth Tables:** Used to determine the truth value of a compound proposition under all possible assignments of truth values to its components.

#### Example:
- Proposition: "If it rains (\( p \)), the ground will be wet (\( q \))" can be written as \( p \rightarrow q \).
- Truth table for \( p \rightarrow q \):

| \( p \) | \( q \) | \( p \rightarrow q \) |
|--------|--------|-----------------------|
| True   | True   | True                  |
| True   | False  | False                 |
| False  | True   | True                  |
| False  | False  | True                  |

---

### **Predicate Logic**  
Predicate logic (also called first-order logic) extends propositional logic by including **quantifiers** and predicates, enabling more expressive reasoning.

#### Key Features:
- **Predicates:** Functions or properties applied to objects, e.g., \( Likes(John, Pizza) \), \( IsStudent(x) \).
- **Quantifiers:**
  - **Universal Quantifier (\( \forall \)):** Indicates that a predicate is true for all objects in a domain. Example: \( \forall x \, Loves(x, Pizza) \) means "Everyone loves pizza."
  - **Existential Quantifier (\( \exists \)):** Indicates that a predicate is true for at least one object in a domain. Example: \( \exists x \, IsStudent(x) \) means "There exists someone who is a student."
- **Domain of Discourse:** The set of objects under consideration.

#### Example:
- Statement: "All humans are mortal."
  - Predicate logic: \( \forall x \, (Human(x) \rightarrow Mortal(x)) \).

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
- Plan: Move \( A \rightarrow B \rightarrow C \). 

Planning leverages logic to model and solve problems systematically in various domains, including robotics, logistics, and AI decision-making.