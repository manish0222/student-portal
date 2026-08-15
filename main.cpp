#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    string status;
};

vector<Book> loadBooks() {
    vector<Book> books;
    ifstream file("books.txt");

    if (!file) {
        cout << "Unable to open books.txt\n";
        return books;
    }

    string line;

    while (getline(file, line)) {
        size_t first = line.find('|');
        size_t second = line.find('|', first + 1);
        size_t third = line.find('|', second + 1);

        if (first == string::npos ||
            second == string::npos ||
            third == string::npos) {
            continue;
        }

        Book book;
        book.id = stoi(line.substr(0, first));
        book.title = line.substr(first + 1, second - first - 1);
        book.author = line.substr(second + 1, third - second - 1);
        book.status = line.substr(third + 1);

        books.push_back(book);
    }

    return books;
}

void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books are currently available.\n";
        return;
    }

    cout << "\n===== BOOKS =====\n";

    for (const Book& book : books) {
        cout << "ID: " << book.id
             << " | Title: " << book.title
             << " | Author: " << book.author
             << " | Status: " << book.status << '\n';
    }
}

void searchBook(const vector<Book>& books) {
    string keyword;
    bool found = false;

    cout << "Enter title or author to search: ";
    cin.ignore();
    getline(cin, keyword);

    for (const Book& book : books) {
        if (book.title.find(keyword) != string::npos ||
            book.author.find(keyword) != string::npos) {

            cout << "ID: " << book.id
                 << " | Title: " << book.title
                 << " | Author: " << book.author
                 << " | Status: " << book.status << '\n';

            found = true;
        }
    }

    if (!found) {
        cout << "No matching book found.\n";
    }
}

void addBook(vector<Book>& books) {
    Book book;

    cout << "Enter book ID: ";
    cin >> book.id;

    cin.ignore();

    cout << "Enter book title: ";
    getline(cin, book.title);

    cout << "Enter author name: ";
    getline(cin, book.author);

    book.status = "Available";

    ofstream file("books.txt", ios::app);

    if (!file) {
        cout << "Unable to open books.txt for writing.\n";
        return;
    }

    file << book.id << '|'
         << book.title << '|'
         << book.author << '|'
         << book.status << '\n';

    file.close();

    books.push_back(book);

    cout << "Book added successfully.\n";
}

void displayMenu() {
    cout << "\n===== BOOK PORTAL =====\n";
    cout << "1. View Books\n";
    cout << "2. Search Book\n";
    cout << "3. Add Book\n";
    cout << "4. Borrow Book\n";
    cout << "5. Return Book\n";
    cout << "6. Exit\n";
}

int main() {
    vector<Book> books = loadBooks();
    int choice;

    cout << "Welcome to the Book Portal!\n";

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayBooks(books);
        } else if (choice == 2) {
            searchBook(books);
        } else if (choice == 3) {
            addBook(books);
        } else if (choice >= 4 && choice <= 5) {
            cout << "This feature will be available soon.\n";
        } else if (choice == 6) {
            cout << "Thank you for using the Book Portal.\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}