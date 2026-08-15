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

        if (choice >= 1 && choice <= 5) {
            cout << "This feature will be available soon.\n";
        } else if (choice == 6) {
            cout << "Thank you for using the Book Portal.\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}