#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password;
    bool loggedIn;
};

User currentUser = {"admin", "book123", false};

struct Book {
    int id;
    string title;
    string author;
    string status;
};
struct Profile {
    string name;
    string email;
    string role;
};

Profile currentProfile = {
    "Admin User",
    "admin@bookportal.com",
    "Administrator"
};

vector<Book> loadBooks() {
    vector<Book> books;
    ifstream file("data/catalog.txt");

    if (!file) {
        cout << "Unable to open data/catalog.txt\n";
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

void saveBooks(const vector<Book>& books) {
    ofstream file("data/catalog.txt");

    if (!file) {
        cout << "Unable to save data/catalog.txt\n";
        return;
    }

    for (const Book& book : books) {
        file << book.id << '|'
             << book.title << '|'
             << book.author << '|'
             << book.status << '\n';
    }
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

bool login() {
    string username;
    string password;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (username == currentUser.username &&
        password == currentUser.password) {
        currentUser.loggedIn = true;
        cout << "Login successful.\n";
        return true;
    }

    cout << "Invalid username or password.\n";
    return false;
}
void displayLoginStatus() {
    if (currentUser.loggedIn) {
    } else {
        cout << "Not logged in.\n";
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
    if (!currentUser.loggedIn) {
        cout << "Please login first.\n";
        return;
    }
    Book book;

    cout << "Enter book ID: ";
    cin >> book.id;

    cin.ignore();

    cout << "Enter book title: ";
    getline(cin, book.title);

    cout << "Enter author name: ";
    getline(cin, book.author);

    book.status = "Available";

    books.push_back(book);
    saveBooks(books);

    cout << "Book added successfully.\n";
}

void borrowBook(vector<Book>& books) {
    if (!currentUser.loggedIn) {
        cout << "Please login first.\n";
        return;
    }
    int id;

    cout << "Enter book ID to borrow: ";
    cin >> id;

    for (Book& book : books) {
        if (book.id == id) {
            if (book.status == "Borrowed") {
                cout << "Book is already borrowed.\n";
                return;
            }

            book.status = "Borrowed";
            saveBooks(books);

            cout << "Book borrowed successfully.\n";
            return;
        }
    }

    cout << "Book with ID " << id << " was not found.\n";
}

void returnBook(vector<Book>& books) {
    if (!currentUser.loggedIn) {
        cout << "Please login first.\n";
        return;
    }
    int id;

    cout << "Enter book ID to return: ";
    cin >> id;

    for (Book& book : books) {
        if (book.id == id) {
            if (book.status == "Available") {
                cout << "Book is already available.\n";
                return;
            }

            book.status = "Available";
            saveBooks(books);

            cout << "Book returned successfully.\n";
            return;
        }
    }

    cout << "Book with ID " << id << " was not found.\n";
}
void displayProfile() {
    cout << "\n===== USER PROFILE =====\n";
    cout << "Name: " << currentProfile.name << "\n";
    cout << "Email: " << currentProfile.email << "\n";
    cout << "Role: " << currentProfile.role << "\n";
}
void updateProfile() {
    string name;
    string email;

    cin.ignore();

    cout << "Enter new name: ";
    getline(cin, name);

    cout << "Enter new email: ";
    getline(cin, email);

    currentProfile.name = name;
    currentProfile.email = email;

    cout << "Profile updated successfully.\n";
}
void displayMenu() {
    cout << "\n===== BOOK PORTAL =====\n";
    displayLoginStatus();
    if (currentUser.loggedIn) {
        cout << "Logged in as: " << currentUser.username << "\n";
        cout << "1. View Books\n";
        cout << "2. Search Book\n";
        cout << "3. Add Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Logout\n";
        cout << "7. View Profile\n";
        cout << "8. Update Profile\n";
        cout << "9. Exit\n";
    } else {
        cout << "1. Login\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
    }
}

int main() {
    vector<Book> books = loadBooks();
    int choice;

    cout << "Welcome to the Book Portal!\n";

    do {
        displayMenu();
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            continue;
        }

        if (!currentUser.loggedIn) {
            if (choice == 1) {
                login();
            } else if (choice == 2) {
                displayBooks(books);
            } else if (choice == 3) {
                searchBook(books);
            } else if (choice == 4) {
                cout << "Thank you for using the Book Portal.\n";
            } else {
                cout << "Invalid choice.\n";
            }
        } else {
            if (choice == 1) {
                displayBooks(books);
            } else if (choice == 2) {
                searchBook(books);
            } else if (choice == 3) {
                addBook(books);
            } else if (choice == 4) {
                borrowBook(books);
            } else if (choice == 5) {
                returnBook(books);
            } else if (choice == 6) {
                currentUser.loggedIn = false;
                cout << "Logged out successfully.\n";
            } else if (choice == 7) {
                displayProfile();
            } else if (choice == 8) {
                updateProfile();
            } else {
                cout << "Invalid choice.\n";
            }
        }

    } while (currentUser.loggedIn || choice != 4);

    return 0;
}