# Data-Structures-and-Algorithms
## Contents
| #Lab  | Topics name |
| ------------- | ------------- |
| 1 | ✔[Installation and Introduction to Datatypes, Arrays, Pointers, Structures, and Class](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/lecture/lab1.md) |
| 2 | ✔[STL (Standard Template Library)](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/lecture/lab2.md) |
| 3 | ✔[Stacks and Queues](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/lecture/lab3.md) |
| 4 | ✔[Linked Lists (Part 1)](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/lecture/lab4.md)|
| 5 | ✔[Linked Lists (Part 2)](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/lecture/lab5.md) |
| 6 | ✔[Graphs](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/lecture/lab6.md) |
| 7 | ✔[Sorting](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/lecture/lab7.md)|
| 8 | ✔[Trees](https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial/blob/main/lecture/lab8.md) |
| 9 | ⏳Backtracking and Greedy |
| 10 | ⏳Hashing |
| 11 | ⏳Dynamic Programming |


<details>
<summary><h2><i>👀Miscellaneous code</i></h2></summary>
	
## 💡Random Number generation

```c
#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;
// Function to return a random number in a given range [min, max]
int getRandomNumber(int min, int max) {
    // Ensure that the range is valid
    if (min > max) {
        cerr << "Invalid range" << endl;
        return -1;  // or throw an exception
    }
    
    // Initialize random seed based on the current time
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Generate a random number between min and max
    return min + rand() % ((max - min) + 1);
}

int main() {
    int min = 1, max = 100;
    int randomNum = getRandomNumber(min, max);
    cout << "Random number between " << min << " and " << max << ": " << randomNum << endl;
}
```
</details>

## Citation

```c
@misc{Salim2024,
  author = {Salim, Md. Shahidul},
  title = {Data Structures and Algorithm Tutorial},
  year = {2024},
  publisher = {GitHub},
  journal = {GitHub repository},
  howpublished = {\url{https://github.com/shahidul034/Data-Structures-and-Algorithm-Tutorial}},
}
```

