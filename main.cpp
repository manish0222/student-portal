#include <iostream>

using namespace std;

void displayMenu() {
    cout << "\n===== BOOK PORTAL =====\n";
    cout << "1. View Books\n";
    cout << "2. Search Book\n";
    cout << "3. Add Book\n";
    cout << "4. Borrow Book\n";
    cout << "5. Return Book\n";
    cout << "6. Exit \n";
}

int main() {
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