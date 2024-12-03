```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// Structure to store book details
struct Book {
    string title;
    string author;
    int isbn;
    Book(string t, string a, int i) : title(t), author(a), isbn(i) {}
};

// Structure for Library Members
struct Member {
    string name;
    int id;
    vector<int> issuedBooks; // List of issued book ISBNs
};

// Tree Node for Library Sections
struct TreeNode {
    string sectionName;
    vector<TreeNode*> subSections;
    TreeNode(string name) : sectionName(name) {}
};

// Main Library Class
class Library {
private:
    vector<Book> books;                // Using vector for book catalog
    vector<Member> members;            // Linked list equivalent for members
    stack<int> recentReturns;          // Stack for recently returned books
    queue<int> requestQueue;           // Queue for book issue requests

public:
    // Add a new book
    void addBook(string title, string author, int isbn) {
        books.push_back(Book(title, author, isbn));
        cout << "Book added successfully.\n";
    }

    // Delete a book
    void deleteBook(int isbn) {
        auto it = remove_if(books.begin(), books.end(), [&](Book &b) { return b.isbn == isbn; });
        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book deleted successfully.\n";
        } else {
            cout << "Book not found.\n";
        }
    }

    // Search for a book
    void searchBook(string title) {
        cout << "Searching for: " << title << "\n";
        bool found = false;
        for (auto &b : books) {
            if (b.title == title) {
                cout << "Book Found: " << b.title << " by " << b.author << " (ISBN: " << b.isbn << ")\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Book not found.\n";
    }

    // Issue a book
    void issueBook(int isbn, int memberId) {
        // Check if book exists
        bool bookFound = false;
        for (auto &b : books) {
            if (b.isbn == isbn) {
                bookFound = true;
                break;
            }
        }

        if (!bookFound) {
            cout << "Book not available in catalog.\n";
            return;
        }

        // Add request to queue
        requestQueue.push(isbn);
        cout << "Request for book (ISBN: " << isbn << ") added to queue.\n";
    }

    // Return a book
    void returnBook(int isbn) {
        recentReturns.push(isbn);
        cout << "Book (ISBN: " << isbn << ") added to recent returns.\n";
    }

    // Add a new member
    void addMember(string name, int id) {
        members.push_back({name, id, {}});
        cout << "Member added successfully.\n";
    }

    // Print recent returns
    void showRecentReturns() {
        cout << "Recent Returns:\n";
        stack<int> temp = recentReturns;
        while (!temp.empty()) {
            cout << "ISBN: " << temp.top() << "\n";
            temp.pop();
        }
    }
};

// Tree to represent Library Sections
class LibraryTree {
private:
    TreeNode* root;

public:
    LibraryTree(string rootName) {
        root = new TreeNode(rootName);
    }

    // Add a subsection
    void addSubSection(TreeNode* parent, string sectionName) {
        TreeNode* newSection = new TreeNode(sectionName);
        parent->subSections.push_back(newSection);
    }

    // Display sections
    void displaySections(TreeNode* node, int depth = 0) {
        if (!node) return;
        for (int i = 0; i < depth; ++i) cout << "  ";
        cout << node->sectionName << "\n";
        for (auto child : node->subSections) {
            displaySections(child, depth + 1);
        }
    }

    TreeNode* getRoot() { return root; }
};

int main() {
    Library lib;

    // Adding some books
    lib.addBook("Data Structures", "John Doe", 101);
    lib.addBook("Algorithms", "Jane Smith", 102);
    lib.addBook("C++ Programming", "Mark Twain", 103);

    // Adding members
    lib.addMember("Alice", 1);
    lib.addMember("Bob", 2);

    // Searching for a book
    lib.searchBook("Algorithms");

    // Issuing and returning books
    lib.issueBook(102, 1);
    lib.returnBook(102);

    // Showing recent returns
    lib.showRecentReturns();

    // Library Sections
    LibraryTree libraryTree("Library");
    TreeNode* root = libraryTree.getRoot();
    libraryTree.addSubSection(root, "Fiction");
    libraryTree.addSubSection(root, "Non-Fiction");
    TreeNode* science = new TreeNode("Science");
    libraryTree.addSubSection(root, "Science");

    cout << "Library Sections:\n";
    libraryTree.displaySections(root);

    return 0;
}
```