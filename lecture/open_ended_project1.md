# Social Network Analysis Project

## Project Overview
Design and implement a social network analysis system that allows users to analyze relationships, communities, and information flow within a network of people. This project integrates multiple data structures and algorithms to create a comprehensive solution.

## Core Requirements

### Data Structure Implementation
1. Implement a custom Graph class to represent the social network
   - Use adjacency list representation using linked lists
   - Each vertex (person) should be implemented as a class containing:
     - Basic information (name, ID, etc.)
     - Connection list
     - Additional metrics (centrality, influence score, etc.)

2. Implement supporting data structures:
   - Use STL containers where appropriate
   - Custom implementation of a Priority Queue for algorithm optimization
   - Binary Tree for hierarchical community structure

### Feature Requirements

#### Basic Features
1. Add/remove users to the network
2. Create/delete connections between users
3. Basic profile management using structures/classes
4. Save/load network data from files

#### Advanced Features
1. Community Detection
   - Implement a graph traversal algorithm (BFS/DFS)
   - Use backtracking to find all possible communities
   - Store communities in appropriate data structures

2. Path Analysis
   - Find shortest path between two users
   - Identify mutual connections
   - Calculate degrees of separation

3. Influence Analysis
   - Calculate centrality metrics
   - Implement sorting algorithms for ranking users
   - Generate influence scores

### Technical Requirements
1. Proper use of pointers and memory management
2. Efficient algorithm implementation
3. Clean code structure and documentation
4. Error handling and input validation

## Extension Possibilities
- Visualization of the network
- Real-time network analysis
- Advanced community detection algorithms
- Machine learning integration for prediction

## Marking Criteria (20 marks)

### 1. Data Structure Implementation (6 marks)
- Graph implementation (2 marks)
  - Correct adjacency list representation
  - Proper memory management
- Supporting data structures (2 marks)
  - Appropriate use of STL
  - Custom data structure implementation
- Class/Structure design (2 marks)
  - Well-organized class hierarchy
  - Proper encapsulation

### 2. Algorithm Implementation (6 marks)
- Graph algorithms (2 marks)
  - Correct traversal implementation
  - Efficient path finding
- Community detection (2 marks)
  - Backtracking implementation
  - Community identification logic
- Sorting and ranking (2 marks)
  - Correct sorting implementation
  - Efficient ranking system

### 3. Features and Functionality (4 marks)
- Basic operations (1 mark)
  - User management
  - Connection handling
- Advanced features (2 marks)
  - Influence analysis
  - Path analysis
- File operations (1 mark)
  - Save/load functionality
  - Error handling

### 4. Code Quality and Documentation (4 marks)
- Code organization (1 mark)
  - Clean structure
  - Modular design
- Documentation (1 mark)
  - Clear comments
  - README/documentation
- Error handling (1 mark)
  - Input validation
  - Exception handling
- Innovation/Creativity (1 mark)
  - Additional features
  - Creative solutions

## Submission Requirements
1. Source code with complete implementation
2. Documentation including:
   - Design decisions
   - Data structure choices
   - Algorithm explanations
   - Setup instructions
3. Test cases and example outputs
4. Project presentation

